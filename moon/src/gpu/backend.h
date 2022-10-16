#pragma once

#include "moon/base.h"
#include "moon/gpu.h"

#include "adapter.h"

namespace moon::gpu::native {
struct Instance;
class MOON_API Backend {
public:
  Backend(Instance *instance, BackendType type);
  virtual ~Backend() = default;

  [[nodiscard]] auto get_type() const -> BackendType;
  [[nodiscard]] auto get_instance() const -> Instance *;

  virtual auto discover_default_adapters()
      -> zinc::vector<zinc::unique<IAdapter>> = 0;
  virtual auto discover_adapters(BackendType backend)
      -> zinc::vector<zinc::unique<IAdapter>> = 0;
};
} // namespace moon::gpu::native