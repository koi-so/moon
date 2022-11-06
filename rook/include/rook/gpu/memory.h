#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class Memory : public interface {
public:
  ~Memory() override = default;
  [[nodiscard]] virtual auto get_type() const -> MemoryType = 0;
};
} // namespace rook::gpu