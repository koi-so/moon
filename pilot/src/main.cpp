#include "rook/rook.h"

#include <iostream>

auto main() -> int {
  auto window_attr = rook::platform::WindowAttributes{};
  window_attr.title = "Retroreflector";
  window_attr.resizable = true;
  window_attr.size = {800, 600};
  window_attr.visible = true;

  auto u_window = rook::platform::Window::Create(window_attr);
  auto instance = rook::gpu::CreateInstance(rook::gpu::BackendType::eD3D12);
  auto adapters = instance->get_adapters();
  for (auto &adapter : adapters) {
    std::cout << adapter->get_name().data() << std::endl;
  }

  while (!u_window->has_closed()) {
    u_window->pump_events();
  }

  return 0;
}