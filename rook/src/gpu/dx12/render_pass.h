#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12RenderPass : public RenderPass {
public:
  DX12RenderPass(RenderPassDescriptor const &descriptor);
  auto get_descriptor() const -> RenderPassDescriptor const & override;

private:
  RenderPassDescriptor m_descriptor;
};
} // namespace rook::gpu::dx12