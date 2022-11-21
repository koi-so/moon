#include "format_translate.h"

namespace rook::gpu::dx12 {
static DXFormat const MapTable[] = {
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RG4_UNORM_GLI,
     math::vec4(0x000F, 0x00F0, 0x0000, 0x0000)}, // FORMAT_RG4_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA4_UNORM_GLI,
     math::vec4(0x000F, 0x00F0, 0x0F00, 0xF000)}, // FORMAT_RGBA4_UNORM,
    {DDPF_FOURCC, D3DFMT_A4R4G4B4, DXGI_FORMAT_B4G4R4A4_UNORM,
     math::vec4(0x0F00, 0x00F0, 0x000F, 0xF000)}, // FORMAT_BGRA4_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R5G6B5_UNORM_GLI,
     math::vec4(0x001f, 0x07e0, 0xf800, 0x0000)}, // FORMAT_R5G6B5_UNORM,
    {DDPF_FOURCC, D3DFMT_R5G6B5, DXGI_FORMAT_B5G6R5_UNORM,
     math::vec4(0xf800, 0x07e0, 0x001f, 0x0000)}, // FORMAT_B5G6R5_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R5G5B5A1_UNORM_GLI,
     math::vec4(0x001f, 0x03e0, 0x7c00, 0x8000)}, // FORMAT_RGB5A1_UNORM,
    {DDPF_FOURCC, D3DFMT_A1R5G5B5, DXGI_FORMAT_B5G5R5A1_UNORM,
     math::vec4(0x7c00, 0x03e0, 0x001f, 0x8000)}, // FORMAT_BGR5A1_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_A1B5G5R5_UNORM_GLI,
     math::vec4(0x7c00, 0x03e0, 0x001f, 0x8000)}, // FORMAT_A1RGB5_UNORM,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_UNORM,
     math::vec4(0x00FF0000, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R8_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_SNORM,
     math::vec4(0)}, // FORMAT_R8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8_USCALED_GLI,
     math::vec4(0x00FF0000, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_R8_SSCALED,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_UINT,
     math::vec4(0)}, // FORMAT_R8_UINT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_SINT,
     math::vec4(0)}, // FORMAT_R8_SINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_R8_SRGB,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_UNORM,
     math::vec4(0x00FF0000, 0x0000FF00, 0x00000000,
                0x00000000)}, // FORMAT_RG8_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_SNORM,
     math::vec4(0)}, // FORMAT_RG8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8_USCALED_GLI,
     math::vec4(0x00FF0000, 0x0000FF00, 0x00000000,
                0x00000000)}, // FORMAT_RG8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_RG8_SSCALED,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_UINT,
     math::vec4(0)}, // FORMAT_RG8_UINT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_SINT,
     math::vec4(0)}, // FORMAT_RG8_SINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RG8_SRGB,

    {DDPF_RGB, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_UNORM_GLI,
     math::vec4(0x000000FF, 0x0000FF00, 0x00FF0000,
                0x00000000)}, // FORMAT_RGB8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_SNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_USCALED_GLI,
     math::vec4(0)}, // FORMAT_RGB8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_RGB8_SSCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_UINT_GLI,
     math::vec4(0)}, // FORMAT_RGB8_UINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_SINT_GLI,
     math::vec4(0)}, // FORMAT_RGB8_SINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGB8_SRGB,

    {DDPF_RGB, D3DFMT_R8G8B8, DXGI_FORMAT_B8G8R8_UNORM_GLI,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0x00000000)}, // FORMAT_BGR8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_SNORM_GLI,
     math::vec4(0)}, // FORMAT_BGR8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_USCALED_GLI,
     math::vec4(0)}, // FORMAT_BGR8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_BGR8_SSCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_UINT_GLI,
     math::vec4(0)}, // FORMAT_BGR8_UINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_SINT_GLI,
     math::vec4(0)}, // FORMAT_BGR8_SINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_BGR8_SRGB,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UNORM,
     math::vec4(0x000000FF, 0x0000FF00, 0x00FF0000,
                0xFF000000)}, // FORMAT_RGBA8_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_SNORM,
     math::vec4(0)}, // FORMAT_RGBA8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_USCALED_GLI,
     math::vec4(0)}, // FORMAT_RGBA8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_RGBA8_SSCALED,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UINT,
     math::vec4(0)}, // FORMAT_RGBA8_UINT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_SINT,
     math::vec4(0)}, // FORMAT_RGBA8_SINT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_RGBA8_SRGB,

    {DDPF_RGBA, D3DFMT_A8R8G8B8, DXGI_FORMAT_B8G8R8A8_UNORM,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0xFF000000)}, // FORMAT_BGRA8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8A8_SNORM_GLI,
     math::vec4(0)}, // FORMAT_BGRA8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8A8_USCALED_GLI,
     math::vec4(0)}, // FORMAT_BGRA8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8A8_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_BGRA8_SSCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8A8_UINT_GLI,
     math::vec4(0)}, // FORMAT_BGRA8_UINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B8G8R8A8_SINT_GLI,
     math::vec4(0)}, // FORMAT_BGRA8_SINT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0xFF000000)}, // FORMAT_BGRA8_SRGB,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_UNORM_GLI,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0xFF000000)}, // FORMAT_ABGR8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_SNORM_GLI,
     math::vec4(0)}, // FORMAT_ABGR8_SNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_USCALED_GLI,
     math::vec4(0)}, // FORMAT_ABGR8_USCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_ABGR8_SSCALED,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_UINT_GLI,
     math::vec4(0)}, // FORMAT_ABGR8_UINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_SINT_GLI,
     math::vec4(0)}, // FORMAT_ABGR8_SINT,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R8G8B8A8_PACK_SRGB_GLI,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0xFF000000)}, // FORMAT_ABGR8_SRGB,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R10G10B10A2_UNORM,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_UNORM_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R10G10B10A2_SNORM_GLI,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_SNORM_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R10G10B10A2_USCALED_GLI,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_USCALED_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R10G10B10A2_SSCALED_GLI,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_SSCALED_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R10G10B10A2_UINT,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R10G10B10A2_SINT_GLI,
     math::vec4(0x000003FF, 0x000FFC00, 0x3FF00000,
                0xC0000000)}, // FORMAT_RGB10A2_SINT_PACK32,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_UNORM_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_UNORM_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_SNORM_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_SNORM_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_USCALED_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_USCALED_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_SSCALED_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_SSCALED_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_UINT_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_B10G10R10A2_SINT_GLI,
     math::vec4(0x3FF00000, 0x000FFC00, 0x000003FF,
                0xC0000000)}, // FORMAT_BGR10A2_SINT_PACK32,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_UNORM,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R16_UNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_SNORM,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R16_SNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16_USCALED_GLI,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R16_USCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16_SSCALED_GLI,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x00000000)}, // FORMAT_R16_SSCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_UINT,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x0000000)}, // FORMAT_R16_UINT_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_SINT,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x0000000)}, // FORMAT_R16_SINT_PACK16,
    {DDPF_FOURCC, D3DFMT_R16F, DXGI_FORMAT_R16_FLOAT,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000,
                0x0000000)}, // FORMAT_R16_SFLOAT_PACK16,

    {DDPF_FOURCC, D3DFMT_G16R16, DXGI_FORMAT_R16G16_UNORM,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_UNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_SNORM,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_SNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16_USCALED_GLI,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_USCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16_SSCALED_GLI,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_SSCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_UINT,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_UINT_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_SINT,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_SINT_PACK16,
    {DDPF_FOURCC, D3DFMT_G16R16F, DXGI_FORMAT_R16G16_FLOAT,
     math::vec4(0x0000FFFF, 0xFFFF0000, 0x00000000,
                0x00000000)}, // FORMAT_RG16_SFLOAT_PACK16,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB16_UNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_SNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB16_SNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_USCALED_GLI,
     math::vec4(0)}, // FORMAT_RGB16_USCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_RGB16_SSCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_UINT_GLI,
     math::vec4(0)}, // FORMAT_RGB16_UINT_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_SINT_GLI,
     math::vec4(0)}, // FORMAT_RGB16_SINT_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16_FLOAT_GLI,
     math::vec4(0)}, // FORMAT_RGB16_SFLOAT_PACK16,

    {DDPF_FOURCC, D3DFMT_A16B16G16R16, DXGI_FORMAT_R16G16B16A16_UNORM,
     math::vec4(0)}, // FORMAT_RGBA16_UNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_SNORM,
     math::vec4(0)}, // FORMAT_RGBA16_SNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16A16_USCALED_GLI,
     math::vec4(0)}, // FORMAT_RGBA16_USCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R16G16B16A16_SSCALED_GLI,
     math::vec4(0)}, // FORMAT_RGBA16_SSCALED_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_UINT,
     math::vec4(0)}, // FORMAT_RGBA16_UINT_PACK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_SINT,
     math::vec4(0)}, // FORMAT_RGBA16_SINT_PACK16,
    {DDPF_FOURCC, D3DFMT_A16B16G16R16F, DXGI_FORMAT_R16G16B16A16_FLOAT,
     math::vec4(0)}, // FORMAT_RGBA16_SFLOAT_PACK16,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32_UINT,
     math::vec4(0)}, // FORMAT_R32_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32_SINT,
     math::vec4(0)}, // FORMAT_R32_SINT_PACK32,
    {DDPF_FOURCC, D3DFMT_R32F, DXGI_FORMAT_R32_FLOAT,
     math::vec4(0xFFFFFFFF, 0x0000000, 0x0000000,
                0x0000000)}, // FORMAT_R32_SFLOAT_PACK32,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32_UINT,
     math::vec4(0)}, // FORMAT_RG32_UINT_PACK32
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32_SINT,
     math::vec4(0)}, // FORMAT_RG32_SINT_PACK32,
    {DDPF_FOURCC, D3DFMT_G32R32F, DXGI_FORMAT_R32G32_FLOAT,
     math::vec4(0)}, // FORMAT_RG32_SFLOAT_PACK32,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_UINT,
     math::vec4(0)}, // FORMAT_RGB32_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_SINT,
     math::vec4(0)}, // FORMAT_RGB32_SINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_FLOAT,
     math::vec4(0)}, // FORMAT_RGB32_SFLOAT_PACK32,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32A32_UINT,
     math::vec4(0)}, // FORMAT_RGBA32_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32A32_SINT,
     math::vec4(0)}, // FORMAT_RGBA32_SINT_PACK32,
    {DDPF_FOURCC, D3DFMT_A32B32G32R32F, DXGI_FORMAT_R32G32B32A32_FLOAT,
     math::vec4(0)}, // FORMAT_RGBA32_SFLOAT_PACK32,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64_UINT_GLI,
     math::vec4(0)}, // FORMAT_R64_UINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64_SINT_GLI,
     math::vec4(0)}, // FORMAT_R64_SINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64_FLOAT_GLI,
     math::vec4(0)}, // FORMAT_R64_SFLOAT_PACK64,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64_UINT_GLI,
     math::vec4(0)}, // FORMAT_RG64_UINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64_SINT_GLI,
     math::vec4(0)}, // FORMAT_RG64_SINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64_FLOAT_GLI,
     math::vec4(0)}, // FORMAT_RG64_SFLOAT_PACK64,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64_UINT_GLI,
     math::vec4(0)}, // FORMAT_RGB64_UINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64_SINT_GLI,
     math::vec4(0)}, // FORMAT_RGB64_SINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64_FLOAT_GLI,
     math::vec4(0)}, // FORMAT_RGB64_SFLOAT_PACK64,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64A64_UINT_GLI,
     math::vec4(0)}, // FORMAT_RGBA64_UINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64A64_SINT_GLI,
     math::vec4(0)}, // FORMAT_RGBA64_SINT_PACK64,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R64G64B64A64_FLOAT_GLI,
     math::vec4(0)}, // FORMAT_RGBA64_SFLOAT_PACK64,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R11G11B10_FLOAT,
     math::vec4(0)}, // FORMAT_RG11B10_UFLOAT,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R9G9B9E5_SHAREDEXP,
     math::vec4(0)}, // FORMAT_RGB9E5_UFLOAT,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D16_UNORM,
     math::vec4(0)}, // FORMAT_D16_UNORM_PACK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_D24_UNORM_GLI,
     math::vec4(0)}, // FORMAT_D24_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D32_FLOAT,
     math::vec4(0)}, // FORMAT_D32_SFLOAT_PACK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_S8_UINT_GLI,
     math::vec4(0)}, // FORMAT_S8_UINT_PACK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_D16_UNORM_S8_UINT_GLI,
     math::vec4(0)}, // FORMAT_D16_UNORM_S8_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D24_UNORM_S8_UINT,
     math::vec4(0)}, // FORMAT_D24_UNORM_S8_UINT_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
     math::vec4(0)}, // FORMAT_D32_SFLOAT_S8_UINT_PACK64,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_BC1_RGB_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_DXT1_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_BC1_RGB_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGB_DXT1_SRGB_BLOCK8,
    {DDPF_FOURCC, D3DFMT_DXT1, DXGI_FORMAT_BC1_UNORM,
     math::vec4(0)}, // FORMAT_RGBA_DXT1_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC1_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_RGBA_DXT1_SRGB_BLOCK8,
    {DDPF_FOURCC, D3DFMT_DXT3, DXGI_FORMAT_BC2_UNORM,
     math::vec4(0)}, // FORMAT_RGBA_DXT3_UNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC2_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_RGBA_DXT3_SRGB_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DXT5, DXGI_FORMAT_BC3_UNORM,
     math::vec4(0)}, // FORMAT_RGBA_DXT5_UNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC3_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_RGBA_DXT5_SRGB_BLOCK16,
    {DDPF_FOURCC, D3DFMT_ATI1, DXGI_FORMAT_BC4_UNORM,
     math::vec4(0)}, // FORMAT_R_ATI1N_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_AT1N, DXGI_FORMAT_BC4_SNORM,
     math::vec4(0)}, // FORMAT_R_ATI1N_SNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_ATI2, DXGI_FORMAT_BC5_UNORM,
     math::vec4(0)}, // FORMAT_RG_ATI2N_UNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_AT2N, DXGI_FORMAT_BC5_SNORM,
     math::vec4(0)}, // FORMAT_RG_ATI2N_SNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC6H_UF16,
     math::vec4(0)}, // FORMAT_RGB_BP_UFLOAT_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC6H_SF16,
     math::vec4(0)}, // FORMAT_RGB_BP_SFLOAT_BLOCK16,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC7_UNORM,
     math::vec4(0)}, // FORMAT_RGB_BP_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC7_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_RGB_BP_SRGB,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGB_ETC2_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_ETC2_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGB_ETC2_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGB_ETC2_SRGB_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_ETC2_A1_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ETC2_A1_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_ETC2_A1_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ETC2_A1_SRGB_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_ETC2_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ETC2_UNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_ETC2_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ETC2_SRGB_BLOCK16,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R11_EAC_UNORM_GLI,
     math::vec4(0)}, // FORMAT_R_EAC_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R11_EAC_SNORM_GLI,
     math::vec4(0)}, // FORMAT_R_EAC_SNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RG11_EAC_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RG_EAC_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RG11_EAC_SNORM_GLI,
     math::vec4(0)}, // FORMAT_RG_EAC_SNORM_BLOCK8,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_4X4_UNORM,
     math::vec4(0)}, // FORMAT_ASTC_4x4_UNORM,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_4X4_UNORM_SRGB,
     math::vec4(0)}, // FORMAT_ASTC_4x4_SRGB,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X4_UNORM,
     math::vec4(0)}, // RGBA_ASTC_5x4,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X4_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_5x4,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X5_UNORM,
     math::vec4(0)}, // RGBA_ASTC_5x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X5_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_5x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X5_UNORM,
     math::vec4(0)}, // RGBA_ASTC_6x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X5_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_6x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X6_UNORM,
     math::vec4(0)}, // RGBA_ASTC_6x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X6_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_6x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X5_UNORM,
     math::vec4(0)}, // RGBA_ASTC_8x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X5_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_8x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X6_UNORM,
     math::vec4(0)}, // RGBA_ASTC_8x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X6_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_8x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X8_UNORM,
     math::vec4(0)}, // RGBA_ASTC_8x8,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X8_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_8x8,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X5_UNORM,
     math::vec4(0)}, // RGBA_ASTC_10x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X5_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_10x5,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X6_UNORM,
     math::vec4(0)}, // RGBA_ASTC_10x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X6_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_10x6,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X8_UNORM,
     math::vec4(0)}, // RGBA_ASTC_10x8,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X8_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_10x8,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X10_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_10x10,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X10_UNORM,
     math::vec4(0)}, // RGBA_ASTC_10x10,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X10_UNORM,
     math::vec4(0)}, // RGBA_ASTC_12x10,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X10_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_12x10,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X12_UNORM,
     math::vec4(0)}, // RGBA_ASTC_12x12,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X12_UNORM_SRGB,
     math::vec4(0)}, // SRGB_ALPHA_ASTC_12x12,

    {DDPF_FOURCC, D3DFMT_POWERVR_4BPP, DXGI_FORMAT_RGB_PVRTC1_8X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_PVRTC1_8X8_UNORM_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGB_PVRTC1_8X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGB_PVRTC1_8X8_SRGB_BLOCK32,
    {DDPF_FOURCC, D3DFMT_POWERVR_2BPP, DXGI_FORMAT_RGB_PVRTC1_16X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_PVRTC1_16X8_UNORM_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGB_PVRTC1_16X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGB_PVRTC1_16X8_SRGB_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC1_8X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC1_8X8_UNORM_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC1_8X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC1_8X8_SRGB_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC1_16X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC1_16X8_UNORM_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC1_16X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC1_16X8_SRGB_BLOCK32,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC2_8X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC2_8X8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC2_8X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC2_8X8_SRGB,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC2_16X8_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC2_16X8_UNORM,
    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_RGBA_PVRTC2_16X8_SRGB_GLI,
     math::vec4(0)}, // FORMAT_RGBA_PVRTC2_16X8_SRGB,

    {DDPF_FOURCC, D3DFMT_ETC, DXGI_FORMAT_RGB_ETC_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_ETC_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_ATC, DXGI_FORMAT_RGB_ATC_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGB_ATC_UNORM_BLOCK8,
    {DDPF_FOURCC, D3DFMT_ATCA, DXGI_FORMAT_RGBA_ATCA_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ATCA_UNORM_BLOCK16,
    {DDPF_FOURCC, D3DFMT_ATCI, DXGI_FORMAT_RGBA_ATCI_UNORM_GLI,
     math::vec4(0)}, // FORMAT_RGBA_ATCI_UNORM_BLOCK16,

    {DDPF_LUMINANCE, D3DFMT_L8, DXGI_FORMAT_L8_UNORM_GLI,
     math::vec4(0x000000FF, 0x00000000, 0x00000000, 0x00000000)}, // L8_UNORM,
    {DDPF_ALPHA, D3DFMT_A8, DXGI_FORMAT_A8_UNORM_GLI,
     math::vec4(0x00000000, 0x00000000, 0x00000000, 0x000000FF)}, // A8_UNORM,
    {DDPF_LUMINANCE_ALPHA, D3DFMT_A8L8, DXGI_FORMAT_LA8_UNORM_GLI,
     math::vec4(0x000000FF, 0x00000000, 0x00000000, 0x0000FF00)}, // LA8_UNORM,
    {DDPF_LUMINANCE, D3DFMT_L16, DXGI_FORMAT_L16_UNORM_GLI,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000, 0x00000000)}, // L16_UNORM,
    {DDPF_ALPHA, D3DFMT_GLI1, DXGI_FORMAT_A16_UNORM_GLI,
     math::vec4(0x00000000, 0x00000000, 0x00000000, 0x0000FFFF)}, // A16_UNORM,
    {DDPF_LUMINANCE_ALPHA, D3DFMT_GLI1, DXGI_FORMAT_LA16_UNORM_GLI,
     math::vec4(0x0000FFFF, 0x00000000, 0x00000000, 0xFFFF0000)}, // LA16_UNORM,

    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8X8_UNORM,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0x00000000)}, // FORMAT_BGR8_UNORM_PACK32,
    {DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
     math::vec4(0x00FF0000, 0x0000FF00, 0x000000FF,
                0x00000000)}, // FORMAT_BGR8_SRGB_PACK32,

    {DDPF_FOURCC, D3DFMT_GLI1, DXGI_FORMAT_R3G3B2_UNORM_GLI,
     math::vec4(0x70, 0x38, 0xC0, 0x00)}, // FORMAT_RG3B2_UNORM,
};

DXFormat const &TranslateFormatToDX12Format(Format Format) {
  return MapTable[static_cast<uint32_t>(Format) -
                  static_cast<uint32_t>(Format::FIRST)];
}
} // namespace rook::gpu::dx12