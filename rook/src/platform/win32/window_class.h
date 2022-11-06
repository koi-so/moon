#pragma once

#include "rook/base.h"

namespace rook::platform {
class Win32WindowClass {
public:
  Win32WindowClass(Win32WindowClass const &) = delete;
  Win32WindowClass(Win32WindowClass &&) = delete;

  ~Win32WindowClass();

  static auto get() -> Win32WindowClass *;
  [[nodiscard]] auto get_class_name() const -> const wchar_t *;

private:
  Win32WindowClass();
};
} // namespace rook::platform