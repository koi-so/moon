#include "gpu_descriptor_pool.h"

#include <EASTL/utility.h>

namespace rook::gpu::dx12 {
DX12GPUDescriptorPool::DX12GPUDescriptorPool(DX12Device &device)
    : m_device(device),
      m_shader_resource(device, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV),
      m_shader_sampler(device, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER) {}

auto DX12GPUDescriptorPool::allocate(D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type,
                                     size_t count)
    -> DX12GPUDescriptorPoolRange {
  switch (descriptor_type) {
  case D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV:
    return m_shader_resource.allocate(count);
  case D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER:
    return m_shader_sampler.allocate(count);
  default:
    EASTL_ASSERT_MSG(false, "Invalid descriptor type");
  }
}

auto DX12GPUDescriptorPool::get_heap(D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type)
    -> ComPtr<ID3D12DescriptorHeap> {
  switch (descriptor_type) {
  case D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV:
    return m_shader_resource.get_heap();
  case D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER:
    return m_shader_sampler.get_heap();
  default:
    EASTL_ASSERT_MSG(false, "Invalid descriptor type");
  }
}
} // namespace rook::gpu::dx12