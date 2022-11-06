#pragma once

#include "rook/base.h"

#include "spatial.h"

#include <EASTL/string_view.h>

namespace rook::platform {
struct WindowAttributes {
  eastl::string_view title;
  Extent2D size;
  Offset2D position;
  bool visible{false};
  bool centered{true};
  bool resizable{false};
  bool borderless{false};
  bool disable_power_saving{false};
  bool accept_drops{false};
  void *context{nullptr};
};
} // namespace rook::platform