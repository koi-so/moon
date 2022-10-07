#pragma once

#include "moon/base.h"

#include "moon/platform/context_handle.h"
#include "moon/platform/window.h"
#include "moon/platform/window_attributes.h"
#include "moon/platform/window_state.h"

namespace moon::platform {
class Win32Window final : public Window {
public:
  Win32Window(const WindowAttributes &desc);
  ~Win32Window() override;

  void set_position(const Offset2D &position) override {}
  [[nodiscard]] auto get_position() const -> Offset2D override {
    return {0, 0};
  }

  void set_size(const Extent2D &size) override {}
  [[nodiscard]] auto get_size() const -> Extent2D override { return {5, 5}; }

  void set_visible(bool visible) override {}
  [[nodiscard]] auto is_visible() const -> bool override { return false; }

  void set_attributes(const WindowAttributes &attributes) override {}
  [[nodiscard]] auto get_attributes() const -> WindowAttributes override {
    return {};
  }
  void pump_events() override;

private:
  auto CreateWindowHandle(const WindowAttributes &attributes) -> HWND;

private:
  WindowState m_window_state;
  ContextHandle m_context;
  HWND m_window;
};
} // namespace moon::platform