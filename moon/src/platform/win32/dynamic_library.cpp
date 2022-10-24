#include "dynamic_library.h"
#include <errhandlingapi.h>

namespace moon::platform {
static auto LoadLibrarySafe(char const *name) -> HMODULE {
  UINT prevMode = SetErrorMode(0);
  SetErrorMode(prevMode | SEM_FAILCRITICALERRORS | SEM_NOOPENFILEERRORBOX);
  wchar_t wname[256];
  MultiByteToWideChar(CP_UTF8, 0, name, -1, wname, sizeof(wname));
  HMODULE module = LoadLibraryA(name);
  SetErrorMode(prevMode);
  return module;
}

auto DynamicLibrary::LibraryExists(char const *name) -> bool {
  if (HMODULE module = LoadLibrarySafe(name)) {
    FreeLibrary(module);
    return true;
  }
  return false;
}

auto DynamicLibrary::Load(char const *name) -> zinc::unique<DynamicLibrary> {
  return zinc::make_unique<Win32DynamicLibrary>(name);
}

Win32DynamicLibrary::Win32DynamicLibrary(char const *name) {
  m_library = LoadLibrarySafe(name);
  ZINC_ASSERTF(m_library, "Failed to load library: %s", name);
}

Win32DynamicLibrary::~Win32DynamicLibrary() { FreeLibrary(m_library); }

auto Win32DynamicLibrary::LoadProcedure(char const *name) -> vptr {
  return reinterpret_cast<vptr>(GetProcAddress(m_library, name));
}
} // namespace moon::platform