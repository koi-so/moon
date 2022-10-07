#pragma once

#include "moon/base.h"

namespace moon::platform {
class Win32WindowClass : public zinc::non_copyable {
public:
  ~Win32WindowClass();

  static auto get() -> Win32WindowClass *;
  [[nodiscard]] auto get_class_name() const -> const wchar_t *;

private:
  Win32WindowClass();
};
} // namespace moon::platform