#pragma once

#include "moon/base.h"

#if ZINC_PLATFORM_WINDOWS
#define MOON_DEFINE_PROCEDURE(RETURN, SYMBOL, ARGS)                            \
  using SYMBOL = RETURN(__stdcall *) ARGS;
#else
#define MOON_DEFINE_PROCEDURE(RETURN, SYMBOL, ARGS)                            \
  using SYMBOL = RETURN(*) ARGS;
#endif

namespace moon {
class DynamicLibrary : public zinc::non_copyable {
public:
  static auto MOON_API LibraryExists(char const *name) -> bool;
  static auto MOON_API Load(char const *name) -> zinc::unique<DynamicLibrary>;
  virtual auto LoadProcedure(char const *name) -> vptr = 0;
};
} // namespace moon