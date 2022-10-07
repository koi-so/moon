#pragma once

#include "types.h"

#define MOON_WGPU_API_CONVERSION_HANDLES(N)                                    \
  inline auto FromWGPU(WGPU##N *ptr)->N * { return as<N *>(ptr); }             \
  inline auto FromWGPU(WGPU##N const *ptr)->N const * {                        \
    return as<N const *>(ptr);                                                 \
  }                                                                            \
                                                                               \
  inline auto ToWGPU(N *ptr)->WGPU##N * { return as<WGPU##N *>(ptr); }         \
  inline auto ToWGPU(N const *ptr)->WGPU##N const * {                          \
    return as<WGPU##N const *>(ptr);                                           \
  }

#define MOON_WGPU_API_CONVERSION_ENUMS(N)                                      \
  inline auto FromWGPU(WGPU##N ptr)->N { return as<N>(ptr); }                  \
                                                                               \
  inline auto ToWGPU(N ptr)->WGPU##N { return as<WGPU##N>(ptr); }

namespace moon::gpu {
using zinc::as;

MOON_WGPU_API_CONVERSION_HANDLES(AdapterProperties)
MOON_WGPU_API_CONVERSION_HANDLES(BindGroupEntry)
MOON_WGPU_API_CONVERSION_HANDLES(BlendComponent)
MOON_WGPU_API_CONVERSION_HANDLES(BufferBindingLayout)
MOON_WGPU_API_CONVERSION_HANDLES(BufferDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(Color)
MOON_WGPU_API_CONVERSION_HANDLES(CommandBufferDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(CommandEncoderDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(CompilationMessage)
MOON_WGPU_API_CONVERSION_HANDLES(ComputePassTimestampWrite)
MOON_WGPU_API_CONVERSION_HANDLES(ConstantEntry)
MOON_WGPU_API_CONVERSION_HANDLES(CopyTextureForBrowserOptions)
MOON_WGPU_API_CONVERSION_HANDLES(MoonAdapterPropertiesPowerPreference)
MOON_WGPU_API_CONVERSION_HANDLES(MoonCacheDeviceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(MoonEncoderInternalUsageDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(MoonInstanceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(MoonTextureInternalUsageDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(MoonTogglesDeviceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(Extent3D)
MOON_WGPU_API_CONVERSION_HANDLES(ExternalTextureBindingEntry)
MOON_WGPU_API_CONVERSION_HANDLES(ExternalTextureBindingLayout)
MOON_WGPU_API_CONVERSION_HANDLES(ExternalTextureDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(InstanceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(Limits)
MOON_WGPU_API_CONVERSION_HANDLES(MultisampleState)
MOON_WGPU_API_CONVERSION_HANDLES(Origin3D)
MOON_WGPU_API_CONVERSION_HANDLES(PipelineLayoutDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(PrimitiveDepthClipControl)
MOON_WGPU_API_CONVERSION_HANDLES(PrimitiveState)
MOON_WGPU_API_CONVERSION_HANDLES(QuerySetDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(QueueDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(RenderBundleDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(RenderBundleEncoderDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPassDepthStencilAttachment)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPassDescriptorMaxDrawCount)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPassTimestampWrite)
MOON_WGPU_API_CONVERSION_HANDLES(RequestAdapterOptions)
MOON_WGPU_API_CONVERSION_HANDLES(SamplerBindingLayout)
MOON_WGPU_API_CONVERSION_HANDLES(SamplerDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(ShaderModuleDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(ShaderModuleSPIRVDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(ShaderModuleWGSLDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(StencilFaceState)
MOON_WGPU_API_CONVERSION_HANDLES(StorageTextureBindingLayout)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromAndroidNativeWindow)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromCanvasHTMLSelector)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromMetalLayer)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromWaylandSurface)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromWindowsCoreWindow)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromWindowsHWND)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromWindowsSwapChainPanel)
MOON_WGPU_API_CONVERSION_HANDLES(SurfaceDescriptorFromXlibWindow)
MOON_WGPU_API_CONVERSION_HANDLES(SwapChainDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(TextureBindingLayout)
MOON_WGPU_API_CONVERSION_HANDLES(TextureDataLayout)
MOON_WGPU_API_CONVERSION_HANDLES(TextureViewDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(VertexAttribute)
MOON_WGPU_API_CONVERSION_HANDLES(BindGroupDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(BindGroupLayoutEntry)
MOON_WGPU_API_CONVERSION_HANDLES(BlendState)
MOON_WGPU_API_CONVERSION_HANDLES(CompilationInfo)
MOON_WGPU_API_CONVERSION_HANDLES(ComputePassDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(DepthStencilState)
MOON_WGPU_API_CONVERSION_HANDLES(ImageCopyBuffer)
MOON_WGPU_API_CONVERSION_HANDLES(ImageCopyTexture)
MOON_WGPU_API_CONVERSION_HANDLES(ProgrammableStageDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPassColorAttachment)
MOON_WGPU_API_CONVERSION_HANDLES(RequiredLimits)
MOON_WGPU_API_CONVERSION_HANDLES(SupportedLimits)
MOON_WGPU_API_CONVERSION_HANDLES(TextureDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(VertexBufferLayout)
MOON_WGPU_API_CONVERSION_HANDLES(BindGroupLayoutDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(ColorTargetState)
MOON_WGPU_API_CONVERSION_HANDLES(ComputePipelineDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(DeviceDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPassDescriptor)
MOON_WGPU_API_CONVERSION_HANDLES(VertexState)
MOON_WGPU_API_CONVERSION_HANDLES(FragmentState)
MOON_WGPU_API_CONVERSION_HANDLES(RenderPipelineDescriptor)

template <typename T> struct EnumCount;

template <> struct EnumCount<AdapterType> { static constexpr u32 value = 4; };
template <> struct EnumCount<AddressMode> { static constexpr u32 value = 3; };
template <> struct EnumCount<AlphaMode> { static constexpr u32 value = 3; };
template <> struct EnumCount<BackendType> { static constexpr u32 value = 8; };
template <> struct EnumCount<BlendFactor> { static constexpr u32 value = 13; };
template <> struct EnumCount<BlendOperation> {
  static constexpr u32 value = 5;
};
template <> struct EnumCount<BufferBindingType> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<BufferMapAsyncStatus> {
  static constexpr u32 value = 6;
};
template <> struct EnumCount<CompareFunction> {
  static constexpr u32 value = 9;
};
template <> struct EnumCount<CompilationInfoRequestStatus> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<CompilationMessageType> {
  static constexpr u32 value = 3;
};
template <> struct EnumCount<ComputePassTimestampLocation> {
  static constexpr u32 value = 2;
};
template <> struct EnumCount<CreatePipelineAsyncStatus> {
  static constexpr u32 value = 5;
};
template <> struct EnumCount<CullMode> { static constexpr u32 value = 3; };
template <> struct EnumCount<DeviceLostReason> {
  static constexpr u32 value = 2;
};
template <> struct EnumCount<ErrorFilter> { static constexpr u32 value = 3; };
template <> struct EnumCount<ErrorType> { static constexpr u32 value = 6; };
template <> struct EnumCount<FilterMode> { static constexpr u32 value = 2; };
template <> struct EnumCount<FrontFace> { static constexpr u32 value = 2; };
template <> struct EnumCount<IndexFormat> { static constexpr u32 value = 3; };
template <> struct EnumCount<LoadOp> { static constexpr u32 value = 3; };
template <> struct EnumCount<LoggingType> { static constexpr u32 value = 4; };
template <> struct EnumCount<PipelineStatisticName> {
  static constexpr u32 value = 5;
};
template <> struct EnumCount<PowerPreference> {
  static constexpr u32 value = 3;
};
template <> struct EnumCount<PresentMode> { static constexpr u32 value = 3; };
template <> struct EnumCount<PrimitiveTopology> {
  static constexpr u32 value = 5;
};
template <> struct EnumCount<QueryType> { static constexpr u32 value = 3; };
template <> struct EnumCount<QueueWorkDoneStatus> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<RenderPassTimestampLocation> {
  static constexpr u32 value = 2;
};
template <> struct EnumCount<RequestAdapterStatus> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<RequestDeviceStatus> {
  static constexpr u32 value = 3;
};
template <> struct EnumCount<SamplerBindingType> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<StencilOperation> {
  static constexpr u32 value = 8;
};
template <> struct EnumCount<StorageTextureAccess> {
  static constexpr u32 value = 2;
};
template <> struct EnumCount<StoreOp> { static constexpr u32 value = 3; };
template <> struct EnumCount<TextureAspect> { static constexpr u32 value = 5; };
template <> struct EnumCount<TextureComponentType> {
  static constexpr u32 value = 4;
};
template <> struct EnumCount<TextureDimension> {
  static constexpr u32 value = 3;
};
template <> struct EnumCount<TextureFormat> {
  static constexpr u32 value = 96;
};
template <> struct EnumCount<TextureSampleType> {
  static constexpr u32 value = 6;
};
template <> struct EnumCount<TextureViewDimension> {
  static constexpr u32 value = 7;
};
template <> struct EnumCount<VertexFormat> { static constexpr u32 value = 31; };
template <> struct EnumCount<VertexStepMode> {
  static constexpr u32 value = 3;
};

MOON_WGPU_API_CONVERSION_ENUMS(AdapterType)
MOON_WGPU_API_CONVERSION_ENUMS(AddressMode)
MOON_WGPU_API_CONVERSION_ENUMS(AlphaMode)
MOON_WGPU_API_CONVERSION_ENUMS(BackendType)
MOON_WGPU_API_CONVERSION_ENUMS(BlendFactor)
MOON_WGPU_API_CONVERSION_ENUMS(BlendOperation)
MOON_WGPU_API_CONVERSION_ENUMS(BufferBindingType)
MOON_WGPU_API_CONVERSION_ENUMS(BufferMapAsyncStatus)
MOON_WGPU_API_CONVERSION_ENUMS(CompareFunction)
MOON_WGPU_API_CONVERSION_ENUMS(CompilationInfoRequestStatus)
MOON_WGPU_API_CONVERSION_ENUMS(CompilationMessageType)
MOON_WGPU_API_CONVERSION_ENUMS(ComputePassTimestampLocation)
MOON_WGPU_API_CONVERSION_ENUMS(CreatePipelineAsyncStatus)
MOON_WGPU_API_CONVERSION_ENUMS(CullMode)
MOON_WGPU_API_CONVERSION_ENUMS(DeviceLostReason)
MOON_WGPU_API_CONVERSION_ENUMS(ErrorFilter)
MOON_WGPU_API_CONVERSION_ENUMS(ErrorType)
MOON_WGPU_API_CONVERSION_ENUMS(FeatureName)
MOON_WGPU_API_CONVERSION_ENUMS(FilterMode)
MOON_WGPU_API_CONVERSION_ENUMS(FrontFace)
MOON_WGPU_API_CONVERSION_ENUMS(IndexFormat)
MOON_WGPU_API_CONVERSION_ENUMS(LoadOp)
MOON_WGPU_API_CONVERSION_ENUMS(LoggingType)
MOON_WGPU_API_CONVERSION_ENUMS(PipelineStatisticName)
MOON_WGPU_API_CONVERSION_ENUMS(PowerPreference)
MOON_WGPU_API_CONVERSION_ENUMS(PresentMode)
MOON_WGPU_API_CONVERSION_ENUMS(PrimitiveTopology)
MOON_WGPU_API_CONVERSION_ENUMS(QueryType)
MOON_WGPU_API_CONVERSION_ENUMS(QueueWorkDoneStatus)
MOON_WGPU_API_CONVERSION_ENUMS(RenderPassTimestampLocation)
MOON_WGPU_API_CONVERSION_ENUMS(RequestAdapterStatus)
MOON_WGPU_API_CONVERSION_ENUMS(RequestDeviceStatus)
MOON_WGPU_API_CONVERSION_ENUMS(SType)
MOON_WGPU_API_CONVERSION_ENUMS(SamplerBindingType)
MOON_WGPU_API_CONVERSION_ENUMS(StencilOperation)
MOON_WGPU_API_CONVERSION_ENUMS(StorageTextureAccess)
MOON_WGPU_API_CONVERSION_ENUMS(StoreOp)
MOON_WGPU_API_CONVERSION_ENUMS(TextureAspect)
MOON_WGPU_API_CONVERSION_ENUMS(TextureComponentType)
MOON_WGPU_API_CONVERSION_ENUMS(TextureDimension)
MOON_WGPU_API_CONVERSION_ENUMS(TextureFormat)
MOON_WGPU_API_CONVERSION_ENUMS(TextureSampleType)
MOON_WGPU_API_CONVERSION_ENUMS(TextureViewDimension)
MOON_WGPU_API_CONVERSION_ENUMS(VertexFormat)
MOON_WGPU_API_CONVERSION_ENUMS(VertexStepMode)
MOON_WGPU_API_CONVERSION_ENUMS(BufferUsage)
MOON_WGPU_API_CONVERSION_ENUMS(ColorWriteMask)
MOON_WGPU_API_CONVERSION_ENUMS(MapMode)
MOON_WGPU_API_CONVERSION_ENUMS(ShaderStage)
MOON_WGPU_API_CONVERSION_ENUMS(TextureUsage)

} // namespace moon::gpu

#undef MOON_WGPU_API_CONVERSION_HANDLES
#undef MOON_WGPU_API_CONVERSION_ENUMS