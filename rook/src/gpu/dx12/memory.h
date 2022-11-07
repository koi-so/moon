#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Device;

class DX12Memory : public Memory {
public:
  DX12Memory(DX12Device &device, uint64_t size, MemoryType memory_type,
             uint32_t memory_type_bits);
  auto get_type() const -> MemoryType override;

  auto get_heap() const -> ComPtr<ID3D12Heap>;

private:
  MemoryType m_memory_type;
  ComPtr<ID3D12Heap> m_heap;
};
} // namespace rook::gpu::dx12