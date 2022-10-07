#pragma once

#include "moon/base.h"
#include "moon/platform/platform_includes/prelude.h"

namespace moon::platform {
auto CALLBACK Win32WindowCallback(HWND window, UINT msg, WPARAM w_param,
                                  LPARAM l_param) -> LRESULT;
} // namespace moon::platform