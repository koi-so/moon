#pragma once

#include "rook/base.h"
#include "rook/gpu.h"

#include "common.h"
#include "gpu_descriptor_pool_range.h"

#include <EASTL/map.h>

namespace rook::gpu::dx12 {
class DX12Device;

class DX12GPUDescriptorPoolTyped {
public:
  DX12GPUDescriptorPoolTyped(DX12Device &device,
                             D3D12_DESCRIPTOR_HEAP_TYPE type);
  auto allocate(size_t size) -> DX12GPUDescriptorPoolRange;
  void resize_heap(size_t required_size);
  void on_range_destroy(size_t offset, size_t size);
  void reset_heap();
  auto get_heap() -> ComPtr<ID3D12DescriptorHeap>;

private:
  DX12Device &m_device;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
  size_t m_offset;
  size_t m_size;
  ComPtr<ID3D12DescriptorHeap> m_heap;
  D3D12_CPU_DESCRIPTOR_HANDLE m_cpu_handle;
  D3D12_GPU_DESCRIPTOR_HANDLE m_gpu_handle;
  ComPtr<ID3D12DescriptorHeap> m_heap_readable;
  D3D12_CPU_DESCRIPTOR_HANDLE m_cpu_handle_readable;
  eastl::multimap<size_t, size_t> m_empty_ranges;
};
} // namespace rook::gpu::dx12