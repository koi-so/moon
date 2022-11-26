#include "resource.h"

#include "rook/platform.h"

#include "device.h"
#include "memory.h"

#include "format_helper.h"

#define EASTL_OPTIONAL_ENABLED 1
#include <EASTL/optional.h>

namespace rook::gpu::dx12 {
auto GetClearValue(D3D12_RESOURCE_DESC const &desc)
    -> eastl::optional<D3D12_CLEAR_VALUE> {
  D3D12_CLEAR_VALUE clear_value = {};
  if (desc.Dimension != D3D12_RESOURCE_DIMENSION_BUFFER) {
    clear_value.Format = desc.Format;
    if (desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET) {
      clear_value.Color[0] = 0.0f;
      clear_value.Color[1] = 0.0f;
      clear_value.Color[2] = 0.0f;
      clear_value.Color[3] = 1.0f;
      return clear_value;
    } else if (desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL) {
      clear_value.DepthStencil.Depth = 1.0f;
      clear_value.DepthStencil.Stencil = 0;
      clear_value.Format = DepthStencilFromTypeless(clear_value.Format);
      return clear_value;
    }
  }
  return {};
}

DX12Resource::DX12Resource(DX12Device &device) : m_device(device) {}

void DX12Resource::commit_memory(MemoryType memory_type) {
  m_memory_type = memory_type;
  auto clear_value = GetClearValue(p_desc);
  D3D12_CLEAR_VALUE *p_clear_value = nullptr;
  if (clear_value.has_value())
    p_clear_value = &clear_value.value();

  if (m_memory_type == MemoryType::eUpload)
    set_initial_state(ResourceState::eGenericRead);
  else if (m_memory_type == MemoryType::eReadback)
    set_initial_state(ResourceState::eCopyDest);

  D3D12_HEAP_FLAGS flags = D3D12_HEAP_FLAG_NONE;
  if (m_device.is_create_not_zeroed_available())
    flags |= D3D12_HEAP_FLAG_CREATE_NOT_ZEROED;

  auto heap_properties = CD3DX12_HEAP_PROPERTIES(GetHeapType(m_memory_type));
  m_device.get_device()->CreateCommittedResource(
      &heap_properties, flags, &p_desc, ConvertState(get_initial_state()),
      p_clear_value, IID_PPV_ARGS(&p_resource));
}

void DX12Resource::bind_memory(eastl::shared_ptr<Memory> const &memory,
                               uint64_t offset) {
  m_memory = memory;
  m_memory_type = m_memory->get_type();
  auto clear_value = GetClearValue(p_desc);
  D3D12_CLEAR_VALUE *p_clear_value = nullptr;
  if (clear_value.has_value())
    p_clear_value = &clear_value.value();

  // TODO
  if (m_memory_type == MemoryType::eUpload)
    set_initial_state(ResourceState::eGenericRead);

  auto dx_memory = m_memory->as<DX12Memory>();
  m_device.get_device()->CreatePlacedResource(
      dx_memory.get_heap().Get(), offset, &p_desc,
      ConvertState(get_initial_state()), p_clear_value,
      IID_PPV_ARGS(&p_resource));
}

auto DX12Resource::get_width() const -> uint64_t { return p_desc.Width; }
auto DX12Resource::get_height() const -> uint32_t { return p_desc.Height; }
auto DX12Resource::get_layer_count() const -> uint16_t {
  return p_desc.DepthOrArraySize;
}
auto DX12Resource::get_level_count() const -> uint16_t {
  return p_desc.MipLevels;
}
auto DX12Resource::get_sample_count() const -> uint32_t {
  return p_desc.SampleDesc.Count;
}
auto DX12Resource::get_acceleration_structure_handle() const -> uint64_t {
  return p_acceleration_structure_handle;
}

void DX12Resource::set_name(eastl::string const &name) {
  if (p_resource) {
    wchar_t res_name[256];
    MultiByteToWideChar(CP_UTF8, 0, name.c_str(), -1, res_name,
                        sizeof(res_name));
    p_resource->SetName(res_name);
  }
}

auto DX12Resource::map() -> uint8_t * {
  CD3DX12_RANGE range(0, 0);
  uint8_t *dst_data = nullptr;
  ASSERT_SUCCEEDED(
      p_resource->Map(0, &range, reinterpret_cast<void **>(&dst_data)));
  return dst_data;
}

void DX12Resource::unmap() {
  CD3DX12_RANGE range(0, 0);
  p_resource->Unmap(0, &range);
}

auto DX12Resource::allow_common_state_promotion(ResourceState state_after)
    -> bool {
  if (p_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    return true;
  if (p_desc.Flags & D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS) {
    switch (ConvertState(state_after)) {
    case D3D12_RESOURCE_STATE_DEPTH_WRITE:
      return false;
    default:
      return true;
    }
  } else {
    switch (ConvertState(state_after)) {
    case D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE:
    case D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE:
    case D3D12_RESOURCE_STATE_COPY_DEST:
    case D3D12_RESOURCE_STATE_COPY_SOURCE:
      return true;
    default:
      return false;
    }
  }
  return false;
}

auto DX12Resource::get_memory_requirements() const -> MemoryRequirements {
  D3D12_RESOURCE_ALLOCATION_INFO allocation_info =
      m_device.get_device()->GetResourceAllocationInfo(0, 1, &p_desc);
  return {allocation_info.SizeInBytes, allocation_info.Alignment, 0};
}
} // namespace rook::gpu::dx12