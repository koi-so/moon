#pragma once

#include "moon/base.h"

#include "moon/platform/context_handle.h"
#include "moon/platform/dynamic_library.h"

namespace moon::platform {
class Win32DynamicLibrary final : public DynamicLibrary {
public:
  Win32DynamicLibrary(char const *name);
  ~Win32DynamicLibrary();

  auto LoadProcedure(char const *name) -> vptr override;

private:
  HMODULE m_library{nullptr};
};
} // namespace moon::platform