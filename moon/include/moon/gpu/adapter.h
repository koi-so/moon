#pragma once

#include "moon/base.h"

#include "device.h"

namespace moon::gpu {
class Adapter : public zinc::interface {
public:
  ~Adapter() override = default;
  [[nodiscard]] virtual auto get_name() const -> const zinc::string & = 0;
  virtual auto create_device() -> zinc::shared<Device> = 0;
};
} // namespace moon::gpu