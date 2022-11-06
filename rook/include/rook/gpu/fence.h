#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class Fence : public interface {
public:
  ~Fence() override = default;
  virtual auto get_completed_value() -> uint64_t = 0;
  virtual void wait(uint64_t value) = 0;
  virtual void signal(uint64_t value) = 0;
};
} // namespace rook::gpu