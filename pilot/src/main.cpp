#include "moon/moon.h"
#include "zinc/allocator/sys.h"

#include <iostream>

using zinc::as;

auto rac(WGPURequestAdapterStatus status, WGPUAdapter adapter,
         char const *message, void *userdata) {}

auto main() -> int {
  auto window_attr = moon::platform::WindowAttributes{};
  window_attr.title = "Retroreflector";
  window_attr.resizable = true;
  window_attr.size = {800, 600};
  window_attr.visible = true;

  auto u_window = moon::platform::Window::Create(window_attr);
  while (!u_window->has_closed()) {
    u_window->pump_events();
  }

  return 0;
}