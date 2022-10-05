#pragma once

#include "moon/base.h"

namespace moon::gpu {
u32 ARRAY_LAYER_COUNT_UNDEFINED = (0xffffffffUL);
u32 COPY_STRIDE_UNDEFINED = (0xffffffffUL);
u32 LIMIT_U32_UNDEFINED = (0xffffffffUL);
u64 LIMIT_U64_UNDEFINED = (0xffffffffffffffffULL);
u32 MIP_LEVEL_COUNT_UNDEFINED = (0xffffffffUL);
u64 WHOLE_MAP_SIZE = SIZE_MAX;
u64 WHOLE_SIZE = (0xffffffffffffffffULL);

using Flags = u32;

// Forward

using Adapter = struct AdapterImpl *;
using BindGroup = struct BindGroupImpl *;
using BindGroupLayout = struct BindGroupLayoutImpl *;
using Buffer = struct BufferImpl *;
using CommandBuffer = struct CommandBufferImpl *;
using CommandEncoder = struct CommandEncoderImpl *;
using ComputePassEncoder = struct ComputePassEncoderImpl *;
using ComputePipeline = struct ComputePipelineImpl *;
using Device = struct DeviceImpl *;
using Instance = struct InstanceImpl *;
using PipelineLayout = struct PipelineLayoutImpl *;
using QuerySet = struct QuerySetImpl *;
using Queue = struct QueueImpl *;
using RenderBundle = struct RenderBundleImpl *;
using RenderBundleEncoder = struct RenderBundleEncoderImpl *;
using RenderPassEncoder = struct RenderPassEncoderImpl *;
using RenderPipeline = struct RenderPipelineImpl *;
using Sampler = struct SamplerImpl *;
using ShaderModule = struct ShaderModuleImpl *;
using Surface = struct SurfaceImpl *;
using SwapChain = struct SwapChainImpl *;
using Texture = struct TextureImpl *;
using TextureView = struct TextureViewImpl *;

// enums

enum struct AdapterType {
  DiscreteGPU = 0x00000000,
  IntegratedGPU = 0x00000001,
  CPU = 0x00000002,
  Unknown = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct AddressMode {
  Repeat = 0x00000000,
  MirrorRepeat = 0x00000001,
  ClampToEdge = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct BackendType {
  Null = 0x00000000,
  WebGPU = 0x00000001,
  D3D11 = 0x00000002,
  D3D12 = 0x00000003,
  Metal = 0x00000004,
  Vulkan = 0x00000005,
  OpenGL = 0x00000006,
  OpenGLES = 0x00000007,
  Force32 = 0x7FFFFFFF
};

enum struct BlendFactor {
  Zero = 0x00000000,
  One = 0x00000001,
  Src = 0x00000002,
  OneMinusSrc = 0x00000003,
  SrcAlpha = 0x00000004,
  OneMinusSrcAlpha = 0x00000005,
  Dst = 0x00000006,
  OneMinusDst = 0x00000007,
  DstAlpha = 0x00000008,
  OneMinusDstAlpha = 0x00000009,
  SrcAlphaSaturated = 0x0000000A,
  Constant = 0x0000000B,
  OneMinusConstant = 0x0000000C,
  Force32 = 0x7FFFFFFF
};

enum struct BlendOperation {
  Add = 0x00000000,
  Subtract = 0x00000001,
  ReverseSubtract = 0x00000002,
  Min = 0x00000003,
  Max = 0x00000004,
  Force32 = 0x7FFFFFFF
};

enum struct BufferBindingType {
  Undefined = 0x00000000,
  Uniform = 0x00000001,
  Storage = 0x00000002,
  ReadOnlyStorage = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct BufferMapAsyncStatus {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
  DeviceLost = 0x00000003,
  DestroyedBeforeCallback = 0x00000004,
  UnmappedBeforeCallback = 0x00000005,
  Force32 = 0x7FFFFFFF
};

enum struct CompareFunction {
  Undefined = 0x00000000,
  Never = 0x00000001,
  Less = 0x00000002,
  LessEqual = 0x00000003,
  Greater = 0x00000004,
  GreaterEqual = 0x00000005,
  Equal = 0x00000006,
  NotEqual = 0x00000007,
  Always = 0x00000008,
  Force32 = 0x7FFFFFFF
};

enum struct CompilationInfoRequestStatus {
  Success = 0x00000000,
  Error = 0x00000001,
  DeviceLost = 0x00000002,
  Unknown = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct CompilationMessageType {
  Error = 0x00000000,
  Warning = 0x00000001,
  Info = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct ComputePassTimestampLocation {
  Beginning = 0x00000000,
  End = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct CreatePipelineAsyncStatus {
  Success = 0x00000000,
  Error = 0x00000001,
  DeviceLost = 0x00000002,
  DeviceDestroyed = 0x00000003,
  Unknown = 0x00000004,
  Force32 = 0x7FFFFFFF
};

enum struct CullMode {
  None = 0x00000000,
  Front = 0x00000001,
  Back = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct DeviceLostReason {
  Undefined = 0x00000000,
  Destroyed = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct ErrorFilter {
  Validation = 0x00000000,
  OutOfMemory = 0x00000001,
  Internal = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct ErrorType {
  NoError = 0x00000000,
  Validation = 0x00000001,
  OutOfMemory = 0x00000002,
  Internal = 0x00000003,
  Unknown = 0x00000004,
  DeviceLost = 0x00000005,
  Force32 = 0x7FFFFFFF
};

enum struct FeatureName {
  Undefined = 0x00000000,
  DepthClipControl = 0x00000001,
  Depth32FloatStencil8 = 0x00000002,
  TimestampQuery = 0x00000003,
  PipelineStatisticsQuery = 0x00000004,
  TextureCompressionBC = 0x00000005,
  TextureCompressionETC2 = 0x00000006,
  TextureCompressionASTC = 0x00000007,
  IndirectFirstInstance = 0x00000008,
  ShaderF16 = 0x00000009,
  RG11B10UfloatRenderable = 0x0000000A,
  Force32 = 0x7FFFFFFF
};

enum struct FilterMode {
  Nearest = 0x00000000,
  Linear = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct FrontFace {
  CCW = 0x00000000,
  CW = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct IndexFormat {
  Undefined = 0x00000000,
  Uint16 = 0x00000001,
  Uint32 = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct LoadOp {
  Undefined = 0x00000000,
  Clear = 0x00000001,
  Load = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct MipmapFilterMode {
  Nearest = 0x00000000,
  Linear = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct PipelineStatisticName {
  VertexShaderInvocations = 0x00000000,
  ClipperInvocations = 0x00000001,
  ClipperPrimitivesOut = 0x00000002,
  FragmentShaderInvocations = 0x00000003,
  ComputeShaderInvocations = 0x00000004,
  Force32 = 0x7FFFFFFF
};

enum struct PowerPreference {
  Undefined = 0x00000000,
  LowPower = 0x00000001,
  HighPerformance = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct PresentMode {
  Immediate = 0x00000000,
  Mailbox = 0x00000001,
  Fifo = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct PrimitiveTopology {
  PointList = 0x00000000,
  LineList = 0x00000001,
  LineStrip = 0x00000002,
  TriangleList = 0x00000003,
  TriangleStrip = 0x00000004,
  Force32 = 0x7FFFFFFF
};

enum struct QueryType {
  Occlusion = 0x00000000,
  PipelineStatistics = 0x00000001,
  Timestamp = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct QueueWorkDoneStatus {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
  DeviceLost = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct RenderPassTimestampLocation {
  Beginning = 0x00000000,
  End = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct RequestAdapterStatus {
  Success = 0x00000000,
  Unavailable = 0x00000001,
  Error = 0x00000002,
  Unknown = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct RequestDeviceStatus {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct s_type {
  Invalid = 0x00000000,
  SurfaceDescriptorFromMetalLayer = 0x00000001,
  SurfaceDescriptorFromWindowsHWND = 0x00000002,
  SurfaceDescriptorFromXlibWindow = 0x00000003,
  SurfaceDescriptorFromCanvasHTMLSelector = 0x00000004,
  ShaderModuleSPIRVDescriptor = 0x00000005,
  ShaderModuleWGSLDescriptor = 0x00000006,
  PrimitiveDepthClipControl = 0x00000007,
  SurfaceDescriptorFromWaylandSurface = 0x00000008,
  SurfaceDescriptorFromAndroidNativeWindow = 0x00000009,
  SurfaceDescriptorFromXcbWindow = 0x0000000A,
  RenderPassDescriptorMaxDrawCount = 0x0000000F,
  Force32 = 0x7FFFFFFF
};

enum struct SamplerBindingType {
  Undefined = 0x00000000,
  Filtering = 0x00000001,
  NonFiltering = 0x00000002,
  Comparison = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct StencilOperation {
  Keep = 0x00000000,
  Zero = 0x00000001,
  Replace = 0x00000002,
  Invert = 0x00000003,
  IncrementClamp = 0x00000004,
  DecrementClamp = 0x00000005,
  IncrementWrap = 0x00000006,
  DecrementWrap = 0x00000007,
  Force32 = 0x7FFFFFFF
};

enum struct StorageTextureAccess {
  Undefined = 0x00000000,
  WriteOnly = 0x00000001,
  Force32 = 0x7FFFFFFF
};

enum struct StoreOp {
  Undefined = 0x00000000,
  Store = 0x00000001,
  Discard = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct TextureAspect {
  All = 0x00000000,
  StencilOnly = 0x00000001,
  DepthOnly = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct TextureComponentType {
  Float = 0x00000000,
  Sint = 0x00000001,
  Uint = 0x00000002,
  DepthComparison = 0x00000003,
  Force32 = 0x7FFFFFFF
};

enum struct TextureDimension {
  _1D = 0x00000000,
  _2D = 0x00000001,
  _3D = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct TextureFormat {
  Undefined = 0x00000000,
  R8Unorm = 0x00000001,
  R8Snorm = 0x00000002,
  R8Uint = 0x00000003,
  R8Sint = 0x00000004,
  R16Uint = 0x00000005,
  R16Sint = 0x00000006,
  R16Float = 0x00000007,
  RG8Unorm = 0x00000008,
  RG8Snorm = 0x00000009,
  RG8Uint = 0x0000000A,
  RG8Sint = 0x0000000B,
  R32Float = 0x0000000C,
  R32Uint = 0x0000000D,
  R32Sint = 0x0000000E,
  RG16Uint = 0x0000000F,
  RG16Sint = 0x00000010,
  RG16Float = 0x00000011,
  RGBA8Unorm = 0x00000012,
  RGBA8UnormSrgb = 0x00000013,
  RGBA8Snorm = 0x00000014,
  RGBA8Uint = 0x00000015,
  RGBA8Sint = 0x00000016,
  BGRA8Unorm = 0x00000017,
  BGRA8UnormSrgb = 0x00000018,
  RGB10A2Unorm = 0x00000019,
  RG11B10Ufloat = 0x0000001A,
  RGB9E5Ufloat = 0x0000001B,
  RG32Float = 0x0000001C,
  RG32Uint = 0x0000001D,
  RG32Sint = 0x0000001E,
  RGBA16Uint = 0x0000001F,
  RGBA16Sint = 0x00000020,
  RGBA16Float = 0x00000021,
  RGBA32Float = 0x00000022,
  RGBA32Uint = 0x00000023,
  RGBA32Sint = 0x00000024,
  Stencil8 = 0x00000025,
  Depth16Unorm = 0x00000026,
  Depth24Plus = 0x00000027,
  Depth24PlusStencil8 = 0x00000028,
  Depth32Float = 0x00000029,
  Depth32FloatStencil8 = 0x0000002A,
  BC1RGBAUnorm = 0x0000002B,
  BC1RGBAUnormSrgb = 0x0000002C,
  BC2RGBAUnorm = 0x0000002D,
  BC2RGBAUnormSrgb = 0x0000002E,
  BC3RGBAUnorm = 0x0000002F,
  BC3RGBAUnormSrgb = 0x00000030,
  BC4RUnorm = 0x00000031,
  BC4RSnorm = 0x00000032,
  BC5RGUnorm = 0x00000033,
  BC5RGSnorm = 0x00000034,
  BC6HRGBUfloat = 0x00000035,
  BC6HRGBFloat = 0x00000036,
  BC7RGBAUnorm = 0x00000037,
  BC7RGBAUnormSrgb = 0x00000038,
  ETC2RGB8Unorm = 0x00000039,
  ETC2RGB8UnormSrgb = 0x0000003A,
  ETC2RGB8A1Unorm = 0x0000003B,
  ETC2RGB8A1UnormSrgb = 0x0000003C,
  ETC2RGBA8Unorm = 0x0000003D,
  ETC2RGBA8UnormSrgb = 0x0000003E,
  EACR11Unorm = 0x0000003F,
  EACR11Snorm = 0x00000040,
  EACRG11Unorm = 0x00000041,
  EACRG11Snorm = 0x00000042,
  ASTC4x4Unorm = 0x00000043,
  ASTC4x4UnormSrgb = 0x00000044,
  ASTC5x4Unorm = 0x00000045,
  ASTC5x4UnormSrgb = 0x00000046,
  ASTC5x5Unorm = 0x00000047,
  ASTC5x5UnormSrgb = 0x00000048,
  ASTC6x5Unorm = 0x00000049,
  ASTC6x5UnormSrgb = 0x0000004A,
  ASTC6x6Unorm = 0x0000004B,
  ASTC6x6UnormSrgb = 0x0000004C,
  ASTC8x5Unorm = 0x0000004D,
  ASTC8x5UnormSrgb = 0x0000004E,
  ASTC8x6Unorm = 0x0000004F,
  ASTC8x6UnormSrgb = 0x00000050,
  ASTC8x8Unorm = 0x00000051,
  ASTC8x8UnormSrgb = 0x00000052,
  ASTC10x5Unorm = 0x00000053,
  ASTC10x5UnormSrgb = 0x00000054,
  ASTC10x6Unorm = 0x00000055,
  ASTC10x6UnormSrgb = 0x00000056,
  ASTC10x8Unorm = 0x00000057,
  ASTC10x8UnormSrgb = 0x00000058,
  ASTC10x10Unorm = 0x00000059,
  ASTC10x10UnormSrgb = 0x0000005A,
  ASTC12x10Unorm = 0x0000005B,
  ASTC12x10UnormSrgb = 0x0000005C,
  ASTC12x12Unorm = 0x0000005D,
  ASTC12x12UnormSrgb = 0x0000005E,
  Force32 = 0x7FFFFFFF
};

enum struct TextureSampleType {
  Undefined = 0x00000000,
  Float = 0x00000001,
  UnfilterableFloat = 0x00000002,
  Depth = 0x00000003,
  Sint = 0x00000004,
  Uint = 0x00000005,
  Force32 = 0x7FFFFFFF
};

enum struct TextureViewDimension {
  Undefined = 0x00000000,
  _1D = 0x00000001,
  _2D = 0x00000002,
  _2DArray = 0x00000003,
  Cube = 0x00000004,
  CubeArray = 0x00000005,
  _3D = 0x00000006,
  Force32 = 0x7FFFFFFF
};

enum struct VertexFormat {
  Undefined = 0x00000000,
  Uint8x2 = 0x00000001,
  Uint8x4 = 0x00000002,
  Sint8x2 = 0x00000003,
  Sint8x4 = 0x00000004,
  Unorm8x2 = 0x00000005,
  Unorm8x4 = 0x00000006,
  Snorm8x2 = 0x00000007,
  Snorm8x4 = 0x00000008,
  Uint16x2 = 0x00000009,
  Uint16x4 = 0x0000000A,
  Sint16x2 = 0x0000000B,
  Sint16x4 = 0x0000000C,
  Unorm16x2 = 0x0000000D,
  Unorm16x4 = 0x0000000E,
  Snorm16x2 = 0x0000000F,
  Snorm16x4 = 0x00000010,
  Float16x2 = 0x00000011,
  Float16x4 = 0x00000012,
  Float32 = 0x00000013,
  Float32x2 = 0x00000014,
  Float32x3 = 0x00000015,
  Float32x4 = 0x00000016,
  Uint32 = 0x00000017,
  Uint32x2 = 0x00000018,
  Uint32x3 = 0x00000019,
  Uint32x4 = 0x0000001A,
  Sint32 = 0x0000001B,
  Sint32x2 = 0x0000001C,
  Sint32x3 = 0x0000001D,
  Sint32x4 = 0x0000001E,
  Force32 = 0x7FFFFFFF
};

enum struct VertexStepMode {
  Vertex = 0x00000000,
  Instance = 0x00000001,
  VertexBufferNotUsed = 0x00000002,
  Force32 = 0x7FFFFFFF
};

enum struct BufferUsage {
  None = 0x00000000,
  MapRead = 0x00000001,
  MapWrite = 0x00000002,
  CopySrc = 0x00000004,
  CopyDst = 0x00000008,
  Index = 0x00000010,
  Vertex = 0x00000020,
  Uniform = 0x00000040,
  Storage = 0x00000080,
  Indirect = 0x00000100,
  QueryResolve = 0x00000200,
  Force32 = 0x7FFFFFFF
};
using BufferUsageFlags = Flags;

enum struct ColorWriteMask {
  None = 0x00000000,
  Red = 0x00000001,
  Green = 0x00000002,
  Blue = 0x00000004,
  Alpha = 0x00000008,
  All = 0x0000000F,
  Force32 = 0x7FFFFFFF
};
using ColorWriteMaskFlags = Flags;

enum struct MapMode {
  None = 0x00000000,
  Read = 0x00000001,
  Write = 0x00000002,
  Force32 = 0x7FFFFFFF
};
using MapModeFlags = Flags;

enum struct ShaderStage {
  None = 0x00000000,
  Vertex = 0x00000001,
  Fragment = 0x00000002,
  Compute = 0x00000004,
  Force32 = 0x7FFFFFFF
};
using ShaderStageFlags = Flags;

enum struct TextureUsage {
  None = 0x00000000,
  CopySrc = 0x00000001,
  CopyDst = 0x00000002,
  TextureBinding = 0x00000004,
  StorageBinding = 0x00000008,
  RenderAttachment = 0x00000010,
  Force32 = 0x7FFFFFFF
};
using TextureUsageFlags = Flags;

// structures
struct ChainedStruct {
  struct ChainedStruct const *next;
  s_type s_type;
};

struct ChainedStructOut {
  struct ChainedStructOut *next;
  s_type s_type;
};

struct AdapterProperties {
  ChainedStructOut *next_in_chain;
  u32 vendor_id;
  zinc::string_view vendor_name;
  zinc::string_view architecture;
  u32 device_id;
  zinc::string_view name;
  zinc::string_view driver_description;
  AdapterType adapter_type;
  BackendType backend_type;
};

struct BindGroupEntry {
  ChainedStruct const *next_in_chain;
  u32 binding;
  Buffer buffer; // nullable
  u64 offset;
  u64 size;
  Sampler sampler;          // nullable
  TextureView texture_view; // nullable
};

struct BlendComponent {
  BlendOperation operation;
  BlendFactor src_factor;
  BlendFactor dst_factor;
};

struct BufferBindingLayout {
  ChainedStruct const *next_in_chain;
  BufferBindingType type;
  bool has_dynamic_offset;
  u64 min_binding_size;
};

struct BufferDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  BufferUsageFlags usage;
  u64 size;
  bool mapped_at_creation;
};

struct Color {
  double r;
  double g;
  double b;
  double a;
};

struct CommandBufferDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
};

struct CommandEncoderDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
};

struct CompilationMessage {
  ChainedStruct const *next_in_chain;
  zinc::string_view message; // nullable
  CompilationMessageType type;
  u64 line_num;
  u64 line_pos;
  u64 offset;
  u64 length;
};

struct ComputePassTimestampWrite {
  QuerySet query_set;
  u32 query_index;
  ComputePassTimestampLocation location;
};

struct ConstantEntry {
  ChainedStruct const *next_in_chain;
  zinc::string_view key;
  double value;
};

struct Extent3D {
  u32 width;
  u32 height;
  u32 depth_or_array_layers;
};

struct InstanceDescriptor {
  ChainedStruct const *next_in_chain;
};

struct Limits {
  u32 max_texture_dimension_1d;
  u32 max_texture_dimension_2d;
  u32 max_texture_dimension3_d;
  u32 max_texture_array_layers;
  u32 max_bind_groups;
  u32 max_bindings_per_bind_group;
  u32 max_dynamic_uniform_buffers_per_pipeline_layout;
  u32 max_dynamic_storage_buffers_per_pipeline_layout;
  u32 max_sampled_textures_per_shader_stage;
  u32 max_samplers_per_shader_stage;
  u32 max_storage_buffers_per_shader_stage;
  u32 max_storage_textures_per_shader_stage;
  u32 max_uniform_buffers_per_shader_stage;
  u64 max_uniform_buffer_binding_size;
  u64 max_storage_buffer_binding_size;
  u32 min_uniform_buffer_offset_alignment;
  u32 min_storage_buffer_offset_alignment;
  u32 max_vertex_buffers;
  u64 max_buffer_size;
  u32 max_vertex_attributes;
  u32 max_vertex_buffer_array_stride;
  u32 max_inter_stage_shader_components;
  u32 max_inter_stage_shader_variables;
  u32 max_color_attachments;
  u32 max_compute_workgroup_storage_size;
  u32 max_compute_invocations_per_workgroup;
  u32 max_compute_workgroup_size_x;
  u32 max_compute_workgroup_size_y;
  u32 max_compute_workgroup_size_z;
  u32 max_compute_workgroups_per_dimension;
};

struct MultisampleState {
  ChainedStruct const *next_in_chain;
  u32 count;
  u32 mask;
  bool alpha_to_coverage_enabled;
};

struct Origin3D {
  u32 x;
  u32 y;
  u32 z;
};

struct PipelineLayoutDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 bind_group_layout_count;
  zinc::array_view<BindGroupLayout> bind_group_layouts;
};

// Can be chained in PrimitiveState
struct PrimitiveDepthClipControl {
  ChainedStruct chain;
  bool unclipped_depth;
};

struct PrimitiveState {
  ChainedStruct const *next_in_chain;
  PrimitiveTopology topology;
  IndexFormat strip_index_format;
  FrontFace front_face;
  CullMode cull_mode;
};

struct QuerySetDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  QueryType type;
  u32 count;
  zinc::array_view<PipelineStatisticName> pipeline_statistics;
  u32 pipeline_statistics_count;
};

struct QueueDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
};

struct RenderBundleDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
};

struct RenderBundleEncoderDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 color_formats_count;
  zinc::array_view<TextureFormat> color_formats;
  TextureFormat depth_stencil_format;
  u32 sample_count;
  bool depth_read_only;
  bool stencil_read_only;
};

struct RenderPassDepthStencilAttachment {
  TextureView view;
  LoadOp depth_load_op;
  StoreOp depth_store_op;
  float depth_clear_value;
  bool depth_read_only;
  LoadOp stencil_load_op;
  StoreOp stencil_store_op;
  u32 stencil_clear_value;
  bool stencil_read_only;
};

// Can be chained in RenderPassDescriptor
struct RenderPassDescriptorMaxDrawCount {
  ChainedStruct chain;
  u64 max_draw_count;
};

struct RenderPassTimestampWrite {
  QuerySet query_set;
  u32 query_index;
  RenderPassTimestampLocation location;
};

struct RequestAdapterOptions {
  ChainedStruct const *next_in_chain;
  Surface compatible_surface; // nullable
  PowerPreference power_preference;
  bool force_fallback_adapter;
};

struct SamplerBindingLayout {
  ChainedStruct const *next_in_chain;
  SamplerBindingType type;
};

struct SamplerDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  AddressMode address_mode_u;
  AddressMode address_mode_v;
  AddressMode address_mode_w;
  FilterMode mag_filter;
  FilterMode min_filter;
  MipmapFilterMode mipmap_filter;
  float lod_min_clamp;
  float lod_max_clamp;
  CompareFunction compare;
  u16 max_anisotropy;
};

struct ShaderModuleCompilationHint {
  ChainedStruct const *next_in_chain;
  zinc::string_view entry_point;
  PipelineLayout layout;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleSPIRVDescriptor {
  ChainedStruct chain;
  u32 code_size;
  u32 const *code;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleWGSLDescriptor {
  ChainedStruct chain;
  zinc::string_view code;
};

struct StencilFaceState {
  CompareFunction compare;
  StencilOperation fail_op;
  StencilOperation depth_fail_op;
  StencilOperation pass_op;
};

struct StorageTextureBindingLayout {
  ChainedStruct const *next_in_chain;
  StorageTextureAccess access;
  TextureFormat format;
  TextureViewDimension view_dimension;
};

struct SurfaceDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromAndroidNativeWindow {
  ChainedStruct chain;
  vptr window;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromCanvasHTMLSelector {
  ChainedStruct chain;
  zinc::string_view selector;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromMetalLayer {
  ChainedStruct chain;
  vptr layer;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWaylandSurface {
  ChainedStruct chain;
  vptr display;
  vptr surface;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsHWND {
  ChainedStruct chain;
  vptr hinstance;
  vptr hwnd;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromXcbWindow {
  ChainedStruct chain;
  vptr connection;
  u32 window;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromXlibWindow {
  ChainedStruct chain;
  vptr display;
  u32 window;
};

struct SwapChainDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  TextureUsageFlags usage;
  TextureFormat format;
  u32 width;
  u32 height;
  PresentMode present_mode;
};

struct TextureBindingLayout {
  ChainedStruct const *next_in_chain;
  TextureSampleType sample_type;
  TextureViewDimension view_dimension;
  bool multisampled;
};

struct TextureDataLayout {
  ChainedStruct const *next_in_chain;
  u64 offset;
  u32 bytes_per_row;
  u32 rows_per_image;
};

struct TextureViewDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  TextureFormat format;
  TextureViewDimension dimension;
  u32 base_mip_level;
  u32 mip_level_count;
  u32 base_array_layer;
  u32 array_layer_count;
  TextureAspect aspect;
};

struct VertexAttribute {
  VertexFormat format;
  u64 offset;
  u32 shader_location;
};

struct BindGroupDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  BindGroupLayout layout;
  u32 entry_count;
  zinc::array_view<BindGroupEntry> entries;
};

struct BindGroupLayoutEntry {
  ChainedStruct const *next_in_chain;
  u32 binding;
  ShaderStageFlags visibility;
  BufferBindingLayout buffer;
  SamplerBindingLayout sampler;
  TextureBindingLayout texture;
  StorageTextureBindingLayout storage_texture;
};

struct BlendState {
  BlendComponent color;
  BlendComponent alpha;
};

struct CompilationInfo {
  ChainedStruct const *next_in_chain;
  u32 message_count;
  zinc::array_view<CompilationMessage> messages;
};

struct ComputePassDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 timestamp_write_count;
  zinc::array_view<ComputePassTimestampWrite> timestamp_writes;
};

struct DepthStencilState {
  ChainedStruct const *next_in_chain;
  TextureFormat format;
  bool depth_write_enabled;
  CompareFunction depth_compare;
  StencilFaceState stencil_front;
  StencilFaceState stencil_back;
  u32 stencil_read_mask;
  u32 stencil_write_mask;
  i32 depth_bias;
  float depth_bias_slope_scale;
  float depth_bias_clamp;
};

struct ImageCopyBuffer {
  ChainedStruct const *next_in_chain;
  TextureDataLayout layout;
  Buffer buffer;
};

struct ImageCopyTexture {
  ChainedStruct const *next_in_chain;
  Texture texture;
  u32 mip_level;
  Origin3D origin;
  TextureAspect aspect;
};

struct ProgrammableStageDescriptor {
  ChainedStruct const *next_in_chain;
  ShaderModule module;
  zinc::string_view entry_point;
  u32 constant_count;
  zinc::array_view<ConstantEntry> constants;
};

struct RenderPassColorAttachment {
  TextureView view;           // nullable
  TextureView resolve_target; // nullable
  LoadOp load_op;
  StoreOp store_op;
  Color clear_value;
};

struct RequiredLimits {
  ChainedStruct const *next_in_chain;
  Limits limits;
};

struct ShaderModuleDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 hint_count;
  zinc::array_view<ShaderModuleCompilationHint> hints;
};

struct SupportedLimits {
  ChainedStructOut *next_in_chain;
  Limits limits;
};

struct TextureDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  TextureUsageFlags usage;
  TextureDimension dimension;
  Extent3D size;
  TextureFormat format;
  u32 mip_level_count;
  u32 sample_count;
  u32 view_format_count;
  zinc::array_view<TextureFormat> view_formats;
};

struct VertexBufferLayout {
  u64 array_stride;
  VertexStepMode step_mode;
  u32 attribute_count;
  zinc::array_view<VertexAttribute> attributes;
};

struct BindGroupLayoutDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 entry_count;
  zinc::array_view<BindGroupLayoutEntry> entries;
};

struct ColorTargetState {
  ChainedStruct const *next_in_chain;
  TextureFormat format;
  zinc::array_view<BlendState> blend; // nullable
  ColorWriteMaskFlags write_mask;
};

struct ComputePipelineDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  PipelineLayout layout;   // nullable
  ProgrammableStageDescriptor compute;
};

struct DeviceDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 required_features_count;
  zinc::array_view<FeatureName> required_features;
  zinc::array_view<RequiredLimits> required_limits; // nullable
  QueueDescriptor default_queue;
};

struct RenderPassDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  u32 color_attachment_count;
  zinc::array_view<RenderPassColorAttachment> color_attachments;
  zinc::array_view<RenderPassDepthStencilAttachment>
      depth_stencil_attachment; // nullable
  QuerySet occlusion_query_set; // nullable
  u32 timestamp_write_count;
  zinc::array_view<RenderPassTimestampWrite> timestamp_writes;
};

struct VertexState {
  ChainedStruct const *next_in_chain;
  ShaderModule module;
  zinc::string_view entry_point;
  u32 constant_count;
  zinc::array_view<ConstantEntry> constants;
  u32 buffer_count;
  zinc::array_view<VertexBufferLayout> buffers;
};

struct FragmentState {
  ChainedStruct const *next_in_chain;
  ShaderModule module;
  zinc::string_view entry_point;
  u32 constant_count;
  zinc::array_view<ConstantEntry> constants;
  u32 target_count;
  zinc::array_view<ColorTargetState> targets;
};

struct RenderPipelineDescriptor {
  ChainedStruct const *next_in_chain;
  zinc::string_view label; // nullable
  PipelineLayout layout;   // nullable
  VertexState vertex;
  PrimitiveState primitive;
  zinc::array_view<DepthStencilState> depth_stencil; // nullable
  MultisampleState multisample;
  zinc::array_view<FragmentState> fragment; // nullable
};

// Procedures

using BufferMapCallback = void (*)(BufferMapAsyncStatus status, void *userdata);
using CompilationInfoCallback =
    void (*)(CompilationInfoRequestStatus status,
             zinc::array_view<CompilationInfo> compilationInfo, void *userdata);
using CreateComputePipelineAsyncCallback =
    void (*)(CreatePipelineAsyncStatus status, ComputePipeline pipeline,
             zinc::string_view message, void *userdata);
using CreateRenderPipelineAsyncCallback =
    void (*)(CreatePipelineAsyncStatus status, RenderPipeline pipeline,
             zinc::string_view message, void *userdata);
using DeviceLostCallback = void (*)(DeviceLostReason reason,
                                    zinc::string_view message, void *userdata);
using ErrorCallback = void (*)(ErrorType type, zinc::string_view message,
                               void *userdata);
using Proc = void (*)();
using QueueWorkDoneCallback = void (*)(QueueWorkDoneStatus status,
                                       void *userdata);
using RequestAdapterCallback = void (*)(RequestAdapterStatus status,
                                        Adapter adapter,
                                        zinc::string_view message,
                                        void *userdata);
using RequestDeviceCallback = void (*)(RequestDeviceStatus status,
                                       Device device, zinc::string_view message,
                                       void *userdata);

using ProcCreateInstance = Instance (*)(InstanceDescriptor const *descriptor);
using ProcGetProcAddress = Proc (*)(Device device, char const *procName);

// Procs of Adapter
using ProcAdapterEnumerateFeatures = usize (*)(Adapter adapter,
                                               FeatureName *features);
using ProcAdapterGetLimits = bool (*)(Adapter adapter, SupportedLimits *limits);
using ProcAdapterGetProperties = void (*)(Adapter adapter,
                                          AdapterProperties *properties);
using ProcAdapterHasFeature = bool (*)(Adapter adapter, FeatureName feature);
using ProcAdapterRequestDevice =
    void (*)(Adapter adapter, DeviceDescriptor const *descriptor /* nullable */,
             RequestDeviceCallback callback, void *userdata);

// Procs of BindGroup
using ProcBindGroupSetLabel = void (*)(BindGroup bindGroup, char const *label);

// Procs of BindGroupLayout
using ProcBindGroupLayoutSetLabel = void (*)(BindGroupLayout bindGroupLayout,
                                             char const *label);

// Procs of Buffer
using ProcBufferDestroy = void (*)(Buffer buffer);
using ProcBufferGetConstMappedRange = void const *(*)(Buffer buffer,
                                                      usize offset, usize size);
using ProcBufferGetMappedRange = void *(*)(Buffer buffer, usize offset,
                                           usize size);
using ProcBufferGetSize = u64 (*)(Buffer buffer);
using ProcBufferGetUsage = BufferUsage (*)(Buffer buffer);
using ProcBufferMapAsync = void (*)(Buffer buffer, MapModeFlags mode,
                                    usize offset, usize size,
                                    BufferMapCallback callback, void *userdata);
using ProcBufferSetLabel = void (*)(Buffer buffer, char const *label);
using ProcBufferUnmap = void (*)(Buffer buffer);

// Procs of CommandBuffer
using ProcCommandBufferSetLabel = void (*)(CommandBuffer commandBuffer,
                                           char const *label);

// Procs of CommandEncoder
using ProcCommandEncoderBeginComputePass = ComputePassEncoder (*)(
    CommandEncoder commandEncoder,
    ComputePassDescriptor const *descriptor /* nullable */);
using ProcCommandEncoderBeginRenderPass = RenderPassEncoder (*)(
    CommandEncoder commandEncoder, RenderPassDescriptor const *descriptor);
using ProcCommandEncoderClearBuffer = void (*)(CommandEncoder commandEncoder,
                                               Buffer buffer, u64 offset,
                                               u64 size);
using ProcCommandEncoderCopyBufferToBuffer =
    void (*)(CommandEncoder commandEncoder, Buffer source, u64 sourceOffset,
             Buffer destination, u64 destinationOffset, u64 size);
using ProcCommandEncoderCopyBufferToTexture =
    void (*)(CommandEncoder commandEncoder, ImageCopyBuffer const *source,
             ImageCopyTexture const *destination, Extent3D const *copySize);
using ProcCommandEncoderCopyTextureToBuffer =
    void (*)(CommandEncoder commandEncoder, ImageCopyTexture const *source,
             ImageCopyBuffer const *destination, Extent3D const *copySize);
using ProcCommandEncoderCopyTextureToTexture =
    void (*)(CommandEncoder commandEncoder, ImageCopyTexture const *source,
             ImageCopyTexture const *destination, Extent3D const *copySize);
using ProcCommandEncoderFinish =
    CommandBuffer (*)(CommandEncoder commandEncoder,
                      CommandBufferDescriptor const *descriptor /* nullable */);
using ProcCommandEncoderInsertDebugMarker =
    void (*)(CommandEncoder commandEncoder, char const *markerLabel);
using ProcCommandEncoderPopDebugGroup = void (*)(CommandEncoder commandEncoder);
using ProcCommandEncoderPushDebugGroup = void (*)(CommandEncoder commandEncoder,
                                                  char const *groupLabel);
using ProcCommandEncoderResolveQuerySet =
    void (*)(CommandEncoder commandEncoder, QuerySet querySet, u32 firstQuery,
             u32 queryCount, Buffer destination, u64 destinationOffset);
using ProcCommandEncoderSetLabel = void (*)(CommandEncoder commandEncoder,
                                            char const *label);
using ProcCommandEncoderWriteTimestamp = void (*)(CommandEncoder commandEncoder,
                                                  QuerySet querySet,
                                                  u32 queryIndex);

// Procs of ComputePassEncoder
using ProcComputePassEncoderBeginPipelineStatisticsQuery = void (*)(
    ComputePassEncoder computePassEncoder, QuerySet querySet, u32 queryIndex);
using ProcComputePassEncoderDispatchWorkgroups =
    void (*)(ComputePassEncoder computePassEncoder, u32 workgroupCountX,
             u32 workgroupCountY, u32 workgroupCountZ);
using ProcComputePassEncoderDispatchWorkgroupsIndirect =
    void (*)(ComputePassEncoder computePassEncoder, Buffer indirectBuffer,
             u64 indirectOffset);
using ProcComputePassEncoderEnd =
    void (*)(ComputePassEncoder computePassEncoder);
using ProcComputePassEncoderEndPipelineStatisticsQuery =
    void (*)(ComputePassEncoder computePassEncoder);
using ProcComputePassEncoderInsertDebugMarker =
    void (*)(ComputePassEncoder computePassEncoder, char const *markerLabel);
using ProcComputePassEncoderPopDebugGroup =
    void (*)(ComputePassEncoder computePassEncoder);
using ProcComputePassEncoderPushDebugGroup =
    void (*)(ComputePassEncoder computePassEncoder, char const *groupLabel);
using ProcComputePassEncoderSetBindGroup = void (*)(
    ComputePassEncoder computePassEncoder, u32 groupIndex, BindGroup group,
    u32 dynamicOffsetCount, u32 const *dynamicOffsets);
using ProcComputePassEncoderSetLabel =
    void (*)(ComputePassEncoder computePassEncoder, char const *label);
using ProcComputePassEncoderSetPipeline =
    void (*)(ComputePassEncoder computePassEncoder, ComputePipeline pipeline);

// Procs of ComputePipeline
using ProcComputePipelineGetBindGroupLayout =
    BindGroupLayout (*)(ComputePipeline computePipeline, u32 groupIndex);
using ProcComputePipelineSetLabel = void (*)(ComputePipeline computePipeline,
                                             char const *label);

// Procs of Device
using ProcDeviceCreateBindGroup =
    BindGroup (*)(Device device, BindGroupDescriptor const *descriptor);
using ProcDeviceCreateBindGroupLayout = BindGroupLayout (*)(
    Device device, BindGroupLayoutDescriptor const *descriptor);
using ProcDeviceCreateBuffer = Buffer (*)(Device device,
                                          BufferDescriptor const *descriptor);
using ProcDeviceCreateCommandEncoder = CommandEncoder (*)(
    Device device, CommandEncoderDescriptor const *descriptor /* nullable */);
using ProcDeviceCreateComputePipeline = ComputePipeline (*)(
    Device device, ComputePipelineDescriptor const *descriptor);
using ProcDeviceCreateComputePipelineAsync =
    void (*)(Device device, ComputePipelineDescriptor const *descriptor,
             CreateComputePipelineAsyncCallback callback, void *userdata);
using ProcDeviceCreatePipelineLayout = PipelineLayout (*)(
    Device device, PipelineLayoutDescriptor const *descriptor);
using ProcDeviceCreateQuerySet =
    QuerySet (*)(Device device, QuerySetDescriptor const *descriptor);
using ProcDeviceCreateRenderBundleEncoder = RenderBundleEncoder (*)(
    Device device, RenderBundleEncoderDescriptor const *descriptor);
using ProcDeviceCreateRenderPipeline = RenderPipeline (*)(
    Device device, RenderPipelineDescriptor const *descriptor);
using ProcDeviceCreateRenderPipelineAsync =
    void (*)(Device device, RenderPipelineDescriptor const *descriptor,
             CreateRenderPipelineAsyncCallback callback, void *userdata);
using ProcDeviceCreateSampler = Sampler (*)(
    Device device, SamplerDescriptor const *descriptor /* nullable */);
using ProcDeviceCreateShaderModule =
    ShaderModule (*)(Device device, ShaderModuleDescriptor const *descriptor);
using ProcDeviceCreateSwapChain = SwapChain (*)(
    Device device, Surface surface, SwapChainDescriptor const *descriptor);
using ProcDeviceCreateTexture =
    Texture (*)(Device device, TextureDescriptor const *descriptor);
using ProcDeviceDestroy = void (*)(Device device);
using ProcDeviceEnumerateFeatures = usize (*)(Device device,
                                              FeatureName *features);
using ProcDeviceGetLimits = bool (*)(Device device, SupportedLimits *limits);
using ProcDeviceGetQueue = Queue (*)(Device device);
using ProcDeviceHasFeature = bool (*)(Device device, FeatureName feature);
using ProcDevicePopErrorScope = bool (*)(Device device, ErrorCallback callback,
                                         void *userdata);
using ProcDevicePushErrorScope = void (*)(Device device, ErrorFilter filter);
using ProcDeviceSetDeviceLostCallback = void (*)(Device device,
                                                 DeviceLostCallback callback,
                                                 void *userdata);
using ProcDeviceSetLabel = void (*)(Device device, char const *label);
using ProcDeviceSetUncapturedErrorCallback = void (*)(Device device,
                                                      ErrorCallback callback,
                                                      void *userdata);

// Procs of Instance
using ProcInstanceCreateSurface =
    Surface (*)(Instance instance, SurfaceDescriptor const *descriptor);
using ProcInstanceProcessEvents = void (*)(Instance instance);
using ProcInstanceRequestAdapter = void (*)(
    Instance instance, RequestAdapterOptions const *options /* nullable */,
    RequestAdapterCallback callback, void *userdata);

// Procs of PipelineLayout
using ProcPipelineLayoutSetLabel = void (*)(PipelineLayout pipelineLayout,
                                            char const *label);

// Procs of QuerySet
using ProcQuerySetDestroy = void (*)(QuerySet querySet);
using ProcQuerySetGetCount = u32 (*)(QuerySet querySet);
using ProcQuerySetGetType = QueryType (*)(QuerySet querySet);
using ProcQuerySetSetLabel = void (*)(QuerySet querySet, char const *label);

// Procs of Queue
using ProcQueueOnSubmittedWorkDone = void (*)(Queue queue,
                                              QueueWorkDoneCallback callback,
                                              void *userdata);
using ProcQueueSetLabel = void (*)(Queue queue, char const *label);
using ProcQueueSubmit = void (*)(Queue queue, u32 commandCount,
                                 CommandBuffer const *commands);
using ProcQueueWriteBuffer = void (*)(Queue queue, Buffer buffer,
                                      u64 bufferOffset, void const *data,
                                      usize size);
using ProcQueueWriteTexture = void (*)(Queue queue,
                                       ImageCopyTexture const *destination,
                                       void const *data, usize dataSize,
                                       TextureDataLayout const *dataLayout,
                                       Extent3D const *writeSize);

// Procs of RenderBundleEncoder
using ProcRenderBundleEncoderDraw =
    void (*)(RenderBundleEncoder renderBundleEncoder, u32 vertexCount,
             u32 instanceCount, u32 firstVertex, u32 firstInstance);
using ProcRenderBundleEncoderDrawIndexed = void (*)(
    RenderBundleEncoder renderBundleEncoder, u32 indexCount, u32 instanceCount,
    u32 firstIndex, i32 baseVertex, u32 firstInstance);
using ProcRenderBundleEncoderDrawIndexedIndirect =
    void (*)(RenderBundleEncoder renderBundleEncoder, Buffer indirectBuffer,
             u64 indirectOffset);
using ProcRenderBundleEncoderDrawIndirect =
    void (*)(RenderBundleEncoder renderBundleEncoder, Buffer indirectBuffer,
             u64 indirectOffset);
using ProcRenderBundleEncoderFinish =
    RenderBundle (*)(RenderBundleEncoder renderBundleEncoder,
                     RenderBundleDescriptor const *descriptor /* nullable */);
using ProcRenderBundleEncoderInsertDebugMarker =
    void (*)(RenderBundleEncoder renderBundleEncoder, char const *markerLabel);
using ProcRenderBundleEncoderPopDebugGroup =
    void (*)(RenderBundleEncoder renderBundleEncoder);
using ProcRenderBundleEncoderPushDebugGroup =
    void (*)(RenderBundleEncoder renderBundleEncoder, char const *groupLabel);
using ProcRenderBundleEncoderSetBindGroup = void (*)(
    RenderBundleEncoder renderBundleEncoder, u32 groupIndex, BindGroup group,
    u32 dynamicOffsetCount, u32 const *dynamicOffsets);
using ProcRenderBundleEncoderSetIndexBuffer =
    void (*)(RenderBundleEncoder renderBundleEncoder, Buffer buffer,
             IndexFormat format, u64 offset, u64 size);
using ProcRenderBundleEncoderSetLabel =
    void (*)(RenderBundleEncoder renderBundleEncoder, char const *label);
using ProcRenderBundleEncoderSetPipeline =
    void (*)(RenderBundleEncoder renderBundleEncoder, RenderPipeline pipeline);
using ProcRenderBundleEncoderSetVertexBuffer =
    void (*)(RenderBundleEncoder renderBundleEncoder, u32 slot, Buffer buffer,
             u64 offset, u64 size);

// Procs of RenderPassEncoder
using ProcRenderPassEncoderBeginOcclusionQuery =
    void (*)(RenderPassEncoder renderPassEncoder, u32 queryIndex);
using ProcRenderPassEncoderBeginPipelineStatisticsQuery = void (*)(
    RenderPassEncoder renderPassEncoder, QuerySet querySet, u32 queryIndex);
using ProcRenderPassEncoderDraw = void (*)(RenderPassEncoder renderPassEncoder,
                                           u32 vertexCount, u32 instanceCount,
                                           u32 firstVertex, u32 firstInstance);
using ProcRenderPassEncoderDrawIndexed = void (*)(
    RenderPassEncoder renderPassEncoder, u32 indexCount, u32 instanceCount,
    u32 firstIndex, i32 baseVertex, u32 firstInstance);
using ProcRenderPassEncoderDrawIndexedIndirect =
    void (*)(RenderPassEncoder renderPassEncoder, Buffer indirectBuffer,
             u64 indirectOffset);
using ProcRenderPassEncoderDrawIndirect =
    void (*)(RenderPassEncoder renderPassEncoder, Buffer indirectBuffer,
             u64 indirectOffset);
using ProcRenderPassEncoderEnd = void (*)(RenderPassEncoder renderPassEncoder);
using ProcRenderPassEncoderEndOcclusionQuery =
    void (*)(RenderPassEncoder renderPassEncoder);
using ProcRenderPassEncoderEndPipelineStatisticsQuery =
    void (*)(RenderPassEncoder renderPassEncoder);
using ProcRenderPassEncoderExecuteBundles =
    void (*)(RenderPassEncoder renderPassEncoder, u32 bundlesCount,
             RenderBundle const *bundles);
using ProcRenderPassEncoderInsertDebugMarker =
    void (*)(RenderPassEncoder renderPassEncoder, char const *markerLabel);
using ProcRenderPassEncoderPopDebugGroup =
    void (*)(RenderPassEncoder renderPassEncoder);
using ProcRenderPassEncoderPushDebugGroup =
    void (*)(RenderPassEncoder renderPassEncoder, char const *groupLabel);
using ProcRenderPassEncoderSetBindGroup = void (*)(
    RenderPassEncoder renderPassEncoder, u32 groupIndex, BindGroup group,
    u32 dynamicOffsetCount, u32 const *dynamicOffsets);
using ProcRenderPassEncoderSetBlendConstant =
    void (*)(RenderPassEncoder renderPassEncoder, Color const *color);
using ProcRenderPassEncoderSetIndexBuffer =
    void (*)(RenderPassEncoder renderPassEncoder, Buffer buffer,
             IndexFormat format, u64 offset, u64 size);
using ProcRenderPassEncoderSetLabel =
    void (*)(RenderPassEncoder renderPassEncoder, char const *label);
using ProcRenderPassEncoderSetPipeline =
    void (*)(RenderPassEncoder renderPassEncoder, RenderPipeline pipeline);
using ProcRenderPassEncoderSetScissorRect = void (*)(
    RenderPassEncoder renderPassEncoder, u32 x, u32 y, u32 width, u32 height);
using ProcRenderPassEncoderSetStencilReference =
    void (*)(RenderPassEncoder renderPassEncoder, u32 reference);
using ProcRenderPassEncoderSetVertexBuffer =
    void (*)(RenderPassEncoder renderPassEncoder, u32 slot, Buffer buffer,
             u64 offset, u64 size);
using ProcRenderPassEncoderSetViewport =
    void (*)(RenderPassEncoder renderPassEncoder, float x, float y, float width,
             float height, float minDepth, float maxDepth);

// Procs of RenderPipeline
using ProcRenderPipelineGetBindGroupLayout =
    BindGroupLayout (*)(RenderPipeline renderPipeline, u32 groupIndex);
using ProcRenderPipelineSetLabel = void (*)(RenderPipeline renderPipeline,
                                            char const *label);

// Procs of Sampler
using ProcSamplerSetLabel = void (*)(Sampler sampler, char const *label);

// Procs of ShaderModule
using ProcShaderModuleGetCompilationInfo =
    void (*)(ShaderModule shaderModule, CompilationInfoCallback callback,
             void *userdata);
using ProcShaderModuleSetLabel = void (*)(ShaderModule shaderModule,
                                          char const *label);

// Procs of Surface
using ProcSurfaceGetPreferredFormat = TextureFormat (*)(Surface surface,
                                                        Adapter adapter);

// Procs of SwapChain
using ProcSwapChainGetCurrentTextureView = TextureView (*)(SwapChain swapChain);
using ProcSwapChainPresent = void (*)(SwapChain swapChain);

// Procs of Texture
using ProcTextureCreateView = TextureView (*)(
    Texture texture, TextureViewDescriptor const *descriptor /* nullable */);
using ProcTextureDestroy = void (*)(Texture texture);
using ProcTextureGetDepthOrArrayLayers = u32 (*)(Texture texture);
using ProcTextureGetDimension = TextureDimension (*)(Texture texture);
using ProcTextureGetFormat = TextureFormat (*)(Texture texture);
using ProcTextureGetHeight = u32 (*)(Texture texture);
using ProcTextureGetMipLevelCount = u32 (*)(Texture texture);
using ProcTextureGetSampleCount = u32 (*)(Texture texture);
using ProcTextureGetUsage = TextureUsage (*)(Texture texture);
using ProcTextureGetWidth = u32 (*)(Texture texture);
using ProcTextureSetLabel = void (*)(Texture texture, char const *label);

// Procs of TextureView
using ProcTextureViewSetLabel = void (*)(TextureView textureView,
                                         char const *label);

// declarations

MOON_API auto CreateInstance(InstanceDescriptor const *descriptor) -> Instance;
MOON_API auto GetProcAddress(Device device, char const *procName) -> Proc;

// Methods of Adapter
MOON_API auto AdapterEnumerateFeatures(Adapter adapter, FeatureName *features)
    -> usize;
MOON_API auto AdapterGetLimits(Adapter adapter, SupportedLimits *limits)
    -> bool;
MOON_API void AdapterGetProperties(Adapter adapter,
                                   AdapterProperties *properties);
MOON_API auto AdapterHasFeature(Adapter adapter, FeatureName feature) -> bool;
MOON_API void
AdapterRequestDevice(Adapter adapter,
                     DeviceDescriptor const *descriptor /* nullable */,
                     RequestDeviceCallback callback, void *userdata);

// Methods of BindGroup
MOON_API void BindGroupSetLabel(BindGroup bindGroup, char const *label);

// Methods of BindGroupLayout
MOON_API void BindGroupLayoutSetLabel(BindGroupLayout bindGroupLayout,
                                      char const *label);

// Methods of Buffer
MOON_API void BufferDestroy(Buffer buffer);
MOON_API auto BufferGetConstMappedRange(Buffer buffer, usize offset, usize size)
    -> void const *;
MOON_API auto BufferGetMappedRange(Buffer buffer, usize offset, usize size)
    -> void *;
MOON_API auto BufferGetSize(Buffer buffer) -> u64;
MOON_API auto BufferGetUsage(Buffer buffer) -> BufferUsage;
MOON_API void BufferMapAsync(Buffer buffer, MapModeFlags mode, usize offset,
                             usize size, BufferMapCallback callback,
                             void *userdata);
MOON_API void BufferSetLabel(Buffer buffer, char const *label);
MOON_API void BufferUnmap(Buffer buffer);

// Methods of CommandBuffer
MOON_API void CommandBufferSetLabel(CommandBuffer commandBuffer,
                                    char const *label);

// Methods of CommandEncoder
MOON_API auto CommandEncoderBeginComputePass(
    CommandEncoder commandEncoder,
    ComputePassDescriptor const *descriptor /* nullable */)
    -> ComputePassEncoder;
MOON_API auto
CommandEncoderBeginRenderPass(CommandEncoder commandEncoder,
                              RenderPassDescriptor const *descriptor)
    -> RenderPassEncoder;
MOON_API void CommandEncoderClearBuffer(CommandEncoder commandEncoder,
                                        Buffer buffer, u64 offset, u64 size);
MOON_API void CommandEncoderCopyBufferToBuffer(CommandEncoder commandEncoder,
                                               Buffer source, u64 sourceOffset,
                                               Buffer destination,
                                               u64 destinationOffset, u64 size);
MOON_API void CommandEncoderCopyBufferToTexture(
    CommandEncoder commandEncoder, ImageCopyBuffer const *source,
    ImageCopyTexture const *destination, Extent3D const *copySize);
MOON_API void CommandEncoderCopyTextureToBuffer(
    CommandEncoder commandEncoder, ImageCopyTexture const *source,
    ImageCopyBuffer const *destination, Extent3D const *copySize);
MOON_API void CommandEncoderCopyTextureToTexture(
    CommandEncoder commandEncoder, ImageCopyTexture const *source,
    ImageCopyTexture const *destination, Extent3D const *copySize);
MOON_API auto
CommandEncoderFinish(CommandEncoder commandEncoder,
                     CommandBufferDescriptor const *descriptor /* nullable */)
    -> CommandBuffer;
MOON_API void CommandEncoderInsertDebugMarker(CommandEncoder commandEncoder,
                                              char const *markerLabel);
MOON_API void CommandEncoderPopDebugGroup(CommandEncoder commandEncoder);
MOON_API void CommandEncoderPushDebugGroup(CommandEncoder commandEncoder,
                                           char const *groupLabel);
MOON_API void CommandEncoderResolveQuerySet(CommandEncoder commandEncoder,
                                            QuerySet querySet, u32 firstQuery,
                                            u32 queryCount, Buffer destination,
                                            u64 destinationOffset);
MOON_API void CommandEncoderSetLabel(CommandEncoder commandEncoder,
                                     char const *label);
MOON_API void CommandEncoderWriteTimestamp(CommandEncoder commandEncoder,
                                           QuerySet querySet, u32 queryIndex);

// Methods of ComputePassEncoder
MOON_API void ComputePassEncoderBeginPipelineStatisticsQuery(
    ComputePassEncoder computePassEncoder, QuerySet querySet, u32 queryIndex);
MOON_API void
ComputePassEncoderDispatchWorkgroups(ComputePassEncoder computePassEncoder,
                                     u32 workgroupCountX, u32 workgroupCountY,
                                     u32 workgroupCountZ);
MOON_API void ComputePassEncoderDispatchWorkgroupsIndirect(
    ComputePassEncoder computePassEncoder, Buffer indirectBuffer,
    u64 indirectOffset);
MOON_API void ComputePassEncoderEnd(ComputePassEncoder computePassEncoder);
MOON_API void ComputePassEncoderEndPipelineStatisticsQuery(
    ComputePassEncoder computePassEncoder);
MOON_API void
ComputePassEncoderInsertDebugMarker(ComputePassEncoder computePassEncoder,
                                    char const *markerLabel);
MOON_API void
ComputePassEncoderPopDebugGroup(ComputePassEncoder computePassEncoder);
MOON_API void
ComputePassEncoderPushDebugGroup(ComputePassEncoder computePassEncoder,
                                 char const *groupLabel);
MOON_API void ComputePassEncoderSetBindGroup(
    ComputePassEncoder computePassEncoder, u32 groupIndex, BindGroup group,
    u32 dynamicOffsetCount, u32 const *dynamicOffsets);
MOON_API void ComputePassEncoderSetLabel(ComputePassEncoder computePassEncoder,
                                         char const *label);
MOON_API void
ComputePassEncoderSetPipeline(ComputePassEncoder computePassEncoder,
                              ComputePipeline pipeline);

// Methods of ComputePipeline
MOON_API auto ComputePipelineGetBindGroupLayout(ComputePipeline computePipeline,
                                                u32 groupIndex)
    -> BindGroupLayout;
MOON_API void ComputePipelineSetLabel(ComputePipeline computePipeline,
                                      char const *label);

// Methods of Device
MOON_API auto DeviceCreateBindGroup(Device device,
                                    BindGroupDescriptor const *descriptor)
    -> BindGroup;
MOON_API auto
DeviceCreateBindGroupLayout(Device device,
                            BindGroupLayoutDescriptor const *descriptor)
    -> BindGroupLayout;
MOON_API auto DeviceCreateBuffer(Device device,
                                 BufferDescriptor const *descriptor) -> Buffer;
MOON_API auto DeviceCreateCommandEncoder(
    Device device, CommandEncoderDescriptor const *descriptor /* nullable */)
    -> CommandEncoder;
MOON_API auto
DeviceCreateComputePipeline(Device device,
                            ComputePipelineDescriptor const *descriptor)
    -> ComputePipeline;
MOON_API void DeviceCreateComputePipelineAsync(
    Device device, ComputePipelineDescriptor const *descriptor,
    CreateComputePipelineAsyncCallback callback, void *userdata);
MOON_API auto
DeviceCreatePipelineLayout(Device device,
                           PipelineLayoutDescriptor const *descriptor)
    -> PipelineLayout;
MOON_API auto DeviceCreateQuerySet(Device device,
                                   QuerySetDescriptor const *descriptor)
    -> QuerySet;
MOON_API auto
DeviceCreateRenderBundleEncoder(Device device,
                                RenderBundleEncoderDescriptor const *descriptor)
    -> RenderBundleEncoder;
MOON_API auto
DeviceCreateRenderPipeline(Device device,
                           RenderPipelineDescriptor const *descriptor)
    -> RenderPipeline;
MOON_API void DeviceCreateRenderPipelineAsync(
    Device device, RenderPipelineDescriptor const *descriptor,
    CreateRenderPipelineAsyncCallback callback, void *userdata);
MOON_API auto
DeviceCreateSampler(Device device,
                    SamplerDescriptor const *descriptor /* nullable */)
    -> Sampler;
MOON_API auto DeviceCreateShaderModule(Device device,
                                       ShaderModuleDescriptor const *descriptor)
    -> ShaderModule;
MOON_API auto DeviceCreateSwapChain(Device device, Surface surface,
                                    SwapChainDescriptor const *descriptor)
    -> SwapChain;
MOON_API auto DeviceCreateTexture(Device device,
                                  TextureDescriptor const *descriptor)
    -> Texture;
MOON_API void DeviceDestroy(Device device);
MOON_API auto DeviceEnumerateFeatures(Device device, FeatureName *features)
    -> usize;
MOON_API auto DeviceGetLimits(Device device, SupportedLimits *limits) -> bool;
MOON_API auto DeviceGetQueue(Device device) -> Queue;
MOON_API auto DeviceHasFeature(Device device, FeatureName feature) -> bool;
MOON_API auto DevicePopErrorScope(Device device, ErrorCallback callback,
                                  void *userdata) -> bool;
MOON_API void DevicePushErrorScope(Device device, ErrorFilter filter);
MOON_API void DeviceSetDeviceLostCallback(Device device,
                                          DeviceLostCallback callback,
                                          void *userdata);
MOON_API void DeviceSetLabel(Device device, char const *label);
MOON_API void DeviceSetUncapturedErrorCallback(Device device,
                                               ErrorCallback callback,
                                               void *userdata);

// Methods of Instance
MOON_API auto InstanceCreateSurface(Instance instance,
                                    SurfaceDescriptor const *descriptor)
    -> Surface;
MOON_API void InstanceProcessEvents(Instance instance);
MOON_API void
InstanceRequestAdapter(Instance instance,
                       RequestAdapterOptions const *options /* nullable */,
                       RequestAdapterCallback callback, void *userdata);

// Methods of PipelineLayout
MOON_API void PipelineLayoutSetLabel(PipelineLayout pipelineLayout,
                                     char const *label);

// Methods of QuerySet
MOON_API void QuerySetDestroy(QuerySet querySet);
MOON_API auto QuerySetGetCount(QuerySet querySet) -> u32;
MOON_API auto QuerySetGetType(QuerySet querySet) -> QueryType;
MOON_API void QuerySetSetLabel(QuerySet querySet, char const *label);

// Methods of Queue
MOON_API void QueueOnSubmittedWorkDone(Queue queue,
                                       QueueWorkDoneCallback callback,
                                       void *userdata);
MOON_API void QueueSetLabel(Queue queue, char const *label);
MOON_API void QueueSubmit(Queue queue, u32 commandCount,
                          CommandBuffer const *commands);
MOON_API void QueueWriteBuffer(Queue queue, Buffer buffer, u64 bufferOffset,
                               void const *data, usize size);
MOON_API void QueueWriteTexture(Queue queue,
                                ImageCopyTexture const *destination,
                                void const *data, usize dataSize,
                                TextureDataLayout const *dataLayout,
                                Extent3D const *writeSize);

// Methods of RenderBundleEncoder
MOON_API void RenderBundleEncoderDraw(RenderBundleEncoder renderBundleEncoder,
                                      u32 vertexCount, u32 instanceCount,
                                      u32 firstVertex, u32 firstInstance);
MOON_API void RenderBundleEncoderDrawIndexed(
    RenderBundleEncoder renderBundleEncoder, u32 indexCount, u32 instanceCount,
    u32 firstIndex, i32 baseVertex, u32 firstInstance);
MOON_API void
RenderBundleEncoderDrawIndexedIndirect(RenderBundleEncoder renderBundleEncoder,
                                       Buffer indirectBuffer,
                                       u64 indirectOffset);
MOON_API void
RenderBundleEncoderDrawIndirect(RenderBundleEncoder renderBundleEncoder,
                                Buffer indirectBuffer, u64 indirectOffset);
MOON_API auto RenderBundleEncoderFinish(
    RenderBundleEncoder renderBundleEncoder,
    RenderBundleDescriptor const *descriptor /* nullable */) -> RenderBundle;
MOON_API void
RenderBundleEncoderInsertDebugMarker(RenderBundleEncoder renderBundleEncoder,
                                     char const *markerLabel);
MOON_API void
RenderBundleEncoderPopDebugGroup(RenderBundleEncoder renderBundleEncoder);
MOON_API void
RenderBundleEncoderPushDebugGroup(RenderBundleEncoder renderBundleEncoder,
                                  char const *groupLabel);
MOON_API void RenderBundleEncoderSetBindGroup(
    RenderBundleEncoder renderBundleEncoder, u32 groupIndex, BindGroup group,
    u32 dynamicOffsetCount, u32 const *dynamicOffsets);
MOON_API void
RenderBundleEncoderSetIndexBuffer(RenderBundleEncoder renderBundleEncoder,
                                  Buffer buffer, IndexFormat format, u64 offset,
                                  u64 size);
MOON_API void
RenderBundleEncoderSetLabel(RenderBundleEncoder renderBundleEncoder,
                            char const *label);
MOON_API void
RenderBundleEncoderSetPipeline(RenderBundleEncoder renderBundleEncoder,
                               RenderPipeline pipeline);
MOON_API void
RenderBundleEncoderSetVertexBuffer(RenderBundleEncoder renderBundleEncoder,
                                   u32 slot, Buffer buffer, u64 offset,
                                   u64 size);

// Methods of RenderPassEncoder
MOON_API void
RenderPassEncoderBeginOcclusionQuery(RenderPassEncoder renderPassEncoder,
                                     u32 queryIndex);
MOON_API void RenderPassEncoderBeginPipelineStatisticsQuery(
    RenderPassEncoder renderPassEncoder, QuerySet querySet, u32 queryIndex);
MOON_API void RenderPassEncoderDraw(RenderPassEncoder renderPassEncoder,
                                    u32 vertexCount, u32 instanceCount,
                                    u32 firstVertex, u32 firstInstance);
MOON_API void RenderPassEncoderDrawIndexed(RenderPassEncoder renderPassEncoder,
                                           u32 indexCount, u32 instanceCount,
                                           u32 firstIndex, i32 baseVertex,
                                           u32 firstInstance);
MOON_API void
RenderPassEncoderDrawIndexedIndirect(RenderPassEncoder renderPassEncoder,
                                     Buffer indirectBuffer, u64 indirectOffset);
MOON_API void RenderPassEncoderDrawIndirect(RenderPassEncoder renderPassEncoder,
                                            Buffer indirectBuffer,
                                            u64 indirectOffset);
MOON_API void RenderPassEncoderEnd(RenderPassEncoder renderPassEncoder);
MOON_API void
RenderPassEncoderEndOcclusionQuery(RenderPassEncoder renderPassEncoder);
MOON_API void RenderPassEncoderEndPipelineStatisticsQuery(
    RenderPassEncoder renderPassEncoder);
MOON_API void
RenderPassEncoderExecuteBundles(RenderPassEncoder renderPassEncoder,
                                u32 bundlesCount, RenderBundle const *bundles);
MOON_API void
RenderPassEncoderInsertDebugMarker(RenderPassEncoder renderPassEncoder,
                                   char const *markerLabel);
MOON_API void
RenderPassEncoderPopDebugGroup(RenderPassEncoder renderPassEncoder);
MOON_API void
RenderPassEncoderPushDebugGroup(RenderPassEncoder renderPassEncoder,
                                char const *groupLabel);
MOON_API void RenderPassEncoderSetBindGroup(RenderPassEncoder renderPassEncoder,
                                            u32 groupIndex, BindGroup group,
                                            u32 dynamicOffsetCount,
                                            u32 const *dynamicOffsets);
MOON_API void
RenderPassEncoderSetBlendConstant(RenderPassEncoder renderPassEncoder,
                                  Color const *color);
MOON_API void
RenderPassEncoderSetIndexBuffer(RenderPassEncoder renderPassEncoder,
                                Buffer buffer, IndexFormat format, u64 offset,
                                u64 size);
MOON_API void RenderPassEncoderSetLabel(RenderPassEncoder renderPassEncoder,
                                        char const *label);
MOON_API void RenderPassEncoderSetPipeline(RenderPassEncoder renderPassEncoder,
                                           RenderPipeline pipeline);
MOON_API void
RenderPassEncoderSetScissorRect(RenderPassEncoder renderPassEncoder, u32 x,
                                u32 y, u32 width, u32 height);
MOON_API void
RenderPassEncoderSetStencilReference(RenderPassEncoder renderPassEncoder,
                                     u32 reference);
MOON_API void
RenderPassEncoderSetVertexBuffer(RenderPassEncoder renderPassEncoder, u32 slot,
                                 Buffer buffer, u64 offset, u64 size);
MOON_API void RenderPassEncoderSetViewport(RenderPassEncoder renderPassEncoder,
                                           float x, float y, float width,
                                           float height, float minDepth,
                                           float maxDepth);

// Methods of RenderPipeline
MOON_API auto RenderPipelineGetBindGroupLayout(RenderPipeline renderPipeline,
                                               u32 groupIndex)
    -> BindGroupLayout;
MOON_API void RenderPipelineSetLabel(RenderPipeline renderPipeline,
                                     char const *label);

// Methods of Sampler
MOON_API void SamplerSetLabel(Sampler sampler, char const *label);

// Methods of ShaderModule
MOON_API void ShaderModuleGetCompilationInfo(ShaderModule shaderModule,
                                             CompilationInfoCallback callback,
                                             void *userdata);
MOON_API void ShaderModuleSetLabel(ShaderModule shaderModule,
                                   char const *label);

// Methods of Surface
MOON_API auto SurfaceGetPreferredFormat(Surface surface, Adapter adapter)
    -> TextureFormat;

// Methods of SwapChain
MOON_API auto SwapChainGetCurrentTextureView(SwapChain swapChain)
    -> TextureView;
MOON_API void SwapChainPresent(SwapChain swapChain);

// Methods of Texture
MOON_API auto
TextureCreateView(Texture texture,
                  TextureViewDescriptor const *descriptor /* nullable */)
    -> TextureView;
MOON_API void TextureDestroy(Texture texture);
MOON_API auto TextureGetDepthOrArrayLayers(Texture texture) -> u32;
MOON_API auto TextureGetDimension(Texture texture) -> TextureDimension;
MOON_API auto TextureGetFormat(Texture texture) -> TextureFormat;
MOON_API auto TextureGetHeight(Texture texture) -> u32;
MOON_API auto TextureGetMipLevelCount(Texture texture) -> u32;
MOON_API auto TextureGetSampleCount(Texture texture) -> u32;
MOON_API auto TextureGetUsage(Texture texture) -> TextureUsage;
MOON_API auto TextureGetWidth(Texture texture) -> u32;
MOON_API void TextureSetLabel(Texture texture, char const *label);

// Methods of TextureView
MOON_API void TextureViewSetLabel(TextureView textureView, char const *label);

} // namespace moon::gpu