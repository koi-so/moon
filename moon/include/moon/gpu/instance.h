#pragma once

#include "moon/base.h"

#include "adapter.h"
#include "types.h"

namespace moon::gpu {
class Instance : public zinc::interface {
public:
  ~Instance() override = default;
  virtual auto get_adapters() -> zinc::vector<zinc::shared<Adapter>> = 0;
};

MOON_API auto CreateInstance(BackendType type) -> zinc::shared<Instance>;
} // namespace moon::gpu