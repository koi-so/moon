#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class CommandList : public zinc::interface {
public:
  ~CommandList() override = default;
};
} // namespace moon::gpu