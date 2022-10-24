#pragma once

#include "moon/base.h"

namespace moon::gpu {
class Device : public zinc::interface {
public:
  ~Device() override = default;
};
} // namespace moon::gpu