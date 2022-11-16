#include "fence.h"

#include "device.h"

namespace rook::gpu::dx12 {
DX12Fence::DX12Fence(DX12Device &device, uint64_t initial_value)
    : m_device(device) {
  ASSERT_SUCCEEDED(m_device.get_device()->CreateFence(
      initial_value, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)));
  m_fence_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);
  EASTL_ASSERT(m_fence_event != nullptr);
}

auto DX12Fence::get_completed_value() -> uint64_t {
  return m_fence->GetCompletedValue();
}

void DX12Fence::wait(uint64_t value) {
  if (m_fence->GetCompletedValue() < value) {
    ASSERT_SUCCEEDED(m_fence->SetEventOnCompletion(value, m_fence_event));
    WaitForSingleObjectEx(m_fence_event, INFINITE, FALSE);
  }
}

void DX12Fence::signal(uint64_t value) { m_fence->Signal(value); }

auto DX12Fence::get_fence() -> ComPtr<ID3D12Fence> { return m_fence; }
} // namespace rook::gpu::dx12