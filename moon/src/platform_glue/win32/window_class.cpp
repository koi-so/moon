#include "window_class.h"

#include "moon/base.h"
#include "moon/platform_glue/platform_includes/prelude.h"
#include "window_callback.h"

namespace moon {
Win32WindowClass::Win32WindowClass() {
  WNDCLASSEX wcex = {};
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
  wcex.lpfnWndProc = Win32WindowCallback;
  wcex.hInstance = GetModuleHandleW(nullptr);
#if ZINC_CPU_ARM
  wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
#else
  wcex.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
#endif
  wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
  wcex.lpszClassName = get_class_name();
  wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);
  auto register_result = RegisterClassExW(&wcex);
  ZINC_ASSERTF(register_result, "Failed to register window class");
}

Win32WindowClass::~Win32WindowClass() {
  UnregisterClassW(get_class_name(), GetModuleHandleW(nullptr));
}

auto Win32WindowClass::get() -> Win32WindowClass * {
  static Win32WindowClass instance;
  return &instance;
}

auto Win32WindowClass::get_class_name() const -> const wchar_t * {
  static wchar_t class_name[] = L"_moon_window_";
  return class_name;
}

} // namespace moon