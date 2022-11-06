#pragma once

#include "rook/base.h"

#include "rook/platform/context_handle.h"
#include "rook/platform/dynamic_library.h"

namespace rook::platform {
class Win32DynamicLibrary final : public DynamicLibrary {
public:
  Win32DynamicLibrary(char const *name);
  ~Win32DynamicLibrary();

  auto LoadProcedure(char const *name) -> void * override;

private:
  HMODULE m_library{nullptr};
};
} // namespace rook::platform