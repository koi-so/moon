#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
void GetSurfaceInfo(size_t width, size_t height, Format format,
                    size_t *outNumBytes, size_t *outRowBytes,
                    size_t *outNumRows);

auto MakeTypelessDepthStencil(DXGI_FORMAT format) -> DXGI_FORMAT;
auto IsTypelessDepthStencil(DXGI_FORMAT format) -> bool;
auto DepthReadFromTypeless(DXGI_FORMAT format) -> DXGI_FORMAT;
auto StencilReadFromTypeless(DXGI_FORMAT format) -> DXGI_FORMAT;
auto DepthStencilFromTypeless(DXGI_FORMAT format) -> DXGI_FORMAT;
} // namespace rook::gpu::dx12