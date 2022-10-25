#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class QueryHeap : public zinc::interface {
public:
  ~QueryHeap() override = default;
  virtual auto get_type() const -> QueryHeapType = 0;
};
}; // namespace moon::gpu