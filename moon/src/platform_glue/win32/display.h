#pragma once

#include "moon/base.h"

#include "moon/platform_glue/context_handle.h"
#include "moon/platform_glue/display.h"

namespace moon {
class Win32Display final : public Display {
public:
  Win32Display(HMONITOR monitor);

  [[nodiscard]] auto is_primary() const -> bool override;
  [[nodiscard]] auto get_device_name() const -> zinc::string override;
  [[nodiscard]] auto get_offset() const -> Offset2D override;
  auto reset_display_attributes() -> bool override;
  auto set_display_attributes(DisplayAttributes const &attributes)
      -> bool override;
  [[nodiscard]] auto get_display_attributes() const
      -> DisplayAttributes override;
  [[nodiscard]] auto get_display_mode_list() const
      -> zinc::vector<DisplayAttributes> override;

  [[nodiscard]] auto get_native() const -> HMONITOR { return m_monitor; }

private:
  void get_info(MONITORINFO &info) const;
  void get_info(MONITORINFOEX &info) const;

  HMONITOR m_monitor{nullptr};
};
} // namespace moon