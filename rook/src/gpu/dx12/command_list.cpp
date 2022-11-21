#include "command_list.h"

#include "binding_set.h"
#include "device.h"
#include "graphics_pipeline.h"
#include "pipeline.h"

#include <EASTL/shared_ptr.h>

namespace rook::gpu::dx12 {
DX12CommandList::DX12CommandList(DX12Device &device, CommandListType type)
    : m_device(device) {
  D3D12_COMMAND_LIST_TYPE dx_type;
  switch (type) {
  case CommandListType::eGraphics:
    dx_type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    break;
  case CommandListType::eCompute:
    dx_type = D3D12_COMMAND_LIST_TYPE_COMPUTE;
    break;
  case CommandListType::eCopy:
    dx_type = D3D12_COMMAND_LIST_TYPE_COPY;
    break;
  default:
    EASTL_ASSERT(false);
    break;
  }

  ASSERT_SUCCEEDED(device.get_device()->CreateCommandAllocator(
      dx_type, IID_PPV_ARGS(&m_command_allocator)));
  ASSERT_SUCCEEDED(device.get_device()->CreateCommandList(
      0, dx_type, m_command_allocator.Get(), nullptr,
      IID_PPV_ARGS(&m_command_list)));

  m_command_list.As(&m_command_list4);
  m_command_list.As(&m_command_list5);
  m_command_list.As(&m_command_list6);
}

void DX12CommandList::reset() {
  close();
  ASSERT_SUCCEEDED(m_command_allocator->Reset());
  ASSERT_SUCCEEDED(m_command_list->Reset(m_command_allocator.Get(), nullptr));
  m_closed = false;
  m_heaps.clear();
  m_state.reset();
  m_binding_set.reset();
  m_lazy_vertex.clear();
  m_shading_rate_image_view.reset();
}

void DX12CommandList::close() {
  if (!m_closed) {
    ASSERT_SUCCEEDED(m_command_list->Close());
    m_closed = true;
  }
}

void DX12CommandList::bind_pipeline(
    eastl::shared_ptr<Pipeline> const &pipeline) {
  if (pipeline == m_state)
    return;
  m_state = eastl::static_pointer_cast<DX12Pipeline>(pipeline);
  m_command_list->SetComputeRootSignature(m_state->get_root_signature().Get());
  auto type = m_state->get_type();
  switch (type) {
  case PipelineType::eGraphics: {
    auto dx_state = m_state->as<DX12GraphicsPipeline>();
    m_command_list->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_command_list->SetGraphicsRootSignature(
        dx_state.get_root_signature().Get());
    m_command_list->SetPipelineState(dx_state.get_pipeline().Get());
    for (auto const &x : dx_state.get_stride_map()) {
      auto it = m_lazy_vertex.find(x.first);
      if (it != m_lazy_vertex.end()) {
        ia_set_vertex_buffer_impl(x.first, it->second, x.second);
      } else {
        ia_set_vertex_buffer_impl(x.first, {}, 0);
      }
    }
    break;
  }
  case PipelineType::eCompute:
  case PipelineType::eRayTracing:
    // TODO
    break;
  }
}

void DX12CommandList::bind_binding_set(
    eastl::shared_ptr<BindingSet> const &binding_set) {
  if (binding_set == m_binding_set)
    return;
  auto dx_binding_set = binding_set->as<DX12BindingSet>();
}
} // namespace rook::gpu::dx12