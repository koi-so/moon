#include "gpu_descriptor_pool_range.h"

#include "device.h"
#include "gpu_descriptor_pool_typed.h"

namespace rook::gpu::dx12 {
DX12GPUDescriptorPoolRange::DX12GPUDescriptorPoolRange(
    DX12GPUDescriptorPoolTyped &pool, DX12Device &device,
    ComPtr<ID3D12DescriptorHeap> &heap, D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle,
    D3D12_GPU_DESCRIPTOR_HANDLE &gpu_handle,
    ComPtr<ID3D12DescriptorHeap> &heap_readable,
    D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle_readable, size_t offset,
    size_t size, uint32_t increment_size, D3D12_DESCRIPTOR_HEAP_TYPE type)
    : m_pool(pool), m_device(device), m_heap(heap), m_cpu_handle(cpu_handle),
      m_gpu_handle(gpu_handle), m_heap_readable(heap_readable),
      m_cpu_handle_readable(cpu_handle_readable), m_offset(offset),
      m_size(size), m_increment_size(increment_size), m_type(type),
      m_callback(this,
                 [m_offset = m_offset, m_size = m_size, m_pool = m_pool](auto) {
                   m_pool.get().on_range_destroy(m_offset, m_size);
                 }) {}

DX12GPUDescriptorPoolRange::DX12GPUDescriptorPoolRange(
    DX12GPUDescriptorPoolRange &&other) = default;

DX12GPUDescriptorPoolRange::~DX12GPUDescriptorPoolRange() = default;

void DX12GPUDescriptorPoolRange::copy_cpu_handle(
    size_t dst_offset, D3D12_CPU_DESCRIPTOR_HANDLE handle) {
  D3D12_CPU_DESCRIPTOR_HANDLE self = get_cpu_handle(m_cpu_handle, dst_offset);
  m_device.get().get_device()->CopyDescriptors(1, &self, nullptr, 1, &handle,
                                               nullptr, m_type);
  self = get_cpu_handle(m_cpu_handle_readable, dst_offset);
  m_device.get().get_device()->CopyDescriptors(1, &self, nullptr, 1, &handle,
                                               nullptr, m_type);
}

auto DX12GPUDescriptorPoolRange::get_cpu_handle(
    D3D12_CPU_DESCRIPTOR_HANDLE handle, size_t offset) const
    -> D3D12_CPU_DESCRIPTOR_HANDLE {
  return CD3DX12_CPU_DESCRIPTOR_HANDLE(
      handle, static_cast<INT>(m_offset + offset), m_increment_size);
}

auto DX12GPUDescriptorPoolRange::get_gpu_handle(size_t offset) const
    -> D3D12_GPU_DESCRIPTOR_HANDLE {
  return CD3DX12_GPU_DESCRIPTOR_HANDLE(
      m_gpu_handle, static_cast<INT>(m_offset + offset), m_increment_size);
}

auto DX12GPUDescriptorPoolRange::get_heap() const
    -> ComPtr<ID3D12DescriptorHeap> const & {
  return m_heap;
}

auto DX12GPUDescriptorPoolRange::get_size() const -> size_t { return m_size; }

auto DX12GPUDescriptorPoolRange::get_offset() const -> size_t {
  return m_offset;
}
} // namespace rook::gpu::dx12