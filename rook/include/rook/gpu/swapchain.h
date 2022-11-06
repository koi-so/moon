#pragma once

#include "rook/base.h"

#include "fence.h"

#include <EASTL/shared_ptr.h>

namespace rook::gpu {
using WindowHandle = void *;

class Swapchain : public interface {
public:
  ~Swapchain() override = default;
  [[nodiscard]] virtual auto get_format() const -> Format = 0;
  virtual auto get_back_buffer(uint32_t buffer)
      -> eastl::shared_ptr<Resource> = 0;
  virtual auto next_image(eastl::shared_ptr<Fence> const &fence,
                          uint64_t signal_value) -> uint32_t = 0;
  virtual void present(eastl::shared_ptr<Fence> const &fence,
                       uint64_t wait_value) = 0;
};
} // namespace rook::gpu