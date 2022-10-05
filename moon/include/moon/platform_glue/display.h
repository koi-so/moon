#pragma once

#include "moon/base.h"

#include "display_attributes.h"

namespace moon {
struct MOON_API Display : public zinc::non_copyable {
public:
  static auto Count() -> usize;
  static auto GetList() -> zinc::array_view<Display *>;
  static auto Get(usize index) -> Display *;
  static auto GetPrimary() -> Display *;

  static auto ToggleCursor(bool show) -> bool;
  static auto IsCursorVisible() -> bool;

  static auto SetCursorPosition(Offset2D const &position) -> bool;
  static auto GetCursorPosition() -> Offset2D;

  // Display methods
  [[nodiscard]] virtual auto IsPrimary() const -> bool = 0;
  [[nodiscard]] virtual auto GetDeviceName() const -> zinc::string = 0;

  [[nodiscard]] virtual auto GetOffset() const -> Offset2D = 0;

  virtual auto ResetDisplayAttributes() -> bool = 0;
  virtual auto SetDisplayAttributes(DisplayAttributes const &attributes)
      -> bool = 0;
  [[nodiscard]] virtual auto GetDisplayAttributes() const
      -> DisplayAttributes = 0;

  [[nodiscard]] virtual auto GetDisplayModeList() const
      -> zinc::vector<DisplayAttributes> = 0;

protected:
  static void
  FinaliseDisplayModes(zinc::vector<DisplayAttributes> &display_attributes);
};
} // namespace moon