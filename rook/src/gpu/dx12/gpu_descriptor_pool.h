#pragma once

#include "rook/base.h"

#include "common.h"
#include "gpu_descriptor_pool_range.h"
#include "gpu_descriptor_pool_typed.h"

namespace rook::gpu::dx12 {
class DX12Device;
class DX12GPUDescriptorPool {
public:
  DX12GPUDescriptorPool(DX12Device &device);
  auto allocate(D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type, size_t count)
      -> DX12GPUDescriptorPoolRange;
  auto get_heap(D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type)
      -> ComPtr<ID3D12DescriptorHeap>;

private:
  DX12Device &m_device;
  DX12GPUDescriptorPoolTyped m_shader_resource;
  DX12GPUDescriptorPoolTyped m_shader_sampler;
};
} // namespace rook::gpu::dx12