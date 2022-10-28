#include "cpu_descriptor_handle.h"

#include "device.h"

namespace moon::gpu::dx12 {
DX12CPUDescriptorHandle::DX12CPUDescriptorHandle(
    DX12Device &device, ComPtr<ID3D12DescriptorHeap> &heap,
    D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle, usize offset, usize size,
    u32 increment_size, D3D12_DESCRIPTOR_HEAP_TYPE type)
    : m_device(device), m_heap(heap), m_cpu_handle(cpu_handle),
      m_offset(offset), m_size(size), m_increment_size(increment_size),
      m_type(type) {}

auto DX12CPUDescriptorHandle::get_cpu_handle(usize offset) const
    -> D3D12_CPU_DESCRIPTOR_HANDLE {
  return CD3DX12_CPU_DESCRIPTOR_HANDLE(
      m_cpu_handle, static_cast<INT>(m_offset + offset), m_increment_size);
}
} // namespace moon::gpu::dx12