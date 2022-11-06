#pragma once

#include "rook/base.h"
#include "rook/platform/platform_includes/prelude.h"

namespace rook::platform {
auto CALLBACK Win32WindowCallback(HWND window, UINT msg, WPARAM w_param,
                                  LPARAM l_param) -> LRESULT;
} // namespace rook::platform