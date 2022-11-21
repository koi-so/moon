#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class RenderPass : public interface {
public:
  ~RenderPass() override = default;
  virtual auto get_descriptor() const -> RenderPassDescriptor const & = 0;
};
} // namespace rook::gpu