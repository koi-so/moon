#pragma once

#include "rook/base.h"

#include "types.h"

#include <EASTL/shared_ptr.h>

namespace rook::gpu {
class BindingSet : public interface {
public:
  ~BindingSet() override = 0;
  virtual void
  write_bindings(eastl::vector<BindingDescriptor> const &bindings) = 0;
};
} // namespace rook::gpu