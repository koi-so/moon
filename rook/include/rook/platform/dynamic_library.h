#pragma once

#include "rook/base.h"

#include <EASTL/unique_ptr.h>

#if EA_PLATFORM_WINDOWS
#define ROOK_DEFINE_PROCEDURE(RETURN, SYMBOL, ARGS)                            \
  using SYMBOL = RETURN(__stdcall *) ARGS;
#else
#define ROOK_DEFINE_PROCEDURE(RETURN, SYMBOL, ARGS)                            \
  using SYMBOL = RETURN(*) ARGS;
#endif

namespace rook::platform {
class DynamicLibrary {
public:
  DynamicLibrary() = default;
  DynamicLibrary(DynamicLibrary const &) = delete;
  DynamicLibrary(DynamicLibrary &&) = delete;

  static auto ROOK_API LibraryExists(char const *name) -> bool;
  static auto ROOK_API Load(char const *name)
      -> eastl::unique_ptr<DynamicLibrary>;
  virtual auto LoadProcedure(char const *name) -> void * = 0;
};
} // namespace rook::platform