#pragma once

#include "rook/base.h"
#include "rook/gpu.h"

#include "common.h"

#include <EASTL/functional.h>

namespace rook::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorHandle {
public:
  DX12CPUDescriptorHandle(DX12Device &device,
                          ComPtr<ID3D12DescriptorHeap> &heap,
                          D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle,
                          size_t offset, size_t size, uint32_t increment_size,
                          D3D12_DESCRIPTOR_HEAP_TYPE type);
  [[nodiscard]] auto get_cpu_handle(size_t offset = 0) const
      -> D3D12_CPU_DESCRIPTOR_HANDLE;

private:
  eastl::reference_wrapper<DX12Device> m_device;
  eastl::reference_wrapper<ComPtr<ID3D12DescriptorHeap>> m_heap;
  eastl::reference_wrapper<D3D12_CPU_DESCRIPTOR_HANDLE> m_cpu_handle;
  size_t m_offset;
  size_t m_size;
  uint32_t m_increment_size;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
};
} // namespace rook::gpu::dx12