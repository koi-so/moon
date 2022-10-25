#pragma once

#include "moon/base.h"

namespace moon::gpu {
class FrameBuffer : public zinc::interface {
public:
  ~FrameBuffer() override = default;
};
} // namespace moon::gpu