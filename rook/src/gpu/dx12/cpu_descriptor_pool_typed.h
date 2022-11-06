#pragma once

#include "rook/base.h"
#include "rook/gpu.h"

#include "common.h"
#include "cpu_descriptor_handle.h"

#include <EASTL/shared_ptr.h>

namespace rook::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorPoolTyped {
public:
  DX12CPUDescriptorPoolTyped(DX12Device &device,
                             D3D12_DESCRIPTOR_HEAP_TYPE type);
  auto allocate(size_t count) -> eastl::shared_ptr<DX12CPUDescriptorHandle>;
  void resize_heap(size_t required_size);

private:
  DX12Device &m_device;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
  size_t m_offset;
  size_t m_size;
  ComPtr<ID3D12DescriptorHeap> m_heap;
  D3D12_CPU_DESCRIPTOR_HANDLE m_cpu_handle;
};
} // namespace rook::gpu::dx12