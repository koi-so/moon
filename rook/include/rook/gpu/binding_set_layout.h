#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class BindingSetLayout : public interface {
public:
  virtual ~BindingSetLayout() = default;
};
} // namespace rook::gpu