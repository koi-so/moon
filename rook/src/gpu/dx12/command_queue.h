#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Device;

class DX12CommandQueue : public CommandQueue {
public:
  DX12CommandQueue(DX12Device &device, CommandListType type);
  void wait(eastl::shared_ptr<Fence> const &fence, uint64_t value) override;
  void signal(eastl::shared_ptr<Fence> const &fence, uint64_t value) override;
  void execute_command_lists(eastl::vector<eastl::shared_ptr<CommandList>> const
                                 &command_lists) override;

  auto get_device() -> DX12Device &;
  auto get_queue() -> ComPtr<ID3D12CommandQueue>;

private:
  DX12Device &m_device;
  ComPtr<ID3D12CommandQueue> m_command_queue;
};
}; // namespace rook::gpu::dx12