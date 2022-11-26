#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12CommandQueue;

class DX12Swapchain : public Swapchain {
public:
  DX12Swapchain(DX12CommandQueue &command_queue, WindowHandle window,
                uint32_t width, uint32_t height, uint32_t frame_count,
                bool vsync);
  [[nodiscard]] auto get_format() const -> Format override;
  auto get_back_buffer(uint32_t index) -> eastl::shared_ptr<Resource> override;
  auto next_image(eastl::shared_ptr<Fence> const &, uint64_t signal_value)
      -> uint32_t override;
  void present(eastl::shared_ptr<Fence> const &fence,
               uint64_t wait_value) override;

private:
  DX12CommandQueue &m_command_queue;
  bool m_vsync;
  ComPtr<IDXGISwapChain3> m_swap_chain;
  eastl::vector<eastl::shared_ptr<Resource>> m_back_buffers;
};
} // namespace rook::gpu::dx12