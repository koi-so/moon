#include "dynamic_library.h"
#include "EASTL/internal/config.h"
#include <errhandlingapi.h>

#include <EASTL/unique_ptr.h>

namespace rook::platform {
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

auto DynamicLibrary::Load(char const *name)
    -> eastl::unique_ptr<DynamicLibrary> {
  return eastl::make_unique<Win32DynamicLibrary>(name);
}

Win32DynamicLibrary::Win32DynamicLibrary(char const *name) {
  m_library = LoadLibrarySafe(name);
  EASTL_ASSERT_MSG(m_library, "Failed to load library");
}

Win32DynamicLibrary::~Win32DynamicLibrary() { FreeLibrary(m_library); }

auto Win32DynamicLibrary::LoadProcedure(char const *name) -> void * {
  return reinterpret_cast<void *>(GetProcAddress(m_library, name));
}
} // namespace rook::platform