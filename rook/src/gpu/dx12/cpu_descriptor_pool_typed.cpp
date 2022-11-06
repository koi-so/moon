#include "cpu_descriptor_pool_typed.h"

#include "device.h"

#include <cmath>

namespace rook::gpu::dx12 {
DX12CPUDescriptorPoolTyped::DX12CPUDescriptorPoolTyped(
    DX12Device &device, D3D12_DESCRIPTOR_HEAP_TYPE type)
    : m_device(device), m_type(type), m_offset(0), m_size(0) {
  resize_heap(1024);
}

auto DX12CPUDescriptorPoolTyped::allocate(size_t count)
    -> eastl::shared_ptr<DX12CPUDescriptorHandle> {
  if (m_offset + count > m_size) {
    resize_heap(std::max(m_size * 2, m_offset + count));
  }
  m_offset += count;

  return eastl::make_shared<DX12CPUDescriptorHandle>(
      m_device, m_heap, m_cpu_handle, m_offset - count, count,
      m_device.get_device()->GetDescriptorHandleIncrementSize(m_type), m_type);
}

void DX12CPUDescriptorPoolTyped::resize_heap(size_t required_size) {
  if (m_size >= required_size)
    return;

  ComPtr<ID3D12DescriptorHeap> heap;
  D3D12_DESCRIPTOR_HEAP_DESC heap_desc = {};
  heap_desc.NumDescriptors = static_cast<uint32_t>(required_size);
  heap_desc.Type = m_type;
  /*ASSERT_SUCCEEDED*/ void(m_device.get_device()->CreateDescriptorHeap(
      &heap_desc, IID_PPV_ARGS(&heap)));
  if (m_size > 0) {
    m_device.get_device()->CopyDescriptorsSimple(
        static_cast<uint32_t>(m_size),
        heap->GetCPUDescriptorHandleForHeapStart(),
        m_heap->GetCPUDescriptorHandleForHeapStart(), m_type);
  }

  m_size = heap_desc.NumDescriptors;
  m_heap = heap;
  m_cpu_handle = m_heap->GetCPUDescriptorHandleForHeapStart();
}
} // namespace rook::gpu::dx12