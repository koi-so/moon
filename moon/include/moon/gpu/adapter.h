#pragma once

#include "moon/base.h"

namespace moon::gpu {
class Adapter : zinc::interface {
public:
  ~Adapter() override = default;
  [[nodiscard]] virtual auto get_name() const -> const zinc::string & = 0;
  virtual auto create_device() -> zinc::shared<class Device> = 0;
};
} // namespace moon::gpu