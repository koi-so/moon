#pragma once

#include "rook/base.h"

#include "device.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>

namespace rook::gpu {
class Adapter : public interface {
public:
  ~Adapter() override = default;
  [[nodiscard]] virtual auto get_name() const -> const eastl::string & = 0;
  virtual auto create_device() -> eastl::shared_ptr<Device> = 0;
};
} // namespace rook::gpu