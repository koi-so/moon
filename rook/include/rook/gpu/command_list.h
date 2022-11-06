#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class CommandList : public interface {
public:
  ~CommandList() override = default;
};
} // namespace rook::gpu