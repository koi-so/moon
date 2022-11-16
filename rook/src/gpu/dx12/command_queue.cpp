#include "command_queue.h"

#include "device.h"
#include "fence.h"

namespace rook::gpu::dx12 {
DX12CommandQueue::DX12CommandQueue(DX12Device &device, CommandListType type)
    : m_device(device) {
  D3D12_COMMAND_LIST_TYPE dx_type;
  switch (type) {
  case CommandListType::eGraphics:
    dx_type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    break;
  case CommandListType::eCompute:
    dx_type = D3D12_COMMAND_LIST_TYPE_COMPUTE;
    break;
  case CommandListType::eCopy:
    dx_type = D3D12_COMMAND_LIST_TYPE_COPY;
    break;
  default:
    EASTL_ASSERT(false);
    break;
  }
  D3D12_COMMAND_QUEUE_DESC queue_desc{};
  queue_desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
  queue_desc.Type = dx_type;
  ASSERT_SUCCEEDED(m_device.get_device()->CreateCommandQueue(
      &queue_desc, IID_PPV_ARGS(&m_command_queue)));
}

void DX12CommandQueue::wait(eastl::shared_ptr<Fence> const &fence,
                            uint64_t value) {
  auto dx_fence = fence->as<DX12Fence>();
  ASSERT_SUCCEEDED(m_command_queue->Wait(dx_fence.get_fence().Get(), value));
}
} // namespace rook::gpu::dx12