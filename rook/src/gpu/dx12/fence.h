#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Device;

class DX12Fence : public Fence {
public:
  DX12Fence(DX12Device &device, uint64_t initial_value);
  auto get_completed_value() -> uint64_t override;
  void wait(uint64_t value) override;
  void signal(uint64_t value) override;

  auto get_fence() -> ComPtr<ID3D12Fence>;

private:
  DX12Device &m_device;
  ComPtr<ID3D12Fence> m_fence;
  HANDLE m_fence_event = nullptr;
};
} // namespace rook::gpu::dx12