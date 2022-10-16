#include "display.h"

namespace moon::platform {
struct Win32DisplayContainer {
  Win32DisplayContainer() = default;
  Win32DisplayContainer(zinc::unique<Win32Display> &&display, u32 cache_index)
      : display{std::move(display)}, cache_index{cache_index} {}

  zinc::unique<Win32Display> display{nullptr};
  u32 cache_index{0};
};

static zinc::vector<Win32DisplayContainer> g_display_list;
static zinc::vector<Win32Display *> g_display_ref;
static Win32Display *g_primary_display{nullptr};
static u32 g_display_cache_index{0};

struct MonitorChangedInfo {
  usize registered_monitors;
  usize unregistered_monitors;
};

static void Convert(DisplayAttributes &dst, DEVMODE const &src) {
  dst.resolution.width = static_cast<std::uint32_t>(src.dmPelsWidth);
  dst.resolution.height = static_cast<std::uint32_t>(src.dmPelsHeight);
  dst.refresh_rate = static_cast<std::uint32_t>(src.dmDisplayFrequency);
}

static void Convert(DEVMODE &dst, DisplayAttributes const &src) {
  dst.dmPelsWidth = static_cast<DWORD>(src.resolution.width);
  dst.dmPelsHeight = static_cast<DWORD>(src.resolution.height);
  dst.dmDisplayFrequency = static_cast<DWORD>(src.refresh_rate);
}

static auto CALLBACK Win32MonitorChangedEnumProcedure(HMONITOR monitor, HDC hDC,
                                                      LPRECT rect, LPARAM data)
    -> BOOL {
  auto &info = *reinterpret_cast<MonitorChangedInfo *>(data);
  auto it = std::find_if(g_display_list.begin(), g_display_list.end(),
                         [monitor](const Win32DisplayContainer &entry) -> bool {
                           return (entry.display->get_native() == monitor);
                         });
  if (it != g_display_list.end())
    info.registered_monitors++;
  else
    info.unregistered_monitors++;
  return TRUE;
}

static auto HasMonitorListChanged() -> bool {
  /* Check if there are any unregistered monitors or if we lost any monitors */
  MonitorChangedInfo info = {0, 0};
  EnumDisplayMonitors(nullptr, nullptr, Win32MonitorChangedEnumProcedure,
                      reinterpret_cast<LPARAM>(&info));
  return (info.unregistered_monitors > 0 ||
          info.registered_monitors != g_display_list.size());
}

static auto CALLBACK Win32MonitorEnumProcedure(HMONITOR monitor, HDC hDC,
                                               LPRECT rect, LPARAM data)
    -> BOOL {
  auto it = std::find_if(g_display_list.begin(), g_display_list.end(),
                         [monitor](const Win32DisplayContainer &entry) -> bool {
                           return (entry.display->get_native() == monitor);
                         });
  if (it != g_display_list.end()) {
    /* Update cache index */
    it->cache_index = g_display_cache_index;
  } else {
    /* Allocate new display object */
    auto display = zinc::make_unique<Win32Display>(monitor);
    if (display->is_primary())
      g_primary_display = display.get();
    g_display_list.emplace_back(std::move(display), g_display_cache_index);
  }
  return TRUE;
}

static auto UpdateDisplayList() -> bool {
  if (HasMonitorListChanged()) {
    /* Clear primary display */
    g_primary_display = nullptr;

    /* Move to next cache index to determine which display entry is outdated */
    g_display_cache_index = (g_display_cache_index + 1) % 2;

    /* Gather new monitors */
    EnumDisplayMonitors(nullptr, nullptr, Win32MonitorEnumProcedure, 0);

    g_display_list.erase(
        std::remove_if(g_display_list.begin(), g_display_list.end(),
                       [](const Win32DisplayContainer &entry) -> bool {
                         return (entry.cache_index != g_display_cache_index);
                       }),
        g_display_list.end());

    return true;
  }
  return false;
}

static auto IsCursorVisible(bool &visible) -> bool {
  CURSORINFO info;
  info.cbSize = sizeof(CURSORINFO);
  if (::GetCursorInfo(&info)) {
    visible = ((info.flags & CURSOR_SHOWING) != 0);
    return true;
  }
  return false;
}

auto Display::count() -> usize {
  UpdateDisplayList();
  return g_display_list.size();
}

auto Display::get_list() -> zinc::array_view<Display *> {
  if (UpdateDisplayList()) {
    /* Update reference list and append null terminator to array */
    g_display_ref.clear();
    g_display_ref.reserve(g_display_list.size() + 1);
    for (const auto &entry : g_display_list)
      g_display_ref.push_back(entry.display.get());
    g_display_ref.push_back(nullptr);
  } else if (g_display_ref.empty()) {
    g_display_ref.clear();
  }
  return {reinterpret_cast<Display *const *>(g_display_ref.data()),
          g_display_ref.size() - 1};
}

auto Display::get(usize index) -> Display * {
  UpdateDisplayList();
  return (index < g_display_list.size() ? g_display_list[index].display.get()
                                        : nullptr);
}

auto Display::get_primary() -> Display * {
  UpdateDisplayList();
  return g_primary_display;
}

auto Display::toggle_cursor(bool show) -> bool {
  if (show)
    ::ShowCursor(TRUE);
  else
    ::ShowCursor(FALSE);
  return true;
}

auto Display::is_cursor_visible() -> bool {
  bool visible;
  if (moon::platform::IsCursorVisible(visible))
    return visible;
  return false;
}

auto Display::set_cursor_position(Offset2D const &position) -> bool {
  return (::SetCursorPos(position.x, position.y) != FALSE);
}

auto Display::get_cursor_position() -> Offset2D {
  POINT point;
  if (::GetCursorPos(&point)) {
    return {point.x, point.y};
  }
  return {0, 0};
}

Win32Display::Win32Display(HMONITOR monitor) : m_monitor(monitor) {}

auto Win32Display::is_primary() const -> bool {
  MONITORINFO info;
  get_info(info);
  return ((info.dwFlags & MONITORINFOF_PRIMARY) != 0);
}

auto Win32Display::get_device_name() const -> zinc::string {
  MONITORINFOEX infoEx;
  get_info(infoEx);
  char device_name[256];
  auto device_name_size =
      WideCharToMultiByte(CP_UTF8, 0, infoEx.szDevice, -1, device_name,
                          sizeof(device_name), nullptr, nullptr);
  return std::move(
      zinc::string{device_name, static_cast<usize>(device_name_size)});
}

auto Win32Display::get_offset() const -> Offset2D {
  MONITORINFO info;
  get_info(info);
  return {static_cast<i32>(info.rcMonitor.left),
          static_cast<i32>(info.rcMonitor.top)};
}

auto Win32Display::reset_display_attributes() -> bool {
  MONITORINFOEX infoEx;
  get_info(infoEx);
  auto result =
      ChangeDisplaySettingsExW(infoEx.szDevice, nullptr, nullptr, 0, nullptr);
  return (result == DISP_CHANGE_SUCCESSFUL);
}

auto Win32Display::set_display_attributes(const DisplayAttributes &attributes)
    -> bool {
  MONITORINFOEX infoEx;
  get_info(infoEx);

  DEVMODE devMode = {};
  {
    devMode.dmSize = sizeof(devMode);
    devMode.dmFields = (DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY);
    Convert(devMode, attributes);
  }
  auto result = ChangeDisplaySettingsEx(infoEx.szDevice, &devMode, nullptr,
                                        CDS_FULLSCREEN, nullptr);

  return (result == DISP_CHANGE_SUCCESSFUL);
}

auto Win32Display::get_display_attributes() const -> DisplayAttributes {
  /* Get display device name */
  MONITORINFOEX infoEx;
  get_info(infoEx);

  /* Get current display settings */
  DEVMODE devMode;
  devMode.dmSize = sizeof(devMode);

  if (EnumDisplaySettings(infoEx.szDevice, ENUM_CURRENT_SETTINGS, &devMode) !=
      FALSE) {
    DisplayAttributes display_attributes;
    Convert(display_attributes, devMode);
    return display_attributes;
  }

  return {};
}

auto Win32Display::get_display_mode_list() const
    -> zinc::vector<DisplayAttributes> {
  zinc::vector<DisplayAttributes> display_attributes;

  MONITORINFOEX infoEx;
  get_info(infoEx);

  const DWORD field_bits = (DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY);

  DEVMODE dev_mode;
  dev_mode.dmSize = sizeof(dev_mode);

  for (DWORD mode = 0;
       EnumDisplaySettings(infoEx.szDevice, mode, &dev_mode) != FALSE; ++mode) {
    if ((dev_mode.dmFields & field_bits) == field_bits) {
      DisplayAttributes outputDesc;
      Convert(outputDesc, dev_mode);
      display_attributes.push_back(outputDesc);
    }
  }

  FinaliseDisplayModes(display_attributes);

  return std::move(display_attributes);
}

auto Win32Display::get_info(MONITORINFO &info) const -> void {
  info.cbSize = sizeof(info);
  ::GetMonitorInfo(m_monitor, &info);
}

auto Win32Display::get_info(MONITORINFOEX &info) const -> void {
  info.cbSize = sizeof(info);
  ::GetMonitorInfo(m_monitor, &info);
}

} // namespace moon::platform