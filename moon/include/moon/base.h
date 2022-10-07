#pragma once

#if _DEBUG
#define ZINC_CONFIG_ENABLE_ASSERT 1
#endif
#include "zinc/zinc.h"

// Shared library
#if MOON_CONFIG_SHARED_LIB
#if ZINC_COMPILER_MSVC
#ifdef MOON_EXPORTS
#define MOON_API __declspec(dllexport)
#else
#define MOON_API __declspec(dllimport)
#endif
#else
#define MOON_API __attribute__((visibility("default")))
#endif
#else
#define MOON_API
#endif