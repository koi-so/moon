#include "gpu_descriptor_pool_typed.h"

#include "common.h"
#include "device.h"

namespace rook::gpu::dx12 {
DX12GPUDescriptorPoolTyped::DX12GPUDescriptorPoolTyped(
    DX12Device &device, D3D12_DESCRIPTOR_HEAP_TYPE type)
    : m_device(device), m_type(type), m_offset(0), m_size(0) {}

auto DX12GPUDescriptorPoolTyped::allocate(size_t count)
    -> DX12GPUDescriptorPoolRange {
  auto it = m_empty_ranges.lower_bound(count);
  if (it != m_empty_ranges.end()) {
    size_t offset = it->second;
    size_t size = it->first;
    m_empty_ranges.erase(it);
    return {*this,
            m_device,
            m_heap,
            m_cpu_handle,
            m_gpu_handle,
            m_heap_readable,
            m_cpu_handle_readable,
            offset,
            size,
            m_device.get_device()->GetDescriptorHandleIncrementSize(m_type),
            m_type};
  }
  if (m_offset + count > m_size)
    resize_heap(std::max(m_offset + count, 2 * (m_size + 1)));
  m_offset += count;
  return {*this,
          m_device,
          m_heap,
          m_cpu_handle,
          m_gpu_handle,
          m_heap_readable,
          m_cpu_handle_readable,
          m_offset - count,
          count,
          m_device.get_device()->GetDescriptorHandleIncrementSize(m_type),
          m_type};
}

void DX12GPUDescriptorPoolTyped::resize_heap(size_t required_size) {
  if (m_size >= required_size)
    return;

  ComPtr<ID3D12DescriptorHeap> heap;
  ComPtr<ID3D12DescriptorHeap> heap_readable;
  D3D12_DESCRIPTOR_HEAP_DESC heap_desc{};
  heap_desc.NumDescriptors = static_cast<uint32_t>(required_size);
  heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
  heap_desc.Type = m_type;
  ASSERT_SUCCEEDED(m_device.get_device()->CreateDescriptorHeap(
      &heap_desc, IID_PPV_ARGS(&heap)));

  heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
  ASSERT_SUCCEEDED(m_device.get_device()->CreateDescriptorHeap(
      &heap_desc, IID_PPV_ARGS(&heap_readable)));

  if (m_size > 0) {
    m_device.get_device()->CopyDescriptorsSimple(
        m_size, heap_readable->GetCPUDescriptorHandleForHeapStart(),
        m_cpu_handle_readable, m_type);
    m_device.get_device()->CopyDescriptorsSimple(
        m_size, heap->GetCPUDescriptorHandleForHeapStart(),
        m_cpu_handle_readable, m_type);
  }

  m_size = heap_desc.NumDescriptors;
  m_heap = heap;
  m_heap_readable = heap_readable;
  m_cpu_handle = m_heap->GetCPUDescriptorHandleForHeapStart();
  m_gpu_handle = m_heap->GetGPUDescriptorHandleForHeapStart();
  m_cpu_handle_readable = m_heap_readable->GetCPUDescriptorHandleForHeapStart();
}

void DX12GPUDescriptorPoolTyped::on_range_destroy(size_t offset, size_t size) {
  m_empty_ranges.emplace(size, offset);
}

void DX12GPUDescriptorPoolTyped::reset_heap() { m_offset = 0; }

auto DX12GPUDescriptorPoolTyped::get_heap() -> ComPtr<ID3D12DescriptorHeap> {
  return m_heap;
}
} // namespace rook::gpu::dx12