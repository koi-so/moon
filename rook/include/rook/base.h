#pragma once

#include "EABase/config/eacompiler.h"

// Shared library
#if ROOK_CONFIG_SHARED_LIB
#if EA_COMPILER_MSVC
#ifdef ROOK_EXPORTS
#define ROOK_API __declspec(dllexport)
#else
#define ROOK_API __declspec(dllimport)
#endif
#else
#define ROOK_API __attribute__((visibility("default")))
#endif
#else
#define ROOK_API
#endif

namespace rook {
class interface {
public:
  virtual ~interface() = default;

  template <typename T> auto as() & -> T & { return static_cast<T &>(*this); }

  template <typename T> auto as() const & -> T const & {
    return static_cast<T &>(*this);
  }
};
} // namespace rook