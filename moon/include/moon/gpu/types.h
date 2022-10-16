#pragma once

#include "moon/base.h"

// #if MOON_CONFIG_SHARED_LIB
// #define WGPU_SHARED_LIBRARY 1
// #endif
// #if MOON_EXPORTS
// #define WGPU_IMPLEMENTATION 1
// #endif
#include "api/webgpu.h"

namespace moon::gpu {

template <typename T> struct IsMoonBitmask {
  static constexpr bool enable = false;
};

template <typename T, typename Enable = void> struct LowerBitmask {
  static constexpr bool enable = false;
};

template <typename T>
struct LowerBitmask<T,
                    typename std::enable_if<IsMoonBitmask<T>::enable>::type> {
  static constexpr bool enable = true;
  using type = T;
  constexpr static auto Lower(T t) -> T { return t; }
};

template <typename T> struct BoolConvertible {
  using Integral = typename std::underlying_type<T>::type;

  // NOLINTNEXTLINE(runtime/explicit)
  constexpr BoolConvertible(Integral value) : value(value) {}
  constexpr operator bool() const { return value != 0; }
  constexpr operator T() const { return static_cast<T>(value); }

  Integral value;
};

template <typename T> struct LowerBitmask<BoolConvertible<T>> {
  static constexpr bool enable = true;
  using type = T;
  static constexpr auto Lower(BoolConvertible<T> t) -> type { return t; }
};

template <typename T1, typename T2,
          typename = typename std::enable_if<LowerBitmask<T1>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator|(T1 left, T2 right)
    -> BoolConvertible<typename LowerBitmask<T1>::type> {
  using T = typename LowerBitmask<T1>::type;
  using Integral = typename std::underlying_type<T>::type;
  return static_cast<Integral>(LowerBitmask<T1>::Lower(left)) |
         static_cast<Integral>(LowerBitmask<T2>::Lower(right));
}

template <typename T1, typename T2,
          typename = typename std::enable_if<LowerBitmask<T1>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator&(T1 left, T2 right)
    -> BoolConvertible<typename LowerBitmask<T1>::type> {
  using T = typename LowerBitmask<T1>::type;
  using Integral = typename std::underlying_type<T>::type;
  return static_cast<Integral>(LowerBitmask<T1>::Lower(left)) &
         static_cast<Integral>(LowerBitmask<T2>::Lower(right));
}

template <typename T1, typename T2,
          typename = typename std::enable_if<LowerBitmask<T1>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator^(T1 left, T2 right)
    -> BoolConvertible<typename LowerBitmask<T1>::type> {
  using T = typename LowerBitmask<T1>::type;
  using Integral = typename std::underlying_type<T>::type;
  return static_cast<Integral>(LowerBitmask<T1>::Lower(left)) ^
         static_cast<Integral>(LowerBitmask<T2>::Lower(right));
}

template <typename T1>
constexpr auto operator~(T1 t)
    -> BoolConvertible<typename LowerBitmask<T1>::type> {
  using T = typename LowerBitmask<T1>::type;
  using Integral = typename std::underlying_type<T>::type;
  return ~static_cast<Integral>(LowerBitmask<T1>::Lower(t));
}

template <typename T, typename T2,
          typename = typename std::enable_if<IsMoonBitmask<T>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator&=(T &l, T2 right) -> T & {
  T r = LowerBitmask<T2>::Lower(right);
  l = l & r;
  return l;
}

template <typename T, typename T2,
          typename = typename std::enable_if<IsMoonBitmask<T>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator|=(T &l, T2 right) -> T & {
  T r = LowerBitmask<T2>::Lower(right);
  l = l | r;
  return l;
}

template <typename T, typename T2,
          typename = typename std::enable_if<IsMoonBitmask<T>::enable &&
                                             LowerBitmask<T2>::enable>::type>
constexpr auto operator^=(T &l, T2 right) -> T & {
  T r = LowerBitmask<T2>::Lower(right);
  l = l ^ r;
  return l;
}

template <typename T> constexpr auto HasZeroOrOneBits(T value) -> bool {
  using Integral = typename std::underlying_type<T>::type;
  return (static_cast<Integral>(value) & (static_cast<Integral>(value) - 1)) ==
         0;
}

namespace detail {
constexpr auto ConstexprMax(size_t a, size_t b) -> size_t {
  return a > b ? a : b;
}
} // namespace detail

static constexpr u32 kArrayLayerCountUndefined =
    WGPU_ARRAY_LAYER_COUNT_UNDEFINED;
static constexpr u32 kCopyStrideUndefined = WGPU_COPY_STRIDE_UNDEFINED;
static constexpr u32 kLimitU32Undefined = WGPU_LIMIT_U32_UNDEFINED;
static constexpr uint64_t kLimitU64Undefined = WGPU_LIMIT_U64_UNDEFINED;
static constexpr u32 kMipLevelCountUndefined = WGPU_MIP_LEVEL_COUNT_UNDEFINED;
static constexpr u32 kStrideUndefined = WGPU_STRIDE_UNDEFINED;
static constexpr size_t kWholeMapSize = WGPU_WHOLE_MAP_SIZE;
static constexpr uint64_t kWholeSize = WGPU_WHOLE_SIZE;

enum class AdapterType : u32 {
  DiscreteGPU = 0x00000000,
  IntegratedGPU = 0x00000001,
  CPU = 0x00000002,
  Unknown = 0x00000003,
};

enum class AddressMode : u32 {
  Repeat = 0x00000000,
  MirrorRepeat = 0x00000001,
  ClampToEdge = 0x00000002,
};

enum class AlphaMode : u32 {
  Premultiplied = 0x00000000,
  Unpremultiplied = 0x00000001,
  Opaque = 0x00000002,
};

enum class BackendType : u32 {
  Null = 0x00000000,
  WebGPU = 0x00000001,
  D3D11 = 0x00000002,
  D3D12 = 0x00000003,
  Metal = 0x00000004,
  Vulkan = 0x00000005,
  OpenGL = 0x00000006,
  OpenGLES = 0x00000007,
};

enum class BlendFactor : u32 {
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
};

enum class BlendOperation : u32 {
  Add = 0x00000000,
  Subtract = 0x00000001,
  ReverseSubtract = 0x00000002,
  Min = 0x00000003,
  Max = 0x00000004,
};

enum class BufferBindingType : u32 {
  Undefined = 0x00000000,
  Uniform = 0x00000001,
  Storage = 0x00000002,
  ReadOnlyStorage = 0x00000003,
};

enum class BufferMapAsyncStatus : u32 {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
  DeviceLost = 0x00000003,
  DestroyedBeforeCallback = 0x00000004,
  UnmappedBeforeCallback = 0x00000005,
};

enum class CompareFunction : u32 {
  Undefined = 0x00000000,
  Never = 0x00000001,
  Less = 0x00000002,
  LessEqual = 0x00000003,
  Greater = 0x00000004,
  GreaterEqual = 0x00000005,
  Equal = 0x00000006,
  NotEqual = 0x00000007,
  Always = 0x00000008,
};

enum class CompilationInfoRequestStatus : u32 {
  Success = 0x00000000,
  Error = 0x00000001,
  DeviceLost = 0x00000002,
  Unknown = 0x00000003,
};

enum class CompilationMessageType : u32 {
  Error = 0x00000000,
  Warning = 0x00000001,
  Info = 0x00000002,
};

enum class ComputePassTimestampLocation : u32 {
  Beginning = 0x00000000,
  End = 0x00000001,
};

enum class CreatePipelineAsyncStatus : u32 {
  Success = 0x00000000,
  Error = 0x00000001,
  DeviceLost = 0x00000002,
  DeviceDestroyed = 0x00000003,
  Unknown = 0x00000004,
};

enum class CullMode : u32 {
  None = 0x00000000,
  Front = 0x00000001,
  Back = 0x00000002,
};

enum class DeviceLostReason : u32 {
  Undefined = 0x00000000,
  Destroyed = 0x00000001,
};

enum class ErrorFilter : u32 {
  Validation = 0x00000000,
  OutOfMemory = 0x00000001,
  Internal = 0x00000002,
};

enum class ErrorType : u32 {
  NoError = 0x00000000,
  Validation = 0x00000001,
  OutOfMemory = 0x00000002,
  Internal = 0x00000003,
  Unknown = 0x00000004,
  DeviceLost = 0x00000005,
};

enum class FeatureName : u32 {
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
  MoonShaderFloat16 = 0x000003E9,
  MoonInternalUsages = 0x000003EA,
  MoonMultiPlanarFormats = 0x000003EB,
  MoonNative = 0x000003EC,
  ChromiumExperimentalDp4a = 0x000003ED,
};

enum class FilterMode : u32 {
  Nearest = 0x00000000,
  Linear = 0x00000001,
};

enum class FrontFace : u32 {
  CCW = 0x00000000,
  CW = 0x00000001,
};

enum class IndexFormat : u32 {
  Undefined = 0x00000000,
  Uint16 = 0x00000001,
  Uint32 = 0x00000002,
};

enum class LoadOp : u32 {
  Undefined = 0x00000000,
  Clear = 0x00000001,
  Load = 0x00000002,
};

enum class LoggingType : u32 {
  Verbose = 0x00000000,
  Info = 0x00000001,
  Warning = 0x00000002,
  Error = 0x00000003,
};

enum class PipelineStatisticName : u32 {
  VertexShaderInvocations = 0x00000000,
  ClipperInvocations = 0x00000001,
  ClipperPrimitivesOut = 0x00000002,
  FragmentShaderInvocations = 0x00000003,
  ComputeShaderInvocations = 0x00000004,
};

enum class PowerPreference : u32 {
  Undefined = 0x00000000,
  LowPower = 0x00000001,
  HighPerformance = 0x00000002,
};

enum class PresentMode : u32 {
  Immediate = 0x00000000,
  Mailbox = 0x00000001,
  Fifo = 0x00000002,
};

enum class PrimitiveTopology : u32 {
  PointList = 0x00000000,
  LineList = 0x00000001,
  LineStrip = 0x00000002,
  TriangleList = 0x00000003,
  TriangleStrip = 0x00000004,
};

enum class QueryType : u32 {
  Occlusion = 0x00000000,
  PipelineStatistics = 0x00000001,
  Timestamp = 0x00000002,
};

enum class QueueWorkDoneStatus : u32 {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
  DeviceLost = 0x00000003,
};

enum class RenderPassTimestampLocation : u32 {
  Beginning = 0x00000000,
  End = 0x00000001,
};

enum class RequestAdapterStatus : u32 {
  Success = 0x00000000,
  Unavailable = 0x00000001,
  Error = 0x00000002,
  Unknown = 0x00000003,
};

enum class RequestDeviceStatus : u32 {
  Success = 0x00000000,
  Error = 0x00000001,
  Unknown = 0x00000002,
};

enum class SType : u32 {
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
  SurfaceDescriptorFromWindowsCoreWindow = 0x0000000B,
  ExternalTextureBindingEntry = 0x0000000C,
  ExternalTextureBindingLayout = 0x0000000D,
  SurfaceDescriptorFromWindowsSwapChainPanel = 0x0000000E,
  RenderPassDescriptorMaxDrawCount = 0x0000000F,
  MoonTextureInternalUsageDescriptor = 0x000003E8,
  MoonTogglesDeviceDescriptor = 0x000003EA,
  MoonEncoderInternalUsageDescriptor = 0x000003EB,
  MoonInstanceDescriptor = 0x000003EC,
  MoonCacheDeviceDescriptor = 0x000003ED,
  MoonAdapterPropertiesPowerPreference = 0x000003EE,
};

enum class SamplerBindingType : u32 {
  Undefined = 0x00000000,
  Filtering = 0x00000001,
  NonFiltering = 0x00000002,
  Comparison = 0x00000003,
};

enum class StencilOperation : u32 {
  Keep = 0x00000000,
  Zero = 0x00000001,
  Replace = 0x00000002,
  Invert = 0x00000003,
  IncrementClamp = 0x00000004,
  DecrementClamp = 0x00000005,
  IncrementWrap = 0x00000006,
  DecrementWrap = 0x00000007,
};

enum class StorageTextureAccess : u32 {
  Undefined = 0x00000000,
  WriteOnly = 0x00000001,
};

enum class StoreOp : u32 {
  Undefined = 0x00000000,
  Store = 0x00000001,
  Discard = 0x00000002,
};

enum class TextureAspect : u32 {
  All = 0x00000000,
  StencilOnly = 0x00000001,
  DepthOnly = 0x00000002,
  Plane0Only = 0x00000003,
  Plane1Only = 0x00000004,
};

enum class TextureComponentType : u32 {
  Float = 0x00000000,
  Sint = 0x00000001,
  Uint = 0x00000002,
  DepthComparison = 0x00000003,
};

enum class TextureDimension : u32 {
  e1D = 0x00000000,
  e2D = 0x00000001,
  e3D = 0x00000002,
};

enum class TextureFormat : u32 {
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
  R8BG8Biplanar420Unorm = 0x0000005F,
};

enum class TextureSampleType : u32 {
  Undefined = 0x00000000,
  Float = 0x00000001,
  UnfilterableFloat = 0x00000002,
  Depth = 0x00000003,
  Sint = 0x00000004,
  Uint = 0x00000005,
};

enum class TextureViewDimension : u32 {
  Undefined = 0x00000000,
  e1D = 0x00000001,
  e2D = 0x00000002,
  e2DArray = 0x00000003,
  Cube = 0x00000004,
  CubeArray = 0x00000005,
  e3D = 0x00000006,
};

enum class VertexFormat : u32 {
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
};

enum class VertexStepMode : u32 {
  Vertex = 0x00000000,
  Instance = 0x00000001,
  VertexBufferNotUsed = 0x00000002,
};

enum class BufferUsage : u32 {
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
};

enum class ColorWriteMask : u32 {
  None = 0x00000000,
  Red = 0x00000001,
  Green = 0x00000002,
  Blue = 0x00000004,
  Alpha = 0x00000008,
  All = 0x0000000F,
};

enum class MapMode : u32 {
  None = 0x00000000,
  Read = 0x00000001,
  Write = 0x00000002,
};

enum class ShaderStage : u32 {
  None = 0x00000000,
  Vertex = 0x00000001,
  Fragment = 0x00000002,
  Compute = 0x00000004,
};

enum class TextureUsage : u32 {
  None = 0x00000000,
  CopySrc = 0x00000001,
  CopyDst = 0x00000002,
  TextureBinding = 0x00000004,
  StorageBinding = 0x00000008,
  RenderAttachment = 0x00000010,
  Present = 0x00000020,
};

using BufferMapCallback = WGPUBufferMapCallback;
using CompilationInfoCallback = WGPUCompilationInfoCallback;
using CreateComputePipelineAsyncCallback =
    WGPUCreateComputePipelineAsyncCallback;
using CreateRenderPipelineAsyncCallback = WGPUCreateRenderPipelineAsyncCallback;
using DeviceLostCallback = WGPUDeviceLostCallback;
using ErrorCallback = WGPUErrorCallback;
using LoggingCallback = WGPULoggingCallback;
using Proc = WGPUProc;
using QueueWorkDoneCallback = WGPUQueueWorkDoneCallback;
using RequestAdapterCallback = WGPURequestAdapterCallback;
using RequestDeviceCallback = WGPURequestDeviceCallback;

class MOON_API Adapter;
class MOON_API BindGroup;
class MOON_API BindGroupLayout;
class MOON_API Buffer;
class MOON_API CommandBuffer;
class MOON_API CommandEncoder;
class MOON_API ComputePassEncoder;
class MOON_API ComputePipeline;
class MOON_API Device;
class MOON_API ExternalTexture;
class MOON_API Instance;
class MOON_API PipelineLayout;
class MOON_API QuerySet;
class MOON_API Queue;
class MOON_API RenderBundle;
class MOON_API RenderBundleEncoder;
class MOON_API RenderPassEncoder;
class MOON_API RenderPipeline;
class MOON_API Sampler;
class MOON_API ShaderModule;
class MOON_API Surface;
class MOON_API SwapChain;
class MOON_API Texture;
class MOON_API TextureView;

struct AdapterProperties;
struct BindGroupEntry;
struct BlendComponent;
struct BufferBindingLayout;
struct BufferDescriptor;
struct Color;
struct CommandBufferDescriptor;
struct CommandEncoderDescriptor;
struct CompilationMessage;
struct ComputePassTimestampWrite;
struct ConstantEntry;
struct CopyTextureForBrowserOptions;
struct MoonAdapterPropertiesPowerPreference;
struct MoonCacheDeviceDescriptor;
struct MoonEncoderInternalUsageDescriptor;
struct MoonInstanceDescriptor;
struct MoonTextureInternalUsageDescriptor;
struct MoonTogglesDeviceDescriptor;
struct Extent3D;
struct ExternalTextureBindingEntry;
struct ExternalTextureBindingLayout;
struct ExternalTextureDescriptor;
struct InstanceDescriptor;
struct Limits;
struct MultisampleState;
struct Origin3D;
struct PipelineLayoutDescriptor;
struct PrimitiveDepthClipControl;
struct PrimitiveState;
struct QuerySetDescriptor;
struct QueueDescriptor;
struct RenderBundleDescriptor;
struct RenderBundleEncoderDescriptor;
struct RenderPassDepthStencilAttachment;
struct RenderPassDescriptorMaxDrawCount;
struct RenderPassTimestampWrite;
struct RequestAdapterOptions;
struct SamplerBindingLayout;
struct SamplerDescriptor;
struct ShaderModuleDescriptor;
struct ShaderModuleSPIRVDescriptor;
struct ShaderModuleWGSLDescriptor;
struct StencilFaceState;
struct StorageTextureBindingLayout;
struct SurfaceDescriptor;
struct SurfaceDescriptorFromAndroidNativeWindow;
struct SurfaceDescriptorFromCanvasHTMLSelector;
struct SurfaceDescriptorFromMetalLayer;
struct SurfaceDescriptorFromWaylandSurface;
struct SurfaceDescriptorFromWindowsCoreWindow;
struct SurfaceDescriptorFromWindowsHWND;
struct SurfaceDescriptorFromWindowsSwapChainPanel;
struct SurfaceDescriptorFromXlibWindow;
struct SwapChainDescriptor;
struct TextureBindingLayout;
struct TextureDataLayout;
struct TextureViewDescriptor;
struct VertexAttribute;
struct BindGroupDescriptor;
struct BindGroupLayoutEntry;
struct BlendState;
struct CompilationInfo;
struct ComputePassDescriptor;
struct DepthStencilState;
struct ImageCopyBuffer;
struct ImageCopyTexture;
struct ProgrammableStageDescriptor;
struct RenderPassColorAttachment;
struct RequiredLimits;
struct SupportedLimits;
struct TextureDescriptor;
struct VertexBufferLayout;
struct BindGroupLayoutDescriptor;
struct ColorTargetState;
struct ComputePipelineDescriptor;
struct DeviceDescriptor;
struct RenderPassDescriptor;
struct VertexState;
struct FragmentState;
struct RenderPipelineDescriptor;

template <typename Derived, typename CType> class ObjectBase {
public:
  ObjectBase() = default;
  ObjectBase(CType handle) : mHandle(handle) {
    if (mHandle)
      Derived::wgpu_reference(mHandle);
  }
  ~ObjectBase() {
    if (mHandle)
      Derived::wgpu_release(mHandle);
  }

  ObjectBase(ObjectBase const &other) : ObjectBase(other.get()) {}
  auto operator=(ObjectBase const &other) -> Derived & {
    if (&other != this) {
      if (mHandle)
        Derived::wgpu_release(mHandle);
      mHandle = other.mHandle;
      if (mHandle)
        Derived::wgpu_reference(mHandle);
    }

    return static_cast<Derived &>(*this);
  }

  ObjectBase(ObjectBase &&other) {
    mHandle = other.mHandle;
    other.mHandle = 0;
  }
  auto operator=(ObjectBase &&other) -> Derived & {
    if (&other != this) {
      if (mHandle)
        Derived::wgpu_release(mHandle);
      mHandle = other.mHandle;
      other.mHandle = 0;
    }

    return static_cast<Derived &>(*this);
  }

  ObjectBase(std::nullptr_t) {}
  auto operator=(std::nullptr_t) -> Derived & {
    if (mHandle != nullptr) {
      Derived::wgpu_release(mHandle);
      mHandle = nullptr;
    }
    return static_cast<Derived &>(*this);
  }

  auto operator==(std::nullptr_t) const -> bool { return mHandle == nullptr; }
  auto operator!=(std::nullptr_t) const -> bool { return mHandle != nullptr; }

  explicit operator bool() const { return mHandle != nullptr; }
  [[nodiscard]] auto get() const -> CType { return mHandle; }
  auto release() -> CType {
    CType result = mHandle;
    mHandle = 0;
    return result;
  }
  static auto acquire(CType handle) -> Derived {
    Derived result;
    result.mHandle = handle;
    return result;
  }

protected:
  CType mHandle = nullptr;
};

class Adapter : public ObjectBase<Adapter, WGPUAdapter> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  auto create_device(DeviceDescriptor const *descriptor = nullptr) const
      -> Device;
  auto enumerate_features(FeatureName *features) const -> size_t;
  auto get_limits(SupportedLimits *limits) const -> bool;
  void get_properties(AdapterProperties *properties) const;
  [[nodiscard]] auto has_feature(FeatureName feature) const -> bool;
  void request_device(DeviceDescriptor const *descriptor,
                      RequestDeviceCallback callback, void *userdata) const;

private:
  friend ObjectBase<Adapter, WGPUAdapter>;
  static void wgpu_reference(WGPUAdapter handle);
  static void wgpu_release(WGPUAdapter handle);
};

class BindGroup : public ObjectBase<BindGroup, WGPUBindGroup> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<BindGroup, WGPUBindGroup>;
  static void wgpu_reference(WGPUBindGroup handle);
  static void wgpu_release(WGPUBindGroup handle);
};

class BindGroupLayout
    : public ObjectBase<BindGroupLayout, WGPUBindGroupLayout> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<BindGroupLayout, WGPUBindGroupLayout>;
  static void wgpu_reference(WGPUBindGroupLayout handle);
  static void wgpu_release(WGPUBindGroupLayout handle);
};

class Buffer : public ObjectBase<Buffer, WGPUBuffer> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void destroy() const;
  [[nodiscard]] auto
  get_const_mapped_range(size_t offset = 0,
                         size_t size = WGPU_WHOLE_MAP_SIZE) const
      -> void const *;
  [[nodiscard]] auto get_mapped_range(size_t offset = 0,
                                      size_t size = WGPU_WHOLE_MAP_SIZE) const
      -> void *;
  [[nodiscard]] auto get_size() const -> uint64_t;
  [[nodiscard]] auto get_usage() const -> BufferUsage;
  void map_async(MapMode mode, size_t offset, size_t size,
                 BufferMapCallback callback, void *userdata) const;
  void set_label(char const *label) const;
  void unmap() const;

private:
  friend ObjectBase<Buffer, WGPUBuffer>;
  static void wgpu_reference(WGPUBuffer handle);
  static void wgpu_release(WGPUBuffer handle);
};

class CommandBuffer : public ObjectBase<CommandBuffer, WGPUCommandBuffer> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<CommandBuffer, WGPUCommandBuffer>;
  static void wgpu_reference(WGPUCommandBuffer handle);
  static void wgpu_release(WGPUCommandBuffer handle);
};

class CommandEncoder : public ObjectBase<CommandEncoder, WGPUCommandEncoder> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  auto
  begin_compute_pass(ComputePassDescriptor const *descriptor = nullptr) const
      -> ComputePassEncoder;
  auto begin_render_pass(RenderPassDescriptor const *descriptor) const
      -> RenderPassEncoder;
  void clear_buffer(Buffer const &buffer, uint64_t offset = 0,
                    uint64_t size = WGPU_WHOLE_SIZE) const;
  void copy_buffer_to_buffer(Buffer const &source, uint64_t source_offset,
                             Buffer const &destination,
                             uint64_t destination_offset, uint64_t size) const;
  void copy_buffer_to_texture(ImageCopyBuffer const *source,
                              ImageCopyTexture const *destination,
                              Extent3D const *copy_size) const;
  void copy_texture_to_buffer(ImageCopyTexture const *source,
                              ImageCopyBuffer const *destination,
                              Extent3D const *copy_size) const;
  void copy_texture_to_texture(ImageCopyTexture const *source,
                               ImageCopyTexture const *destination,
                               Extent3D const *copy_size) const;
  void copy_texture_to_texture_internal(ImageCopyTexture const *source,
                                        ImageCopyTexture const *destination,
                                        Extent3D const *copy_size) const;
  auto finish(CommandBufferDescriptor const *descriptor = nullptr) const
      -> CommandBuffer;
  void inject_validation_error(char const *message) const;
  void insert_debug_marker(char const *marker_label) const;
  void pop_debug_group() const;
  void push_debug_group(char const *group_label) const;
  void resolve_query_set(QuerySet const &query_set, u32 first_query,
                         u32 query_count, Buffer const &destination,
                         uint64_t destination_offset) const;
  void set_label(char const *label) const;
  void write_buffer(Buffer const &buffer, uint64_t buffer_offset,
                    uint8_t const *data, uint64_t size) const;
  void write_timestamp(QuerySet const &query_set, u32 query_index) const;

private:
  friend ObjectBase<CommandEncoder, WGPUCommandEncoder>;
  static void wgpu_reference(WGPUCommandEncoder handle);
  static void wgpu_release(WGPUCommandEncoder handle);
};

class ComputePassEncoder
    : public ObjectBase<ComputePassEncoder, WGPUComputePassEncoder> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void dispatch(u32 workgroup_count_x, u32 workgroup_count_y = 1,
                u32 workgroup_count_z = 1) const;
  void dispatch_indirect(Buffer const &indirect_buffer,
                         uint64_t indirect_offset) const;
  void dispatch_workgroups(u32 workgroup_count_x, u32 workgroup_count_y = 1,
                           u32 workgroup_count_z = 1) const;
  void dispatch_workgroups_indirect(Buffer const &indirect_buffer,
                                    uint64_t indirect_offset) const;
  void end() const;
  void end_pass() const;
  void insert_debug_marker(char const *marker_label) const;
  void pop_debug_group() const;
  void push_debug_group(char const *group_label) const;
  void set_bind_group(u32 group_index, BindGroup const &group,
                      u32 dynamic_offset_count = 0,
                      u32 const *dynamic_offsets = nullptr) const;
  void set_label(char const *label) const;
  void set_pipeline(ComputePipeline const &pipeline) const;
  void write_timestamp(QuerySet const &query_set, u32 query_index) const;

private:
  friend ObjectBase<ComputePassEncoder, WGPUComputePassEncoder>;
  static void wgpu_reference(WGPUComputePassEncoder handle);
  static void wgpu_release(WGPUComputePassEncoder handle);
};

class ComputePipeline
    : public ObjectBase<ComputePipeline, WGPUComputePipeline> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  [[nodiscard]] auto get_bind_group_layout(u32 group_index) const
      -> BindGroupLayout;
  void set_label(char const *label) const;

private:
  friend ObjectBase<ComputePipeline, WGPUComputePipeline>;
  static void wgpu_reference(WGPUComputePipeline handle);
  static void wgpu_release(WGPUComputePipeline handle);
};

class Device : public ObjectBase<Device, WGPUDevice> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  auto create_bind_group(BindGroupDescriptor const *descriptor) const
      -> BindGroup;
  auto
  create_bind_group_layout(BindGroupLayoutDescriptor const *descriptor) const
      -> BindGroupLayout;
  auto create_buffer(BufferDescriptor const *descriptor) const -> Buffer;
  auto create_command_encoder(CommandEncoderDescriptor const *descriptor =
                                  nullptr) const -> CommandEncoder;
  auto
  create_compute_pipeline(ComputePipelineDescriptor const *descriptor) const
      -> ComputePipeline;
  void
  create_compute_pipeline_async(ComputePipelineDescriptor const *descriptor,
                                CreateComputePipelineAsyncCallback callback,
                                void *userdata) const;
  [[nodiscard]] auto create_error_buffer() const -> Buffer;
  [[nodiscard]] auto create_error_external_texture() const -> ExternalTexture;
  auto create_error_texture(TextureDescriptor const *descriptor) const
      -> Texture;
  auto create_external_texture(
      ExternalTextureDescriptor const *external_texture_descriptor) const
      -> ExternalTexture;
  auto create_pipeline_layout(PipelineLayoutDescriptor const *descriptor) const
      -> PipelineLayout;
  auto create_query_set(QuerySetDescriptor const *descriptor) const -> QuerySet;
  auto create_render_bundle_encoder(
      RenderBundleEncoderDescriptor const *descriptor) const
      -> RenderBundleEncoder;
  auto create_render_pipeline(RenderPipelineDescriptor const *descriptor) const
      -> RenderPipeline;
  void create_render_pipeline_async(RenderPipelineDescriptor const *descriptor,
                                    CreateRenderPipelineAsyncCallback callback,
                                    void *userdata) const;
  auto create_sampler(SamplerDescriptor const *descriptor = nullptr) const
      -> Sampler;
  auto create_shader_module(ShaderModuleDescriptor const *descriptor) const
      -> ShaderModule;
  auto create_swap_chain(Surface const &surface,
                         SwapChainDescriptor const *descriptor) const
      -> SwapChain;
  auto create_texture(TextureDescriptor const *descriptor) const -> Texture;
  void destroy() const;
  auto enumerate_features(FeatureName *features) const -> size_t;
  void force_loss(DeviceLostReason type, char const *message) const;
  [[nodiscard]] auto get_adapter() const -> Adapter;
  auto get_limits(SupportedLimits *limits) const -> bool;
  [[nodiscard]] auto get_queue() const -> Queue;
  [[nodiscard]] auto has_feature(FeatureName feature) const -> bool;
  void inject_error(ErrorType type, char const *message) const;
  auto pop_error_scope(ErrorCallback callback, void *userdata) const -> bool;
  void push_error_scope(ErrorFilter filter) const;
  void set_device_lost_callback(DeviceLostCallback callback,
                                void *userdata) const;
  void set_label(char const *label) const;
  void set_logging_callback(LoggingCallback callback, void *userdata) const;
  void set_uncaptured_error_callback(ErrorCallback callback,
                                     void *userdata) const;
  void tick() const;

private:
  friend ObjectBase<Device, WGPUDevice>;
  static void wgpu_reference(WGPUDevice handle);
  static void wgpu_release(WGPUDevice handle);
};

class ExternalTexture
    : public ObjectBase<ExternalTexture, WGPUExternalTexture> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void destroy() const;
  void set_label(char const *label) const;

private:
  friend ObjectBase<ExternalTexture, WGPUExternalTexture>;
  static void wgpu_reference(WGPUExternalTexture handle);
  static void wgpu_release(WGPUExternalTexture handle);
};

class Instance : public ObjectBase<Instance, WGPUInstance> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  auto create_surface(SurfaceDescriptor const *descriptor) const -> Surface;
  void request_adapter(RequestAdapterOptions const *options,
                       RequestAdapterCallback callback, void *userdata) const;

private:
  friend ObjectBase<Instance, WGPUInstance>;
  static void wgpu_reference(WGPUInstance handle);
  static void wgpu_release(WGPUInstance handle);
};

class PipelineLayout : public ObjectBase<PipelineLayout, WGPUPipelineLayout> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<PipelineLayout, WGPUPipelineLayout>;
  static void wgpu_reference(WGPUPipelineLayout handle);
  static void wgpu_release(WGPUPipelineLayout handle);
};

class QuerySet : public ObjectBase<QuerySet, WGPUQuerySet> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void destroy() const;
  [[nodiscard]] auto get_count() const -> u32;
  [[nodiscard]] auto get_type() const -> QueryType;
  void set_label(char const *label) const;

private:
  friend ObjectBase<QuerySet, WGPUQuerySet>;
  static void wgpu_reference(WGPUQuerySet handle);
  static void wgpu_release(WGPUQuerySet handle);
};

class Queue : public ObjectBase<Queue, WGPUQueue> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void
  copy_texture_for_browser(ImageCopyTexture const *source,
                           ImageCopyTexture const *destination,
                           Extent3D const *copy_size,
                           CopyTextureForBrowserOptions const *options) const;
  void on_submitted_work_done(uint64_t signal_value,
                              QueueWorkDoneCallback callback,
                              void *userdata) const;
  void set_label(char const *label) const;
  void submit(u32 command_count, CommandBuffer const *commands) const;
  void write_buffer(Buffer const &buffer, uint64_t buffer_offset,
                    void const *data, size_t size) const;
  void write_texture(ImageCopyTexture const *destination, void const *data,
                     size_t data_size, TextureDataLayout const *data_layout,
                     Extent3D const *write_size) const;

private:
  friend ObjectBase<Queue, WGPUQueue>;
  static void wgpu_reference(WGPUQueue handle);
  static void wgpu_release(WGPUQueue handle);
};

class RenderBundle : public ObjectBase<RenderBundle, WGPURenderBundle> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

private:
  friend ObjectBase<RenderBundle, WGPURenderBundle>;
  static void wgpu_reference(WGPURenderBundle handle);
  static void wgpu_release(WGPURenderBundle handle);
};

class RenderBundleEncoder
    : public ObjectBase<RenderBundleEncoder, WGPURenderBundleEncoder> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void draw(u32 vertex_count, u32 instance_count = 1, u32 first_vertex = 0,
            u32 first_instance = 0) const;
  void draw_indexed(u32 index_count, u32 instance_count = 1,
                    u32 first_index = 0, int32_t base_vertex = 0,
                    u32 first_instance = 0) const;
  void draw_indexed_indirect(Buffer const &indirect_buffer,
                             uint64_t indirect_offset) const;
  void draw_indirect(Buffer const &indirect_buffer,
                     uint64_t indirect_offset) const;
  auto finish(RenderBundleDescriptor const *descriptor = nullptr) const
      -> RenderBundle;
  void insert_debug_marker(char const *marker_label) const;
  void pop_debug_group() const;
  void push_debug_group(char const *group_label) const;
  void set_bind_group(u32 group_index, BindGroup const &group,
                      u32 dynamic_offset_count = 0,
                      u32 const *dynamic_offsets = nullptr) const;
  void set_index_buffer(Buffer const &buffer, IndexFormat format,
                        uint64_t offset = 0,
                        uint64_t size = WGPU_WHOLE_SIZE) const;
  void set_label(char const *label) const;
  void set_pipeline(RenderPipeline const &pipeline) const;
  void set_vertex_buffer(u32 slot, Buffer const &buffer, uint64_t offset = 0,
                         uint64_t size = WGPU_WHOLE_SIZE) const;

private:
  friend ObjectBase<RenderBundleEncoder, WGPURenderBundleEncoder>;
  static void wgpu_reference(WGPURenderBundleEncoder handle);
  static void wgpu_release(WGPURenderBundleEncoder handle);
};

class RenderPassEncoder
    : public ObjectBase<RenderPassEncoder, WGPURenderPassEncoder> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void begin_occlusion_query(u32 query_index) const;
  void draw(u32 vertex_count, u32 instance_count = 1, u32 first_vertex = 0,
            u32 first_instance = 0) const;
  void draw_indexed(u32 index_count, u32 instance_count = 1,
                    u32 first_index = 0, int32_t base_vertex = 0,
                    u32 first_instance = 0) const;
  void draw_indexed_indirect(Buffer const &indirect_buffer,
                             uint64_t indirect_offset) const;
  void draw_indirect(Buffer const &indirect_buffer,
                     uint64_t indirect_offset) const;
  void end() const;
  void end_occlusion_query() const;
  void end_pass() const;
  void execute_bundles(u32 bundle_count, RenderBundle const *bundles) const;
  void insert_debug_marker(char const *marker_label) const;
  void pop_debug_group() const;
  void push_debug_group(char const *group_label) const;
  void set_bind_group(u32 group_index, BindGroup const &group,
                      u32 dynamic_offset_count = 0,
                      u32 const *dynamic_offsets = nullptr) const;
  void set_blend_constant(Color const *color) const;
  void set_index_buffer(Buffer const &buffer, IndexFormat format,
                        uint64_t offset = 0,
                        uint64_t size = WGPU_WHOLE_SIZE) const;
  void set_label(char const *label) const;
  void set_pipeline(RenderPipeline const &pipeline) const;
  void set_scissor_rect(u32 x, u32 y, u32 width, u32 height) const;
  void set_stencil_reference(u32 reference) const;
  void set_vertex_buffer(u32 slot, Buffer const &buffer, uint64_t offset = 0,
                         uint64_t size = WGPU_WHOLE_SIZE) const;
  void set_viewport(float x, float y, float width, float height,
                    float min_depth, float max_depth) const;
  void write_timestamp(QuerySet const &query_set, u32 query_index) const;

private:
  friend ObjectBase<RenderPassEncoder, WGPURenderPassEncoder>;
  static void wgpu_reference(WGPURenderPassEncoder handle);
  static void wgpu_release(WGPURenderPassEncoder handle);
};

class RenderPipeline : public ObjectBase<RenderPipeline, WGPURenderPipeline> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  [[nodiscard]] auto get_bind_group_layout(u32 group_index) const
      -> BindGroupLayout;
  void set_label(char const *label) const;

private:
  friend ObjectBase<RenderPipeline, WGPURenderPipeline>;
  static void wgpu_reference(WGPURenderPipeline handle);
  static void wgpu_release(WGPURenderPipeline handle);
};

class Sampler : public ObjectBase<Sampler, WGPUSampler> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<Sampler, WGPUSampler>;
  static void wgpu_reference(WGPUSampler handle);
  static void wgpu_release(WGPUSampler handle);
};

class ShaderModule : public ObjectBase<ShaderModule, WGPUShaderModule> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void get_compilation_info(CompilationInfoCallback callback,
                            void *userdata) const;
  void set_label(char const *label) const;

private:
  friend ObjectBase<ShaderModule, WGPUShaderModule>;
  static void wgpu_reference(WGPUShaderModule handle);
  static void wgpu_release(WGPUShaderModule handle);
};

class Surface : public ObjectBase<Surface, WGPUSurface> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

private:
  friend ObjectBase<Surface, WGPUSurface>;
  static void wgpu_reference(WGPUSurface handle);
  static void wgpu_release(WGPUSurface handle);
};

class SwapChain : public ObjectBase<SwapChain, WGPUSwapChain> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void configure(TextureFormat format, TextureUsage allowed_usage, u32 width,
                 u32 height) const;
  [[nodiscard]] auto get_current_texture_view() const -> TextureView;
  void present() const;

private:
  friend ObjectBase<SwapChain, WGPUSwapChain>;
  static void wgpu_reference(WGPUSwapChain handle);
  static void wgpu_release(WGPUSwapChain handle);
};

class Texture : public ObjectBase<Texture, WGPUTexture> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  auto create_view(TextureViewDescriptor const *descriptor = nullptr) const
      -> TextureView;
  void destroy() const;
  [[nodiscard]] auto get_depth_or_array_layers() const -> u32;
  [[nodiscard]] auto get_dimension() const -> TextureDimension;
  [[nodiscard]] auto get_format() const -> TextureFormat;
  [[nodiscard]] auto get_height() const -> u32;
  [[nodiscard]] auto get_mip_level_count() const -> u32;
  [[nodiscard]] auto get_sample_count() const -> u32;
  [[nodiscard]] auto get_usage() const -> TextureUsage;
  [[nodiscard]] auto get_width() const -> u32;
  void set_label(char const *label) const;

private:
  friend ObjectBase<Texture, WGPUTexture>;
  static void wgpu_reference(WGPUTexture handle);
  static void wgpu_release(WGPUTexture handle);
};

class TextureView : public ObjectBase<TextureView, WGPUTextureView> {
public:
  using ObjectBase::ObjectBase;
  using ObjectBase::operator=;

  void set_label(char const *label) const;

private:
  friend ObjectBase<TextureView, WGPUTextureView>;
  static void wgpu_reference(WGPUTextureView handle);
  static void wgpu_release(WGPUTextureView handle);
};

MOON_API auto CreateInstance(InstanceDescriptor const *descriptor = nullptr)
    -> Instance;
MOON_API auto GetProcAddress(Device device, char const *proc_name) -> Proc;

struct ChainedStruct {
  ChainedStruct const *nextInChain = nullptr;
  SType sType = SType::Invalid;
};

struct ChainedStructOut {
  ChainedStruct *nextInChain = nullptr;
  SType sType = SType::Invalid;
};

struct AdapterProperties {
  ChainedStructOut *nextInChain = nullptr;
  u32 vendorID;
  char const *vendorName;
  char const *architecture;
  u32 deviceID;
  char const *name;
  char const *driverDescription;
  AdapterType adapterType;
  BackendType backendType;
};

struct BindGroupEntry {
  ChainedStruct const *nextInChain = nullptr;
  u32 binding;
  Buffer buffer = nullptr;
  uint64_t offset = 0;
  uint64_t size = WGPU_WHOLE_SIZE;
  Sampler sampler = nullptr;
  TextureView textureView = nullptr;
};

struct BlendComponent {
  BlendOperation operation = BlendOperation::Add;
  BlendFactor srcFactor = BlendFactor::One;
  BlendFactor dstFactor = BlendFactor::Zero;
};

struct BufferBindingLayout {
  ChainedStruct const *nextInChain = nullptr;
  BufferBindingType type = BufferBindingType::Undefined;
  bool hasDynamicOffset = false;
  uint64_t minBindingSize = 0;
};

struct BufferDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  BufferUsage usage;
  uint64_t size;
  bool mappedAtCreation = false;
};

struct Color {
  double r;
  double g;
  double b;
  double a;
};

struct CommandBufferDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

struct CommandEncoderDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

struct CompilationMessage {
  ChainedStruct const *nextInChain = nullptr;
  char const *message = nullptr;
  CompilationMessageType type;
  uint64_t lineNum;
  uint64_t linePos;
  uint64_t offset;
  uint64_t length;
};

struct ComputePassTimestampWrite {
  QuerySet querySet;
  u32 queryIndex;
  ComputePassTimestampLocation location;
};

struct ConstantEntry {
  ChainedStruct const *nextInChain = nullptr;
  char const *key;
  double value;
};

struct CopyTextureForBrowserOptions {
  ChainedStruct const *nextInChain = nullptr;
  bool flipY = false;
  bool needsColorSpaceConversion = false;
  AlphaMode srcAlphaMode = AlphaMode::Unpremultiplied;
  float const *srcTransferFunctionParameters = nullptr;
  float const *conversionMatrix = nullptr;
  float const *dstTransferFunctionParameters = nullptr;
  AlphaMode dstAlphaMode = AlphaMode::Unpremultiplied;
  bool internalUsage = false;
};

// Can be chained in AdapterProperties
struct MoonAdapterPropertiesPowerPreference : ChainedStructOut {
  MoonAdapterPropertiesPowerPreference() {
    sType = SType::MoonAdapterPropertiesPowerPreference;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(PowerPreference));
  alignas(kFirstMemberAlignment)
      PowerPreference powerPreference = PowerPreference::Undefined;
};

// Can be chained in DeviceDescriptor
struct MoonCacheDeviceDescriptor : ChainedStruct {
  MoonCacheDeviceDescriptor() { sType = SType::MoonCacheDeviceDescriptor; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(char const *));
  alignas(kFirstMemberAlignment) char const *isolationKey = "";
};

// Can be chained in CommandEncoderDescriptor
struct MoonEncoderInternalUsageDescriptor : ChainedStruct {
  MoonEncoderInternalUsageDescriptor() {
    sType = SType::MoonEncoderInternalUsageDescriptor;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(bool));
  alignas(kFirstMemberAlignment) bool useInternalUsages = false;
};

// Can be chained in InstanceDescriptor
struct MoonInstanceDescriptor : ChainedStruct {
  MoonInstanceDescriptor() { sType = SType::MoonInstanceDescriptor; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(u32));
  alignas(kFirstMemberAlignment) u32 additionalRuntimeSearchPathsCount = 0;
  const char *const *additionalRuntimeSearchPaths;
};

// Can be chained in TextureDescriptor
struct MoonTextureInternalUsageDescriptor : ChainedStruct {
  MoonTextureInternalUsageDescriptor() {
    sType = SType::MoonTextureInternalUsageDescriptor;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(TextureUsage));
  alignas(kFirstMemberAlignment)
      TextureUsage internalUsage = TextureUsage::None;
};

// Can be chained in DeviceDescriptor
struct MoonTogglesDeviceDescriptor : ChainedStruct {
  MoonTogglesDeviceDescriptor() { sType = SType::MoonTogglesDeviceDescriptor; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(u32));
  alignas(kFirstMemberAlignment) u32 forceEnabledTogglesCount = 0;
  const char *const *forceEnabledToggles;
  u32 forceDisabledTogglesCount = 0;
  const char *const *forceDisabledToggles;
};

struct Extent3D {
  u32 width;
  u32 height = 1;
  u32 depthOrArrayLayers = 1;
};

// Can be chained in BindGroupEntry
struct ExternalTextureBindingEntry : ChainedStruct {
  ExternalTextureBindingEntry() { sType = SType::ExternalTextureBindingEntry; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(ExternalTexture));
  alignas(kFirstMemberAlignment) ExternalTexture externalTexture;
};

// Can be chained in BindGroupLayoutEntry
struct ExternalTextureBindingLayout : ChainedStruct {
  ExternalTextureBindingLayout() {
    sType = SType::ExternalTextureBindingLayout;
  }
};

struct ExternalTextureDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  TextureView plane0;
  TextureView plane1 = nullptr;
  bool doYuvToRgbConversionOnly = false;
  float const *yuvToRgbConversionMatrix = nullptr;
  float const *srcTransferFunctionParameters;
  float const *dstTransferFunctionParameters;
  float const *gamutConversionMatrix;
};

struct InstanceDescriptor {
  ChainedStruct const *nextInChain = nullptr;
};

struct Limits {
  u32 maxTextureDimension1D = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxTextureDimension2D = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxTextureDimension3D = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxTextureArrayLayers = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxBindGroups = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxBindingsPerBindGroup = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxDynamicUniformBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxDynamicStorageBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxSampledTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxSamplersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxStorageBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxStorageTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxUniformBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
  uint64_t maxUniformBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
  uint64_t maxStorageBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
  u32 minUniformBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
  u32 minStorageBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
  uint64_t maxBufferSize = WGPU_LIMIT_U64_UNDEFINED;
  u32 maxVertexAttributes = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxVertexBufferArrayStride = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxInterStageShaderComponents = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxInterStageShaderVariables = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxColorAttachments = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeWorkgroupStorageSize = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeInvocationsPerWorkgroup = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeWorkgroupSizeX = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeWorkgroupSizeY = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeWorkgroupSizeZ = WGPU_LIMIT_U32_UNDEFINED;
  u32 maxComputeWorkgroupsPerDimension = WGPU_LIMIT_U32_UNDEFINED;
};

struct MultisampleState {
  ChainedStruct const *nextInChain = nullptr;
  u32 count = 1;
  u32 mask = 0xFFFFFFFF;
  bool alphaToCoverageEnabled = false;
};

struct Origin3D {
  u32 x = 0;
  u32 y = 0;
  u32 z = 0;
};

struct PipelineLayoutDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 bindGroupLayoutCount;
  BindGroupLayout const *bindGroupLayouts;
};

// Can be chained in PrimitiveState
struct PrimitiveDepthClipControl : ChainedStruct {
  PrimitiveDepthClipControl() { sType = SType::PrimitiveDepthClipControl; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(bool));
  alignas(kFirstMemberAlignment) bool unclippedDepth = false;
};

struct PrimitiveState {
  ChainedStruct const *nextInChain = nullptr;
  PrimitiveTopology topology = PrimitiveTopology::TriangleList;
  IndexFormat stripIndexFormat = IndexFormat::Undefined;
  FrontFace frontFace = FrontFace::CCW;
  CullMode cullMode = CullMode::None;
};

struct QuerySetDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  QueryType type;
  u32 count;
  PipelineStatisticName const *pipelineStatistics;
  u32 pipelineStatisticsCount = 0;
};

struct QueueDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

struct RenderBundleDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

struct RenderBundleEncoderDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 colorFormatsCount;
  TextureFormat const *colorFormats;
  TextureFormat depthStencilFormat = TextureFormat::Undefined;
  u32 sampleCount = 1;
  bool depthReadOnly = false;
  bool stencilReadOnly = false;
};

struct RenderPassDepthStencilAttachment {
  TextureView view;
  LoadOp depthLoadOp = LoadOp::Undefined;
  StoreOp depthStoreOp = StoreOp::Undefined;
  float clearDepth = NAN;
  float depthClearValue = 0;
  bool depthReadOnly = false;
  LoadOp stencilLoadOp = LoadOp::Undefined;
  StoreOp stencilStoreOp = StoreOp::Undefined;
  u32 clearStencil = 0;
  u32 stencilClearValue = 0;
  bool stencilReadOnly = false;
};

// Can be chained in RenderPassDescriptor
struct RenderPassDescriptorMaxDrawCount : ChainedStruct {
  RenderPassDescriptorMaxDrawCount() {
    sType = SType::RenderPassDescriptorMaxDrawCount;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(uint64_t));
  alignas(kFirstMemberAlignment) uint64_t maxDrawCount = 50000000;
};

struct RenderPassTimestampWrite {
  QuerySet querySet;
  u32 queryIndex;
  RenderPassTimestampLocation location;
};

struct RequestAdapterOptions {
  ChainedStruct const *nextInChain = nullptr;
  Surface compatibleSurface = nullptr;
  PowerPreference powerPreference = PowerPreference::Undefined;
  bool forceFallbackAdapter = false;
};

struct SamplerBindingLayout {
  ChainedStruct const *nextInChain = nullptr;
  SamplerBindingType type = SamplerBindingType::Undefined;
};

struct SamplerDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  AddressMode addressModeU = AddressMode::ClampToEdge;
  AddressMode addressModeV = AddressMode::ClampToEdge;
  AddressMode addressModeW = AddressMode::ClampToEdge;
  FilterMode magFilter = FilterMode::Nearest;
  FilterMode minFilter = FilterMode::Nearest;
  FilterMode mipmapFilter = FilterMode::Nearest;
  float lodMinClamp = 0.0f;
  float lodMaxClamp = 1000.0f;
  CompareFunction compare = CompareFunction::Undefined;
  uint16_t maxAnisotropy = 1;
};

struct ShaderModuleDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleSPIRVDescriptor : ChainedStruct {
  ShaderModuleSPIRVDescriptor() { sType = SType::ShaderModuleSPIRVDescriptor; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(u32));
  alignas(kFirstMemberAlignment) u32 codeSize;
  u32 const *code;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleWGSLDescriptor : ChainedStruct {
  ShaderModuleWGSLDescriptor() { sType = SType::ShaderModuleWGSLDescriptor; }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(char const *));
  alignas(kFirstMemberAlignment) char const *source;
};

struct StencilFaceState {
  CompareFunction compare = CompareFunction::Always;
  StencilOperation failOp = StencilOperation::Keep;
  StencilOperation depthFailOp = StencilOperation::Keep;
  StencilOperation passOp = StencilOperation::Keep;
};

struct StorageTextureBindingLayout {
  ChainedStruct const *nextInChain = nullptr;
  StorageTextureAccess access = StorageTextureAccess::Undefined;
  TextureFormat format = TextureFormat::Undefined;
  TextureViewDimension viewDimension = TextureViewDimension::Undefined;
};

struct SurfaceDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromAndroidNativeWindow : ChainedStruct {
  SurfaceDescriptorFromAndroidNativeWindow() {
    sType = SType::SurfaceDescriptorFromAndroidNativeWindow;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *window;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromCanvasHTMLSelector : ChainedStruct {
  SurfaceDescriptorFromCanvasHTMLSelector() {
    sType = SType::SurfaceDescriptorFromCanvasHTMLSelector;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(char const *));
  alignas(kFirstMemberAlignment) char const *selector;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromMetalLayer : ChainedStruct {
  SurfaceDescriptorFromMetalLayer() {
    sType = SType::SurfaceDescriptorFromMetalLayer;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *layer;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWaylandSurface : ChainedStruct {
  SurfaceDescriptorFromWaylandSurface() {
    sType = SType::SurfaceDescriptorFromWaylandSurface;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *display;
  void *surface;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsCoreWindow : ChainedStruct {
  SurfaceDescriptorFromWindowsCoreWindow() {
    sType = SType::SurfaceDescriptorFromWindowsCoreWindow;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *coreWindow;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsHWND : ChainedStruct {
  SurfaceDescriptorFromWindowsHWND() {
    sType = SType::SurfaceDescriptorFromWindowsHWND;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *hinstance;
  void *hwnd;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsSwapChainPanel : ChainedStruct {
  SurfaceDescriptorFromWindowsSwapChainPanel() {
    sType = SType::SurfaceDescriptorFromWindowsSwapChainPanel;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *swapChainPanel;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromXlibWindow : ChainedStruct {
  SurfaceDescriptorFromXlibWindow() {
    sType = SType::SurfaceDescriptorFromXlibWindow;
  }
  static constexpr size_t kFirstMemberAlignment =
      detail::ConstexprMax(alignof(ChainedStruct), alignof(void *));
  alignas(kFirstMemberAlignment) void *display;
  u32 window;
};

struct SwapChainDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  TextureUsage usage;
  TextureFormat format;
  u32 width;
  u32 height;
  PresentMode presentMode;
  uint64_t implementation = 0;
};

struct TextureBindingLayout {
  ChainedStruct const *nextInChain = nullptr;
  TextureSampleType sampleType = TextureSampleType::Undefined;
  TextureViewDimension viewDimension = TextureViewDimension::Undefined;
  bool multisampled = false;
};

struct TextureDataLayout {
  ChainedStruct const *nextInChain = nullptr;
  uint64_t offset = 0;
  u32 bytesPerRow = WGPU_COPY_STRIDE_UNDEFINED;
  u32 rowsPerImage = WGPU_COPY_STRIDE_UNDEFINED;
};

struct TextureViewDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  TextureFormat format = TextureFormat::Undefined;
  TextureViewDimension dimension = TextureViewDimension::Undefined;
  u32 baseMipLevel = 0;
  u32 mipLevelCount = WGPU_MIP_LEVEL_COUNT_UNDEFINED;
  u32 baseArrayLayer = 0;
  u32 arrayLayerCount = WGPU_ARRAY_LAYER_COUNT_UNDEFINED;
  TextureAspect aspect = TextureAspect::All;
};

struct VertexAttribute {
  VertexFormat format;
  uint64_t offset;
  u32 shaderLocation;
};

struct BindGroupDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  BindGroupLayout layout;
  u32 entryCount;
  BindGroupEntry const *entries;
};

struct BindGroupLayoutEntry {
  ChainedStruct const *nextInChain = nullptr;
  u32 binding;
  ShaderStage visibility;
  BufferBindingLayout buffer;
  SamplerBindingLayout sampler;
  TextureBindingLayout texture;
  StorageTextureBindingLayout storageTexture;
};

struct BlendState {
  BlendComponent color;
  BlendComponent alpha;
};

struct CompilationInfo {
  ChainedStruct const *nextInChain = nullptr;
  u32 messageCount;
  CompilationMessage const *messages;
};

struct ComputePassDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 timestampWriteCount = 0;
  ComputePassTimestampWrite const *timestampWrites;
};

struct DepthStencilState {
  ChainedStruct const *nextInChain = nullptr;
  TextureFormat format;
  bool depthWriteEnabled = false;
  CompareFunction depthCompare = CompareFunction::Always;
  StencilFaceState stencilFront;
  StencilFaceState stencilBack;
  u32 stencilReadMask = 0xFFFFFFFF;
  u32 stencilWriteMask = 0xFFFFFFFF;
  int32_t depthBias = 0;
  float depthBiasSlopeScale = 0.0f;
  float depthBiasClamp = 0.0f;
};

struct ImageCopyBuffer {
  ChainedStruct const *nextInChain = nullptr;
  TextureDataLayout layout;
  Buffer buffer;
};

struct ImageCopyTexture {
  ChainedStruct const *nextInChain = nullptr;
  Texture texture;
  u32 mipLevel = 0;
  Origin3D origin;
  TextureAspect aspect = TextureAspect::All;
};

struct ProgrammableStageDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  ShaderModule module;
  char const *entryPoint;
  u32 constantCount = 0;
  ConstantEntry const *constants;
};

struct RenderPassColorAttachment {
  TextureView view = nullptr;
  TextureView resolveTarget = nullptr;
  LoadOp loadOp;
  StoreOp storeOp;
  Color clearColor = {NAN, NAN, NAN, NAN};
  Color clearValue;
};

struct RequiredLimits {
  ChainedStruct const *nextInChain = nullptr;
  Limits limits;
};

struct SupportedLimits {
  ChainedStructOut *nextInChain = nullptr;
  Limits limits;
};

struct TextureDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  TextureUsage usage;
  TextureDimension dimension = TextureDimension::e2D;
  Extent3D size;
  TextureFormat format;
  u32 mipLevelCount = 1;
  u32 sampleCount = 1;
  u32 viewFormatCount = 0;
  TextureFormat const *viewFormats;
};

struct VertexBufferLayout {
  uint64_t arrayStride;
  VertexStepMode stepMode = VertexStepMode::Vertex;
  u32 attributeCount;
  VertexAttribute const *attributes;
};

struct BindGroupLayoutDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 entryCount;
  BindGroupLayoutEntry const *entries;
};

struct ColorTargetState {
  ChainedStruct const *nextInChain = nullptr;
  TextureFormat format;
  BlendState const *blend = nullptr;
  ColorWriteMask writeMask = ColorWriteMask::All;
};

struct ComputePipelineDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  PipelineLayout layout = nullptr;
  ProgrammableStageDescriptor compute;
};

struct DeviceDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 requiredFeaturesCount = 0;
  FeatureName const *requiredFeatures = nullptr;
  RequiredLimits const *requiredLimits = nullptr;
  QueueDescriptor defaultQueue;
};

struct RenderPassDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  u32 colorAttachmentCount;
  RenderPassColorAttachment const *colorAttachments;
  RenderPassDepthStencilAttachment const *depthStencilAttachment = nullptr;
  QuerySet occlusionQuerySet = nullptr;
  u32 timestampWriteCount = 0;
  RenderPassTimestampWrite const *timestampWrites;
};

struct VertexState {
  ChainedStruct const *nextInChain = nullptr;
  ShaderModule module;
  char const *entryPoint;
  u32 constantCount = 0;
  ConstantEntry const *constants;
  u32 bufferCount = 0;
  VertexBufferLayout const *buffers;
};

struct FragmentState {
  ChainedStruct const *nextInChain = nullptr;
  ShaderModule module;
  char const *entryPoint;
  u32 constantCount = 0;
  ConstantEntry const *constants;
  u32 targetCount;
  ColorTargetState const *targets;
};

struct RenderPipelineDescriptor {
  ChainedStruct const *nextInChain = nullptr;
  char const *label = nullptr;
  PipelineLayout layout = nullptr;
  VertexState vertex;
  PrimitiveState primitive;
  DepthStencilState const *depthStencil = nullptr;
  MultisampleState multisample;
  FragmentState const *fragment = nullptr;
};

template <> struct IsMoonBitmask<BufferUsage> {
  static constexpr bool enable = true;
};

template <> struct IsMoonBitmask<ColorWriteMask> {
  static constexpr bool enable = true;
};

template <> struct IsMoonBitmask<MapMode> {
  static constexpr bool enable = true;
};

template <> struct IsMoonBitmask<ShaderStage> {
  static constexpr bool enable = true;
};

template <> struct IsMoonBitmask<TextureUsage> {
  static constexpr bool enable = true;
};

struct GPUProcTable {
  WGPUProcCreateInstance create_instance;
  WGPUProcGetProcAddress get_proc_address;

  WGPUProcAdapterCreateDevice adapter_create_device;
  WGPUProcAdapterEnumerateFeatures adapter_enumerate_features;
  WGPUProcAdapterGetLimits adapter_get_limits;
  WGPUProcAdapterGetProperties adapter_get_properties;
  WGPUProcAdapterHasFeature adapter_has_feature;
  WGPUProcAdapterRequestDevice adapter_request_device;
  WGPUProcAdapterReference adapter_reference;
  WGPUProcAdapterRelease adapter_release;

  WGPUProcBindGroupSetLabel bind_group_set_label;
  WGPUProcBindGroupReference bind_group_reference;
  WGPUProcBindGroupRelease bind_group_release;

  WGPUProcBindGroupLayoutSetLabel bind_group_layout_set_label;
  WGPUProcBindGroupLayoutReference bind_group_layout_reference;
  WGPUProcBindGroupLayoutRelease bind_group_layout_release;

  WGPUProcBufferDestroy buffer_destroy;
  WGPUProcBufferGetConstMappedRange buffer_get_const_mapped_range;
  WGPUProcBufferGetMappedRange buffer_get_mapped_range;
  WGPUProcBufferGetSize buffer_get_size;
  WGPUProcBufferGetUsage buffer_get_usage;
  WGPUProcBufferMapAsync buffer_map_async;
  WGPUProcBufferSetLabel buffer_set_label;
  WGPUProcBufferUnmap buffer_unmap;
  WGPUProcBufferReference buffer_reference;
  WGPUProcBufferRelease buffer_release;

  WGPUProcCommandBufferSetLabel command_buffer_set_label;
  WGPUProcCommandBufferReference command_buffer_reference;
  WGPUProcCommandBufferRelease command_buffer_release;

  WGPUProcCommandEncoderBeginComputePass command_encoder_begin_compute_pass;
  WGPUProcCommandEncoderBeginRenderPass command_encoder_begin_render_pass;
  WGPUProcCommandEncoderClearBuffer command_encoder_clear_buffer;
  WGPUProcCommandEncoderCopyBufferToBuffer
      command_encoder_copy_buffer_to_buffer;
  WGPUProcCommandEncoderCopyBufferToTexture
      command_encoder_copy_buffer_to_texture;
  WGPUProcCommandEncoderCopyTextureToBuffer
      command_encoder_copy_texture_to_buffer;
  WGPUProcCommandEncoderCopyTextureToTexture
      command_encoder_copy_texture_to_texture;
  WGPUProcCommandEncoderCopyTextureToTextureInternal
      command_encoder_copy_texture_to_texture_internal;
  WGPUProcCommandEncoderFinish command_encoder_finish;
  WGPUProcCommandEncoderInjectValidationError
      command_encoder_inject_validation_error;
  WGPUProcCommandEncoderInsertDebugMarker command_encoder_insert_debug_marker;
  WGPUProcCommandEncoderPopDebugGroup command_encoder_pop_debug_group;
  WGPUProcCommandEncoderPushDebugGroup command_encoder_push_debug_group;
  WGPUProcCommandEncoderResolveQuerySet command_encoder_resolve_query_set;
  WGPUProcCommandEncoderSetLabel command_encoder_set_label;
  WGPUProcCommandEncoderWriteBuffer command_encoder_write_buffer;
  WGPUProcCommandEncoderWriteTimestamp command_encoder_write_timestamp;
  WGPUProcCommandEncoderReference command_encoder_reference;
  WGPUProcCommandEncoderRelease command_encoder_release;

  WGPUProcComputePassEncoderDispatch compute_pass_encoder_dispatch;
  WGPUProcComputePassEncoderDispatchIndirect
      compute_pass_encoder_dispatch_indirect;
  WGPUProcComputePassEncoderDispatchWorkgroups
      compute_pass_encoder_dispatch_workgroups;
  WGPUProcComputePassEncoderDispatchWorkgroupsIndirect
      compute_pass_encoder_dispatch_workgroups_indirect;
  WGPUProcComputePassEncoderEnd compute_pass_encoder_end;
  WGPUProcComputePassEncoderEndPass compute_pass_encoder_end_pass;
  WGPUProcComputePassEncoderInsertDebugMarker
      compute_pass_encoder_insert_debug_marker;
  WGPUProcComputePassEncoderPopDebugGroup compute_pass_encoder_pop_debug_group;
  WGPUProcComputePassEncoderPushDebugGroup
      compute_pass_encoder_push_debug_group;
  WGPUProcComputePassEncoderSetBindGroup compute_pass_encoder_set_bind_group;
  WGPUProcComputePassEncoderSetLabel compute_pass_encoder_set_label;
  WGPUProcComputePassEncoderSetPipeline compute_pass_encoder_set_pipeline;
  WGPUProcComputePassEncoderWriteTimestamp compute_pass_encoder_write_timestamp;
  WGPUProcComputePassEncoderReference compute_pass_encoder_reference;
  WGPUProcComputePassEncoderRelease compute_pass_encoder_release;

  WGPUProcComputePipelineGetBindGroupLayout
      compute_pipeline_get_bind_group_layout;
  WGPUProcComputePipelineSetLabel compute_pipeline_set_label;
  WGPUProcComputePipelineReference compute_pipeline_reference;
  WGPUProcComputePipelineRelease compute_pipeline_release;

  WGPUProcDeviceCreateBindGroup device_create_bind_group;
  WGPUProcDeviceCreateBindGroupLayout device_create_bind_group_layout;
  WGPUProcDeviceCreateBuffer device_create_buffer;
  WGPUProcDeviceCreateCommandEncoder device_create_command_encoder;
  WGPUProcDeviceCreateComputePipeline device_create_compute_pipeline;
  WGPUProcDeviceCreateComputePipelineAsync device_create_compute_pipeline_async;
  WGPUProcDeviceCreateErrorBuffer device_create_error_buffer;
  WGPUProcDeviceCreateErrorExternalTexture device_create_error_external_texture;
  WGPUProcDeviceCreateErrorTexture device_create_error_texture;
  WGPUProcDeviceCreateExternalTexture device_create_external_texture;
  WGPUProcDeviceCreatePipelineLayout device_create_pipeline_layout;
  WGPUProcDeviceCreateQuerySet device_create_query_set;
  WGPUProcDeviceCreateRenderBundleEncoder device_create_render_bundle_encoder;
  WGPUProcDeviceCreateRenderPipeline device_create_render_pipeline;
  WGPUProcDeviceCreateRenderPipelineAsync device_create_render_pipeline_async;
  WGPUProcDeviceCreateSampler device_create_sampler;
  WGPUProcDeviceCreateShaderModule device_create_shader_module;
  WGPUProcDeviceCreateSwapChain device_create_swap_chain;
  WGPUProcDeviceCreateTexture device_create_texture;
  WGPUProcDeviceDestroy device_destroy;
  WGPUProcDeviceEnumerateFeatures device_enumerate_features;
  WGPUProcDeviceForceLoss device_force_loss;
  WGPUProcDeviceGetAdapter device_get_adapter;
  WGPUProcDeviceGetLimits device_get_limits;
  WGPUProcDeviceGetQueue device_get_queue;
  WGPUProcDeviceHasFeature device_has_feature;
  WGPUProcDeviceInjectError device_inject_error;
  WGPUProcDevicePopErrorScope device_pop_error_scope;
  WGPUProcDevicePushErrorScope device_push_error_scope;
  WGPUProcDeviceSetDeviceLostCallback device_set_device_lost_callback;
  WGPUProcDeviceSetLabel device_set_label;
  WGPUProcDeviceSetLoggingCallback device_set_logging_callback;
  WGPUProcDeviceSetUncapturedErrorCallback device_set_uncaptured_error_callback;
  WGPUProcDeviceTick device_tick;
  WGPUProcDeviceReference device_reference;
  WGPUProcDeviceRelease device_release;

  WGPUProcExternalTextureDestroy external_texture_destroy;
  WGPUProcExternalTextureSetLabel external_texture_set_label;
  WGPUProcExternalTextureReference external_texture_reference;
  WGPUProcExternalTextureRelease external_texture_release;

  WGPUProcInstanceCreateSurface instance_create_surface;
  WGPUProcInstanceRequestAdapter instance_request_adapter;
  WGPUProcInstanceReference instance_reference;
  WGPUProcInstanceRelease instance_release;

  WGPUProcPipelineLayoutSetLabel pipeline_layout_set_label;
  WGPUProcPipelineLayoutReference pipeline_layout_reference;
  WGPUProcPipelineLayoutRelease pipeline_layout_release;

  WGPUProcQuerySetDestroy query_set_destroy;
  WGPUProcQuerySetGetCount query_set_get_count;
  WGPUProcQuerySetGetType query_set_get_type;
  WGPUProcQuerySetSetLabel query_set_set_label;
  WGPUProcQuerySetReference query_set_reference;
  WGPUProcQuerySetRelease query_set_release;

  WGPUProcQueueCopyTextureForBrowser queue_copy_texture_for_browser;
  WGPUProcQueueOnSubmittedWorkDone queue_on_submitted_work_done;
  WGPUProcQueueSetLabel queue_set_label;
  WGPUProcQueueSubmit queue_submit;
  WGPUProcQueueWriteBuffer queue_write_buffer;
  WGPUProcQueueWriteTexture queue_write_texture;
  WGPUProcQueueReference queue_reference;
  WGPUProcQueueRelease queue_release;

  WGPUProcRenderBundleReference render_bundle_reference;
  WGPUProcRenderBundleRelease render_bundle_release;

  WGPUProcRenderBundleEncoderDraw render_bundle_encoder_draw;
  WGPUProcRenderBundleEncoderDrawIndexed render_bundle_encoder_draw_indexed;
  WGPUProcRenderBundleEncoderDrawIndexedIndirect
      render_bundle_encoder_draw_indexed_indirect;
  WGPUProcRenderBundleEncoderDrawIndirect render_bundle_encoder_draw_indirect;
  WGPUProcRenderBundleEncoderFinish render_bundle_encoder_finish;
  WGPUProcRenderBundleEncoderInsertDebugMarker
      render_bundle_encoder_insert_debug_marker;
  WGPUProcRenderBundleEncoderPopDebugGroup
      render_bundle_encoder_pop_debug_group;
  WGPUProcRenderBundleEncoderPushDebugGroup
      render_bundle_encoder_push_debug_group;
  WGPUProcRenderBundleEncoderSetBindGroup render_bundle_encoder_set_bind_group;
  WGPUProcRenderBundleEncoderSetIndexBuffer
      render_bundle_encoder_set_index_buffer;
  WGPUProcRenderBundleEncoderSetLabel render_bundle_encoder_set_label;
  WGPUProcRenderBundleEncoderSetPipeline render_bundle_encoder_set_pipeline;
  WGPUProcRenderBundleEncoderSetVertexBuffer
      render_bundle_encoder_set_vertex_buffer;
  WGPUProcRenderBundleEncoderReference render_bundle_encoder_reference;
  WGPUProcRenderBundleEncoderRelease render_bundle_encoder_release;

  WGPUProcRenderPassEncoderBeginOcclusionQuery
      render_pass_encoder_begin_occlusion_query;
  WGPUProcRenderPassEncoderDraw render_pass_encoder_draw;
  WGPUProcRenderPassEncoderDrawIndexed render_pass_encoder_draw_indexed;
  WGPUProcRenderPassEncoderDrawIndexedIndirect
      render_pass_encoder_draw_indexed_indirect;
  WGPUProcRenderPassEncoderDrawIndirect render_pass_encoder_draw_indirect;
  WGPUProcRenderPassEncoderEnd render_pass_encoder_end;
  WGPUProcRenderPassEncoderEndOcclusionQuery
      render_pass_encoder_end_occlusion_query;
  WGPUProcRenderPassEncoderEndPass render_pass_encoder_end_pass;
  WGPUProcRenderPassEncoderExecuteBundles render_pass_encoder_execute_bundles;
  WGPUProcRenderPassEncoderInsertDebugMarker
      render_pass_encoder_insert_debug_marker;
  WGPUProcRenderPassEncoderPopDebugGroup render_pass_encoder_pop_debug_group;
  WGPUProcRenderPassEncoderPushDebugGroup render_pass_encoder_push_debug_group;
  WGPUProcRenderPassEncoderSetBindGroup render_pass_encoder_set_bind_group;
  WGPUProcRenderPassEncoderSetBlendConstant
      render_pass_encoder_set_blend_constant;
  WGPUProcRenderPassEncoderSetIndexBuffer render_pass_encoder_set_index_buffer;
  WGPUProcRenderPassEncoderSetLabel render_pass_encoder_set_label;
  WGPUProcRenderPassEncoderSetPipeline render_pass_encoder_set_pipeline;
  WGPUProcRenderPassEncoderSetScissorRect render_pass_encoder_set_scissor_rect;
  WGPUProcRenderPassEncoderSetStencilReference
      render_pass_encoder_set_stencil_reference;
  WGPUProcRenderPassEncoderSetVertexBuffer
      render_pass_encoder_set_vertex_buffer;
  WGPUProcRenderPassEncoderSetViewport render_pass_encoder_set_viewport;
  WGPUProcRenderPassEncoderWriteTimestamp render_pass_encoder_write_timestamp;
  WGPUProcRenderPassEncoderReference render_pass_encoder_reference;
  WGPUProcRenderPassEncoderRelease render_pass_encoder_release;

  WGPUProcRenderPipelineGetBindGroupLayout
      render_pipeline_get_bind_group_layout;
  WGPUProcRenderPipelineSetLabel render_pipeline_set_label;
  WGPUProcRenderPipelineReference render_pipeline_reference;
  WGPUProcRenderPipelineRelease render_pipeline_release;

  WGPUProcSamplerSetLabel sampler_set_label;
  WGPUProcSamplerReference sampler_reference;
  WGPUProcSamplerRelease sampler_release;

  WGPUProcShaderModuleGetCompilationInfo shader_module_get_compilation_info;
  WGPUProcShaderModuleSetLabel shader_module_set_label;
  WGPUProcShaderModuleReference shader_module_reference;
  WGPUProcShaderModuleRelease shader_module_release;

  WGPUProcSurfaceReference surface_reference;
  WGPUProcSurfaceRelease surface_release;

  WGPUProcSwapChainConfigure swap_chain_configure;
  WGPUProcSwapChainGetCurrentTextureView swap_chain_get_current_texture_view;
  WGPUProcSwapChainPresent swap_chain_present;
  WGPUProcSwapChainReference swap_chain_reference;
  WGPUProcSwapChainRelease swap_chain_release;

  WGPUProcTextureCreateView texture_create_view;
  WGPUProcTextureDestroy texture_destroy;
  WGPUProcTextureGetDepthOrArrayLayers texture_get_depth_or_array_layers;
  WGPUProcTextureGetDimension texture_get_dimension;
  WGPUProcTextureGetFormat texture_get_format;
  WGPUProcTextureGetHeight texture_get_height;
  WGPUProcTextureGetMipLevelCount texture_get_mip_level_count;
  WGPUProcTextureGetSampleCount texture_get_sample_count;
  WGPUProcTextureGetUsage texture_get_usage;
  WGPUProcTextureGetWidth texture_get_width;
  WGPUProcTextureSetLabel texture_set_label;
  WGPUProcTextureReference texture_reference;
  WGPUProcTextureRelease texture_release;

  WGPUProcTextureViewSetLabel texture_view_set_label;
  WGPUProcTextureViewReference texture_view_reference;
  WGPUProcTextureViewRelease texture_view_release;
};

MOON_API void SetProcs(const GPUProcTable *procs);

} // namespace moon::gpu

using MoonSwapChainError = char const *;
constexpr MoonSwapChainError kSwapChainErrorNone = {};

struct MoonSwapChainNextTexture {
  union {
    vptr ptr;
    u64 u64;
    u32 u32;
  } texture;
};

struct IMoonSwapChain {
  void (*init)(vptr userdata, vptr impl_context);
  void (*destroy)(vptr userdata);

  MoonSwapChainError (*configure)(vptr userdata, WGPUTextureFormat format,
                                  WGPUTextureUsage usage, u32 width,
                                  u32 height);
  MoonSwapChainError (*get_next_texture)(
      vptr userdata, MoonSwapChainNextTexture *next_texture);
  MoonSwapChainError (*present)(vptr userdata);

  vptr userdata;
  WGPUTextureUsage texture_usage;
};