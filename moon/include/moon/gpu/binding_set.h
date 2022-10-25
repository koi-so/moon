#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class BindingSet : public zinc::interface {
public:
  ~BindingSet() override = 0;
  virtual void
  write_bindings(zinc::vector<BindingDescriptor> const &bindings) = 0;
};
} // namespace moon::gpu