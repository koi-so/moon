#pragma once

#include "rook/base.h"

#include "display_attributes.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>
#include <EASTL/vector.h>

namespace rook::platform {
class ROOK_API Display {
public:
  Display() = default;
  Display(Display const &) = delete;
  auto operator=(Display const &) -> Display & = delete;

  static auto count() -> size_t;
  static auto get_list() -> Display *const *;
  static auto get(size_t index) -> Display *;
  static auto get_primary() -> Display *;

  static auto toggle_cursor(bool show) -> bool;
  static auto is_cursor_visible() -> bool;

  static auto set_cursor_position(Offset2D const &position) -> bool;
  static auto get_cursor_position() -> Offset2D;

  // Display methods
  [[nodiscard]] virtual auto is_primary() const -> bool = 0;
  [[nodiscard]] virtual auto get_device_name() const -> eastl::string = 0;

  [[nodiscard]] virtual auto get_offset() const -> Offset2D = 0;

  virtual auto reset_display_attributes() -> bool = 0;
  virtual auto set_display_attributes(DisplayAttributes const &attributes)
      -> bool = 0;
  [[nodiscard]] virtual auto get_display_attributes() const
      -> DisplayAttributes = 0;

  [[nodiscard]] virtual auto get_display_mode_list() const
      -> eastl::vector<DisplayAttributes> = 0;

protected:
  static void
  FinaliseDisplayModes(eastl::vector<DisplayAttributes> &display_attributes);
};
} // namespace rook::platform