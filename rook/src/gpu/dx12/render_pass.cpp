#include "render_pass.h"

namespace rook::gpu::dx12 {
DX12RenderPass::DX12RenderPass(RenderPassDescriptor const &descriptor)
    : m_descriptor(descriptor) {}

auto DX12RenderPass::get_descriptor() const -> RenderPassDescriptor const & {
  return m_descriptor;
}
} // namespace rook::gpu::dx12