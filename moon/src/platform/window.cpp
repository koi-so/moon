#include "moon/platform/window.h"

#if ZINC_PLATFORM_WINDOWS
#include "win32/window.h"
#endif

namespace moon::platform {
auto Window::Create(const WindowAttributes &attributes)
    -> zinc::unique<Window> {
#if ZINC_PLATFORM_WINDOWS
  return zinc::make_unique<Win32Window>(attributes);
#endif
}

auto Window::has_focus() const -> bool { return m_focus; }
auto Window::has_closed() const -> bool { return m_closed; }
auto Window::signal_close() -> void {
  if (!has_closed()) {
    m_closed = true;
  }
}
} // namespace moon::platform