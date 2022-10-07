#pragma once

#include "moon/base.h"

// #define MOON_GPU_DX11 0
// #define MOON_GPU_DX12 0
// #define MOON_GPU_NONE 0
// #define MOON_GPU_GLES 0
// #define MOON_GPU_METAL 0
// #define MOON_GPU_VULKAN 0

namespace {
constexpr u8 MAX_ANISOTROPY = 16;
constexpr usize MAX_BIND_GROUPS = 8;
constexpr usize MAX_VERTEX_BUFFERS = 16;
constexpr usize MAX_COLOR_ATTACHMENTS = 8;
constexpr u32 MAX_MIP_LEVELS = 8;
} // namespace