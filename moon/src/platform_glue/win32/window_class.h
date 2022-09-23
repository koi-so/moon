#pragma once

#include "moon/base.h"

namespace moon {
class Win32WindowClass {
public:
  NO_COPY(Win32WindowClass);
  ~Win32WindowClass();

  static auto get() -> Win32WindowClass *;
  [[nodiscard]] auto get_class_name() const -> const wchar_t *;

private:
  Win32WindowClass();
};
} // namespace moon