#pragma once

#include "moon/base.h"
#include "platform_includes/prelude.h"

namespace moon::platform {
#if ZINC_PLATFORM_WINDOWS
struct Handle {
  HWND hwnd;
};

struct ContextHandle {
  HWND root_window;
};
#endif
} // namespace moon::platform