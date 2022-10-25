#pragma once

#include "moon/base.h"

#include "fence.h"

namespace moon::gpu {
using WindowHandle = vptr;

class Swapchain : public zinc::interface {
public:
  ~Swapchain() override = default;
  virtual auto get_format() const -> Format = 0;
  virtual auto get_back_buffer(u32 buffer) -> zinc::shared<Resource> = 0;
  virtual auto next_image(zinc::shared<Fence> const &fence, u64 signal_value)
      -> u32 = 0;
  virtual void present(zinc::shared<Fence> const &fence, u64 wait_value) = 0;
};
} // namespace moon::gpu