#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class QueryHeap : public interface {
public:
  ~QueryHeap() override = default;
  [[nodiscard]] virtual auto get_type() const -> QueryHeapType = 0;
};
}; // namespace rook::gpu