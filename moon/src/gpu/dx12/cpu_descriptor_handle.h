#pragma once

#include "moon/base.h"
#include "moon/gpu.h"

#include "common.h"

namespace moon::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorHandle {
public:
  DX12CPUDescriptorHandle(DX12Device &device,
                          ComPtr<ID3D12DescriptorHeap> &heap,
                          D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle, usize offset,
                          usize size, u32 increment_size,
                          D3D12_DESCRIPTOR_HEAP_TYPE type);
  [[nodiscard]] auto get_cpu_handle(usize offset = 0) const
      -> D3D12_CPU_DESCRIPTOR_HANDLE;

private:
  zinc::ref_wrapper<DX12Device> m_device;
  zinc::ref_wrapper<ComPtr<ID3D12DescriptorHeap>> m_heap;
  zinc::ref_wrapper<D3D12_CPU_DESCRIPTOR_HANDLE> m_cpu_handle;
  usize m_offset;
  usize m_size;
  u32 m_increment_size;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
};
} // namespace moon::gpu::dx12