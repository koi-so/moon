#pragma once

#include "rook/base.h"

#include "rook/platform/context_handle.h"
#include "rook/platform/display.h"

#include <EASTL/string.h>
#include <EASTL/vector.h>

namespace rook::platform {
class Win32Display final : public Display {
public:
  Win32Display(HMONITOR monitor);
  [[nodiscard]] auto is_primary() const -> bool override;
  [[nodiscard]] auto get_device_name() const -> eastl::string override;
  [[nodiscard]] auto get_offset() const -> Offset2D override;
  auto reset_display_attributes() -> bool override;
  auto set_display_attributes(DisplayAttributes const &attributes)
      -> bool override;
  [[nodiscard]] auto get_display_attributes() const
      -> DisplayAttributes override;
  [[nodiscard]] auto get_display_mode_list() const
      -> eastl::vector<DisplayAttributes> override;

  [[nodiscard]] auto get_native() const -> HMONITOR { return m_monitor; }

private:
  void get_info(MONITORINFO &info) const;
  void get_info(MONITORINFOEX &info) const;

  HMONITOR m_monitor{nullptr};
};
} // namespace rook::platform