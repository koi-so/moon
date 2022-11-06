#pragma once

#include <utility>

#include "rook/base.h"
#include "rook/math.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>
#include <EASTL/tuple.h>
#include <EASTL/vector.h>

namespace rook::gpu {
class BindingSetLayout;
class Program;
class RenderPass;
class Resource;
class View;

enum class BackendType {
  eVulkan,
  eMetal,
  eD3D12,
};

namespace Enums {
enum ResourceState : uint32_t {
  eUnknown = 0,
  eCommon = 1 << 0,
  eVertexAndConstantBuffer = 1 << 1,
  eIndexBuffer = 1 << 2,
  eRenderTarget = 1 << 3,
  eUnorderedAccess = 1 << 4,
  eDepthStencilWrite = 1 << 5,
  eDepthStencilRead = 1 << 6,
  eNonPixelShaderResource = 1 << 7,
  ePixelShaderResource = 1 << 8,
  eIndirectArgument = 1 << 9,
  eCopyDest = 1 << 10,
  eCopySource = 1 << 11,
  eRaytracingAccelerationStructure = 1 << 12,
  eShadingRateSource = 1 << 13,
  ePresent = 1 << 14,
  eGenericRead =
      ResourceState::eVertexAndConstantBuffer | ResourceState::eIndexBuffer |
      ResourceState::eCopySource | ResourceState::eNonPixelShaderResource |
      ResourceState::ePixelShaderResource | ResourceState::eIndirectArgument,
  eUndefined = 1 << 15,
};
}

using ResourceState = Enums::ResourceState;

enum class ViewDimension {
  eUnknown,
  eBuffer,
  eTexture1D,
  eTexture1DArray,
  eTexture2D,
  eTexture2DArray,
  eTexture2DMS,
  eTexture2DMSArray,
  eTexture3D,
  eTextureCube,
  eTextureCubeArray,
};

enum class SamplerFilter {
  eAnisotropic,
  eMinMagMipLinear,
  eComparisonMinMagMipLinear,
};

enum class SamplerTextureAddressMode { eWrap, eClamp };

enum class SamplerComparisonFunc { eNever, eAlways, eLess };

struct SamplerDescriptor {
  SamplerFilter filter;
  SamplerTextureAddressMode mode;
  SamplerComparisonFunc func;
};

enum class ViewType {
  eUnknown,
  eConstantBuffer,
  eSampler,
  eTexture,
  eRWTexture,
  eBuffer,
  eRWBuffer,
  eStructuredBuffer,
  eRWStructuredBuffer,
  eAccelerationStructure,
  eShadingRateSource,
  eRenderTarget,
  eDepthStencil
};

enum class ShaderBlobType {
  eDXIL,
  eSPIRV,
};

enum class ResourceType {
  eUnknown,
  eBuffer,
  eTexture,
  eSampler,
  eAccelerationStructure,
};

enum class TextureType {
  e1D,
  e2D,
  e3D,
};

enum class BindFlag {
  eRenderTarget = 1 << 1,
  eDepthStencil = 1 << 2,
  eShaderResource = 1 << 3,
  eUnorderedAccess = 1 << 4,
  eConstantBuffer = 1 << 5,
  eIndexBuffer = 1 << 6,
  eVertexBuffer = 1 << 7,
  eAccelerationStructure = 1 << 8,
  eRayTracing = 1 << 9,
  eCopyDest = 1 << 10,
  eCopySource = 1 << 11,
  eShadingRateSource = 1 << 12,
  eShaderTable = 1 << 13,
  eIndirectBuffer = 1 << 14
};

enum class FillMode { eWireframe, eSolid };

enum class CullMode {
  eNone,
  eFront,
  eBack,
};

struct RasterizerDescriptor {
  FillMode fill_mode = FillMode::eSolid;
  CullMode cull_mode = CullMode::eNone;
  int32_t depth_bias = 0;

  [[nodiscard]] auto tied() const {
    return eastl::tie(fill_mode, cull_mode, depth_bias);
  }
};

enum class Blend {
  eZero,
  eSrcAlpha,
  eInvSrcAlpha,
};

enum class BlendOperation {
  eAdd,
};

struct BlendDescriptor {
  bool blend_enable = false;
  Blend blend_src;
  Blend blend_dest;
  BlendOperation blend_op;
  Blend blend_src_alpha;
  Blend blend_dest_apha;
  BlendOperation blend_op_alpha;

  [[nodiscard]] auto tied() const {
    return eastl::tie(blend_enable, blend_src, blend_dest, blend_op,
                      blend_src_alpha, blend_dest_apha, blend_op_alpha);
  }
};

enum class ComparisonFunc {
  eNever,
  eLess,
  eEqual,
  eLessEqual,
  eGreater,
  eNotEqual,
  eGreaterEqual,
  eAlways
};

enum class StencilOperation {
  eKeep,
  eZero,
  eReplace,
  eIncrementSat,
  eDecrementSat,
  eInvert,
  eIncrement,
  eDecrement
};

struct StencilOperationDescriptor {
  StencilOperation fail_op = StencilOperation::eKeep;
  StencilOperation depth_fail_op = StencilOperation::eKeep;
  StencilOperation pass_op = StencilOperation::eKeep;
  ComparisonFunc func = ComparisonFunc::eAlways;

  [[nodiscard]] auto tied() const {
    return eastl::tie(fail_op, depth_fail_op, pass_op, func);
  }
};

struct DepthStencilDescriptor {
  bool depth_test_enable = true;
  ComparisonFunc depth_func = ComparisonFunc::eLess;
  bool depth_write_enable = true;
  bool depth_bounds_test_enable = false;
  bool stencil_enable = false;
  uint8_t stencil_read_mask = 0xff;
  uint8_t stencil_write_mask = 0xff;
  StencilOperationDescriptor front_face = {};
  StencilOperationDescriptor back_face = {};

  [[nodiscard]] auto tied() const {
    return eastl::tie(depth_test_enable, depth_func, depth_write_enable,
                      depth_bounds_test_enable, stencil_enable,
                      stencil_read_mask, stencil_write_mask, front_face,
                      back_face);
  }
};

enum class ShaderType {
  eUnknown,
  eVertex,
  ePixel,
  eCompute,
  eGeometry,
  eAmplification,
  eMesh,
  eLibrary,
};

enum class Format {
  UNDEFINED = 0,

  RG4_UNORM_PACK8,
  FIRST = RG4_UNORM_PACK8,
  RGBA4_UNORM_PACK16,
  BGRA4_UNORM_PACK16,
  R5G6B5_UNORM_PACK16,
  B5G6R5_UNORM_PACK16,
  RGB5A1_UNORM_PACK16,
  BGR5A1_UNORM_PACK16,
  A1RGB5_UNORM_PACK16,

  R8_UNORM_PACK8,
  R8_SNORM_PACK8,
  R8_USCALED_PACK8,
  R8_SSCALED_PACK8,
  R8_UINT_PACK8,
  R8_SINT_PACK8,
  R8_SRGB_PACK8,

  RG8_UNORM_PACK8,
  RG8_SNORM_PACK8,
  RG8_USCALED_PACK8,
  RG8_SSCALED_PACK8,
  RG8_UINT_PACK8,
  RG8_SINT_PACK8,
  RG8_SRGB_PACK8,

  RGB8_UNORM_PACK8,
  RGB8_SNORM_PACK8,
  RGB8_USCALED_PACK8,
  RGB8_SSCALED_PACK8,
  RGB8_UINT_PACK8,
  RGB8_SINT_PACK8,
  RGB8_SRGB_PACK8,

  BGR8_UNORM_PACK8,
  BGR8_SNORM_PACK8,
  BGR8_USCALED_PACK8,
  BGR8_SSCALED_PACK8,
  BGR8_UINT_PACK8,
  BGR8_SINT_PACK8,
  BGR8_SRGB_PACK8,

  RGBA8_UNORM_PACK8,
  RGBA8_SNORM_PACK8,
  RGBA8_USCALED_PACK8,
  RGBA8_SSCALED_PACK8,
  RGBA8_UINT_PACK8,
  RGBA8_SINT_PACK8,
  RGBA8_SRGB_PACK8,

  BGRA8_UNORM_PACK8,
  BGRA8_SNORM_PACK8,
  BGRA8_USCALED_PACK8,
  BGRA8_SSCALED_PACK8,
  BGRA8_UINT_PACK8,
  BGRA8_SINT_PACK8,
  BGRA8_SRGB_PACK8,

  RGBA8_UNORM_PACK32,
  RGBA8_SNORM_PACK32,
  RGBA8_USCALED_PACK32,
  RGBA8_SSCALED_PACK32,
  RGBA8_UINT_PACK32,
  RGBA8_SINT_PACK32,
  RGBA8_SRGB_PACK32,

  RGB10A2_UNORM_PACK32,
  RGB10A2_SNORM_PACK32,
  RGB10A2_USCALED_PACK32,
  RGB10A2_SSCALED_PACK32,
  RGB10A2_UINT_PACK32,
  RGB10A2_SINT_PACK32,

  BGR10A2_UNORM_PACK32,
  BGR10A2_SNORM_PACK32,
  BGR10A2_USCALED_PACK32,
  BGR10A2_SSCALED_PACK32,
  BGR10A2_UINT_PACK32,
  BGR10A2_SINT_PACK32,

  R16_UNORM_PACK16,
  R16_SNORM_PACK16,
  R16_USCALED_PACK16,
  R16_SSCALED_PACK16,
  R16_UINT_PACK16,
  R16_SINT_PACK16,
  R16_SFLOAT_PACK16,

  RG16_UNORM_PACK16,
  RG16_SNORM_PACK16,
  RG16_USCALED_PACK16,
  RG16_SSCALED_PACK16,
  RG16_UINT_PACK16,
  RG16_SINT_PACK16,
  RG16_SFLOAT_PACK16,

  RGB16_UNORM_PACK16,
  RGB16_SNORM_PACK16,
  RGB16_USCALED_PACK16,
  RGB16_SSCALED_PACK16,
  RGB16_UINT_PACK16,
  RGB16_SINT_PACK16,
  RGB16_SFLOAT_PACK16,

  RGBA16_UNORM_PACK16,
  RGBA16_SNORM_PACK16,
  RGBA16_USCALED_PACK16,
  RGBA16_SSCALED_PACK16,
  RGBA16_UINT_PACK16,
  RGBA16_SINT_PACK16,
  RGBA16_SFLOAT_PACK16,

  R32_UINT_PACK32,
  R32_SINT_PACK32,
  R32_SFLOAT_PACK32,

  RG32_UINT_PACK32,
  RG32_SINT_PACK32,
  RG32_SFLOAT_PACK32,

  RGB32_UINT_PACK32,
  RGB32_SINT_PACK32,
  RGB32_SFLOAT_PACK32,

  RGBA32_UINT_PACK32,
  RGBA32_SINT_PACK32,
  RGBA32_SFLOAT_PACK32,

  R64_UINT_PACK64,
  R64_SINT_PACK64,
  R64_SFLOAT_PACK64,

  RG64_UINT_PACK64,
  RG64_SINT_PACK64,
  RG64_SFLOAT_PACK64,

  RGB64_UINT_PACK64,
  RGB64_SINT_PACK64,
  RGB64_SFLOAT_PACK64,

  RGBA64_UINT_PACK64,
  RGBA64_SINT_PACK64,
  RGBA64_SFLOAT_PACK64,

  RG11B10_UFLOAT_PACK32,
  RGB9E5_UFLOAT_PACK32,

  D16_UNORM_PACK16,
  D24_UNORM_PACK32,
  D32_SFLOAT_PACK32,
  S8_UINT_PACK8,
  D16_UNORM_S8_UINT_PACK32,
  D24_UNORM_S8_UINT_PACK32,
  D32_SFLOAT_S8_UINT_PACK64,

  RGB_DXT1_UNORM_BLOCK8,
  RGB_DXT1_SRGB_BLOCK8,
  RGBA_DXT1_UNORM_BLOCK8,
  RGBA_DXT1_SRGB_BLOCK8,
  RGBA_DXT3_UNORM_BLOCK16,
  RGBA_DXT3_SRGB_BLOCK16,
  RGBA_DXT5_UNORM_BLOCK16,
  RGBA_DXT5_SRGB_BLOCK16,
  R_ATI1N_UNORM_BLOCK8,
  R_ATI1N_SNORM_BLOCK8,
  RG_ATI2N_UNORM_BLOCK16,
  RG_ATI2N_SNORM_BLOCK16,
  RGB_BP_UFLOAT_BLOCK16,
  RGB_BP_SFLOAT_BLOCK16,
  RGBA_BP_UNORM_BLOCK16,
  RGBA_BP_SRGB_BLOCK16,

  RGB_ETC2_UNORM_BLOCK8,
  RGB_ETC2_SRGB_BLOCK8,
  RGBA_ETC2_UNORM_BLOCK8,
  RGBA_ETC2_SRGB_BLOCK8,
  RGBA_ETC2_UNORM_BLOCK16,
  RGBA_ETC2_SRGB_BLOCK16,
  R_EAC_UNORM_BLOCK8,
  R_EAC_SNORM_BLOCK8,
  RG_EAC_UNORM_BLOCK16,
  RG_EAC_SNORM_BLOCK16,

  RGBA_ASTC_4X4_UNORM_BLOCK16,
  RGBA_ASTC_4X4_SRGB_BLOCK16,
  RGBA_ASTC_5X4_UNORM_BLOCK16,
  RGBA_ASTC_5X4_SRGB_BLOCK16,
  RGBA_ASTC_5X5_UNORM_BLOCK16,
  RGBA_ASTC_5X5_SRGB_BLOCK16,
  RGBA_ASTC_6X5_UNORM_BLOCK16,
  RGBA_ASTC_6X5_SRGB_BLOCK16,
  RGBA_ASTC_6X6_UNORM_BLOCK16,
  RGBA_ASTC_6X6_SRGB_BLOCK16,
  RGBA_ASTC_8X5_UNORM_BLOCK16,
  RGBA_ASTC_8X5_SRGB_BLOCK16,
  RGBA_ASTC_8X6_UNORM_BLOCK16,
  RGBA_ASTC_8X6_SRGB_BLOCK16,
  RGBA_ASTC_8X8_UNORM_BLOCK16,
  RGBA_ASTC_8X8_SRGB_BLOCK16,
  RGBA_ASTC_10X5_UNORM_BLOCK16,
  RGBA_ASTC_10X5_SRGB_BLOCK16,
  RGBA_ASTC_10X6_UNORM_BLOCK16,
  RGBA_ASTC_10X6_SRGB_BLOCK16,
  RGBA_ASTC_10X8_UNORM_BLOCK16,
  RGBA_ASTC_10X8_SRGB_BLOCK16,
  RGBA_ASTC_10X10_UNORM_BLOCK16,
  RGBA_ASTC_10X10_SRGB_BLOCK16,
  RGBA_ASTC_12X10_UNORM_BLOCK16,
  RGBA_ASTC_12X10_SRGB_BLOCK16,
  RGBA_ASTC_12X12_UNORM_BLOCK16,
  RGBA_ASTC_12X12_SRGB_BLOCK16,

  RGB_PVRTC1_8X8_UNORM_BLOCK32,
  RGB_PVRTC1_8X8_SRGB_BLOCK32,
  RGB_PVRTC1_16X8_UNORM_BLOCK32,
  RGB_PVRTC1_16X8_SRGB_BLOCK32,
  RGBA_PVRTC1_8X8_UNORM_BLOCK32,
  RGBA_PVRTC1_8X8_SRGB_BLOCK32,
  RGBA_PVRTC1_16X8_UNORM_BLOCK32,
  RGBA_PVRTC1_16X8_SRGB_BLOCK32,
  RGBA_PVRTC2_4X4_UNORM_BLOCK8,
  RGBA_PVRTC2_4X4_SRGB_BLOCK8,
  RGBA_PVRTC2_8X4_UNORM_BLOCK8,
  RGBA_PVRTC2_8X4_SRGB_BLOCK8,

  RGB_ETC_UNORM_BLOCK8,
  RGB_ATC_UNORM_BLOCK8,
  RGBA_ATCA_UNORM_BLOCK16,
  RGBA_ATCI_UNORM_BLOCK16,

  L8_UNORM_PACK8,
  A8_UNORM_PACK8,
  LA8_UNORM_PACK8,
  L16_UNORM_PACK16,
  A16_UNORM_PACK16,
  LA16_UNORM_PACK16,

  BGR8_UNORM_PACK32,
  BGR8_SRGB_PACK32,

  RG3B2_UNORM_PACK8,
  LAST = RG3B2_UNORM_PACK8
};

struct ViewDescriptor {
  ViewType view_type = ViewType::eUnknown;
  ViewDimension dimension = ViewDimension::eUnknown;
  uint32_t base_mip_level = 0;
  uint32_t level_count = static_cast<uint32_t>(-1);
  uint32_t base_array_layer = 0;
  uint32_t layer_count = static_cast<uint32_t>(-1);
  uint32_t plane_slice = 0;
  uint64_t offset = 0;
  uint32_t structure_stride = 0;
  uint64_t buffer_size = static_cast<uint64_t>(-1);
  Format buffer_format = Format::UNDEFINED;
  bool bindless = false;

  [[nodiscard]] auto tied() const {
    return eastl::tie(view_type, dimension, base_mip_level, level_count,
                      base_array_layer, layer_count, plane_slice, offset,
                      structure_stride, buffer_size,
                      /*buffer_format,*/ bindless);
  }
};

struct ShaderDescriptor {
  eastl::vector<uint8_t> shader_data;
  eastl::string entrypoint;
  ShaderType type;
  eastl::string model;
  // std::map<eastl::string, eastl::string> define;

  ShaderDescriptor(eastl::vector<uint8_t> shader_data, eastl::string entrypoint,
                   ShaderType type, eastl::string model)
      : shader_data(std::move(shader_data)), entrypoint(std::move(entrypoint)),
        type(type), model(std::move(model)) {}
};

struct InputLayoutDescriptor {
  uint32_t slot = 0;
  eastl::string semantic_name;
  Format format = Format::UNDEFINED;
  uint32_t stride = 0;

  [[nodiscard]] auto tied() const {
    return eastl::tie(slot, semantic_name, format, stride);
  }
};

enum class RenderPassLoadOperation {
  eLoad,
  eClear,
  eDontCare,
};

enum class RenderPassStoreOperation {
  eStore = 0,
  eDontCare,
};

struct RenderPassColorDescriptor {
  Format format = Format::UNDEFINED;
  RenderPassLoadOperation load_op = RenderPassLoadOperation::eLoad;
  RenderPassStoreOperation store_op = RenderPassStoreOperation::eStore;

  [[nodiscard]] auto tied() const {
    return eastl::tie(format, load_op, store_op);
  }
};

struct RenderPassDepthStencilDescriptor {
  Format format = Format::UNDEFINED;
  RenderPassLoadOperation depth_load_op = RenderPassLoadOperation::eLoad;
  RenderPassStoreOperation depth_store_op = RenderPassStoreOperation::eStore;
  RenderPassLoadOperation stencil_load_op = RenderPassLoadOperation::eLoad;
  RenderPassStoreOperation stencil_store_op = RenderPassStoreOperation::eStore;

  [[nodiscard]] auto tied() const {
    return eastl::tie(format, depth_load_op, depth_store_op, stencil_load_op,
                      stencil_store_op);
  }
};

struct RenderPassDescriptor {
  eastl::vector<RenderPassColorDescriptor> colors;
  RenderPassDepthStencilDescriptor depth_stencil;
  Format shading_rate_format = Format::UNDEFINED;
  uint32_t sample_count = 1;

  [[nodiscard]] auto tied() const {
    return eastl::tie(colors, depth_stencil, shading_rate_format, sample_count);
  }
};

struct FrameBufferDescriptor {
  eastl::shared_ptr<RenderPass> render_pass;
  uint32_t width;
  uint32_t height;
  eastl::vector<eastl::shared_ptr<View>> colors;
  eastl::shared_ptr<View> depth_stencil;
  eastl::shared_ptr<View> shading_rate_image;

  [[nodiscard]] auto tied() const {
    return eastl::tie(render_pass, width, height, colors, depth_stencil,
                      shading_rate_image);
  }
};

struct GraphicsPipelineDescriptor {
  eastl::shared_ptr<Program> program;
  eastl::shared_ptr<BindingSetLayout> layout;
  eastl::vector<InputLayoutDescriptor> input;
  eastl::shared_ptr<RenderPass> render_pass;
  DepthStencilDescriptor depth_stencil_desc;
  BlendDescriptor blend_desc;
  RasterizerDescriptor rasterizer_desc;

  [[nodiscard]] auto tied() const {
    return eastl::tie(program, layout, input, render_pass, depth_stencil_desc,
                      blend_desc, rasterizer_desc);
  }
};

struct ComputePipelineDescriptor {
  eastl::shared_ptr<Program> program;
  eastl::shared_ptr<BindingSetLayout> layout;

  [[nodiscard]] auto tied() const { return eastl::tie(program, layout); }
};

enum class RayTracingShaderGroupType {
  eGeneral,
  eTrianglesHitGroup,
  eProceduralHitGroup,
};

struct RayTracingShaderGroup {
  RayTracingShaderGroupType type = RayTracingShaderGroupType::eGeneral;
  uint64_t general = 0;
  uint64_t closest_hit = 0;
  uint64_t any_hit = 0;
  uint64_t intersection = 0;

  [[nodiscard]] auto tied() const {
    return eastl::tie(type, general, closest_hit, any_hit, intersection);
  }
};

struct RayTracingPipelineDescriptor {
  eastl::shared_ptr<Program> program;
  eastl::shared_ptr<BindingSetLayout> layout;
  eastl::vector<RayTracingShaderGroup> groups;

  [[nodiscard]] auto tied() const {
    return eastl::tie(program, layout, groups);
  }
};

struct RayTracingShaderTable {
  eastl::shared_ptr<Resource> resource;
  uint64_t offset;
  uint64_t size;
  uint64_t stride;
};

struct RayTracingShaderTables {
  RayTracingShaderTable raygen;
  RayTracingShaderTable miss;
  RayTracingShaderTable hit;
  RayTracingShaderTable callable;
};

struct BindKey {
  ShaderType shader_type = ShaderType::eUnknown;
  ViewType view_type = ViewType::eUnknown;
  uint32_t slot = 0;
  uint32_t space = 0;
  uint32_t count = 1;

  [[nodiscard]] auto tied() const {
    return eastl::tie(shader_type, view_type, slot, space, count);
  }
};

struct BindingDescriptor {
  BindKey bind_key;
  eastl::shared_ptr<View> view;

  [[nodiscard]] auto tied() const { return eastl::tie(bind_key, view); }
};

enum class ReturnType {
  eUnknown,
  eFloat,
  eUint,
  eInt,
  eDouble,
};

struct ResourceBindingDescriptor {
  eastl::string name;
  ViewType type;
  uint32_t slot;
  uint32_t space;
  uint32_t count;
  ViewDimension dimension;
  ReturnType return_type;
  uint32_t structure_stride;
};

enum class PipelineType {
  eGraphics,
  eCompute,
  eRayTracing,
};

struct BufferDescriptor {
  eastl::shared_ptr<Resource> res;
  Format format = Format::UNDEFINED;
  uint32_t count = 0;
  uint32_t offset = 0;
};

enum class RaytracingInstanceFlags : uint32_t {
  eNone = 0x0,
  eTriangleCullDisable = 0x1,
  eTriangleFrontCounterclockwise = 0x2,
  eForceOpaque = 0x4,
  eForceNonOpaque = 0x8
};

enum class RaytracingGeometryFlags {
  eNone,
  eOpaque,
  eNoDuplicateAnyHitInvocation
};

struct RaytracingGeometryDesc {
  BufferDescriptor vertex;
  BufferDescriptor index;
  RaytracingGeometryFlags flags = RaytracingGeometryFlags::eNone;
};

enum class MemoryType { eDefault, eUpload, eReadback };

struct TextureOffset {
  int32_t x;
  int32_t y;
  int32_t z;
};

struct TextureExtent3D {
  uint32_t width;
  uint32_t height;
  uint32_t depth;
};

struct BufferToTextureCopyRegion {
  uint64_t buffer_offset;
  uint32_t buffer_row_pitch;
  uint32_t texture_mip_level;
  uint32_t texture_array_layer;
  TextureOffset texture_offset;
  TextureExtent3D texture_extent;
};

struct TextureCopyRegion {
  TextureExtent3D extent;
  uint32_t src_mip_level;
  uint32_t src_array_layer;
  TextureOffset src_offset;
  uint32_t dst_mip_level;
  uint32_t dst_array_layer;
  TextureOffset dst_offset;
};

struct BufferCopyRegion {
  uint64_t src_offset;
  uint64_t dst_offset;
  uint64_t num_bytes;
};

struct RaytracingGeometryInstance {
  math::mat3x4 transform;
  uint32_t instance_id : 24;
  uint32_t instance_mask : 8;
  uint32_t instance_offset : 24;
  RaytracingInstanceFlags flags : 8;
  uint64_t acceleration_structure_handle;
};

static_assert(sizeof(RaytracingGeometryInstance) == 64);

struct ResourceBarrierDescriptor {
  eastl::shared_ptr<Resource> resource;
  ResourceState state_before;
  ResourceState state_after;
  uint32_t base_mip_level = 0;
  uint32_t level_count = 1;
  uint32_t base_array_layer = 0;
  uint32_t layer_count = 1;
};

enum class ShadingRate : uint8_t {
  e1x1 = 0,
  e1x2 = 0x1,
  e2x1 = 0x4,
  e2x2 = 0x5,
  e2x4 = 0x6,
  e4x2 = 0x9,
  e4x4 = 0xa,
};

enum class ShadingRateCombiner {
  ePassthrough = 0,
  eOverride = 1,
  eMin = 2,
  eMax = 3,
  eSum = 4,
};

struct RaytracingASPrebuildInfo {
  uint64_t acceleration_structure_size = 0;
  uint64_t build_scratch_data_size = 0;
  uint64_t update_scratch_data_size = 0;
};

enum class AccelerationStructureType {
  eTopLevel,
  eBottomLevel,
};

enum class CommandListType {
  eGraphics,
  eCompute,
  eCopy,
};

struct ClearDesc {
  eastl::vector<math::fvec4> colors;
  float depth = 1.0f;
  uint8_t stencil = 0;
};

enum class CopyAccelerationStructureMode {
  eClone,
  eCompact,
};

enum class BuildAccelerationStructureFlags {
  eNone = 0,
  eAllowUpdate = 1 << 0,
  eAllowCompaction = 1 << 1,
  ePreferFastTrace = 1 << 2,
  ePreferFastBuild = 1 << 3,
  eMinimizeMemory = 1 << 4,
};

struct DrawIndirectCommand {
  uint32_t vertex_count;
  uint32_t instance_count;
  uint32_t first_vertex;
  uint32_t first_instance;
};

struct DrawIndexedIndirectCommand {
  uint32_t index_count;
  uint32_t instance_count;
  uint32_t first_index;
  int32_t vertex_offset;
  uint32_t first_instance;
};

struct DispatchIndirectCommand {
  uint32_t thread_group_count_x;
  uint32_t thread_group_count_y;
  uint32_t thread_group_count_z;
};

using IndirectCountType = uint32_t;

constexpr uint64_t eAccelerationStructureAlignment = 256;

enum class QueryHeapType { eAccelerationStructureCompactedSize };

} // namespace rook::gpu

#define ROOK_GPU_ENABLE_BITMASK_OPERATORS(x)                                   \
  template <> struct EnableBitMaskOperators<x> {                               \
    static const bool enable = true;                                           \
  };

template <typename E> struct EnableBitMaskOperators {
  static const bool enable = false;
};

template <typename E>
inline auto operator|(E lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> {
  return static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) |
                        static_cast<std::underlying_type_t<E>>(rhs));
}

template <typename E>
inline auto operator&(E lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> {
  return static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) &
                        static_cast<std::underlying_type_t<E>>(rhs));
}

template <typename E>
inline auto operator^(E lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> {
  return static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) ^
                        static_cast<std::underlying_type_t<E>>(rhs));
}

template <typename E>
inline auto operator~(E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> {
  return static_cast<E>(~static_cast<std::underlying_type_t<E>>(rhs));
}

template <typename E>
inline auto operator|=(E &lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> & {
  lhs = static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) |
                       static_cast<std::underlying_type_t<E>>(rhs));
  return lhs;
}

template <typename E>
inline auto operator&=(E &lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> & {
  lhs = static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) &
                       static_cast<std::underlying_type_t<E>>(rhs));
  return lhs;
}

template <typename E>
inline auto operator^=(E &lhs, E rhs)
    -> std::enable_if_t<EnableBitMaskOperators<E>::enable, E> & {
  lhs = static_cast<E>(static_cast<std::underlying_type_t<E>>(lhs) ^
                       static_cast<std::underlying_type_t<E>>(rhs));
  return lhs;
}

ROOK_GPU_ENABLE_BITMASK_OPERATORS(rook::gpu::ResourceState);
ROOK_GPU_ENABLE_BITMASK_OPERATORS(rook::gpu::BuildAccelerationStructureFlags);