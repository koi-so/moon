#include "rook/platform/window.h"

#if EA_PLATFORM_WINDOWS
#include "win32/window.h"
#endif

namespace rook::platform {
auto Window::Create(const WindowAttributes &attributes)
    -> eastl::unique_ptr<Window> {
#if EA_PLATFORM_WINDOWS
  return eastl::make_unique<Win32Window>(attributes);
#endif
}

auto Window::has_focus() const -> bool { return m_focus; }
auto Window::has_closed() const -> bool { return m_closed; }
auto Window::signal_close() -> void {
  if (!has_closed()) {
    m_closed = true;
  }
}
} // namespace rook::platform