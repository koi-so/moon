#include "window_callback.h"

#include "window.h"

#ifndef HID_USAGE_PAGE_GENERIC
#define HID_USAGE_PAGE_GENERIC ((USHORT)0x01)
#endif
#ifndef HID_USAGE_GENERIC_MOUSE
#define HID_USAGE_GENERIC_MOUSE ((USHORT)0x02)
#endif

namespace moon {
static auto GetWindowFromUserData(HWND window) -> Win32Window * {
  return reinterpret_cast<Win32Window *>(
      GetWindowLongPtrW(window, GWLP_USERDATA));
}

auto CALLBACK Win32WindowCallback(HWND window, UINT msg, WPARAM w_param,
                                  LPARAM l_param) -> LRESULT {
  switch (msg) {
  case WM_CREATE: {
    RAWINPUTDEVICE device;
    device.usUsagePage = HID_USAGE_PAGE_GENERIC;
    device.usUsage = HID_USAGE_GENERIC_MOUSE;
    device.dwFlags = RIDEV_INPUTSINK;
    device.hwndTarget = window;

    RegisterRawInputDevices(&device, 1, sizeof(RAWINPUTDEVICE));
  } break;
  case WM_CLOSE:
    if (auto window_w = GetWindowFromUserData(window)) {
      window_w->signal_close();
    }
    break;
  }
  return DefWindowProcW(window, msg, w_param, l_param);
}
} // namespace moon