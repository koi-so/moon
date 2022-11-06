#pragma once

#include "rook/base.h"

#include "window_attributes.h"

#include <EASTL/unique_ptr.h>

namespace rook::platform {
class Window {
public:
  Window();
  Window(Window const &) = delete;
  Window(Window &&) = delete;

  static ROOK_API auto Create(const WindowAttributes &attributes)
      -> eastl::unique_ptr<Window>;
  virtual ~Window() = default;

  virtual void set_position(const Offset2D &position) = 0;
  [[nodiscard]] virtual auto get_position() const -> Offset2D = 0;

  virtual void set_size(const Extent2D &size) = 0;
  [[nodiscard]] virtual auto get_size() const -> Extent2D = 0;

  virtual void set_visible(bool visible) = 0;
  [[nodiscard]] virtual auto is_visible() const -> bool = 0;

  virtual void set_attributes(const WindowAttributes &attributes) = 0;
  [[nodiscard]] virtual auto get_attributes() const -> WindowAttributes = 0;

  [[nodiscard]] auto ROOK_API has_focus() const -> bool;
  [[nodiscard]] auto ROOK_API has_closed() const -> bool;

  void ROOK_API signal_close();
  virtual void pump_events() = 0;

private:
  bool m_closed{false};
  bool m_focus{false};
};
} // namespace rook::platform