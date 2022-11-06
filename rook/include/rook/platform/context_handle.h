#pragma once

#include "platform_includes/prelude.h"
#include "rook/base.h"

#include "EABase/config/eaplatform.h"

namespace rook::platform {
#if EA_PLATFORM_WINDOWS
struct Handle {
  HWND hwnd;
};

struct ContextHandle {
  HWND root_window;
};
#endif
} // namespace rook::platform