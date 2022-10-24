#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class Memory : public zinc::interface {
public:
  ~Memory() override = default;
  [[nodiscard]] virtual auto get_type() const -> MemoryType = 0;
};
} // namespace moon::gpu