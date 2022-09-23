#include "moon/platform_glue/window.h"

namespace moon {
auto Window::Create() -> zinc::unique<Window> {
#if ZINC_PLATFORM_WINDOWS
  return zinc::MakeUnique<Window>();
#endif
}
} // namespace moon