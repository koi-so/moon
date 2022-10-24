#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class Fence : public zinc::interface {
public:
  ~Fence() override = default;
  virtual auto get_completed_value() -> u64 = 0;
  virtual void wait(u64 value) = 0;
  virtual void signal(u64 value) = 0;
};
} // namespace moon::gpu