#pragma once

#include "moon/base.h"

#include "display_attributes.h"

namespace moon {
class MOON_API Display : public zinc::non_copyable {
public:
  static auto count() -> usize;
  static auto get_list() -> zinc::array_view<Display *>;
  static auto get(usize index) -> Display *;
  static auto get_primary() -> Display *;

  static auto toggle_cursor(bool show) -> bool;
  static auto is_cursor_visible() -> bool;

  static auto set_cursor_position(Offset2D const &position) -> bool;
  static auto get_cursor_position() -> Offset2D;

  // Display methods
  [[nodiscard]] virtual auto is_primary() const -> bool = 0;
  [[nodiscard]] virtual auto get_device_name() const -> zinc::string = 0;

  [[nodiscard]] virtual auto get_offset() const -> Offset2D = 0;

  virtual auto reset_display_attributes() -> bool = 0;
  virtual auto set_display_attributes(DisplayAttributes const &attributes)
      -> bool = 0;
  [[nodiscard]] virtual auto get_display_attributes() const
      -> DisplayAttributes = 0;

  [[nodiscard]] virtual auto get_display_mode_list() const
      -> zinc::vector<DisplayAttributes> = 0;

protected:
  static void
  FinaliseDisplayModes(zinc::vector<DisplayAttributes> &display_attributes);
};
} // namespace moon