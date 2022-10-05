#include "window.h"

#include "window_class.h"

namespace moon {
struct WindowAppearance {
  DWORD style = 0;
  Offset2D position{};
  Extent2D size{};
};

static void SetUserData(HWND window, vptr user_data) {
  SetWindowLongPtr(window, GWLP_USERDATA,
                   reinterpret_cast<LONG_PTR>(user_data));
}

static auto GetClientArea(LONG width, LONG height, DWORD style) -> RECT {
  RECT client_area{0, 0, width, height};
  AdjustWindowRect(&client_area, style, false);
  return client_area;
}

static auto GetWindowStyle(const WindowAttributes &attributes) -> DWORD {
  DWORD style = (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);

  if (attributes.context != nullptr &&
      reinterpret_cast<const ContextHandle *>(attributes.context)
              ->root_window != nullptr)
    style |= WS_CHILD;
  else if (attributes.borderless)
    style |= WS_POPUP;
  else {
    style |= (WS_SYSMENU | WS_MINIMIZEBOX | WS_CAPTION);
    if (attributes.resizable)
      style |= (WS_SIZEBOX | WS_MAXIMIZEBOX);
  }

  if (attributes.visible)
    style |= WS_VISIBLE;

  if (attributes.accept_drops)
    style |= WM_DROPFILES;

  return style;
}

static auto GetScreenCenteredPosition(const Extent2D &size) -> Offset2D {
  return {GetSystemMetrics(SM_CXSCREEN) / 2 - static_cast<i32>(size.width / 2),
          GetSystemMetrics(SM_CYSCREEN) / 2 -
              static_cast<i32>(size.height / 2)};
}

static auto GetWindowAppearance(const WindowAttributes &attributes)
    -> WindowAppearance {
  WindowAppearance appearance;

  /* Get window style and client area */
  appearance.style = GetWindowStyle(attributes);

  auto rc = GetClientArea(static_cast<LONG>(attributes.size.width),
                          static_cast<LONG>(attributes.size.height),
                          appearance.style);

  /* Setup window size */
  appearance.size.width = static_cast<u32>(rc.right - rc.left);
  appearance.size.height = static_cast<u32>(rc.bottom - rc.top);

  /* Setup window position */
  appearance.position =
      (attributes.centered ? GetScreenCenteredPosition(attributes.size)
                           : attributes.position);

  if (attributes.centered) {
    appearance.position.x += rc.left;
    appearance.position.y += rc.top;
  }

  return appearance;
}

Win32Window::Win32Window(const WindowAttributes &attributes)
    : m_context{nullptr}, m_window{CreateWindowHandle(attributes)} {}

Win32Window::~Win32Window() {
  if (m_window != nullptr) {
    DestroyWindow(m_window);
    m_window = nullptr;
  }
}

void Win32Window::pump_events() {
  MSG msg;
  while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }
}

auto Win32Window::CreateWindowHandle(const WindowAttributes &attributes)
    -> HWND {
  auto window_class = Win32WindowClass::get();
  auto appearance = GetWindowAppearance(attributes);

  HWND root_window = HWND_DESKTOP;
  if (auto context =
          reinterpret_cast<const ContextHandle *>(attributes.context);
      context != nullptr && context->root_window != nullptr) {
    root_window = context->root_window;
    m_context = *context;
  }

  wchar_t title[256];
  auto converted_count = MultiByteToWideChar(
      CP_UTF8, 0, attributes.title.data(),
      static_cast<i32>(attributes.title.length()), title, sizeof(title));
  title[converted_count] = L'\0';
  HWND window = CreateWindowExW(0, window_class->get_class_name(), title,
                                appearance.style, appearance.position.x,
                                appearance.position.y, appearance.size.width,
                                appearance.size.height, root_window, nullptr,
                                GetModuleHandleW(nullptr), nullptr);
  ZINC_ASSERTF(window, "Failed to create window");

  if (attributes.visible) {
    ShowWindow(window, SW_SHOW);
  }

#if !(ZINC_CPU_ARM)
  if (attributes.accept_drops)
    ::DragAcceptFiles(window, true);
#endif

  SetUserData(window, this);

  return window;
}
} // namespace moon