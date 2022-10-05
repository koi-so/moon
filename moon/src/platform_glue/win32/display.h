#pragma once

#include "moon/base.h"

#include "moon/platform_glue/context_handle.h"
#include "moon/platform_glue/display.h"

namespace moon {
struct Win32Display final : public Display {
public:
  Win32Display(HMONITOR monitor);

  [[nodiscard]] auto IsPrimary() const -> bool override;
  [[nodiscard]] auto GetDeviceName() const -> zinc::string override;
  [[nodiscard]] auto GetOffset() const -> Offset2D override;
  auto ResetDisplayAttributes() -> bool override;
  auto SetDisplayAttributes(DisplayAttributes const &attributes)
      -> bool override;
  [[nodiscard]] auto GetDisplayAttributes() const -> DisplayAttributes override;
  [[nodiscard]] auto GetDisplayModeList() const
      -> zinc::vector<DisplayAttributes> override;

  [[nodiscard]] auto GetNative() const -> HMONITOR { return m_monitor; }

private:
  void GetInfo(MONITORINFO &info) const;
  void GetInfo(MONITORINFOEX &info) const;

  HMONITOR m_monitor{nullptr};
};
} // namespace moon