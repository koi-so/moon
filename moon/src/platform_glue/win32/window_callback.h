#pragma once

#include "moon/base.h"
#include "moon/platform_glue/platform_includes/prelude.h"

namespace moon {
auto CALLBACK Win32WindowCallback(HWND window, UINT msg, WPARAM w_param,
                                  LPARAM l_param) -> LRESULT;
} // namespace moon