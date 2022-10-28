#pragma once

#include "moon/base.h"
#include "moon/gpu.h"

#include "common.h"

#include "cpu_descriptor_handle.h"

namespace moon::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorPoolTyped {
public:
  DX12CPUDescriptorPoolTyped(DX12Device &device,
                             D3D12_DESCRIPTOR_HEAP_TYPE type);
  auto allocate(usize count) -> zinc::shared<DX12CPUDescriptorHandle>;
  void resize_heap(usize required_size);

private:
  DX12Device &m_device;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
  usize m_offset;
  usize m_size;
  ComPtr<ID3D12DescriptorHeap> m_heap;
  D3D12_CPU_DESCRIPTOR_HANDLE m_cpu_handle;
};
} // namespace moon::gpu::dx12