#pragma once

#include "moon/base.h"

#include "spatial.h"

namespace moon::platform {
struct WindowAttributes {
  zinc::string_view title;
  Extent2D size;
  Offset2D position;
  bool visible{false};
  bool centered{true};
  bool resizable{false};
  bool borderless{false};
  bool disable_power_saving{false};
  bool accept_drops{false};
  vptr context{nullptr};
};
} // namespace moon::platform