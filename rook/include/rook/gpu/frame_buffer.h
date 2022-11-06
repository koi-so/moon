#pragma once

#include "rook/base.h"

namespace rook::gpu {
class FrameBuffer : public interface {
public:
  ~FrameBuffer() override = default;
};
} // namespace rook::gpu