#pragma once

#include <utility>

#include "moon/base.h"
#include "moon/math.h"

namespace moon::gpu {
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

enum class ResourceState : u32 {
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
  i32 depth_bias = 0;

  [[nodiscard]] auto tied() const {
    return zinc::tie(fill_mode, cull_mode, depth_bias);
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
    return zinc::tie(blend_enable, blend_src, blend_dest, blend_op,
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
    return zinc::tie(fail_op, depth_fail_op, pass_op, func);
  }
};

struct DepthStencilDescriptor {
  bool depth_test_enable = true;
  ComparisonFunc depth_func = ComparisonFunc::eLess;
  bool depth_write_enable = true;
  bool depth_bounds_test_enable = false;
  bool stencil_enable = false;
  u8 stencil_read_mask = 0xff;
  u8 stencil_write_mask = 0xff;
  StencilOperationDescriptor front_face = {};
  StencilOperationDescriptor back_face = {};

  [[nodiscard]] auto tied() const {
    return zinc::tie(depth_test_enable, depth_func, depth_write_enable,
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
  u32 base_mip_level = 0;
  u32 level_count = static_cast<u32>(-1);
  u32 base_array_layer = 0;
  u32 layer_count = static_cast<u32>(-1);
  u32 plane_slice = 0;
  u64 offset = 0;
  u32 structure_stride = 0;
  u64 buffer_size = static_cast<u64>(-1);
  Format buffer_format = Format::UNDEFINED;
  bool bindless = false;

  [[nodiscard]] auto tied() const {
    return zinc::tie(view_type, dimension, base_mip_level, level_count,
                     base_array_layer, layer_count, plane_slice, offset,
                     structure_stride, buffer_size,
                     /*buffer_format,*/ bindless);
  }
};

struct ShaderDescriptor {
  zinc::vector<u8> shader_data;
  zinc::string entrypoint;
  ShaderType type;
  zinc::string model;
  // std::map<zinc::string, zinc::string> define;

  ShaderDescriptor(zinc::vector<u8> shader_data, zinc::string entrypoint,
                   ShaderType type, zinc::string model)
      : shader_data(std::move(shader_data)), entrypoint(std::move(entrypoint)),
        type(type), model(std::move(model)) {}
};

struct InputLayoutDesc {
  u32 slot = 0;
  zinc::string semantic_name;
  Format format = Format::UNDEFINED;
  u32 stride = 0;

  [[nodiscard]] auto tied() const {
    return zinc::tie(slot, semantic_name, format, stride);
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
    return zinc::tie(format, load_op, store_op);
  }
};

struct RenderPassDepthStencilDescriptor {
  Format format = Format::UNDEFINED;
  RenderPassLoadOperation depth_load_op = RenderPassLoadOperation::eLoad;
  RenderPassStoreOperation depth_store_op = RenderPassStoreOperation::eStore;
  RenderPassLoadOperation stencil_load_op = RenderPassLoadOperation::eLoad;
  RenderPassStoreOperation stencil_store_op = RenderPassStoreOperation::eStore;

  [[nodiscard]] auto tied() const {
    return zinc::tie(format, depth_load_op, depth_store_op, stencil_load_op,
                     stencil_store_op);
  }
};

struct RenderPassDescriptor {
  zinc::vector<RenderPassColorDescriptor> colors;
  RenderPassDepthStencilDescriptor depth_stencil;
  Format shading_rate_format = Format::UNDEFINED;
  u32 sample_count = 1;

  [[nodiscard]] auto tied() const {
    return zinc::tie(colors, depth_stencil, shading_rate_format, sample_count);
  }
};

struct FramebufferDescriptor {
  zinc::shared<RenderPass> render_pass;
  u32 width;
  u32 height;
  zinc::vector<zinc::shared<View>> colors;
  zinc::shared<View> depth_stencil;
  zinc::shared<View> shading_rate_image;

  [[nodiscard]] auto tied() const {
    return zinc::tie(render_pass, width, height, colors, depth_stencil,
                     shading_rate_image);
  }
};

struct GraphicsPipelineDescriptor {
  zinc::shared<Program> program;
  zinc::shared<BindingSetLayout> layout;
  zinc::vector<InputLayoutDesc> input;
  zinc::shared<RenderPass> render_pass;
  DepthStencilDescriptor depth_stencil_desc;
  BlendDescriptor blend_desc;
  RasterizerDescriptor rasterizer_desc;

  [[nodiscard]] auto tied() const {
    return zinc::tie(program, layout, input, render_pass, depth_stencil_desc,
                     blend_desc, rasterizer_desc);
  }
};

struct ComputePipelineDescriptor {
  zinc::shared<Program> program;
  zinc::shared<BindingSetLayout> layout;

  [[nodiscard]] auto tied() const { return zinc::tie(program, layout); }
};

enum class RayTracingShaderGroupType {
  eGeneral,
  eTrianglesHitGroup,
  eProceduralHitGroup,
};

struct RayTracingShaderGroup {
  RayTracingShaderGroupType type = RayTracingShaderGroupType::eGeneral;
  u64 general = 0;
  u64 closest_hit = 0;
  u64 any_hit = 0;
  u64 intersection = 0;

  [[nodiscard]] auto tied() const {
    return zinc::tie(type, general, closest_hit, any_hit, intersection);
  }
};

struct RayTracingPipelineDescriptor {
  zinc::shared<Program> program;
  zinc::shared<BindingSetLayout> layout;
  zinc::vector<RayTracingShaderGroup> groups;

  [[nodiscard]] auto tied() const { return zinc::tie(program, layout, groups); }
};

struct RayTracingShaderTable {
  zinc::shared<Resource> resource;
  u64 offset;
  u64 size;
  u64 stride;
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
  u32 slot = 0;
  u32 space = 0;
  u32 count = 1;

  [[nodiscard]] auto tied() const {
    return zinc::tie(shader_type, view_type, slot, space, count);
  }
};

struct BindingDescriptor {
  BindKey bind_key;
  zinc::shared<View> view;

  [[nodiscard]] auto tied() const { return zinc::tie(bind_key, view); }
};

enum class ReturnType {
  eUnknown,
  eFloat,
  eUint,
  eInt,
  eDouble,
};

struct ResourceBindingDescriptor {
  zinc::string name;
  ViewType type;
  u32 slot;
  u32 space;
  u32 count;
  ViewDimension dimension;
  ReturnType return_type;
  u32 structure_stride;
};

enum class PipelineType {
  eGraphics,
  eCompute,
  eRayTracing,
};

struct BufferDescriptor {
  zinc::shared<Resource> res;
  Format format = Format::UNDEFINED;
  u32 count = 0;
  u32 offset = 0;
};

enum class RaytracingInstanceFlags : u32 {
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
  i32 x;
  i32 y;
  i32 z;
};

struct TextureExtent3D {
  u32 width;
  u32 height;
  u32 depth;
};

struct BufferToTextureCopyRegion {
  u64 buffer_offset;
  u32 buffer_row_pitch;
  u32 texture_mip_level;
  u32 texture_array_layer;
  TextureOffset texture_offset;
  TextureExtent3D texture_extent;
};

struct TextureCopyRegion {
  TextureExtent3D extent;
  u32 src_mip_level;
  u32 src_array_layer;
  TextureOffset src_offset;
  u32 dst_mip_level;
  u32 dst_array_layer;
  TextureOffset dst_offset;
};

struct BufferCopyRegion {
  u64 src_offset;
  u64 dst_offset;
  u64 num_bytes;
};

struct RaytracingGeometryInstance {
  math::mat3x4 transform;
  u32 instance_id : 24;
  u32 instance_mask : 8;
  u32 instance_offset : 24;
  RaytracingInstanceFlags flags : 8;
  u64 acceleration_structure_handle;
};

static_assert(sizeof(RaytracingGeometryInstance) == 64);

struct ResourceBarrierDescriptor {
  zinc::shared<Resource> resource;
  ResourceState state_before;
  ResourceState state_after;
  u32 base_mip_level = 0;
  u32 level_count = 1;
  u32 base_array_layer = 0;
  u32 layer_count = 1;
};

enum class ShadingRate : u8 {
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
  u64 acceleration_structure_size = 0;
  u64 build_scratch_data_size = 0;
  u64 update_scratch_data_size = 0;
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
  zinc::vector<math::fvec4> colors;
  float depth = 1.0f;
  u8 stencil = 0;
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
  u32 vertex_count;
  u32 instance_count;
  u32 first_vertex;
  u32 first_instance;
};

struct DrawIndexedIndirectCommand {
  u32 index_count;
  u32 instance_count;
  u32 first_index;
  i32 vertex_offset;
  u32 first_instance;
};

struct DispatchIndirectCommand {
  u32 thread_group_count_x;
  u32 thread_group_count_y;
  u32 thread_group_count_z;
};

} // namespace moon::gpu

ZINC_ENABLE_BITMASK_OPERATORS(moon::gpu::ResourceState);
ZINC_ENABLE_BITMASK_OPERATORS(moon::gpu::BuildAccelerationStructureFlags);