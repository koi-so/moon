#include "swapchain.h"

#include "adapter.h"
#include "command_queue.h"
#include "device.h"
#include "format_translate.h"
#include "instance.h"
#include "resource.h"

namespace rook::gpu::dx12 {
DX12Swapchain::DX12Swapchain(DX12CommandQueue &command_queue,
                             WindowHandle window, uint32_t width,
                             uint32_t height, uint32_t frame_count, bool vsync)
    : m_command_queue(command_queue), m_vsync(vsync) {
  DX12Instance &instance =
      command_queue.get_device().get_adapter().get_instance();
  DXGI_SWAP_CHAIN_DESC1 swap_chain_desc = {};
  swap_chain_desc.Width = width;
  swap_chain_desc.Height = height;
  swap_chain_desc.Format = static_cast<DXGI_FORMAT>(
      TranslateFormatToDX12Format(get_format()).DXGIFormat.DDS);
  swap_chain_desc.SampleDesc.Count = 1;
  swap_chain_desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
  swap_chain_desc.BufferCount = frame_count;
  swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
  swap_chain_desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;

  ComPtr<IDXGISwapChain1> tmp_swap_chain;
  ASSERT_SUCCEEDED(instance.get_factory()->CreateSwapChainForHwnd(
      command_queue.get_queue().Get(), reinterpret_cast<HWND>(window),
      &swap_chain_desc, nullptr, nullptr, &tmp_swap_chain));
  ASSERT_SUCCEEDED(instance.get_factory()->MakeWindowAssociation(
      reinterpret_cast<HWND>(window), DXGI_MWA_NO_WINDOW_CHANGES));
  tmp_swap_chain.As(&m_swap_chain);

  for (size_t i = 0; i < frame_count; ++i) {
    std::shared_ptr<DX12Resource> res =
        std::make_shared<DX12Resource>(command_queue.get_device());
    ComPtr<ID3D12Resource> back_buffer;
    ASSERT_SUCCEEDED(m_swap_chain->GetBuffer(i, IID_PPV_ARGS(&back_buffer)));
    res->p_format = get_format();
    res->set_initial_state(ResourceState::ePresent);
    res->p_resource = back_buffer;
    res->p_desc = back_buffer->GetDesc();
    res->p_is_back_buffer = true;
    m_back_buffers.emplace_back(res);
  }
}

auto DX12Swapchain::get_format() const -> Format {
  return Format::RGBA8_UNORM_PACK8;
}

auto DX12Swapchain::get_back_buffer(uint32_t index)
    -> eastl::shared_ptr<Resource> {
  return m_back_buffers[index];
}

auto DX12Swapchain::next_image(eastl::shared_ptr<Fence> const &fence,
                               uint64_t signal_value) -> uint32_t {
  uint32_t index = m_swap_chain->GetCurrentBackBufferIndex();
  m_command_queue.signal(fence, signal_value);
  return index;
}

void DX12Swapchain::present(eastl::shared_ptr<Fence> const &fence,
                            uint64_t wait_value) {
  m_command_queue.wait(fence, wait_value);
  ASSERT_SUCCEEDED(m_swap_chain->Present(
      m_vsync ? 1 : 0, m_vsync ? 0 : DXGI_PRESENT_ALLOW_TEARING));
}
} // namespace rook::gpu::dx12