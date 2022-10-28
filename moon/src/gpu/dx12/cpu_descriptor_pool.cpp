#include "cpu_descriptor_pool.h"

#include "device.h"

namespace moon::gpu::dx12 {
DX12CPUDescriptorPool::DX12CPUDescriptorPool(DX12Device &device)
    : m_device(device),
      m_resource(device, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV),
      m_sampler(device, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER),
      m_rtv(device, D3D12_DESCRIPTOR_HEAP_TYPE_RTV),
      m_dsv(device, D3D12_DESCRIPTOR_HEAP_TYPE_DSV) {}

auto DX12CPUDescriptorPool::allocate_descriptor(ViewType view_type)
    -> zinc::shared<DX12CPUDescriptorHandle> {
  auto &heap = select_heap(view_type);
  return heap.allocate(1);
}

auto DX12CPUDescriptorPool::select_heap(ViewType view_type)
    -> DX12CPUDescriptorPoolTyped & {
  switch (view_type) {
  case ViewType::eAccelerationStructure:
  case ViewType::eConstantBuffer:
  case ViewType::eTexture:
  case ViewType::eRWTexture:
  case ViewType::eBuffer:
  case ViewType::eRWBuffer:
  case ViewType::eStructuredBuffer:
  case ViewType::eRWStructuredBuffer:
    return m_resource;
  case ViewType::eSampler:
    return m_sampler;
  case ViewType::eRenderTarget:
    return m_rtv;
  case ViewType::eDepthStencil:
    return m_dsv;
  default:
    throw "fatal failure";
  }
  return m_sampler;
};
} // namespace moon::gpu::dx12