#include "memory.h"

#include "device.h"

namespace rook::gpu::dx12 {
DX12Memory::DX12Memory(DX12Device &device, uint64_t size,
                       MemoryType memory_type, uint32_t memory_type_bits)
    : m_memory_type(memory_type) {
  D3D12_HEAP_DESC heap_desc = {};
  heap_desc.Properties = CD3DX12_HEAP_PROPERTIES(GetHeapType(memory_type));
}

auto DX12Memory::get_type() const -> MemoryType { return m_memory_type; }

auto DX12Memory::get_heap() const -> ComPtr<ID3D12Heap> { return m_heap; }
} // namespace rook::gpu::dx12