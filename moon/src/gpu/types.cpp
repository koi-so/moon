#include "moon/gpu/types.h"
// #include "../../moon/include/moon/gpu/types.h"

namespace moon::gpu {
// AdapterType

static_assert(sizeof(AdapterType) == sizeof(WGPUAdapterType),
              "sizeof mismatch for AdapterType");
static_assert(alignof(AdapterType) == alignof(WGPUAdapterType),
              "alignof mismatch for AdapterType");

static_assert(static_cast<u32>(AdapterType::DiscreteGPU) ==
                  WGPUAdapterType_DiscreteGPU,
              "value mismatch for AdapterType::DiscreteGPU");
static_assert(static_cast<u32>(AdapterType::IntegratedGPU) ==
                  WGPUAdapterType_IntegratedGPU,
              "value mismatch for AdapterType::IntegratedGPU");
static_assert(static_cast<u32>(AdapterType::CPU) == WGPUAdapterType_CPU,
              "value mismatch for AdapterType::CPU");
static_assert(static_cast<u32>(AdapterType::Unknown) == WGPUAdapterType_Unknown,
              "value mismatch for AdapterType::Unknown");

// AddressMode

static_assert(sizeof(AddressMode) == sizeof(WGPUAddressMode),
              "sizeof mismatch for AddressMode");
static_assert(alignof(AddressMode) == alignof(WGPUAddressMode),
              "alignof mismatch for AddressMode");

static_assert(static_cast<u32>(AddressMode::Repeat) == WGPUAddressMode_Repeat,
              "value mismatch for AddressMode::Repeat");
static_assert(static_cast<u32>(AddressMode::MirrorRepeat) ==
                  WGPUAddressMode_MirrorRepeat,
              "value mismatch for AddressMode::MirrorRepeat");
static_assert(static_cast<u32>(AddressMode::ClampToEdge) ==
                  WGPUAddressMode_ClampToEdge,
              "value mismatch for AddressMode::ClampToEdge");

// AlphaMode

static_assert(sizeof(AlphaMode) == sizeof(WGPUAlphaMode),
              "sizeof mismatch for AlphaMode");
static_assert(alignof(AlphaMode) == alignof(WGPUAlphaMode),
              "alignof mismatch for AlphaMode");

static_assert(static_cast<u32>(AlphaMode::Premultiplied) ==
                  WGPUAlphaMode_Premultiplied,
              "value mismatch for AlphaMode::Premultiplied");
static_assert(static_cast<u32>(AlphaMode::Unpremultiplied) ==
                  WGPUAlphaMode_Unpremultiplied,
              "value mismatch for AlphaMode::Unpremultiplied");
static_assert(static_cast<u32>(AlphaMode::Opaque) == WGPUAlphaMode_Opaque,
              "value mismatch for AlphaMode::Opaque");

// BackendType

static_assert(sizeof(BackendType) == sizeof(WGPUBackendType),
              "sizeof mismatch for BackendType");
static_assert(alignof(BackendType) == alignof(WGPUBackendType),
              "alignof mismatch for BackendType");

static_assert(static_cast<u32>(BackendType::Null) == WGPUBackendType_Null,
              "value mismatch for BackendType::Null");
static_assert(static_cast<u32>(BackendType::WebGPU) == WGPUBackendType_WebGPU,
              "value mismatch for BackendType::WebGPU");
static_assert(static_cast<u32>(BackendType::D3D11) == WGPUBackendType_D3D11,
              "value mismatch for BackendType::D3D11");
static_assert(static_cast<u32>(BackendType::D3D12) == WGPUBackendType_D3D12,
              "value mismatch for BackendType::D3D12");
static_assert(static_cast<u32>(BackendType::Metal) == WGPUBackendType_Metal,
              "value mismatch for BackendType::Metal");
static_assert(static_cast<u32>(BackendType::Vulkan) == WGPUBackendType_Vulkan,
              "value mismatch for BackendType::Vulkan");
static_assert(static_cast<u32>(BackendType::OpenGL) == WGPUBackendType_OpenGL,
              "value mismatch for BackendType::OpenGL");
static_assert(static_cast<u32>(BackendType::OpenGLES) ==
                  WGPUBackendType_OpenGLES,
              "value mismatch for BackendType::OpenGLES");

// BlendFactor

static_assert(sizeof(BlendFactor) == sizeof(WGPUBlendFactor),
              "sizeof mismatch for BlendFactor");
static_assert(alignof(BlendFactor) == alignof(WGPUBlendFactor),
              "alignof mismatch for BlendFactor");

static_assert(static_cast<u32>(BlendFactor::Zero) == WGPUBlendFactor_Zero,
              "value mismatch for BlendFactor::Zero");
static_assert(static_cast<u32>(BlendFactor::One) == WGPUBlendFactor_One,
              "value mismatch for BlendFactor::One");
static_assert(static_cast<u32>(BlendFactor::Src) == WGPUBlendFactor_Src,
              "value mismatch for BlendFactor::Src");
static_assert(static_cast<u32>(BlendFactor::OneMinusSrc) ==
                  WGPUBlendFactor_OneMinusSrc,
              "value mismatch for BlendFactor::OneMinusSrc");
static_assert(static_cast<u32>(BlendFactor::SrcAlpha) ==
                  WGPUBlendFactor_SrcAlpha,
              "value mismatch for BlendFactor::SrcAlpha");
static_assert(static_cast<u32>(BlendFactor::OneMinusSrcAlpha) ==
                  WGPUBlendFactor_OneMinusSrcAlpha,
              "value mismatch for BlendFactor::OneMinusSrcAlpha");
static_assert(static_cast<u32>(BlendFactor::Dst) == WGPUBlendFactor_Dst,
              "value mismatch for BlendFactor::Dst");
static_assert(static_cast<u32>(BlendFactor::OneMinusDst) ==
                  WGPUBlendFactor_OneMinusDst,
              "value mismatch for BlendFactor::OneMinusDst");
static_assert(static_cast<u32>(BlendFactor::DstAlpha) ==
                  WGPUBlendFactor_DstAlpha,
              "value mismatch for BlendFactor::DstAlpha");
static_assert(static_cast<u32>(BlendFactor::OneMinusDstAlpha) ==
                  WGPUBlendFactor_OneMinusDstAlpha,
              "value mismatch for BlendFactor::OneMinusDstAlpha");
static_assert(static_cast<u32>(BlendFactor::SrcAlphaSaturated) ==
                  WGPUBlendFactor_SrcAlphaSaturated,
              "value mismatch for BlendFactor::SrcAlphaSaturated");
static_assert(static_cast<u32>(BlendFactor::Constant) ==
                  WGPUBlendFactor_Constant,
              "value mismatch for BlendFactor::Constant");
static_assert(static_cast<u32>(BlendFactor::OneMinusConstant) ==
                  WGPUBlendFactor_OneMinusConstant,
              "value mismatch for BlendFactor::OneMinusConstant");

// BlendOperation

static_assert(sizeof(BlendOperation) == sizeof(WGPUBlendOperation),
              "sizeof mismatch for BlendOperation");
static_assert(alignof(BlendOperation) == alignof(WGPUBlendOperation),
              "alignof mismatch for BlendOperation");

static_assert(static_cast<u32>(BlendOperation::Add) == WGPUBlendOperation_Add,
              "value mismatch for BlendOperation::Add");
static_assert(static_cast<u32>(BlendOperation::Subtract) ==
                  WGPUBlendOperation_Subtract,
              "value mismatch for BlendOperation::Subtract");
static_assert(static_cast<u32>(BlendOperation::ReverseSubtract) ==
                  WGPUBlendOperation_ReverseSubtract,
              "value mismatch for BlendOperation::ReverseSubtract");
static_assert(static_cast<u32>(BlendOperation::Min) == WGPUBlendOperation_Min,
              "value mismatch for BlendOperation::Min");
static_assert(static_cast<u32>(BlendOperation::Max) == WGPUBlendOperation_Max,
              "value mismatch for BlendOperation::Max");

// BufferBindingType

static_assert(sizeof(BufferBindingType) == sizeof(WGPUBufferBindingType),
              "sizeof mismatch for BufferBindingType");
static_assert(alignof(BufferBindingType) == alignof(WGPUBufferBindingType),
              "alignof mismatch for BufferBindingType");

static_assert(static_cast<u32>(BufferBindingType::Undefined) ==
                  WGPUBufferBindingType_Undefined,
              "value mismatch for BufferBindingType::Undefined");
static_assert(static_cast<u32>(BufferBindingType::Uniform) ==
                  WGPUBufferBindingType_Uniform,
              "value mismatch for BufferBindingType::Uniform");
static_assert(static_cast<u32>(BufferBindingType::Storage) ==
                  WGPUBufferBindingType_Storage,
              "value mismatch for BufferBindingType::Storage");
static_assert(static_cast<u32>(BufferBindingType::ReadOnlyStorage) ==
                  WGPUBufferBindingType_ReadOnlyStorage,
              "value mismatch for BufferBindingType::ReadOnlyStorage");

// BufferMapAsyncStatus

static_assert(sizeof(BufferMapAsyncStatus) == sizeof(WGPUBufferMapAsyncStatus),
              "sizeof mismatch for BufferMapAsyncStatus");
static_assert(alignof(BufferMapAsyncStatus) ==
                  alignof(WGPUBufferMapAsyncStatus),
              "alignof mismatch for BufferMapAsyncStatus");

static_assert(static_cast<u32>(BufferMapAsyncStatus::Success) ==
                  WGPUBufferMapAsyncStatus_Success,
              "value mismatch for BufferMapAsyncStatus::Success");
static_assert(static_cast<u32>(BufferMapAsyncStatus::Error) ==
                  WGPUBufferMapAsyncStatus_Error,
              "value mismatch for BufferMapAsyncStatus::Error");
static_assert(static_cast<u32>(BufferMapAsyncStatus::Unknown) ==
                  WGPUBufferMapAsyncStatus_Unknown,
              "value mismatch for BufferMapAsyncStatus::Unknown");
static_assert(static_cast<u32>(BufferMapAsyncStatus::DeviceLost) ==
                  WGPUBufferMapAsyncStatus_DeviceLost,
              "value mismatch for BufferMapAsyncStatus::DeviceLost");
static_assert(
    static_cast<u32>(BufferMapAsyncStatus::DestroyedBeforeCallback) ==
        WGPUBufferMapAsyncStatus_DestroyedBeforeCallback,
    "value mismatch for BufferMapAsyncStatus::DestroyedBeforeCallback");
static_assert(
    static_cast<u32>(BufferMapAsyncStatus::UnmappedBeforeCallback) ==
        WGPUBufferMapAsyncStatus_UnmappedBeforeCallback,
    "value mismatch for BufferMapAsyncStatus::UnmappedBeforeCallback");

// CompareFunction

static_assert(sizeof(CompareFunction) == sizeof(WGPUCompareFunction),
              "sizeof mismatch for CompareFunction");
static_assert(alignof(CompareFunction) == alignof(WGPUCompareFunction),
              "alignof mismatch for CompareFunction");

static_assert(static_cast<u32>(CompareFunction::Undefined) ==
                  WGPUCompareFunction_Undefined,
              "value mismatch for CompareFunction::Undefined");
static_assert(static_cast<u32>(CompareFunction::Never) ==
                  WGPUCompareFunction_Never,
              "value mismatch for CompareFunction::Never");
static_assert(static_cast<u32>(CompareFunction::Less) ==
                  WGPUCompareFunction_Less,
              "value mismatch for CompareFunction::Less");
static_assert(static_cast<u32>(CompareFunction::LessEqual) ==
                  WGPUCompareFunction_LessEqual,
              "value mismatch for CompareFunction::LessEqual");
static_assert(static_cast<u32>(CompareFunction::Greater) ==
                  WGPUCompareFunction_Greater,
              "value mismatch for CompareFunction::Greater");
static_assert(static_cast<u32>(CompareFunction::GreaterEqual) ==
                  WGPUCompareFunction_GreaterEqual,
              "value mismatch for CompareFunction::GreaterEqual");
static_assert(static_cast<u32>(CompareFunction::Equal) ==
                  WGPUCompareFunction_Equal,
              "value mismatch for CompareFunction::Equal");
static_assert(static_cast<u32>(CompareFunction::NotEqual) ==
                  WGPUCompareFunction_NotEqual,
              "value mismatch for CompareFunction::NotEqual");
static_assert(static_cast<u32>(CompareFunction::Always) ==
                  WGPUCompareFunction_Always,
              "value mismatch for CompareFunction::Always");

// CompilationInfoRequestStatus

static_assert(sizeof(CompilationInfoRequestStatus) ==
                  sizeof(WGPUCompilationInfoRequestStatus),
              "sizeof mismatch for CompilationInfoRequestStatus");
static_assert(alignof(CompilationInfoRequestStatus) ==
                  alignof(WGPUCompilationInfoRequestStatus),
              "alignof mismatch for CompilationInfoRequestStatus");

static_assert(static_cast<u32>(CompilationInfoRequestStatus::Success) ==
                  WGPUCompilationInfoRequestStatus_Success,
              "value mismatch for CompilationInfoRequestStatus::Success");
static_assert(static_cast<u32>(CompilationInfoRequestStatus::Error) ==
                  WGPUCompilationInfoRequestStatus_Error,
              "value mismatch for CompilationInfoRequestStatus::Error");
static_assert(static_cast<u32>(CompilationInfoRequestStatus::DeviceLost) ==
                  WGPUCompilationInfoRequestStatus_DeviceLost,
              "value mismatch for CompilationInfoRequestStatus::DeviceLost");
static_assert(static_cast<u32>(CompilationInfoRequestStatus::Unknown) ==
                  WGPUCompilationInfoRequestStatus_Unknown,
              "value mismatch for CompilationInfoRequestStatus::Unknown");

// CompilationMessageType

static_assert(sizeof(CompilationMessageType) ==
                  sizeof(WGPUCompilationMessageType),
              "sizeof mismatch for CompilationMessageType");
static_assert(alignof(CompilationMessageType) ==
                  alignof(WGPUCompilationMessageType),
              "alignof mismatch for CompilationMessageType");

static_assert(static_cast<u32>(CompilationMessageType::Error) ==
                  WGPUCompilationMessageType_Error,
              "value mismatch for CompilationMessageType::Error");
static_assert(static_cast<u32>(CompilationMessageType::Warning) ==
                  WGPUCompilationMessageType_Warning,
              "value mismatch for CompilationMessageType::Warning");
static_assert(static_cast<u32>(CompilationMessageType::Info) ==
                  WGPUCompilationMessageType_Info,
              "value mismatch for CompilationMessageType::Info");

// ComputePassTimestampLocation

static_assert(sizeof(ComputePassTimestampLocation) ==
                  sizeof(WGPUComputePassTimestampLocation),
              "sizeof mismatch for ComputePassTimestampLocation");
static_assert(alignof(ComputePassTimestampLocation) ==
                  alignof(WGPUComputePassTimestampLocation),
              "alignof mismatch for ComputePassTimestampLocation");

static_assert(static_cast<u32>(ComputePassTimestampLocation::Beginning) ==
                  WGPUComputePassTimestampLocation_Beginning,
              "value mismatch for ComputePassTimestampLocation::Beginning");
static_assert(static_cast<u32>(ComputePassTimestampLocation::End) ==
                  WGPUComputePassTimestampLocation_End,
              "value mismatch for ComputePassTimestampLocation::End");

// CreatePipelineAsyncStatus

static_assert(sizeof(CreatePipelineAsyncStatus) ==
                  sizeof(WGPUCreatePipelineAsyncStatus),
              "sizeof mismatch for CreatePipelineAsyncStatus");
static_assert(alignof(CreatePipelineAsyncStatus) ==
                  alignof(WGPUCreatePipelineAsyncStatus),
              "alignof mismatch for CreatePipelineAsyncStatus");

static_assert(static_cast<u32>(CreatePipelineAsyncStatus::Success) ==
                  WGPUCreatePipelineAsyncStatus_Success,
              "value mismatch for CreatePipelineAsyncStatus::Success");
static_assert(static_cast<u32>(CreatePipelineAsyncStatus::Error) ==
                  WGPUCreatePipelineAsyncStatus_Error,
              "value mismatch for CreatePipelineAsyncStatus::Error");
static_assert(static_cast<u32>(CreatePipelineAsyncStatus::DeviceLost) ==
                  WGPUCreatePipelineAsyncStatus_DeviceLost,
              "value mismatch for CreatePipelineAsyncStatus::DeviceLost");
static_assert(static_cast<u32>(CreatePipelineAsyncStatus::DeviceDestroyed) ==
                  WGPUCreatePipelineAsyncStatus_DeviceDestroyed,
              "value mismatch for CreatePipelineAsyncStatus::DeviceDestroyed");
static_assert(static_cast<u32>(CreatePipelineAsyncStatus::Unknown) ==
                  WGPUCreatePipelineAsyncStatus_Unknown,
              "value mismatch for CreatePipelineAsyncStatus::Unknown");

// CullMode

static_assert(sizeof(CullMode) == sizeof(WGPUCullMode),
              "sizeof mismatch for CullMode");
static_assert(alignof(CullMode) == alignof(WGPUCullMode),
              "alignof mismatch for CullMode");

static_assert(static_cast<u32>(CullMode::None) == WGPUCullMode_None,
              "value mismatch for CullMode::None");
static_assert(static_cast<u32>(CullMode::Front) == WGPUCullMode_Front,
              "value mismatch for CullMode::Front");
static_assert(static_cast<u32>(CullMode::Back) == WGPUCullMode_Back,
              "value mismatch for CullMode::Back");

// DeviceLostReason

static_assert(sizeof(DeviceLostReason) == sizeof(WGPUDeviceLostReason),
              "sizeof mismatch for DeviceLostReason");
static_assert(alignof(DeviceLostReason) == alignof(WGPUDeviceLostReason),
              "alignof mismatch for DeviceLostReason");

static_assert(static_cast<u32>(DeviceLostReason::Undefined) ==
                  WGPUDeviceLostReason_Undefined,
              "value mismatch for DeviceLostReason::Undefined");
static_assert(static_cast<u32>(DeviceLostReason::Destroyed) ==
                  WGPUDeviceLostReason_Destroyed,
              "value mismatch for DeviceLostReason::Destroyed");

// ErrorFilter

static_assert(sizeof(ErrorFilter) == sizeof(WGPUErrorFilter),
              "sizeof mismatch for ErrorFilter");
static_assert(alignof(ErrorFilter) == alignof(WGPUErrorFilter),
              "alignof mismatch for ErrorFilter");

static_assert(static_cast<u32>(ErrorFilter::Validation) ==
                  WGPUErrorFilter_Validation,
              "value mismatch for ErrorFilter::Validation");
static_assert(static_cast<u32>(ErrorFilter::OutOfMemory) ==
                  WGPUErrorFilter_OutOfMemory,
              "value mismatch for ErrorFilter::OutOfMemory");
static_assert(static_cast<u32>(ErrorFilter::Internal) ==
                  WGPUErrorFilter_Internal,
              "value mismatch for ErrorFilter::Internal");

// ErrorType

static_assert(sizeof(ErrorType) == sizeof(WGPUErrorType),
              "sizeof mismatch for ErrorType");
static_assert(alignof(ErrorType) == alignof(WGPUErrorType),
              "alignof mismatch for ErrorType");

static_assert(static_cast<u32>(ErrorType::NoError) == WGPUErrorType_NoError,
              "value mismatch for ErrorType::NoError");
static_assert(static_cast<u32>(ErrorType::Validation) ==
                  WGPUErrorType_Validation,
              "value mismatch for ErrorType::Validation");
static_assert(static_cast<u32>(ErrorType::OutOfMemory) ==
                  WGPUErrorType_OutOfMemory,
              "value mismatch for ErrorType::OutOfMemory");
static_assert(static_cast<u32>(ErrorType::Internal) == WGPUErrorType_Internal,
              "value mismatch for ErrorType::Internal");
static_assert(static_cast<u32>(ErrorType::Unknown) == WGPUErrorType_Unknown,
              "value mismatch for ErrorType::Unknown");
static_assert(static_cast<u32>(ErrorType::DeviceLost) ==
                  WGPUErrorType_DeviceLost,
              "value mismatch for ErrorType::DeviceLost");

// FeatureName

static_assert(sizeof(FeatureName) == sizeof(WGPUFeatureName),
              "sizeof mismatch for FeatureName");
static_assert(alignof(FeatureName) == alignof(WGPUFeatureName),
              "alignof mismatch for FeatureName");

static_assert(static_cast<u32>(FeatureName::Undefined) ==
                  WGPUFeatureName_Undefined,
              "value mismatch for FeatureName::Undefined");
static_assert(static_cast<u32>(FeatureName::DepthClipControl) ==
                  WGPUFeatureName_DepthClipControl,
              "value mismatch for FeatureName::DepthClipControl");
static_assert(static_cast<u32>(FeatureName::Depth32FloatStencil8) ==
                  WGPUFeatureName_Depth32FloatStencil8,
              "value mismatch for FeatureName::Depth32FloatStencil8");
static_assert(static_cast<u32>(FeatureName::TimestampQuery) ==
                  WGPUFeatureName_TimestampQuery,
              "value mismatch for FeatureName::TimestampQuery");
static_assert(static_cast<u32>(FeatureName::PipelineStatisticsQuery) ==
                  WGPUFeatureName_PipelineStatisticsQuery,
              "value mismatch for FeatureName::PipelineStatisticsQuery");
static_assert(static_cast<u32>(FeatureName::TextureCompressionBC) ==
                  WGPUFeatureName_TextureCompressionBC,
              "value mismatch for FeatureName::TextureCompressionBC");
static_assert(static_cast<u32>(FeatureName::TextureCompressionETC2) ==
                  WGPUFeatureName_TextureCompressionETC2,
              "value mismatch for FeatureName::TextureCompressionETC2");
static_assert(static_cast<u32>(FeatureName::TextureCompressionASTC) ==
                  WGPUFeatureName_TextureCompressionASTC,
              "value mismatch for FeatureName::TextureCompressionASTC");
static_assert(static_cast<u32>(FeatureName::IndirectFirstInstance) ==
                  WGPUFeatureName_IndirectFirstInstance,
              "value mismatch for FeatureName::IndirectFirstInstance");
static_assert(static_cast<u32>(FeatureName::ShaderF16) ==
                  WGPUFeatureName_ShaderF16,
              "value mismatch for FeatureName::ShaderF16");
static_assert(static_cast<u32>(FeatureName::RG11B10UfloatRenderable) ==
                  WGPUFeatureName_RG11B10UfloatRenderable,
              "value mismatch for FeatureName::RG11B10UfloatRenderable");
static_assert(static_cast<u32>(FeatureName::MoonShaderFloat16) ==
                  WGPUFeatureName_MoonShaderFloat16,
              "value mismatch for FeatureName::MoonShaderFloat16");
static_assert(static_cast<u32>(FeatureName::MoonInternalUsages) ==
                  WGPUFeatureName_MoonInternalUsages,
              "value mismatch for FeatureName::MoonInternalUsages");
static_assert(static_cast<u32>(FeatureName::MoonMultiPlanarFormats) ==
                  WGPUFeatureName_MoonMultiPlanarFormats,
              "value mismatch for FeatureName::MoonMultiPlanarFormats");
static_assert(static_cast<u32>(FeatureName::MoonNative) ==
                  WGPUFeatureName_MoonNative,
              "value mismatch for FeatureName::MoonNative");
static_assert(static_cast<u32>(FeatureName::ChromiumExperimentalDp4a) ==
                  WGPUFeatureName_ChromiumExperimentalDp4a,
              "value mismatch for FeatureName::ChromiumExperimentalDp4a");

// FilterMode

static_assert(sizeof(FilterMode) == sizeof(WGPUFilterMode),
              "sizeof mismatch for FilterMode");
static_assert(alignof(FilterMode) == alignof(WGPUFilterMode),
              "alignof mismatch for FilterMode");

static_assert(static_cast<u32>(FilterMode::Nearest) == WGPUFilterMode_Nearest,
              "value mismatch for FilterMode::Nearest");
static_assert(static_cast<u32>(FilterMode::Linear) == WGPUFilterMode_Linear,
              "value mismatch for FilterMode::Linear");

// FrontFace

static_assert(sizeof(FrontFace) == sizeof(WGPUFrontFace),
              "sizeof mismatch for FrontFace");
static_assert(alignof(FrontFace) == alignof(WGPUFrontFace),
              "alignof mismatch for FrontFace");

static_assert(static_cast<u32>(FrontFace::CCW) == WGPUFrontFace_CCW,
              "value mismatch for FrontFace::CCW");
static_assert(static_cast<u32>(FrontFace::CW) == WGPUFrontFace_CW,
              "value mismatch for FrontFace::CW");

// IndexFormat

static_assert(sizeof(IndexFormat) == sizeof(WGPUIndexFormat),
              "sizeof mismatch for IndexFormat");
static_assert(alignof(IndexFormat) == alignof(WGPUIndexFormat),
              "alignof mismatch for IndexFormat");

static_assert(static_cast<u32>(IndexFormat::Undefined) ==
                  WGPUIndexFormat_Undefined,
              "value mismatch for IndexFormat::Undefined");
static_assert(static_cast<u32>(IndexFormat::Uint16) == WGPUIndexFormat_Uint16,
              "value mismatch for IndexFormat::Uint16");
static_assert(static_cast<u32>(IndexFormat::Uint32) == WGPUIndexFormat_Uint32,
              "value mismatch for IndexFormat::Uint32");

// LoadOp

static_assert(sizeof(LoadOp) == sizeof(WGPULoadOp),
              "sizeof mismatch for LoadOp");
static_assert(alignof(LoadOp) == alignof(WGPULoadOp),
              "alignof mismatch for LoadOp");

static_assert(static_cast<u32>(LoadOp::Undefined) == WGPULoadOp_Undefined,
              "value mismatch for LoadOp::Undefined");
static_assert(static_cast<u32>(LoadOp::Clear) == WGPULoadOp_Clear,
              "value mismatch for LoadOp::Clear");
static_assert(static_cast<u32>(LoadOp::Load) == WGPULoadOp_Load,
              "value mismatch for LoadOp::Load");

// LoggingType

static_assert(sizeof(LoggingType) == sizeof(WGPULoggingType),
              "sizeof mismatch for LoggingType");
static_assert(alignof(LoggingType) == alignof(WGPULoggingType),
              "alignof mismatch for LoggingType");

static_assert(static_cast<u32>(LoggingType::Verbose) == WGPULoggingType_Verbose,
              "value mismatch for LoggingType::Verbose");
static_assert(static_cast<u32>(LoggingType::Info) == WGPULoggingType_Info,
              "value mismatch for LoggingType::Info");
static_assert(static_cast<u32>(LoggingType::Warning) == WGPULoggingType_Warning,
              "value mismatch for LoggingType::Warning");
static_assert(static_cast<u32>(LoggingType::Error) == WGPULoggingType_Error,
              "value mismatch for LoggingType::Error");

// PipelineStatisticName

static_assert(sizeof(PipelineStatisticName) ==
                  sizeof(WGPUPipelineStatisticName),
              "sizeof mismatch for PipelineStatisticName");
static_assert(alignof(PipelineStatisticName) ==
                  alignof(WGPUPipelineStatisticName),
              "alignof mismatch for PipelineStatisticName");

static_assert(
    static_cast<u32>(PipelineStatisticName::VertexShaderInvocations) ==
        WGPUPipelineStatisticName_VertexShaderInvocations,
    "value mismatch for PipelineStatisticName::VertexShaderInvocations");
static_assert(static_cast<u32>(PipelineStatisticName::ClipperInvocations) ==
                  WGPUPipelineStatisticName_ClipperInvocations,
              "value mismatch for PipelineStatisticName::ClipperInvocations");
static_assert(static_cast<u32>(PipelineStatisticName::ClipperPrimitivesOut) ==
                  WGPUPipelineStatisticName_ClipperPrimitivesOut,
              "value mismatch for PipelineStatisticName::ClipperPrimitivesOut");
static_assert(
    static_cast<u32>(PipelineStatisticName::FragmentShaderInvocations) ==
        WGPUPipelineStatisticName_FragmentShaderInvocations,
    "value mismatch for PipelineStatisticName::FragmentShaderInvocations");
static_assert(
    static_cast<u32>(PipelineStatisticName::ComputeShaderInvocations) ==
        WGPUPipelineStatisticName_ComputeShaderInvocations,
    "value mismatch for PipelineStatisticName::ComputeShaderInvocations");

// PowerPreference

static_assert(sizeof(PowerPreference) == sizeof(WGPUPowerPreference),
              "sizeof mismatch for PowerPreference");
static_assert(alignof(PowerPreference) == alignof(WGPUPowerPreference),
              "alignof mismatch for PowerPreference");

static_assert(static_cast<u32>(PowerPreference::Undefined) ==
                  WGPUPowerPreference_Undefined,
              "value mismatch for PowerPreference::Undefined");
static_assert(static_cast<u32>(PowerPreference::LowPower) ==
                  WGPUPowerPreference_LowPower,
              "value mismatch for PowerPreference::LowPower");
static_assert(static_cast<u32>(PowerPreference::HighPerformance) ==
                  WGPUPowerPreference_HighPerformance,
              "value mismatch for PowerPreference::HighPerformance");

// PresentMode

static_assert(sizeof(PresentMode) == sizeof(WGPUPresentMode),
              "sizeof mismatch for PresentMode");
static_assert(alignof(PresentMode) == alignof(WGPUPresentMode),
              "alignof mismatch for PresentMode");

static_assert(static_cast<u32>(PresentMode::Immediate) ==
                  WGPUPresentMode_Immediate,
              "value mismatch for PresentMode::Immediate");
static_assert(static_cast<u32>(PresentMode::Mailbox) == WGPUPresentMode_Mailbox,
              "value mismatch for PresentMode::Mailbox");
static_assert(static_cast<u32>(PresentMode::Fifo) == WGPUPresentMode_Fifo,
              "value mismatch for PresentMode::Fifo");

// PrimitiveTopology

static_assert(sizeof(PrimitiveTopology) == sizeof(WGPUPrimitiveTopology),
              "sizeof mismatch for PrimitiveTopology");
static_assert(alignof(PrimitiveTopology) == alignof(WGPUPrimitiveTopology),
              "alignof mismatch for PrimitiveTopology");

static_assert(static_cast<u32>(PrimitiveTopology::PointList) ==
                  WGPUPrimitiveTopology_PointList,
              "value mismatch for PrimitiveTopology::PointList");
static_assert(static_cast<u32>(PrimitiveTopology::LineList) ==
                  WGPUPrimitiveTopology_LineList,
              "value mismatch for PrimitiveTopology::LineList");
static_assert(static_cast<u32>(PrimitiveTopology::LineStrip) ==
                  WGPUPrimitiveTopology_LineStrip,
              "value mismatch for PrimitiveTopology::LineStrip");
static_assert(static_cast<u32>(PrimitiveTopology::TriangleList) ==
                  WGPUPrimitiveTopology_TriangleList,
              "value mismatch for PrimitiveTopology::TriangleList");
static_assert(static_cast<u32>(PrimitiveTopology::TriangleStrip) ==
                  WGPUPrimitiveTopology_TriangleStrip,
              "value mismatch for PrimitiveTopology::TriangleStrip");

// QueryType

static_assert(sizeof(QueryType) == sizeof(WGPUQueryType),
              "sizeof mismatch for QueryType");
static_assert(alignof(QueryType) == alignof(WGPUQueryType),
              "alignof mismatch for QueryType");

static_assert(static_cast<u32>(QueryType::Occlusion) == WGPUQueryType_Occlusion,
              "value mismatch for QueryType::Occlusion");
static_assert(static_cast<u32>(QueryType::PipelineStatistics) ==
                  WGPUQueryType_PipelineStatistics,
              "value mismatch for QueryType::PipelineStatistics");
static_assert(static_cast<u32>(QueryType::Timestamp) == WGPUQueryType_Timestamp,
              "value mismatch for QueryType::Timestamp");

// QueueWorkDoneStatus

static_assert(sizeof(QueueWorkDoneStatus) == sizeof(WGPUQueueWorkDoneStatus),
              "sizeof mismatch for QueueWorkDoneStatus");
static_assert(alignof(QueueWorkDoneStatus) == alignof(WGPUQueueWorkDoneStatus),
              "alignof mismatch for QueueWorkDoneStatus");

static_assert(static_cast<u32>(QueueWorkDoneStatus::Success) ==
                  WGPUQueueWorkDoneStatus_Success,
              "value mismatch for QueueWorkDoneStatus::Success");
static_assert(static_cast<u32>(QueueWorkDoneStatus::Error) ==
                  WGPUQueueWorkDoneStatus_Error,
              "value mismatch for QueueWorkDoneStatus::Error");
static_assert(static_cast<u32>(QueueWorkDoneStatus::Unknown) ==
                  WGPUQueueWorkDoneStatus_Unknown,
              "value mismatch for QueueWorkDoneStatus::Unknown");
static_assert(static_cast<u32>(QueueWorkDoneStatus::DeviceLost) ==
                  WGPUQueueWorkDoneStatus_DeviceLost,
              "value mismatch for QueueWorkDoneStatus::DeviceLost");

// RenderPassTimestampLocation

static_assert(sizeof(RenderPassTimestampLocation) ==
                  sizeof(WGPURenderPassTimestampLocation),
              "sizeof mismatch for RenderPassTimestampLocation");
static_assert(alignof(RenderPassTimestampLocation) ==
                  alignof(WGPURenderPassTimestampLocation),
              "alignof mismatch for RenderPassTimestampLocation");

static_assert(static_cast<u32>(RenderPassTimestampLocation::Beginning) ==
                  WGPURenderPassTimestampLocation_Beginning,
              "value mismatch for RenderPassTimestampLocation::Beginning");
static_assert(static_cast<u32>(RenderPassTimestampLocation::End) ==
                  WGPURenderPassTimestampLocation_End,
              "value mismatch for RenderPassTimestampLocation::End");

// RequestAdapterStatus

static_assert(sizeof(RequestAdapterStatus) == sizeof(WGPURequestAdapterStatus),
              "sizeof mismatch for RequestAdapterStatus");
static_assert(alignof(RequestAdapterStatus) ==
                  alignof(WGPURequestAdapterStatus),
              "alignof mismatch for RequestAdapterStatus");

static_assert(static_cast<u32>(RequestAdapterStatus::Success) ==
                  WGPURequestAdapterStatus_Success,
              "value mismatch for RequestAdapterStatus::Success");
static_assert(static_cast<u32>(RequestAdapterStatus::Unavailable) ==
                  WGPURequestAdapterStatus_Unavailable,
              "value mismatch for RequestAdapterStatus::Unavailable");
static_assert(static_cast<u32>(RequestAdapterStatus::Error) ==
                  WGPURequestAdapterStatus_Error,
              "value mismatch for RequestAdapterStatus::Error");
static_assert(static_cast<u32>(RequestAdapterStatus::Unknown) ==
                  WGPURequestAdapterStatus_Unknown,
              "value mismatch for RequestAdapterStatus::Unknown");

// RequestDeviceStatus

static_assert(sizeof(RequestDeviceStatus) == sizeof(WGPURequestDeviceStatus),
              "sizeof mismatch for RequestDeviceStatus");
static_assert(alignof(RequestDeviceStatus) == alignof(WGPURequestDeviceStatus),
              "alignof mismatch for RequestDeviceStatus");

static_assert(static_cast<u32>(RequestDeviceStatus::Success) ==
                  WGPURequestDeviceStatus_Success,
              "value mismatch for RequestDeviceStatus::Success");
static_assert(static_cast<u32>(RequestDeviceStatus::Error) ==
                  WGPURequestDeviceStatus_Error,
              "value mismatch for RequestDeviceStatus::Error");
static_assert(static_cast<u32>(RequestDeviceStatus::Unknown) ==
                  WGPURequestDeviceStatus_Unknown,
              "value mismatch for RequestDeviceStatus::Unknown");

// SType

static_assert(sizeof(SType) == sizeof(WGPUSType), "sizeof mismatch for SType");
static_assert(alignof(SType) == alignof(WGPUSType),
              "alignof mismatch for SType");

static_assert(static_cast<u32>(SType::Invalid) == WGPUSType_Invalid,
              "value mismatch for SType::Invalid");
static_assert(static_cast<u32>(SType::SurfaceDescriptorFromMetalLayer) ==
                  WGPUSType_SurfaceDescriptorFromMetalLayer,
              "value mismatch for SType::SurfaceDescriptorFromMetalLayer");
static_assert(static_cast<u32>(SType::SurfaceDescriptorFromWindowsHWND) ==
                  WGPUSType_SurfaceDescriptorFromWindowsHWND,
              "value mismatch for SType::SurfaceDescriptorFromWindowsHWND");
static_assert(static_cast<u32>(SType::SurfaceDescriptorFromXlibWindow) ==
                  WGPUSType_SurfaceDescriptorFromXlibWindow,
              "value mismatch for SType::SurfaceDescriptorFromXlibWindow");
static_assert(
    static_cast<u32>(SType::SurfaceDescriptorFromCanvasHTMLSelector) ==
        WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector,
    "value mismatch for SType::SurfaceDescriptorFromCanvasHTMLSelector");
static_assert(static_cast<u32>(SType::ShaderModuleSPIRVDescriptor) ==
                  WGPUSType_ShaderModuleSPIRVDescriptor,
              "value mismatch for SType::ShaderModuleSPIRVDescriptor");
static_assert(static_cast<u32>(SType::ShaderModuleWGSLDescriptor) ==
                  WGPUSType_ShaderModuleWGSLDescriptor,
              "value mismatch for SType::ShaderModuleWGSLDescriptor");
static_assert(static_cast<u32>(SType::PrimitiveDepthClipControl) ==
                  WGPUSType_PrimitiveDepthClipControl,
              "value mismatch for SType::PrimitiveDepthClipControl");
static_assert(static_cast<u32>(SType::SurfaceDescriptorFromWaylandSurface) ==
                  WGPUSType_SurfaceDescriptorFromWaylandSurface,
              "value mismatch for SType::SurfaceDescriptorFromWaylandSurface");
static_assert(
    static_cast<u32>(SType::SurfaceDescriptorFromAndroidNativeWindow) ==
        WGPUSType_SurfaceDescriptorFromAndroidNativeWindow,
    "value mismatch for SType::SurfaceDescriptorFromAndroidNativeWindow");
static_assert(
    static_cast<u32>(SType::SurfaceDescriptorFromWindowsCoreWindow) ==
        WGPUSType_SurfaceDescriptorFromWindowsCoreWindow,
    "value mismatch for SType::SurfaceDescriptorFromWindowsCoreWindow");
static_assert(static_cast<u32>(SType::ExternalTextureBindingEntry) ==
                  WGPUSType_ExternalTextureBindingEntry,
              "value mismatch for SType::ExternalTextureBindingEntry");
static_assert(static_cast<u32>(SType::ExternalTextureBindingLayout) ==
                  WGPUSType_ExternalTextureBindingLayout,
              "value mismatch for SType::ExternalTextureBindingLayout");
static_assert(
    static_cast<u32>(SType::SurfaceDescriptorFromWindowsSwapChainPanel) ==
        WGPUSType_SurfaceDescriptorFromWindowsSwapChainPanel,
    "value mismatch for SType::SurfaceDescriptorFromWindowsSwapChainPanel");
static_assert(static_cast<u32>(SType::RenderPassDescriptorMaxDrawCount) ==
                  WGPUSType_RenderPassDescriptorMaxDrawCount,
              "value mismatch for SType::RenderPassDescriptorMaxDrawCount");
static_assert(static_cast<u32>(SType::MoonTextureInternalUsageDescriptor) ==
                  WGPUSType_MoonTextureInternalUsageDescriptor,
              "value mismatch for SType::MoonTextureInternalUsageDescriptor");
static_assert(static_cast<u32>(SType::MoonTogglesDeviceDescriptor) ==
                  WGPUSType_MoonTogglesDeviceDescriptor,
              "value mismatch for SType::MoonTogglesDeviceDescriptor");
static_assert(static_cast<u32>(SType::MoonEncoderInternalUsageDescriptor) ==
                  WGPUSType_MoonEncoderInternalUsageDescriptor,
              "value mismatch for SType::MoonEncoderInternalUsageDescriptor");
static_assert(static_cast<u32>(SType::MoonInstanceDescriptor) ==
                  WGPUSType_MoonInstanceDescriptor,
              "value mismatch for SType::MoonInstanceDescriptor");
static_assert(static_cast<u32>(SType::MoonCacheDeviceDescriptor) ==
                  WGPUSType_MoonCacheDeviceDescriptor,
              "value mismatch for SType::MoonCacheDeviceDescriptor");
static_assert(static_cast<u32>(SType::MoonAdapterPropertiesPowerPreference) ==
                  WGPUSType_MoonAdapterPropertiesPowerPreference,
              "value mismatch for SType::MoonAdapterPropertiesPowerPreference");

// SamplerBindingType

static_assert(sizeof(SamplerBindingType) == sizeof(WGPUSamplerBindingType),
              "sizeof mismatch for SamplerBindingType");
static_assert(alignof(SamplerBindingType) == alignof(WGPUSamplerBindingType),
              "alignof mismatch for SamplerBindingType");

static_assert(static_cast<u32>(SamplerBindingType::Undefined) ==
                  WGPUSamplerBindingType_Undefined,
              "value mismatch for SamplerBindingType::Undefined");
static_assert(static_cast<u32>(SamplerBindingType::Filtering) ==
                  WGPUSamplerBindingType_Filtering,
              "value mismatch for SamplerBindingType::Filtering");
static_assert(static_cast<u32>(SamplerBindingType::NonFiltering) ==
                  WGPUSamplerBindingType_NonFiltering,
              "value mismatch for SamplerBindingType::NonFiltering");
static_assert(static_cast<u32>(SamplerBindingType::Comparison) ==
                  WGPUSamplerBindingType_Comparison,
              "value mismatch for SamplerBindingType::Comparison");

// StencilOperation

static_assert(sizeof(StencilOperation) == sizeof(WGPUStencilOperation),
              "sizeof mismatch for StencilOperation");
static_assert(alignof(StencilOperation) == alignof(WGPUStencilOperation),
              "alignof mismatch for StencilOperation");

static_assert(static_cast<u32>(StencilOperation::Keep) ==
                  WGPUStencilOperation_Keep,
              "value mismatch for StencilOperation::Keep");
static_assert(static_cast<u32>(StencilOperation::Zero) ==
                  WGPUStencilOperation_Zero,
              "value mismatch for StencilOperation::Zero");
static_assert(static_cast<u32>(StencilOperation::Replace) ==
                  WGPUStencilOperation_Replace,
              "value mismatch for StencilOperation::Replace");
static_assert(static_cast<u32>(StencilOperation::Invert) ==
                  WGPUStencilOperation_Invert,
              "value mismatch for StencilOperation::Invert");
static_assert(static_cast<u32>(StencilOperation::IncrementClamp) ==
                  WGPUStencilOperation_IncrementClamp,
              "value mismatch for StencilOperation::IncrementClamp");
static_assert(static_cast<u32>(StencilOperation::DecrementClamp) ==
                  WGPUStencilOperation_DecrementClamp,
              "value mismatch for StencilOperation::DecrementClamp");
static_assert(static_cast<u32>(StencilOperation::IncrementWrap) ==
                  WGPUStencilOperation_IncrementWrap,
              "value mismatch for StencilOperation::IncrementWrap");
static_assert(static_cast<u32>(StencilOperation::DecrementWrap) ==
                  WGPUStencilOperation_DecrementWrap,
              "value mismatch for StencilOperation::DecrementWrap");

// StorageTextureAccess

static_assert(sizeof(StorageTextureAccess) == sizeof(WGPUStorageTextureAccess),
              "sizeof mismatch for StorageTextureAccess");
static_assert(alignof(StorageTextureAccess) ==
                  alignof(WGPUStorageTextureAccess),
              "alignof mismatch for StorageTextureAccess");

static_assert(static_cast<u32>(StorageTextureAccess::Undefined) ==
                  WGPUStorageTextureAccess_Undefined,
              "value mismatch for StorageTextureAccess::Undefined");
static_assert(static_cast<u32>(StorageTextureAccess::WriteOnly) ==
                  WGPUStorageTextureAccess_WriteOnly,
              "value mismatch for StorageTextureAccess::WriteOnly");

// StoreOp

static_assert(sizeof(StoreOp) == sizeof(WGPUStoreOp),
              "sizeof mismatch for StoreOp");
static_assert(alignof(StoreOp) == alignof(WGPUStoreOp),
              "alignof mismatch for StoreOp");

static_assert(static_cast<u32>(StoreOp::Undefined) == WGPUStoreOp_Undefined,
              "value mismatch for StoreOp::Undefined");
static_assert(static_cast<u32>(StoreOp::Store) == WGPUStoreOp_Store,
              "value mismatch for StoreOp::Store");
static_assert(static_cast<u32>(StoreOp::Discard) == WGPUStoreOp_Discard,
              "value mismatch for StoreOp::Discard");

// TextureAspect

static_assert(sizeof(TextureAspect) == sizeof(WGPUTextureAspect),
              "sizeof mismatch for TextureAspect");
static_assert(alignof(TextureAspect) == alignof(WGPUTextureAspect),
              "alignof mismatch for TextureAspect");

static_assert(static_cast<u32>(TextureAspect::All) == WGPUTextureAspect_All,
              "value mismatch for TextureAspect::All");
static_assert(static_cast<u32>(TextureAspect::StencilOnly) ==
                  WGPUTextureAspect_StencilOnly,
              "value mismatch for TextureAspect::StencilOnly");
static_assert(static_cast<u32>(TextureAspect::DepthOnly) ==
                  WGPUTextureAspect_DepthOnly,
              "value mismatch for TextureAspect::DepthOnly");
static_assert(static_cast<u32>(TextureAspect::Plane0Only) ==
                  WGPUTextureAspect_Plane0Only,
              "value mismatch for TextureAspect::Plane0Only");
static_assert(static_cast<u32>(TextureAspect::Plane1Only) ==
                  WGPUTextureAspect_Plane1Only,
              "value mismatch for TextureAspect::Plane1Only");

// TextureComponentType

static_assert(sizeof(TextureComponentType) == sizeof(WGPUTextureComponentType),
              "sizeof mismatch for TextureComponentType");
static_assert(alignof(TextureComponentType) ==
                  alignof(WGPUTextureComponentType),
              "alignof mismatch for TextureComponentType");

static_assert(static_cast<u32>(TextureComponentType::Float) ==
                  WGPUTextureComponentType_Float,
              "value mismatch for TextureComponentType::Float");
static_assert(static_cast<u32>(TextureComponentType::Sint) ==
                  WGPUTextureComponentType_Sint,
              "value mismatch for TextureComponentType::Sint");
static_assert(static_cast<u32>(TextureComponentType::Uint) ==
                  WGPUTextureComponentType_Uint,
              "value mismatch for TextureComponentType::Uint");
static_assert(static_cast<u32>(TextureComponentType::DepthComparison) ==
                  WGPUTextureComponentType_DepthComparison,
              "value mismatch for TextureComponentType::DepthComparison");

// TextureDimension

static_assert(sizeof(TextureDimension) == sizeof(WGPUTextureDimension),
              "sizeof mismatch for TextureDimension");
static_assert(alignof(TextureDimension) == alignof(WGPUTextureDimension),
              "alignof mismatch for TextureDimension");

static_assert(static_cast<u32>(TextureDimension::e1D) ==
                  WGPUTextureDimension_1D,
              "value mismatch for TextureDimension::e1D");
static_assert(static_cast<u32>(TextureDimension::e2D) ==
                  WGPUTextureDimension_2D,
              "value mismatch for TextureDimension::e2D");
static_assert(static_cast<u32>(TextureDimension::e3D) ==
                  WGPUTextureDimension_3D,
              "value mismatch for TextureDimension::e3D");

// TextureFormat

static_assert(sizeof(TextureFormat) == sizeof(WGPUTextureFormat),
              "sizeof mismatch for TextureFormat");
static_assert(alignof(TextureFormat) == alignof(WGPUTextureFormat),
              "alignof mismatch for TextureFormat");

static_assert(static_cast<u32>(TextureFormat::Undefined) ==
                  WGPUTextureFormat_Undefined,
              "value mismatch for TextureFormat::Undefined");
static_assert(static_cast<u32>(TextureFormat::R8Unorm) ==
                  WGPUTextureFormat_R8Unorm,
              "value mismatch for TextureFormat::R8Unorm");
static_assert(static_cast<u32>(TextureFormat::R8Snorm) ==
                  WGPUTextureFormat_R8Snorm,
              "value mismatch for TextureFormat::R8Snorm");
static_assert(static_cast<u32>(TextureFormat::R8Uint) ==
                  WGPUTextureFormat_R8Uint,
              "value mismatch for TextureFormat::R8Uint");
static_assert(static_cast<u32>(TextureFormat::R8Sint) ==
                  WGPUTextureFormat_R8Sint,
              "value mismatch for TextureFormat::R8Sint");
static_assert(static_cast<u32>(TextureFormat::R16Uint) ==
                  WGPUTextureFormat_R16Uint,
              "value mismatch for TextureFormat::R16Uint");
static_assert(static_cast<u32>(TextureFormat::R16Sint) ==
                  WGPUTextureFormat_R16Sint,
              "value mismatch for TextureFormat::R16Sint");
static_assert(static_cast<u32>(TextureFormat::R16Float) ==
                  WGPUTextureFormat_R16Float,
              "value mismatch for TextureFormat::R16Float");
static_assert(static_cast<u32>(TextureFormat::RG8Unorm) ==
                  WGPUTextureFormat_RG8Unorm,
              "value mismatch for TextureFormat::RG8Unorm");
static_assert(static_cast<u32>(TextureFormat::RG8Snorm) ==
                  WGPUTextureFormat_RG8Snorm,
              "value mismatch for TextureFormat::RG8Snorm");
static_assert(static_cast<u32>(TextureFormat::RG8Uint) ==
                  WGPUTextureFormat_RG8Uint,
              "value mismatch for TextureFormat::RG8Uint");
static_assert(static_cast<u32>(TextureFormat::RG8Sint) ==
                  WGPUTextureFormat_RG8Sint,
              "value mismatch for TextureFormat::RG8Sint");
static_assert(static_cast<u32>(TextureFormat::R32Float) ==
                  WGPUTextureFormat_R32Float,
              "value mismatch for TextureFormat::R32Float");
static_assert(static_cast<u32>(TextureFormat::R32Uint) ==
                  WGPUTextureFormat_R32Uint,
              "value mismatch for TextureFormat::R32Uint");
static_assert(static_cast<u32>(TextureFormat::R32Sint) ==
                  WGPUTextureFormat_R32Sint,
              "value mismatch for TextureFormat::R32Sint");
static_assert(static_cast<u32>(TextureFormat::RG16Uint) ==
                  WGPUTextureFormat_RG16Uint,
              "value mismatch for TextureFormat::RG16Uint");
static_assert(static_cast<u32>(TextureFormat::RG16Sint) ==
                  WGPUTextureFormat_RG16Sint,
              "value mismatch for TextureFormat::RG16Sint");
static_assert(static_cast<u32>(TextureFormat::RG16Float) ==
                  WGPUTextureFormat_RG16Float,
              "value mismatch for TextureFormat::RG16Float");
static_assert(static_cast<u32>(TextureFormat::RGBA8Unorm) ==
                  WGPUTextureFormat_RGBA8Unorm,
              "value mismatch for TextureFormat::RGBA8Unorm");
static_assert(static_cast<u32>(TextureFormat::RGBA8UnormSrgb) ==
                  WGPUTextureFormat_RGBA8UnormSrgb,
              "value mismatch for TextureFormat::RGBA8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::RGBA8Snorm) ==
                  WGPUTextureFormat_RGBA8Snorm,
              "value mismatch for TextureFormat::RGBA8Snorm");
static_assert(static_cast<u32>(TextureFormat::RGBA8Uint) ==
                  WGPUTextureFormat_RGBA8Uint,
              "value mismatch for TextureFormat::RGBA8Uint");
static_assert(static_cast<u32>(TextureFormat::RGBA8Sint) ==
                  WGPUTextureFormat_RGBA8Sint,
              "value mismatch for TextureFormat::RGBA8Sint");
static_assert(static_cast<u32>(TextureFormat::BGRA8Unorm) ==
                  WGPUTextureFormat_BGRA8Unorm,
              "value mismatch for TextureFormat::BGRA8Unorm");
static_assert(static_cast<u32>(TextureFormat::BGRA8UnormSrgb) ==
                  WGPUTextureFormat_BGRA8UnormSrgb,
              "value mismatch for TextureFormat::BGRA8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::RGB10A2Unorm) ==
                  WGPUTextureFormat_RGB10A2Unorm,
              "value mismatch for TextureFormat::RGB10A2Unorm");
static_assert(static_cast<u32>(TextureFormat::RG11B10Ufloat) ==
                  WGPUTextureFormat_RG11B10Ufloat,
              "value mismatch for TextureFormat::RG11B10Ufloat");
static_assert(static_cast<u32>(TextureFormat::RGB9E5Ufloat) ==
                  WGPUTextureFormat_RGB9E5Ufloat,
              "value mismatch for TextureFormat::RGB9E5Ufloat");
static_assert(static_cast<u32>(TextureFormat::RG32Float) ==
                  WGPUTextureFormat_RG32Float,
              "value mismatch for TextureFormat::RG32Float");
static_assert(static_cast<u32>(TextureFormat::RG32Uint) ==
                  WGPUTextureFormat_RG32Uint,
              "value mismatch for TextureFormat::RG32Uint");
static_assert(static_cast<u32>(TextureFormat::RG32Sint) ==
                  WGPUTextureFormat_RG32Sint,
              "value mismatch for TextureFormat::RG32Sint");
static_assert(static_cast<u32>(TextureFormat::RGBA16Uint) ==
                  WGPUTextureFormat_RGBA16Uint,
              "value mismatch for TextureFormat::RGBA16Uint");
static_assert(static_cast<u32>(TextureFormat::RGBA16Sint) ==
                  WGPUTextureFormat_RGBA16Sint,
              "value mismatch for TextureFormat::RGBA16Sint");
static_assert(static_cast<u32>(TextureFormat::RGBA16Float) ==
                  WGPUTextureFormat_RGBA16Float,
              "value mismatch for TextureFormat::RGBA16Float");
static_assert(static_cast<u32>(TextureFormat::RGBA32Float) ==
                  WGPUTextureFormat_RGBA32Float,
              "value mismatch for TextureFormat::RGBA32Float");
static_assert(static_cast<u32>(TextureFormat::RGBA32Uint) ==
                  WGPUTextureFormat_RGBA32Uint,
              "value mismatch for TextureFormat::RGBA32Uint");
static_assert(static_cast<u32>(TextureFormat::RGBA32Sint) ==
                  WGPUTextureFormat_RGBA32Sint,
              "value mismatch for TextureFormat::RGBA32Sint");
static_assert(static_cast<u32>(TextureFormat::Stencil8) ==
                  WGPUTextureFormat_Stencil8,
              "value mismatch for TextureFormat::Stencil8");
static_assert(static_cast<u32>(TextureFormat::Depth16Unorm) ==
                  WGPUTextureFormat_Depth16Unorm,
              "value mismatch for TextureFormat::Depth16Unorm");
static_assert(static_cast<u32>(TextureFormat::Depth24Plus) ==
                  WGPUTextureFormat_Depth24Plus,
              "value mismatch for TextureFormat::Depth24Plus");
static_assert(static_cast<u32>(TextureFormat::Depth24PlusStencil8) ==
                  WGPUTextureFormat_Depth24PlusStencil8,
              "value mismatch for TextureFormat::Depth24PlusStencil8");
static_assert(static_cast<u32>(TextureFormat::Depth32Float) ==
                  WGPUTextureFormat_Depth32Float,
              "value mismatch for TextureFormat::Depth32Float");
static_assert(static_cast<u32>(TextureFormat::Depth32FloatStencil8) ==
                  WGPUTextureFormat_Depth32FloatStencil8,
              "value mismatch for TextureFormat::Depth32FloatStencil8");
static_assert(static_cast<u32>(TextureFormat::BC1RGBAUnorm) ==
                  WGPUTextureFormat_BC1RGBAUnorm,
              "value mismatch for TextureFormat::BC1RGBAUnorm");
static_assert(static_cast<u32>(TextureFormat::BC1RGBAUnormSrgb) ==
                  WGPUTextureFormat_BC1RGBAUnormSrgb,
              "value mismatch for TextureFormat::BC1RGBAUnormSrgb");
static_assert(static_cast<u32>(TextureFormat::BC2RGBAUnorm) ==
                  WGPUTextureFormat_BC2RGBAUnorm,
              "value mismatch for TextureFormat::BC2RGBAUnorm");
static_assert(static_cast<u32>(TextureFormat::BC2RGBAUnormSrgb) ==
                  WGPUTextureFormat_BC2RGBAUnormSrgb,
              "value mismatch for TextureFormat::BC2RGBAUnormSrgb");
static_assert(static_cast<u32>(TextureFormat::BC3RGBAUnorm) ==
                  WGPUTextureFormat_BC3RGBAUnorm,
              "value mismatch for TextureFormat::BC3RGBAUnorm");
static_assert(static_cast<u32>(TextureFormat::BC3RGBAUnormSrgb) ==
                  WGPUTextureFormat_BC3RGBAUnormSrgb,
              "value mismatch for TextureFormat::BC3RGBAUnormSrgb");
static_assert(static_cast<u32>(TextureFormat::BC4RUnorm) ==
                  WGPUTextureFormat_BC4RUnorm,
              "value mismatch for TextureFormat::BC4RUnorm");
static_assert(static_cast<u32>(TextureFormat::BC4RSnorm) ==
                  WGPUTextureFormat_BC4RSnorm,
              "value mismatch for TextureFormat::BC4RSnorm");
static_assert(static_cast<u32>(TextureFormat::BC5RGUnorm) ==
                  WGPUTextureFormat_BC5RGUnorm,
              "value mismatch for TextureFormat::BC5RGUnorm");
static_assert(static_cast<u32>(TextureFormat::BC5RGSnorm) ==
                  WGPUTextureFormat_BC5RGSnorm,
              "value mismatch for TextureFormat::BC5RGSnorm");
static_assert(static_cast<u32>(TextureFormat::BC6HRGBUfloat) ==
                  WGPUTextureFormat_BC6HRGBUfloat,
              "value mismatch for TextureFormat::BC6HRGBUfloat");
static_assert(static_cast<u32>(TextureFormat::BC6HRGBFloat) ==
                  WGPUTextureFormat_BC6HRGBFloat,
              "value mismatch for TextureFormat::BC6HRGBFloat");
static_assert(static_cast<u32>(TextureFormat::BC7RGBAUnorm) ==
                  WGPUTextureFormat_BC7RGBAUnorm,
              "value mismatch for TextureFormat::BC7RGBAUnorm");
static_assert(static_cast<u32>(TextureFormat::BC7RGBAUnormSrgb) ==
                  WGPUTextureFormat_BC7RGBAUnormSrgb,
              "value mismatch for TextureFormat::BC7RGBAUnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ETC2RGB8Unorm) ==
                  WGPUTextureFormat_ETC2RGB8Unorm,
              "value mismatch for TextureFormat::ETC2RGB8Unorm");
static_assert(static_cast<u32>(TextureFormat::ETC2RGB8UnormSrgb) ==
                  WGPUTextureFormat_ETC2RGB8UnormSrgb,
              "value mismatch for TextureFormat::ETC2RGB8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ETC2RGB8A1Unorm) ==
                  WGPUTextureFormat_ETC2RGB8A1Unorm,
              "value mismatch for TextureFormat::ETC2RGB8A1Unorm");
static_assert(static_cast<u32>(TextureFormat::ETC2RGB8A1UnormSrgb) ==
                  WGPUTextureFormat_ETC2RGB8A1UnormSrgb,
              "value mismatch for TextureFormat::ETC2RGB8A1UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ETC2RGBA8Unorm) ==
                  WGPUTextureFormat_ETC2RGBA8Unorm,
              "value mismatch for TextureFormat::ETC2RGBA8Unorm");
static_assert(static_cast<u32>(TextureFormat::ETC2RGBA8UnormSrgb) ==
                  WGPUTextureFormat_ETC2RGBA8UnormSrgb,
              "value mismatch for TextureFormat::ETC2RGBA8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::EACR11Unorm) ==
                  WGPUTextureFormat_EACR11Unorm,
              "value mismatch for TextureFormat::EACR11Unorm");
static_assert(static_cast<u32>(TextureFormat::EACR11Snorm) ==
                  WGPUTextureFormat_EACR11Snorm,
              "value mismatch for TextureFormat::EACR11Snorm");
static_assert(static_cast<u32>(TextureFormat::EACRG11Unorm) ==
                  WGPUTextureFormat_EACRG11Unorm,
              "value mismatch for TextureFormat::EACRG11Unorm");
static_assert(static_cast<u32>(TextureFormat::EACRG11Snorm) ==
                  WGPUTextureFormat_EACRG11Snorm,
              "value mismatch for TextureFormat::EACRG11Snorm");
static_assert(static_cast<u32>(TextureFormat::ASTC4x4Unorm) ==
                  WGPUTextureFormat_ASTC4x4Unorm,
              "value mismatch for TextureFormat::ASTC4x4Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC4x4UnormSrgb) ==
                  WGPUTextureFormat_ASTC4x4UnormSrgb,
              "value mismatch for TextureFormat::ASTC4x4UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC5x4Unorm) ==
                  WGPUTextureFormat_ASTC5x4Unorm,
              "value mismatch for TextureFormat::ASTC5x4Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC5x4UnormSrgb) ==
                  WGPUTextureFormat_ASTC5x4UnormSrgb,
              "value mismatch for TextureFormat::ASTC5x4UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC5x5Unorm) ==
                  WGPUTextureFormat_ASTC5x5Unorm,
              "value mismatch for TextureFormat::ASTC5x5Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC5x5UnormSrgb) ==
                  WGPUTextureFormat_ASTC5x5UnormSrgb,
              "value mismatch for TextureFormat::ASTC5x5UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC6x5Unorm) ==
                  WGPUTextureFormat_ASTC6x5Unorm,
              "value mismatch for TextureFormat::ASTC6x5Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC6x5UnormSrgb) ==
                  WGPUTextureFormat_ASTC6x5UnormSrgb,
              "value mismatch for TextureFormat::ASTC6x5UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC6x6Unorm) ==
                  WGPUTextureFormat_ASTC6x6Unorm,
              "value mismatch for TextureFormat::ASTC6x6Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC6x6UnormSrgb) ==
                  WGPUTextureFormat_ASTC6x6UnormSrgb,
              "value mismatch for TextureFormat::ASTC6x6UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC8x5Unorm) ==
                  WGPUTextureFormat_ASTC8x5Unorm,
              "value mismatch for TextureFormat::ASTC8x5Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC8x5UnormSrgb) ==
                  WGPUTextureFormat_ASTC8x5UnormSrgb,
              "value mismatch for TextureFormat::ASTC8x5UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC8x6Unorm) ==
                  WGPUTextureFormat_ASTC8x6Unorm,
              "value mismatch for TextureFormat::ASTC8x6Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC8x6UnormSrgb) ==
                  WGPUTextureFormat_ASTC8x6UnormSrgb,
              "value mismatch for TextureFormat::ASTC8x6UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC8x8Unorm) ==
                  WGPUTextureFormat_ASTC8x8Unorm,
              "value mismatch for TextureFormat::ASTC8x8Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC8x8UnormSrgb) ==
                  WGPUTextureFormat_ASTC8x8UnormSrgb,
              "value mismatch for TextureFormat::ASTC8x8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC10x5Unorm) ==
                  WGPUTextureFormat_ASTC10x5Unorm,
              "value mismatch for TextureFormat::ASTC10x5Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC10x5UnormSrgb) ==
                  WGPUTextureFormat_ASTC10x5UnormSrgb,
              "value mismatch for TextureFormat::ASTC10x5UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC10x6Unorm) ==
                  WGPUTextureFormat_ASTC10x6Unorm,
              "value mismatch for TextureFormat::ASTC10x6Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC10x6UnormSrgb) ==
                  WGPUTextureFormat_ASTC10x6UnormSrgb,
              "value mismatch for TextureFormat::ASTC10x6UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC10x8Unorm) ==
                  WGPUTextureFormat_ASTC10x8Unorm,
              "value mismatch for TextureFormat::ASTC10x8Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC10x8UnormSrgb) ==
                  WGPUTextureFormat_ASTC10x8UnormSrgb,
              "value mismatch for TextureFormat::ASTC10x8UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC10x10Unorm) ==
                  WGPUTextureFormat_ASTC10x10Unorm,
              "value mismatch for TextureFormat::ASTC10x10Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC10x10UnormSrgb) ==
                  WGPUTextureFormat_ASTC10x10UnormSrgb,
              "value mismatch for TextureFormat::ASTC10x10UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC12x10Unorm) ==
                  WGPUTextureFormat_ASTC12x10Unorm,
              "value mismatch for TextureFormat::ASTC12x10Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC12x10UnormSrgb) ==
                  WGPUTextureFormat_ASTC12x10UnormSrgb,
              "value mismatch for TextureFormat::ASTC12x10UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::ASTC12x12Unorm) ==
                  WGPUTextureFormat_ASTC12x12Unorm,
              "value mismatch for TextureFormat::ASTC12x12Unorm");
static_assert(static_cast<u32>(TextureFormat::ASTC12x12UnormSrgb) ==
                  WGPUTextureFormat_ASTC12x12UnormSrgb,
              "value mismatch for TextureFormat::ASTC12x12UnormSrgb");
static_assert(static_cast<u32>(TextureFormat::R8BG8Biplanar420Unorm) ==
                  WGPUTextureFormat_R8BG8Biplanar420Unorm,
              "value mismatch for TextureFormat::R8BG8Biplanar420Unorm");

// TextureSampleType

static_assert(sizeof(TextureSampleType) == sizeof(WGPUTextureSampleType),
              "sizeof mismatch for TextureSampleType");
static_assert(alignof(TextureSampleType) == alignof(WGPUTextureSampleType),
              "alignof mismatch for TextureSampleType");

static_assert(static_cast<u32>(TextureSampleType::Undefined) ==
                  WGPUTextureSampleType_Undefined,
              "value mismatch for TextureSampleType::Undefined");
static_assert(static_cast<u32>(TextureSampleType::Float) ==
                  WGPUTextureSampleType_Float,
              "value mismatch for TextureSampleType::Float");
static_assert(static_cast<u32>(TextureSampleType::UnfilterableFloat) ==
                  WGPUTextureSampleType_UnfilterableFloat,
              "value mismatch for TextureSampleType::UnfilterableFloat");
static_assert(static_cast<u32>(TextureSampleType::Depth) ==
                  WGPUTextureSampleType_Depth,
              "value mismatch for TextureSampleType::Depth");
static_assert(static_cast<u32>(TextureSampleType::Sint) ==
                  WGPUTextureSampleType_Sint,
              "value mismatch for TextureSampleType::Sint");
static_assert(static_cast<u32>(TextureSampleType::Uint) ==
                  WGPUTextureSampleType_Uint,
              "value mismatch for TextureSampleType::Uint");

// TextureViewDimension

static_assert(sizeof(TextureViewDimension) == sizeof(WGPUTextureViewDimension),
              "sizeof mismatch for TextureViewDimension");
static_assert(alignof(TextureViewDimension) ==
                  alignof(WGPUTextureViewDimension),
              "alignof mismatch for TextureViewDimension");

static_assert(static_cast<u32>(TextureViewDimension::Undefined) ==
                  WGPUTextureViewDimension_Undefined,
              "value mismatch for TextureViewDimension::Undefined");
static_assert(static_cast<u32>(TextureViewDimension::e1D) ==
                  WGPUTextureViewDimension_1D,
              "value mismatch for TextureViewDimension::e1D");
static_assert(static_cast<u32>(TextureViewDimension::e2D) ==
                  WGPUTextureViewDimension_2D,
              "value mismatch for TextureViewDimension::e2D");
static_assert(static_cast<u32>(TextureViewDimension::e2DArray) ==
                  WGPUTextureViewDimension_2DArray,
              "value mismatch for TextureViewDimension::e2DArray");
static_assert(static_cast<u32>(TextureViewDimension::Cube) ==
                  WGPUTextureViewDimension_Cube,
              "value mismatch for TextureViewDimension::Cube");
static_assert(static_cast<u32>(TextureViewDimension::CubeArray) ==
                  WGPUTextureViewDimension_CubeArray,
              "value mismatch for TextureViewDimension::CubeArray");
static_assert(static_cast<u32>(TextureViewDimension::e3D) ==
                  WGPUTextureViewDimension_3D,
              "value mismatch for TextureViewDimension::e3D");

// VertexFormat

static_assert(sizeof(VertexFormat) == sizeof(WGPUVertexFormat),
              "sizeof mismatch for VertexFormat");
static_assert(alignof(VertexFormat) == alignof(WGPUVertexFormat),
              "alignof mismatch for VertexFormat");

static_assert(static_cast<u32>(VertexFormat::Undefined) ==
                  WGPUVertexFormat_Undefined,
              "value mismatch for VertexFormat::Undefined");
static_assert(static_cast<u32>(VertexFormat::Uint8x2) ==
                  WGPUVertexFormat_Uint8x2,
              "value mismatch for VertexFormat::Uint8x2");
static_assert(static_cast<u32>(VertexFormat::Uint8x4) ==
                  WGPUVertexFormat_Uint8x4,
              "value mismatch for VertexFormat::Uint8x4");
static_assert(static_cast<u32>(VertexFormat::Sint8x2) ==
                  WGPUVertexFormat_Sint8x2,
              "value mismatch for VertexFormat::Sint8x2");
static_assert(static_cast<u32>(VertexFormat::Sint8x4) ==
                  WGPUVertexFormat_Sint8x4,
              "value mismatch for VertexFormat::Sint8x4");
static_assert(static_cast<u32>(VertexFormat::Unorm8x2) ==
                  WGPUVertexFormat_Unorm8x2,
              "value mismatch for VertexFormat::Unorm8x2");
static_assert(static_cast<u32>(VertexFormat::Unorm8x4) ==
                  WGPUVertexFormat_Unorm8x4,
              "value mismatch for VertexFormat::Unorm8x4");
static_assert(static_cast<u32>(VertexFormat::Snorm8x2) ==
                  WGPUVertexFormat_Snorm8x2,
              "value mismatch for VertexFormat::Snorm8x2");
static_assert(static_cast<u32>(VertexFormat::Snorm8x4) ==
                  WGPUVertexFormat_Snorm8x4,
              "value mismatch for VertexFormat::Snorm8x4");
static_assert(static_cast<u32>(VertexFormat::Uint16x2) ==
                  WGPUVertexFormat_Uint16x2,
              "value mismatch for VertexFormat::Uint16x2");
static_assert(static_cast<u32>(VertexFormat::Uint16x4) ==
                  WGPUVertexFormat_Uint16x4,
              "value mismatch for VertexFormat::Uint16x4");
static_assert(static_cast<u32>(VertexFormat::Sint16x2) ==
                  WGPUVertexFormat_Sint16x2,
              "value mismatch for VertexFormat::Sint16x2");
static_assert(static_cast<u32>(VertexFormat::Sint16x4) ==
                  WGPUVertexFormat_Sint16x4,
              "value mismatch for VertexFormat::Sint16x4");
static_assert(static_cast<u32>(VertexFormat::Unorm16x2) ==
                  WGPUVertexFormat_Unorm16x2,
              "value mismatch for VertexFormat::Unorm16x2");
static_assert(static_cast<u32>(VertexFormat::Unorm16x4) ==
                  WGPUVertexFormat_Unorm16x4,
              "value mismatch for VertexFormat::Unorm16x4");
static_assert(static_cast<u32>(VertexFormat::Snorm16x2) ==
                  WGPUVertexFormat_Snorm16x2,
              "value mismatch for VertexFormat::Snorm16x2");
static_assert(static_cast<u32>(VertexFormat::Snorm16x4) ==
                  WGPUVertexFormat_Snorm16x4,
              "value mismatch for VertexFormat::Snorm16x4");
static_assert(static_cast<u32>(VertexFormat::Float16x2) ==
                  WGPUVertexFormat_Float16x2,
              "value mismatch for VertexFormat::Float16x2");
static_assert(static_cast<u32>(VertexFormat::Float16x4) ==
                  WGPUVertexFormat_Float16x4,
              "value mismatch for VertexFormat::Float16x4");
static_assert(static_cast<u32>(VertexFormat::Float32) ==
                  WGPUVertexFormat_Float32,
              "value mismatch for VertexFormat::Float32");
static_assert(static_cast<u32>(VertexFormat::Float32x2) ==
                  WGPUVertexFormat_Float32x2,
              "value mismatch for VertexFormat::Float32x2");
static_assert(static_cast<u32>(VertexFormat::Float32x3) ==
                  WGPUVertexFormat_Float32x3,
              "value mismatch for VertexFormat::Float32x3");
static_assert(static_cast<u32>(VertexFormat::Float32x4) ==
                  WGPUVertexFormat_Float32x4,
              "value mismatch for VertexFormat::Float32x4");
static_assert(static_cast<u32>(VertexFormat::Uint32) == WGPUVertexFormat_Uint32,
              "value mismatch for VertexFormat::Uint32");
static_assert(static_cast<u32>(VertexFormat::Uint32x2) ==
                  WGPUVertexFormat_Uint32x2,
              "value mismatch for VertexFormat::Uint32x2");
static_assert(static_cast<u32>(VertexFormat::Uint32x3) ==
                  WGPUVertexFormat_Uint32x3,
              "value mismatch for VertexFormat::Uint32x3");
static_assert(static_cast<u32>(VertexFormat::Uint32x4) ==
                  WGPUVertexFormat_Uint32x4,
              "value mismatch for VertexFormat::Uint32x4");
static_assert(static_cast<u32>(VertexFormat::Sint32) == WGPUVertexFormat_Sint32,
              "value mismatch for VertexFormat::Sint32");
static_assert(static_cast<u32>(VertexFormat::Sint32x2) ==
                  WGPUVertexFormat_Sint32x2,
              "value mismatch for VertexFormat::Sint32x2");
static_assert(static_cast<u32>(VertexFormat::Sint32x3) ==
                  WGPUVertexFormat_Sint32x3,
              "value mismatch for VertexFormat::Sint32x3");
static_assert(static_cast<u32>(VertexFormat::Sint32x4) ==
                  WGPUVertexFormat_Sint32x4,
              "value mismatch for VertexFormat::Sint32x4");

// VertexStepMode

static_assert(sizeof(VertexStepMode) == sizeof(WGPUVertexStepMode),
              "sizeof mismatch for VertexStepMode");
static_assert(alignof(VertexStepMode) == alignof(WGPUVertexStepMode),
              "alignof mismatch for VertexStepMode");

static_assert(static_cast<u32>(VertexStepMode::Vertex) ==
                  WGPUVertexStepMode_Vertex,
              "value mismatch for VertexStepMode::Vertex");
static_assert(static_cast<u32>(VertexStepMode::Instance) ==
                  WGPUVertexStepMode_Instance,
              "value mismatch for VertexStepMode::Instance");
static_assert(static_cast<u32>(VertexStepMode::VertexBufferNotUsed) ==
                  WGPUVertexStepMode_VertexBufferNotUsed,
              "value mismatch for VertexStepMode::VertexBufferNotUsed");

// BufferUsage

static_assert(sizeof(BufferUsage) == sizeof(WGPUBufferUsageFlags),
              "sizeof mismatch for BufferUsage");
static_assert(alignof(BufferUsage) == alignof(WGPUBufferUsageFlags),
              "alignof mismatch for BufferUsage");

static_assert(static_cast<u32>(BufferUsage::None) == WGPUBufferUsage_None,
              "value mismatch for BufferUsage::None");
static_assert(static_cast<u32>(BufferUsage::MapRead) == WGPUBufferUsage_MapRead,
              "value mismatch for BufferUsage::MapRead");
static_assert(static_cast<u32>(BufferUsage::MapWrite) ==
                  WGPUBufferUsage_MapWrite,
              "value mismatch for BufferUsage::MapWrite");
static_assert(static_cast<u32>(BufferUsage::CopySrc) == WGPUBufferUsage_CopySrc,
              "value mismatch for BufferUsage::CopySrc");
static_assert(static_cast<u32>(BufferUsage::CopyDst) == WGPUBufferUsage_CopyDst,
              "value mismatch for BufferUsage::CopyDst");
static_assert(static_cast<u32>(BufferUsage::Index) == WGPUBufferUsage_Index,
              "value mismatch for BufferUsage::Index");
static_assert(static_cast<u32>(BufferUsage::Vertex) == WGPUBufferUsage_Vertex,
              "value mismatch for BufferUsage::Vertex");
static_assert(static_cast<u32>(BufferUsage::Uniform) == WGPUBufferUsage_Uniform,
              "value mismatch for BufferUsage::Uniform");
static_assert(static_cast<u32>(BufferUsage::Storage) == WGPUBufferUsage_Storage,
              "value mismatch for BufferUsage::Storage");
static_assert(static_cast<u32>(BufferUsage::Indirect) ==
                  WGPUBufferUsage_Indirect,
              "value mismatch for BufferUsage::Indirect");
static_assert(static_cast<u32>(BufferUsage::QueryResolve) ==
                  WGPUBufferUsage_QueryResolve,
              "value mismatch for BufferUsage::QueryResolve");

// ColorWriteMask

static_assert(sizeof(ColorWriteMask) == sizeof(WGPUColorWriteMaskFlags),
              "sizeof mismatch for ColorWriteMask");
static_assert(alignof(ColorWriteMask) == alignof(WGPUColorWriteMaskFlags),
              "alignof mismatch for ColorWriteMask");

static_assert(static_cast<u32>(ColorWriteMask::None) == WGPUColorWriteMask_None,
              "value mismatch for ColorWriteMask::None");
static_assert(static_cast<u32>(ColorWriteMask::Red) == WGPUColorWriteMask_Red,
              "value mismatch for ColorWriteMask::Red");
static_assert(static_cast<u32>(ColorWriteMask::Green) ==
                  WGPUColorWriteMask_Green,
              "value mismatch for ColorWriteMask::Green");
static_assert(static_cast<u32>(ColorWriteMask::Blue) == WGPUColorWriteMask_Blue,
              "value mismatch for ColorWriteMask::Blue");
static_assert(static_cast<u32>(ColorWriteMask::Alpha) ==
                  WGPUColorWriteMask_Alpha,
              "value mismatch for ColorWriteMask::Alpha");
static_assert(static_cast<u32>(ColorWriteMask::All) == WGPUColorWriteMask_All,
              "value mismatch for ColorWriteMask::All");

// MapMode

static_assert(sizeof(MapMode) == sizeof(WGPUMapModeFlags),
              "sizeof mismatch for MapMode");
static_assert(alignof(MapMode) == alignof(WGPUMapModeFlags),
              "alignof mismatch for MapMode");

static_assert(static_cast<u32>(MapMode::None) == WGPUMapMode_None,
              "value mismatch for MapMode::None");
static_assert(static_cast<u32>(MapMode::Read) == WGPUMapMode_Read,
              "value mismatch for MapMode::Read");
static_assert(static_cast<u32>(MapMode::Write) == WGPUMapMode_Write,
              "value mismatch for MapMode::Write");

// ShaderStage

static_assert(sizeof(ShaderStage) == sizeof(WGPUShaderStageFlags),
              "sizeof mismatch for ShaderStage");
static_assert(alignof(ShaderStage) == alignof(WGPUShaderStageFlags),
              "alignof mismatch for ShaderStage");

static_assert(static_cast<u32>(ShaderStage::None) == WGPUShaderStage_None,
              "value mismatch for ShaderStage::None");
static_assert(static_cast<u32>(ShaderStage::Vertex) == WGPUShaderStage_Vertex,
              "value mismatch for ShaderStage::Vertex");
static_assert(static_cast<u32>(ShaderStage::Fragment) ==
                  WGPUShaderStage_Fragment,
              "value mismatch for ShaderStage::Fragment");
static_assert(static_cast<u32>(ShaderStage::Compute) == WGPUShaderStage_Compute,
              "value mismatch for ShaderStage::Compute");

// TextureUsage

static_assert(sizeof(TextureUsage) == sizeof(WGPUTextureUsageFlags),
              "sizeof mismatch for TextureUsage");
static_assert(alignof(TextureUsage) == alignof(WGPUTextureUsageFlags),
              "alignof mismatch for TextureUsage");

static_assert(static_cast<u32>(TextureUsage::None) == WGPUTextureUsage_None,
              "value mismatch for TextureUsage::None");
static_assert(static_cast<u32>(TextureUsage::CopySrc) ==
                  WGPUTextureUsage_CopySrc,
              "value mismatch for TextureUsage::CopySrc");
static_assert(static_cast<u32>(TextureUsage::CopyDst) ==
                  WGPUTextureUsage_CopyDst,
              "value mismatch for TextureUsage::CopyDst");
static_assert(static_cast<u32>(TextureUsage::TextureBinding) ==
                  WGPUTextureUsage_TextureBinding,
              "value mismatch for TextureUsage::TextureBinding");
static_assert(static_cast<u32>(TextureUsage::StorageBinding) ==
                  WGPUTextureUsage_StorageBinding,
              "value mismatch for TextureUsage::StorageBinding");
static_assert(static_cast<u32>(TextureUsage::RenderAttachment) ==
                  WGPUTextureUsage_RenderAttachment,
              "value mismatch for TextureUsage::RenderAttachment");
static_assert(static_cast<u32>(TextureUsage::Present) ==
                  WGPUTextureUsage_Present,
              "value mismatch for TextureUsage::Present");

// ChainedStruct

static_assert(sizeof(ChainedStruct) == sizeof(WGPUChainedStruct),
              "sizeof mismatch for ChainedStruct");
static_assert(alignof(ChainedStruct) == alignof(WGPUChainedStruct),
              "alignof mismatch for ChainedStruct");
static_assert(offsetof(ChainedStruct, nextInChain) ==
                  offsetof(WGPUChainedStruct, next),
              "offsetof mismatch for ChainedStruct::nextInChain");
static_assert(offsetof(ChainedStruct, sType) ==
                  offsetof(WGPUChainedStruct, sType),
              "offsetof mismatch for ChainedStruct::sType");

// AdapterProperties

static_assert(sizeof(AdapterProperties) == sizeof(WGPUAdapterProperties),
              "sizeof mismatch for AdapterProperties");
static_assert(alignof(AdapterProperties) == alignof(WGPUAdapterProperties),
              "alignof mismatch for AdapterProperties");

static_assert(offsetof(AdapterProperties, nextInChain) ==
                  offsetof(WGPUAdapterProperties, nextInChain),
              "offsetof mismatch for AdapterProperties::nextInChain");
static_assert(offsetof(AdapterProperties, vendorID) ==
                  offsetof(WGPUAdapterProperties, vendorID),
              "offsetof mismatch for AdapterProperties::vendorID");
static_assert(offsetof(AdapterProperties, vendorName) ==
                  offsetof(WGPUAdapterProperties, vendorName),
              "offsetof mismatch for AdapterProperties::vendorName");
static_assert(offsetof(AdapterProperties, architecture) ==
                  offsetof(WGPUAdapterProperties, architecture),
              "offsetof mismatch for AdapterProperties::architecture");
static_assert(offsetof(AdapterProperties, deviceID) ==
                  offsetof(WGPUAdapterProperties, deviceID),
              "offsetof mismatch for AdapterProperties::deviceID");
static_assert(offsetof(AdapterProperties, name) ==
                  offsetof(WGPUAdapterProperties, name),
              "offsetof mismatch for AdapterProperties::name");
static_assert(offsetof(AdapterProperties, driverDescription) ==
                  offsetof(WGPUAdapterProperties, driverDescription),
              "offsetof mismatch for AdapterProperties::driverDescription");
static_assert(offsetof(AdapterProperties, adapterType) ==
                  offsetof(WGPUAdapterProperties, adapterType),
              "offsetof mismatch for AdapterProperties::adapterType");
static_assert(offsetof(AdapterProperties, backendType) ==
                  offsetof(WGPUAdapterProperties, backendType),
              "offsetof mismatch for AdapterProperties::backendType");

// BindGroupEntry

static_assert(sizeof(BindGroupEntry) == sizeof(WGPUBindGroupEntry),
              "sizeof mismatch for BindGroupEntry");
static_assert(alignof(BindGroupEntry) == alignof(WGPUBindGroupEntry),
              "alignof mismatch for BindGroupEntry");

static_assert(offsetof(BindGroupEntry, nextInChain) ==
                  offsetof(WGPUBindGroupEntry, nextInChain),
              "offsetof mismatch for BindGroupEntry::nextInChain");
static_assert(offsetof(BindGroupEntry, binding) ==
                  offsetof(WGPUBindGroupEntry, binding),
              "offsetof mismatch for BindGroupEntry::binding");
static_assert(offsetof(BindGroupEntry, buffer) ==
                  offsetof(WGPUBindGroupEntry, buffer),
              "offsetof mismatch for BindGroupEntry::buffer");
static_assert(offsetof(BindGroupEntry, offset) ==
                  offsetof(WGPUBindGroupEntry, offset),
              "offsetof mismatch for BindGroupEntry::offset");
static_assert(offsetof(BindGroupEntry, size) ==
                  offsetof(WGPUBindGroupEntry, size),
              "offsetof mismatch for BindGroupEntry::size");
static_assert(offsetof(BindGroupEntry, sampler) ==
                  offsetof(WGPUBindGroupEntry, sampler),
              "offsetof mismatch for BindGroupEntry::sampler");
static_assert(offsetof(BindGroupEntry, textureView) ==
                  offsetof(WGPUBindGroupEntry, textureView),
              "offsetof mismatch for BindGroupEntry::textureView");

// BlendComponent

static_assert(sizeof(BlendComponent) == sizeof(WGPUBlendComponent),
              "sizeof mismatch for BlendComponent");
static_assert(alignof(BlendComponent) == alignof(WGPUBlendComponent),
              "alignof mismatch for BlendComponent");

static_assert(offsetof(BlendComponent, operation) ==
                  offsetof(WGPUBlendComponent, operation),
              "offsetof mismatch for BlendComponent::operation");
static_assert(offsetof(BlendComponent, srcFactor) ==
                  offsetof(WGPUBlendComponent, srcFactor),
              "offsetof mismatch for BlendComponent::srcFactor");
static_assert(offsetof(BlendComponent, dstFactor) ==
                  offsetof(WGPUBlendComponent, dstFactor),
              "offsetof mismatch for BlendComponent::dstFactor");

// BufferBindingLayout

static_assert(sizeof(BufferBindingLayout) == sizeof(WGPUBufferBindingLayout),
              "sizeof mismatch for BufferBindingLayout");
static_assert(alignof(BufferBindingLayout) == alignof(WGPUBufferBindingLayout),
              "alignof mismatch for BufferBindingLayout");

static_assert(offsetof(BufferBindingLayout, nextInChain) ==
                  offsetof(WGPUBufferBindingLayout, nextInChain),
              "offsetof mismatch for BufferBindingLayout::nextInChain");
static_assert(offsetof(BufferBindingLayout, type) ==
                  offsetof(WGPUBufferBindingLayout, type),
              "offsetof mismatch for BufferBindingLayout::type");
static_assert(offsetof(BufferBindingLayout, hasDynamicOffset) ==
                  offsetof(WGPUBufferBindingLayout, hasDynamicOffset),
              "offsetof mismatch for BufferBindingLayout::hasDynamicOffset");
static_assert(offsetof(BufferBindingLayout, minBindingSize) ==
                  offsetof(WGPUBufferBindingLayout, minBindingSize),
              "offsetof mismatch for BufferBindingLayout::minBindingSize");

// BufferDescriptor

static_assert(sizeof(BufferDescriptor) == sizeof(WGPUBufferDescriptor),
              "sizeof mismatch for BufferDescriptor");
static_assert(alignof(BufferDescriptor) == alignof(WGPUBufferDescriptor),
              "alignof mismatch for BufferDescriptor");

static_assert(offsetof(BufferDescriptor, nextInChain) ==
                  offsetof(WGPUBufferDescriptor, nextInChain),
              "offsetof mismatch for BufferDescriptor::nextInChain");
static_assert(offsetof(BufferDescriptor, label) ==
                  offsetof(WGPUBufferDescriptor, label),
              "offsetof mismatch for BufferDescriptor::label");
static_assert(offsetof(BufferDescriptor, usage) ==
                  offsetof(WGPUBufferDescriptor, usage),
              "offsetof mismatch for BufferDescriptor::usage");
static_assert(offsetof(BufferDescriptor, size) ==
                  offsetof(WGPUBufferDescriptor, size),
              "offsetof mismatch for BufferDescriptor::size");
static_assert(offsetof(BufferDescriptor, mappedAtCreation) ==
                  offsetof(WGPUBufferDescriptor, mappedAtCreation),
              "offsetof mismatch for BufferDescriptor::mappedAtCreation");

// Color

static_assert(sizeof(Color) == sizeof(WGPUColor), "sizeof mismatch for Color");
static_assert(alignof(Color) == alignof(WGPUColor),
              "alignof mismatch for Color");

static_assert(offsetof(Color, r) == offsetof(WGPUColor, r),
              "offsetof mismatch for Color::r");
static_assert(offsetof(Color, g) == offsetof(WGPUColor, g),
              "offsetof mismatch for Color::g");
static_assert(offsetof(Color, b) == offsetof(WGPUColor, b),
              "offsetof mismatch for Color::b");
static_assert(offsetof(Color, a) == offsetof(WGPUColor, a),
              "offsetof mismatch for Color::a");

// CommandBufferDescriptor

static_assert(sizeof(CommandBufferDescriptor) ==
                  sizeof(WGPUCommandBufferDescriptor),
              "sizeof mismatch for CommandBufferDescriptor");
static_assert(alignof(CommandBufferDescriptor) ==
                  alignof(WGPUCommandBufferDescriptor),
              "alignof mismatch for CommandBufferDescriptor");

static_assert(offsetof(CommandBufferDescriptor, nextInChain) ==
                  offsetof(WGPUCommandBufferDescriptor, nextInChain),
              "offsetof mismatch for CommandBufferDescriptor::nextInChain");
static_assert(offsetof(CommandBufferDescriptor, label) ==
                  offsetof(WGPUCommandBufferDescriptor, label),
              "offsetof mismatch for CommandBufferDescriptor::label");

// CommandEncoderDescriptor

static_assert(sizeof(CommandEncoderDescriptor) ==
                  sizeof(WGPUCommandEncoderDescriptor),
              "sizeof mismatch for CommandEncoderDescriptor");
static_assert(alignof(CommandEncoderDescriptor) ==
                  alignof(WGPUCommandEncoderDescriptor),
              "alignof mismatch for CommandEncoderDescriptor");

static_assert(offsetof(CommandEncoderDescriptor, nextInChain) ==
                  offsetof(WGPUCommandEncoderDescriptor, nextInChain),
              "offsetof mismatch for CommandEncoderDescriptor::nextInChain");
static_assert(offsetof(CommandEncoderDescriptor, label) ==
                  offsetof(WGPUCommandEncoderDescriptor, label),
              "offsetof mismatch for CommandEncoderDescriptor::label");

// CompilationMessage

static_assert(sizeof(CompilationMessage) == sizeof(WGPUCompilationMessage),
              "sizeof mismatch for CompilationMessage");
static_assert(alignof(CompilationMessage) == alignof(WGPUCompilationMessage),
              "alignof mismatch for CompilationMessage");

static_assert(offsetof(CompilationMessage, nextInChain) ==
                  offsetof(WGPUCompilationMessage, nextInChain),
              "offsetof mismatch for CompilationMessage::nextInChain");
static_assert(offsetof(CompilationMessage, message) ==
                  offsetof(WGPUCompilationMessage, message),
              "offsetof mismatch for CompilationMessage::message");
static_assert(offsetof(CompilationMessage, type) ==
                  offsetof(WGPUCompilationMessage, type),
              "offsetof mismatch for CompilationMessage::type");
static_assert(offsetof(CompilationMessage, lineNum) ==
                  offsetof(WGPUCompilationMessage, lineNum),
              "offsetof mismatch for CompilationMessage::lineNum");
static_assert(offsetof(CompilationMessage, linePos) ==
                  offsetof(WGPUCompilationMessage, linePos),
              "offsetof mismatch for CompilationMessage::linePos");
static_assert(offsetof(CompilationMessage, offset) ==
                  offsetof(WGPUCompilationMessage, offset),
              "offsetof mismatch for CompilationMessage::offset");
static_assert(offsetof(CompilationMessage, length) ==
                  offsetof(WGPUCompilationMessage, length),
              "offsetof mismatch for CompilationMessage::length");

// ComputePassTimestampWrite

static_assert(sizeof(ComputePassTimestampWrite) ==
                  sizeof(WGPUComputePassTimestampWrite),
              "sizeof mismatch for ComputePassTimestampWrite");
static_assert(alignof(ComputePassTimestampWrite) ==
                  alignof(WGPUComputePassTimestampWrite),
              "alignof mismatch for ComputePassTimestampWrite");

static_assert(offsetof(ComputePassTimestampWrite, querySet) ==
                  offsetof(WGPUComputePassTimestampWrite, querySet),
              "offsetof mismatch for ComputePassTimestampWrite::querySet");
static_assert(offsetof(ComputePassTimestampWrite, queryIndex) ==
                  offsetof(WGPUComputePassTimestampWrite, queryIndex),
              "offsetof mismatch for ComputePassTimestampWrite::queryIndex");
static_assert(offsetof(ComputePassTimestampWrite, location) ==
                  offsetof(WGPUComputePassTimestampWrite, location),
              "offsetof mismatch for ComputePassTimestampWrite::location");

// ConstantEntry

static_assert(sizeof(ConstantEntry) == sizeof(WGPUConstantEntry),
              "sizeof mismatch for ConstantEntry");
static_assert(alignof(ConstantEntry) == alignof(WGPUConstantEntry),
              "alignof mismatch for ConstantEntry");

static_assert(offsetof(ConstantEntry, nextInChain) ==
                  offsetof(WGPUConstantEntry, nextInChain),
              "offsetof mismatch for ConstantEntry::nextInChain");
static_assert(offsetof(ConstantEntry, key) == offsetof(WGPUConstantEntry, key),
              "offsetof mismatch for ConstantEntry::key");
static_assert(offsetof(ConstantEntry, value) ==
                  offsetof(WGPUConstantEntry, value),
              "offsetof mismatch for ConstantEntry::value");

// CopyTextureForBrowserOptions

static_assert(sizeof(CopyTextureForBrowserOptions) ==
                  sizeof(WGPUCopyTextureForBrowserOptions),
              "sizeof mismatch for CopyTextureForBrowserOptions");
static_assert(alignof(CopyTextureForBrowserOptions) ==
                  alignof(WGPUCopyTextureForBrowserOptions),
              "alignof mismatch for CopyTextureForBrowserOptions");

static_assert(
    offsetof(CopyTextureForBrowserOptions, nextInChain) ==
        offsetof(WGPUCopyTextureForBrowserOptions, nextInChain),
    "offsetof mismatch for CopyTextureForBrowserOptions::nextInChain");
static_assert(offsetof(CopyTextureForBrowserOptions, flipY) ==
                  offsetof(WGPUCopyTextureForBrowserOptions, flipY),
              "offsetof mismatch for CopyTextureForBrowserOptions::flipY");
static_assert(offsetof(CopyTextureForBrowserOptions,
                       needsColorSpaceConversion) ==
                  offsetof(WGPUCopyTextureForBrowserOptions,
                           needsColorSpaceConversion),
              "offsetof mismatch for "
              "CopyTextureForBrowserOptions::needsColorSpaceConversion");
static_assert(
    offsetof(CopyTextureForBrowserOptions, srcAlphaMode) ==
        offsetof(WGPUCopyTextureForBrowserOptions, srcAlphaMode),
    "offsetof mismatch for CopyTextureForBrowserOptions::srcAlphaMode");
static_assert(offsetof(CopyTextureForBrowserOptions,
                       srcTransferFunctionParameters) ==
                  offsetof(WGPUCopyTextureForBrowserOptions,
                           srcTransferFunctionParameters),
              "offsetof mismatch for "
              "CopyTextureForBrowserOptions::srcTransferFunctionParameters");
static_assert(
    offsetof(CopyTextureForBrowserOptions, conversionMatrix) ==
        offsetof(WGPUCopyTextureForBrowserOptions, conversionMatrix),
    "offsetof mismatch for CopyTextureForBrowserOptions::conversionMatrix");
static_assert(offsetof(CopyTextureForBrowserOptions,
                       dstTransferFunctionParameters) ==
                  offsetof(WGPUCopyTextureForBrowserOptions,
                           dstTransferFunctionParameters),
              "offsetof mismatch for "
              "CopyTextureForBrowserOptions::dstTransferFunctionParameters");
static_assert(
    offsetof(CopyTextureForBrowserOptions, dstAlphaMode) ==
        offsetof(WGPUCopyTextureForBrowserOptions, dstAlphaMode),
    "offsetof mismatch for CopyTextureForBrowserOptions::dstAlphaMode");
static_assert(
    offsetof(CopyTextureForBrowserOptions, internalUsage) ==
        offsetof(WGPUCopyTextureForBrowserOptions, internalUsage),
    "offsetof mismatch for CopyTextureForBrowserOptions::internalUsage");

// MoonAdapterPropertiesPowerPreference

static_assert(sizeof(MoonAdapterPropertiesPowerPreference) ==
                  sizeof(WGPUMoonAdapterPropertiesPowerPreference),
              "sizeof mismatch for MoonAdapterPropertiesPowerPreference");
static_assert(alignof(MoonAdapterPropertiesPowerPreference) ==
                  alignof(WGPUMoonAdapterPropertiesPowerPreference),
              "alignof mismatch for MoonAdapterPropertiesPowerPreference");

static_assert(offsetof(MoonAdapterPropertiesPowerPreference, powerPreference) ==
                  offsetof(WGPUMoonAdapterPropertiesPowerPreference,
                           powerPreference),
              "offsetof mismatch for "
              "MoonAdapterPropertiesPowerPreference::powerPreference");

// MoonCacheDeviceDescriptor

static_assert(sizeof(MoonCacheDeviceDescriptor) ==
                  sizeof(WGPUMoonCacheDeviceDescriptor),
              "sizeof mismatch for MoonCacheDeviceDescriptor");
static_assert(alignof(MoonCacheDeviceDescriptor) ==
                  alignof(WGPUMoonCacheDeviceDescriptor),
              "alignof mismatch for MoonCacheDeviceDescriptor");

static_assert(offsetof(MoonCacheDeviceDescriptor, isolationKey) ==
                  offsetof(WGPUMoonCacheDeviceDescriptor, isolationKey),
              "offsetof mismatch for MoonCacheDeviceDescriptor::isolationKey");

// MoonEncoderInternalUsageDescriptor

static_assert(sizeof(MoonEncoderInternalUsageDescriptor) ==
                  sizeof(WGPUMoonEncoderInternalUsageDescriptor),
              "sizeof mismatch for MoonEncoderInternalUsageDescriptor");
static_assert(alignof(MoonEncoderInternalUsageDescriptor) ==
                  alignof(WGPUMoonEncoderInternalUsageDescriptor),
              "alignof mismatch for MoonEncoderInternalUsageDescriptor");

static_assert(offsetof(MoonEncoderInternalUsageDescriptor, useInternalUsages) ==
                  offsetof(WGPUMoonEncoderInternalUsageDescriptor,
                           useInternalUsages),
              "offsetof mismatch for "
              "MoonEncoderInternalUsageDescriptor::useInternalUsages");

// MoonInstanceDescriptor

static_assert(sizeof(MoonInstanceDescriptor) ==
                  sizeof(WGPUMoonInstanceDescriptor),
              "sizeof mismatch for MoonInstanceDescriptor");
static_assert(alignof(MoonInstanceDescriptor) ==
                  alignof(WGPUMoonInstanceDescriptor),
              "alignof mismatch for MoonInstanceDescriptor");

static_assert(offsetof(MoonInstanceDescriptor,
                       additionalRuntimeSearchPathsCount) ==
                  offsetof(WGPUMoonInstanceDescriptor,
                           additionalRuntimeSearchPathsCount),
              "offsetof mismatch for "
              "MoonInstanceDescriptor::additionalRuntimeSearchPathsCount");
static_assert(offsetof(MoonInstanceDescriptor, additionalRuntimeSearchPaths) ==
                  offsetof(WGPUMoonInstanceDescriptor,
                           additionalRuntimeSearchPaths),
              "offsetof mismatch for "
              "MoonInstanceDescriptor::additionalRuntimeSearchPaths");

// MoonTextureInternalUsageDescriptor

static_assert(sizeof(MoonTextureInternalUsageDescriptor) ==
                  sizeof(WGPUMoonTextureInternalUsageDescriptor),
              "sizeof mismatch for MoonTextureInternalUsageDescriptor");
static_assert(alignof(MoonTextureInternalUsageDescriptor) ==
                  alignof(WGPUMoonTextureInternalUsageDescriptor),
              "alignof mismatch for MoonTextureInternalUsageDescriptor");

static_assert(
    offsetof(MoonTextureInternalUsageDescriptor, internalUsage) ==
        offsetof(WGPUMoonTextureInternalUsageDescriptor, internalUsage),
    "offsetof mismatch for MoonTextureInternalUsageDescriptor::internalUsage");

// MoonTogglesDeviceDescriptor

static_assert(sizeof(MoonTogglesDeviceDescriptor) ==
                  sizeof(WGPUMoonTogglesDeviceDescriptor),
              "sizeof mismatch for MoonTogglesDeviceDescriptor");
static_assert(alignof(MoonTogglesDeviceDescriptor) ==
                  alignof(WGPUMoonTogglesDeviceDescriptor),
              "alignof mismatch for MoonTogglesDeviceDescriptor");

static_assert(offsetof(MoonTogglesDeviceDescriptor, forceEnabledTogglesCount) ==
                  offsetof(WGPUMoonTogglesDeviceDescriptor,
                           forceEnabledTogglesCount),
              "offsetof mismatch for "
              "MoonTogglesDeviceDescriptor::forceEnabledTogglesCount");
static_assert(
    offsetof(MoonTogglesDeviceDescriptor, forceEnabledToggles) ==
        offsetof(WGPUMoonTogglesDeviceDescriptor, forceEnabledToggles),
    "offsetof mismatch for MoonTogglesDeviceDescriptor::forceEnabledToggles");
static_assert(offsetof(MoonTogglesDeviceDescriptor,
                       forceDisabledTogglesCount) ==
                  offsetof(WGPUMoonTogglesDeviceDescriptor,
                           forceDisabledTogglesCount),
              "offsetof mismatch for "
              "MoonTogglesDeviceDescriptor::forceDisabledTogglesCount");
static_assert(
    offsetof(MoonTogglesDeviceDescriptor, forceDisabledToggles) ==
        offsetof(WGPUMoonTogglesDeviceDescriptor, forceDisabledToggles),
    "offsetof mismatch for MoonTogglesDeviceDescriptor::forceDisabledToggles");

// Extent3D

static_assert(sizeof(Extent3D) == sizeof(WGPUExtent3D),
              "sizeof mismatch for Extent3D");
static_assert(alignof(Extent3D) == alignof(WGPUExtent3D),
              "alignof mismatch for Extent3D");

static_assert(offsetof(Extent3D, width) == offsetof(WGPUExtent3D, width),
              "offsetof mismatch for Extent3D::width");
static_assert(offsetof(Extent3D, height) == offsetof(WGPUExtent3D, height),
              "offsetof mismatch for Extent3D::height");
static_assert(offsetof(Extent3D, depthOrArrayLayers) ==
                  offsetof(WGPUExtent3D, depthOrArrayLayers),
              "offsetof mismatch for Extent3D::depthOrArrayLayers");

// ExternalTextureBindingEntry

static_assert(sizeof(ExternalTextureBindingEntry) ==
                  sizeof(WGPUExternalTextureBindingEntry),
              "sizeof mismatch for ExternalTextureBindingEntry");
static_assert(alignof(ExternalTextureBindingEntry) ==
                  alignof(WGPUExternalTextureBindingEntry),
              "alignof mismatch for ExternalTextureBindingEntry");

static_assert(
    offsetof(ExternalTextureBindingEntry, externalTexture) ==
        offsetof(WGPUExternalTextureBindingEntry, externalTexture),
    "offsetof mismatch for ExternalTextureBindingEntry::externalTexture");

// ExternalTextureBindingLayout

static_assert(sizeof(ExternalTextureBindingLayout) ==
                  sizeof(WGPUExternalTextureBindingLayout),
              "sizeof mismatch for ExternalTextureBindingLayout");
static_assert(alignof(ExternalTextureBindingLayout) ==
                  alignof(WGPUExternalTextureBindingLayout),
              "alignof mismatch for ExternalTextureBindingLayout");

// ExternalTextureDescriptor

static_assert(sizeof(ExternalTextureDescriptor) ==
                  sizeof(WGPUExternalTextureDescriptor),
              "sizeof mismatch for ExternalTextureDescriptor");
static_assert(alignof(ExternalTextureDescriptor) ==
                  alignof(WGPUExternalTextureDescriptor),
              "alignof mismatch for ExternalTextureDescriptor");

static_assert(offsetof(ExternalTextureDescriptor, nextInChain) ==
                  offsetof(WGPUExternalTextureDescriptor, nextInChain),
              "offsetof mismatch for ExternalTextureDescriptor::nextInChain");
static_assert(offsetof(ExternalTextureDescriptor, label) ==
                  offsetof(WGPUExternalTextureDescriptor, label),
              "offsetof mismatch for ExternalTextureDescriptor::label");
static_assert(offsetof(ExternalTextureDescriptor, plane0) ==
                  offsetof(WGPUExternalTextureDescriptor, plane0),
              "offsetof mismatch for ExternalTextureDescriptor::plane0");
static_assert(offsetof(ExternalTextureDescriptor, plane1) ==
                  offsetof(WGPUExternalTextureDescriptor, plane1),
              "offsetof mismatch for ExternalTextureDescriptor::plane1");
static_assert(offsetof(ExternalTextureDescriptor, doYuvToRgbConversionOnly) ==
                  offsetof(WGPUExternalTextureDescriptor,
                           doYuvToRgbConversionOnly),
              "offsetof mismatch for "
              "ExternalTextureDescriptor::doYuvToRgbConversionOnly");
static_assert(offsetof(ExternalTextureDescriptor, yuvToRgbConversionMatrix) ==
                  offsetof(WGPUExternalTextureDescriptor,
                           yuvToRgbConversionMatrix),
              "offsetof mismatch for "
              "ExternalTextureDescriptor::yuvToRgbConversionMatrix");
static_assert(offsetof(ExternalTextureDescriptor,
                       srcTransferFunctionParameters) ==
                  offsetof(WGPUExternalTextureDescriptor,
                           srcTransferFunctionParameters),
              "offsetof mismatch for "
              "ExternalTextureDescriptor::srcTransferFunctionParameters");
static_assert(offsetof(ExternalTextureDescriptor,
                       dstTransferFunctionParameters) ==
                  offsetof(WGPUExternalTextureDescriptor,
                           dstTransferFunctionParameters),
              "offsetof mismatch for "
              "ExternalTextureDescriptor::dstTransferFunctionParameters");
static_assert(
    offsetof(ExternalTextureDescriptor, gamutConversionMatrix) ==
        offsetof(WGPUExternalTextureDescriptor, gamutConversionMatrix),
    "offsetof mismatch for ExternalTextureDescriptor::gamutConversionMatrix");

// InstanceDescriptor

static_assert(sizeof(InstanceDescriptor) == sizeof(WGPUInstanceDescriptor),
              "sizeof mismatch for InstanceDescriptor");
static_assert(alignof(InstanceDescriptor) == alignof(WGPUInstanceDescriptor),
              "alignof mismatch for InstanceDescriptor");

static_assert(offsetof(InstanceDescriptor, nextInChain) ==
                  offsetof(WGPUInstanceDescriptor, nextInChain),
              "offsetof mismatch for InstanceDescriptor::nextInChain");

// Limits

static_assert(sizeof(Limits) == sizeof(WGPULimits),
              "sizeof mismatch for Limits");
static_assert(alignof(Limits) == alignof(WGPULimits),
              "alignof mismatch for Limits");

static_assert(offsetof(Limits, maxTextureDimension1D) ==
                  offsetof(WGPULimits, maxTextureDimension1D),
              "offsetof mismatch for Limits::maxTextureDimension1D");
static_assert(offsetof(Limits, maxTextureDimension2D) ==
                  offsetof(WGPULimits, maxTextureDimension2D),
              "offsetof mismatch for Limits::maxTextureDimension2D");
static_assert(offsetof(Limits, maxTextureDimension3D) ==
                  offsetof(WGPULimits, maxTextureDimension3D),
              "offsetof mismatch for Limits::maxTextureDimension3D");
static_assert(offsetof(Limits, maxTextureArrayLayers) ==
                  offsetof(WGPULimits, maxTextureArrayLayers),
              "offsetof mismatch for Limits::maxTextureArrayLayers");
static_assert(offsetof(Limits, maxBindGroups) ==
                  offsetof(WGPULimits, maxBindGroups),
              "offsetof mismatch for Limits::maxBindGroups");
static_assert(offsetof(Limits, maxBindingsPerBindGroup) ==
                  offsetof(WGPULimits, maxBindingsPerBindGroup),
              "offsetof mismatch for Limits::maxBindingsPerBindGroup");
static_assert(
    offsetof(Limits, maxDynamicUniformBuffersPerPipelineLayout) ==
        offsetof(WGPULimits, maxDynamicUniformBuffersPerPipelineLayout),
    "offsetof mismatch for Limits::maxDynamicUniformBuffersPerPipelineLayout");
static_assert(
    offsetof(Limits, maxDynamicStorageBuffersPerPipelineLayout) ==
        offsetof(WGPULimits, maxDynamicStorageBuffersPerPipelineLayout),
    "offsetof mismatch for Limits::maxDynamicStorageBuffersPerPipelineLayout");
static_assert(offsetof(Limits, maxSampledTexturesPerShaderStage) ==
                  offsetof(WGPULimits, maxSampledTexturesPerShaderStage),
              "offsetof mismatch for Limits::maxSampledTexturesPerShaderStage");
static_assert(offsetof(Limits, maxSamplersPerShaderStage) ==
                  offsetof(WGPULimits, maxSamplersPerShaderStage),
              "offsetof mismatch for Limits::maxSamplersPerShaderStage");
static_assert(offsetof(Limits, maxStorageBuffersPerShaderStage) ==
                  offsetof(WGPULimits, maxStorageBuffersPerShaderStage),
              "offsetof mismatch for Limits::maxStorageBuffersPerShaderStage");
static_assert(offsetof(Limits, maxStorageTexturesPerShaderStage) ==
                  offsetof(WGPULimits, maxStorageTexturesPerShaderStage),
              "offsetof mismatch for Limits::maxStorageTexturesPerShaderStage");
static_assert(offsetof(Limits, maxUniformBuffersPerShaderStage) ==
                  offsetof(WGPULimits, maxUniformBuffersPerShaderStage),
              "offsetof mismatch for Limits::maxUniformBuffersPerShaderStage");
static_assert(offsetof(Limits, maxUniformBufferBindingSize) ==
                  offsetof(WGPULimits, maxUniformBufferBindingSize),
              "offsetof mismatch for Limits::maxUniformBufferBindingSize");
static_assert(offsetof(Limits, maxStorageBufferBindingSize) ==
                  offsetof(WGPULimits, maxStorageBufferBindingSize),
              "offsetof mismatch for Limits::maxStorageBufferBindingSize");
static_assert(offsetof(Limits, minUniformBufferOffsetAlignment) ==
                  offsetof(WGPULimits, minUniformBufferOffsetAlignment),
              "offsetof mismatch for Limits::minUniformBufferOffsetAlignment");
static_assert(offsetof(Limits, minStorageBufferOffsetAlignment) ==
                  offsetof(WGPULimits, minStorageBufferOffsetAlignment),
              "offsetof mismatch for Limits::minStorageBufferOffsetAlignment");
static_assert(offsetof(Limits, maxVertexBuffers) ==
                  offsetof(WGPULimits, maxVertexBuffers),
              "offsetof mismatch for Limits::maxVertexBuffers");
static_assert(offsetof(Limits, maxBufferSize) ==
                  offsetof(WGPULimits, maxBufferSize),
              "offsetof mismatch for Limits::maxBufferSize");
static_assert(offsetof(Limits, maxVertexAttributes) ==
                  offsetof(WGPULimits, maxVertexAttributes),
              "offsetof mismatch for Limits::maxVertexAttributes");
static_assert(offsetof(Limits, maxVertexBufferArrayStride) ==
                  offsetof(WGPULimits, maxVertexBufferArrayStride),
              "offsetof mismatch for Limits::maxVertexBufferArrayStride");
static_assert(offsetof(Limits, maxInterStageShaderComponents) ==
                  offsetof(WGPULimits, maxInterStageShaderComponents),
              "offsetof mismatch for Limits::maxInterStageShaderComponents");
static_assert(offsetof(Limits, maxInterStageShaderVariables) ==
                  offsetof(WGPULimits, maxInterStageShaderVariables),
              "offsetof mismatch for Limits::maxInterStageShaderVariables");
static_assert(offsetof(Limits, maxColorAttachments) ==
                  offsetof(WGPULimits, maxColorAttachments),
              "offsetof mismatch for Limits::maxColorAttachments");
static_assert(offsetof(Limits, maxComputeWorkgroupStorageSize) ==
                  offsetof(WGPULimits, maxComputeWorkgroupStorageSize),
              "offsetof mismatch for Limits::maxComputeWorkgroupStorageSize");
static_assert(
    offsetof(Limits, maxComputeInvocationsPerWorkgroup) ==
        offsetof(WGPULimits, maxComputeInvocationsPerWorkgroup),
    "offsetof mismatch for Limits::maxComputeInvocationsPerWorkgroup");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeX) ==
                  offsetof(WGPULimits, maxComputeWorkgroupSizeX),
              "offsetof mismatch for Limits::maxComputeWorkgroupSizeX");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeY) ==
                  offsetof(WGPULimits, maxComputeWorkgroupSizeY),
              "offsetof mismatch for Limits::maxComputeWorkgroupSizeY");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeZ) ==
                  offsetof(WGPULimits, maxComputeWorkgroupSizeZ),
              "offsetof mismatch for Limits::maxComputeWorkgroupSizeZ");
static_assert(offsetof(Limits, maxComputeWorkgroupsPerDimension) ==
                  offsetof(WGPULimits, maxComputeWorkgroupsPerDimension),
              "offsetof mismatch for Limits::maxComputeWorkgroupsPerDimension");

// MultisampleState

static_assert(sizeof(MultisampleState) == sizeof(WGPUMultisampleState),
              "sizeof mismatch for MultisampleState");
static_assert(alignof(MultisampleState) == alignof(WGPUMultisampleState),
              "alignof mismatch for MultisampleState");

static_assert(offsetof(MultisampleState, nextInChain) ==
                  offsetof(WGPUMultisampleState, nextInChain),
              "offsetof mismatch for MultisampleState::nextInChain");
static_assert(offsetof(MultisampleState, count) ==
                  offsetof(WGPUMultisampleState, count),
              "offsetof mismatch for MultisampleState::count");
static_assert(offsetof(MultisampleState, mask) ==
                  offsetof(WGPUMultisampleState, mask),
              "offsetof mismatch for MultisampleState::mask");
static_assert(offsetof(MultisampleState, alphaToCoverageEnabled) ==
                  offsetof(WGPUMultisampleState, alphaToCoverageEnabled),
              "offsetof mismatch for MultisampleState::alphaToCoverageEnabled");

// Origin3D

static_assert(sizeof(Origin3D) == sizeof(WGPUOrigin3D),
              "sizeof mismatch for Origin3D");
static_assert(alignof(Origin3D) == alignof(WGPUOrigin3D),
              "alignof mismatch for Origin3D");

static_assert(offsetof(Origin3D, x) == offsetof(WGPUOrigin3D, x),
              "offsetof mismatch for Origin3D::x");
static_assert(offsetof(Origin3D, y) == offsetof(WGPUOrigin3D, y),
              "offsetof mismatch for Origin3D::y");
static_assert(offsetof(Origin3D, z) == offsetof(WGPUOrigin3D, z),
              "offsetof mismatch for Origin3D::z");

// PipelineLayoutDescriptor

static_assert(sizeof(PipelineLayoutDescriptor) ==
                  sizeof(WGPUPipelineLayoutDescriptor),
              "sizeof mismatch for PipelineLayoutDescriptor");
static_assert(alignof(PipelineLayoutDescriptor) ==
                  alignof(WGPUPipelineLayoutDescriptor),
              "alignof mismatch for PipelineLayoutDescriptor");

static_assert(offsetof(PipelineLayoutDescriptor, nextInChain) ==
                  offsetof(WGPUPipelineLayoutDescriptor, nextInChain),
              "offsetof mismatch for PipelineLayoutDescriptor::nextInChain");
static_assert(offsetof(PipelineLayoutDescriptor, label) ==
                  offsetof(WGPUPipelineLayoutDescriptor, label),
              "offsetof mismatch for PipelineLayoutDescriptor::label");
static_assert(
    offsetof(PipelineLayoutDescriptor, bindGroupLayoutCount) ==
        offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayoutCount),
    "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayoutCount");
static_assert(
    offsetof(PipelineLayoutDescriptor, bindGroupLayouts) ==
        offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayouts),
    "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayouts");

// PrimitiveDepthClipControl

static_assert(sizeof(PrimitiveDepthClipControl) ==
                  sizeof(WGPUPrimitiveDepthClipControl),
              "sizeof mismatch for PrimitiveDepthClipControl");
static_assert(alignof(PrimitiveDepthClipControl) ==
                  alignof(WGPUPrimitiveDepthClipControl),
              "alignof mismatch for PrimitiveDepthClipControl");

static_assert(
    offsetof(PrimitiveDepthClipControl, unclippedDepth) ==
        offsetof(WGPUPrimitiveDepthClipControl, unclippedDepth),
    "offsetof mismatch for PrimitiveDepthClipControl::unclippedDepth");

// PrimitiveState

static_assert(sizeof(PrimitiveState) == sizeof(WGPUPrimitiveState),
              "sizeof mismatch for PrimitiveState");
static_assert(alignof(PrimitiveState) == alignof(WGPUPrimitiveState),
              "alignof mismatch for PrimitiveState");

static_assert(offsetof(PrimitiveState, nextInChain) ==
                  offsetof(WGPUPrimitiveState, nextInChain),
              "offsetof mismatch for PrimitiveState::nextInChain");
static_assert(offsetof(PrimitiveState, topology) ==
                  offsetof(WGPUPrimitiveState, topology),
              "offsetof mismatch for PrimitiveState::topology");
static_assert(offsetof(PrimitiveState, stripIndexFormat) ==
                  offsetof(WGPUPrimitiveState, stripIndexFormat),
              "offsetof mismatch for PrimitiveState::stripIndexFormat");
static_assert(offsetof(PrimitiveState, frontFace) ==
                  offsetof(WGPUPrimitiveState, frontFace),
              "offsetof mismatch for PrimitiveState::frontFace");
static_assert(offsetof(PrimitiveState, cullMode) ==
                  offsetof(WGPUPrimitiveState, cullMode),
              "offsetof mismatch for PrimitiveState::cullMode");

// QuerySetDescriptor

static_assert(sizeof(QuerySetDescriptor) == sizeof(WGPUQuerySetDescriptor),
              "sizeof mismatch for QuerySetDescriptor");
static_assert(alignof(QuerySetDescriptor) == alignof(WGPUQuerySetDescriptor),
              "alignof mismatch for QuerySetDescriptor");

static_assert(offsetof(QuerySetDescriptor, nextInChain) ==
                  offsetof(WGPUQuerySetDescriptor, nextInChain),
              "offsetof mismatch for QuerySetDescriptor::nextInChain");
static_assert(offsetof(QuerySetDescriptor, label) ==
                  offsetof(WGPUQuerySetDescriptor, label),
              "offsetof mismatch for QuerySetDescriptor::label");
static_assert(offsetof(QuerySetDescriptor, type) ==
                  offsetof(WGPUQuerySetDescriptor, type),
              "offsetof mismatch for QuerySetDescriptor::type");
static_assert(offsetof(QuerySetDescriptor, count) ==
                  offsetof(WGPUQuerySetDescriptor, count),
              "offsetof mismatch for QuerySetDescriptor::count");
static_assert(offsetof(QuerySetDescriptor, pipelineStatistics) ==
                  offsetof(WGPUQuerySetDescriptor, pipelineStatistics),
              "offsetof mismatch for QuerySetDescriptor::pipelineStatistics");
static_assert(
    offsetof(QuerySetDescriptor, pipelineStatisticsCount) ==
        offsetof(WGPUQuerySetDescriptor, pipelineStatisticsCount),
    "offsetof mismatch for QuerySetDescriptor::pipelineStatisticsCount");

// QueueDescriptor

static_assert(sizeof(QueueDescriptor) == sizeof(WGPUQueueDescriptor),
              "sizeof mismatch for QueueDescriptor");
static_assert(alignof(QueueDescriptor) == alignof(WGPUQueueDescriptor),
              "alignof mismatch for QueueDescriptor");

static_assert(offsetof(QueueDescriptor, nextInChain) ==
                  offsetof(WGPUQueueDescriptor, nextInChain),
              "offsetof mismatch for QueueDescriptor::nextInChain");
static_assert(offsetof(QueueDescriptor, label) ==
                  offsetof(WGPUQueueDescriptor, label),
              "offsetof mismatch for QueueDescriptor::label");

// RenderBundleDescriptor

static_assert(sizeof(RenderBundleDescriptor) ==
                  sizeof(WGPURenderBundleDescriptor),
              "sizeof mismatch for RenderBundleDescriptor");
static_assert(alignof(RenderBundleDescriptor) ==
                  alignof(WGPURenderBundleDescriptor),
              "alignof mismatch for RenderBundleDescriptor");

static_assert(offsetof(RenderBundleDescriptor, nextInChain) ==
                  offsetof(WGPURenderBundleDescriptor, nextInChain),
              "offsetof mismatch for RenderBundleDescriptor::nextInChain");
static_assert(offsetof(RenderBundleDescriptor, label) ==
                  offsetof(WGPURenderBundleDescriptor, label),
              "offsetof mismatch for RenderBundleDescriptor::label");

// RenderBundleEncoderDescriptor

static_assert(sizeof(RenderBundleEncoderDescriptor) ==
                  sizeof(WGPURenderBundleEncoderDescriptor),
              "sizeof mismatch for RenderBundleEncoderDescriptor");
static_assert(alignof(RenderBundleEncoderDescriptor) ==
                  alignof(WGPURenderBundleEncoderDescriptor),
              "alignof mismatch for RenderBundleEncoderDescriptor");

static_assert(
    offsetof(RenderBundleEncoderDescriptor, nextInChain) ==
        offsetof(WGPURenderBundleEncoderDescriptor, nextInChain),
    "offsetof mismatch for RenderBundleEncoderDescriptor::nextInChain");
static_assert(offsetof(RenderBundleEncoderDescriptor, label) ==
                  offsetof(WGPURenderBundleEncoderDescriptor, label),
              "offsetof mismatch for RenderBundleEncoderDescriptor::label");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, colorFormatsCount) ==
        offsetof(WGPURenderBundleEncoderDescriptor, colorFormatsCount),
    "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormatsCount");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, colorFormats) ==
        offsetof(WGPURenderBundleEncoderDescriptor, colorFormats),
    "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormats");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, depthStencilFormat) ==
        offsetof(WGPURenderBundleEncoderDescriptor, depthStencilFormat),
    "offsetof mismatch for RenderBundleEncoderDescriptor::depthStencilFormat");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, sampleCount) ==
        offsetof(WGPURenderBundleEncoderDescriptor, sampleCount),
    "offsetof mismatch for RenderBundleEncoderDescriptor::sampleCount");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, depthReadOnly) ==
        offsetof(WGPURenderBundleEncoderDescriptor, depthReadOnly),
    "offsetof mismatch for RenderBundleEncoderDescriptor::depthReadOnly");
static_assert(
    offsetof(RenderBundleEncoderDescriptor, stencilReadOnly) ==
        offsetof(WGPURenderBundleEncoderDescriptor, stencilReadOnly),
    "offsetof mismatch for RenderBundleEncoderDescriptor::stencilReadOnly");

// RenderPassDepthStencilAttachment

static_assert(sizeof(RenderPassDepthStencilAttachment) ==
                  sizeof(WGPURenderPassDepthStencilAttachment),
              "sizeof mismatch for RenderPassDepthStencilAttachment");
static_assert(alignof(RenderPassDepthStencilAttachment) ==
                  alignof(WGPURenderPassDepthStencilAttachment),
              "alignof mismatch for RenderPassDepthStencilAttachment");

static_assert(offsetof(RenderPassDepthStencilAttachment, view) ==
                  offsetof(WGPURenderPassDepthStencilAttachment, view),
              "offsetof mismatch for RenderPassDepthStencilAttachment::view");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, depthLoadOp) ==
        offsetof(WGPURenderPassDepthStencilAttachment, depthLoadOp),
    "offsetof mismatch for RenderPassDepthStencilAttachment::depthLoadOp");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, depthStoreOp) ==
        offsetof(WGPURenderPassDepthStencilAttachment, depthStoreOp),
    "offsetof mismatch for RenderPassDepthStencilAttachment::depthStoreOp");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, clearDepth) ==
        offsetof(WGPURenderPassDepthStencilAttachment, clearDepth),
    "offsetof mismatch for RenderPassDepthStencilAttachment::clearDepth");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, depthClearValue) ==
        offsetof(WGPURenderPassDepthStencilAttachment, depthClearValue),
    "offsetof mismatch for RenderPassDepthStencilAttachment::depthClearValue");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, depthReadOnly) ==
        offsetof(WGPURenderPassDepthStencilAttachment, depthReadOnly),
    "offsetof mismatch for RenderPassDepthStencilAttachment::depthReadOnly");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, stencilLoadOp) ==
        offsetof(WGPURenderPassDepthStencilAttachment, stencilLoadOp),
    "offsetof mismatch for RenderPassDepthStencilAttachment::stencilLoadOp");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, stencilStoreOp) ==
        offsetof(WGPURenderPassDepthStencilAttachment, stencilStoreOp),
    "offsetof mismatch for RenderPassDepthStencilAttachment::stencilStoreOp");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, clearStencil) ==
        offsetof(WGPURenderPassDepthStencilAttachment, clearStencil),
    "offsetof mismatch for RenderPassDepthStencilAttachment::clearStencil");
static_assert(offsetof(RenderPassDepthStencilAttachment, stencilClearValue) ==
                  offsetof(WGPURenderPassDepthStencilAttachment,
                           stencilClearValue),
              "offsetof mismatch for "
              "RenderPassDepthStencilAttachment::stencilClearValue");
static_assert(
    offsetof(RenderPassDepthStencilAttachment, stencilReadOnly) ==
        offsetof(WGPURenderPassDepthStencilAttachment, stencilReadOnly),
    "offsetof mismatch for RenderPassDepthStencilAttachment::stencilReadOnly");

// RenderPassDescriptorMaxDrawCount

static_assert(sizeof(RenderPassDescriptorMaxDrawCount) ==
                  sizeof(WGPURenderPassDescriptorMaxDrawCount),
              "sizeof mismatch for RenderPassDescriptorMaxDrawCount");
static_assert(alignof(RenderPassDescriptorMaxDrawCount) ==
                  alignof(WGPURenderPassDescriptorMaxDrawCount),
              "alignof mismatch for RenderPassDescriptorMaxDrawCount");

static_assert(
    offsetof(RenderPassDescriptorMaxDrawCount, maxDrawCount) ==
        offsetof(WGPURenderPassDescriptorMaxDrawCount, maxDrawCount),
    "offsetof mismatch for RenderPassDescriptorMaxDrawCount::maxDrawCount");

// RenderPassTimestampWrite

static_assert(sizeof(RenderPassTimestampWrite) ==
                  sizeof(WGPURenderPassTimestampWrite),
              "sizeof mismatch for RenderPassTimestampWrite");
static_assert(alignof(RenderPassTimestampWrite) ==
                  alignof(WGPURenderPassTimestampWrite),
              "alignof mismatch for RenderPassTimestampWrite");

static_assert(offsetof(RenderPassTimestampWrite, querySet) ==
                  offsetof(WGPURenderPassTimestampWrite, querySet),
              "offsetof mismatch for RenderPassTimestampWrite::querySet");
static_assert(offsetof(RenderPassTimestampWrite, queryIndex) ==
                  offsetof(WGPURenderPassTimestampWrite, queryIndex),
              "offsetof mismatch for RenderPassTimestampWrite::queryIndex");
static_assert(offsetof(RenderPassTimestampWrite, location) ==
                  offsetof(WGPURenderPassTimestampWrite, location),
              "offsetof mismatch for RenderPassTimestampWrite::location");

// RequestAdapterOptions

static_assert(sizeof(RequestAdapterOptions) ==
                  sizeof(WGPURequestAdapterOptions),
              "sizeof mismatch for RequestAdapterOptions");
static_assert(alignof(RequestAdapterOptions) ==
                  alignof(WGPURequestAdapterOptions),
              "alignof mismatch for RequestAdapterOptions");

static_assert(offsetof(RequestAdapterOptions, nextInChain) ==
                  offsetof(WGPURequestAdapterOptions, nextInChain),
              "offsetof mismatch for RequestAdapterOptions::nextInChain");
static_assert(offsetof(RequestAdapterOptions, compatibleSurface) ==
                  offsetof(WGPURequestAdapterOptions, compatibleSurface),
              "offsetof mismatch for RequestAdapterOptions::compatibleSurface");
static_assert(offsetof(RequestAdapterOptions, powerPreference) ==
                  offsetof(WGPURequestAdapterOptions, powerPreference),
              "offsetof mismatch for RequestAdapterOptions::powerPreference");
static_assert(
    offsetof(RequestAdapterOptions, forceFallbackAdapter) ==
        offsetof(WGPURequestAdapterOptions, forceFallbackAdapter),
    "offsetof mismatch for RequestAdapterOptions::forceFallbackAdapter");

// SamplerBindingLayout

static_assert(sizeof(SamplerBindingLayout) == sizeof(WGPUSamplerBindingLayout),
              "sizeof mismatch for SamplerBindingLayout");
static_assert(alignof(SamplerBindingLayout) ==
                  alignof(WGPUSamplerBindingLayout),
              "alignof mismatch for SamplerBindingLayout");

static_assert(offsetof(SamplerBindingLayout, nextInChain) ==
                  offsetof(WGPUSamplerBindingLayout, nextInChain),
              "offsetof mismatch for SamplerBindingLayout::nextInChain");
static_assert(offsetof(SamplerBindingLayout, type) ==
                  offsetof(WGPUSamplerBindingLayout, type),
              "offsetof mismatch for SamplerBindingLayout::type");

// SamplerDescriptor

static_assert(sizeof(SamplerDescriptor) == sizeof(WGPUSamplerDescriptor),
              "sizeof mismatch for SamplerDescriptor");
static_assert(alignof(SamplerDescriptor) == alignof(WGPUSamplerDescriptor),
              "alignof mismatch for SamplerDescriptor");

static_assert(offsetof(SamplerDescriptor, nextInChain) ==
                  offsetof(WGPUSamplerDescriptor, nextInChain),
              "offsetof mismatch for SamplerDescriptor::nextInChain");
static_assert(offsetof(SamplerDescriptor, label) ==
                  offsetof(WGPUSamplerDescriptor, label),
              "offsetof mismatch for SamplerDescriptor::label");
static_assert(offsetof(SamplerDescriptor, addressModeU) ==
                  offsetof(WGPUSamplerDescriptor, addressModeU),
              "offsetof mismatch for SamplerDescriptor::addressModeU");
static_assert(offsetof(SamplerDescriptor, addressModeV) ==
                  offsetof(WGPUSamplerDescriptor, addressModeV),
              "offsetof mismatch for SamplerDescriptor::addressModeV");
static_assert(offsetof(SamplerDescriptor, addressModeW) ==
                  offsetof(WGPUSamplerDescriptor, addressModeW),
              "offsetof mismatch for SamplerDescriptor::addressModeW");
static_assert(offsetof(SamplerDescriptor, magFilter) ==
                  offsetof(WGPUSamplerDescriptor, magFilter),
              "offsetof mismatch for SamplerDescriptor::magFilter");
static_assert(offsetof(SamplerDescriptor, minFilter) ==
                  offsetof(WGPUSamplerDescriptor, minFilter),
              "offsetof mismatch for SamplerDescriptor::minFilter");
static_assert(offsetof(SamplerDescriptor, mipmapFilter) ==
                  offsetof(WGPUSamplerDescriptor, mipmapFilter),
              "offsetof mismatch for SamplerDescriptor::mipmapFilter");
static_assert(offsetof(SamplerDescriptor, lodMinClamp) ==
                  offsetof(WGPUSamplerDescriptor, lodMinClamp),
              "offsetof mismatch for SamplerDescriptor::lodMinClamp");
static_assert(offsetof(SamplerDescriptor, lodMaxClamp) ==
                  offsetof(WGPUSamplerDescriptor, lodMaxClamp),
              "offsetof mismatch for SamplerDescriptor::lodMaxClamp");
static_assert(offsetof(SamplerDescriptor, compare) ==
                  offsetof(WGPUSamplerDescriptor, compare),
              "offsetof mismatch for SamplerDescriptor::compare");
static_assert(offsetof(SamplerDescriptor, maxAnisotropy) ==
                  offsetof(WGPUSamplerDescriptor, maxAnisotropy),
              "offsetof mismatch for SamplerDescriptor::maxAnisotropy");

// ShaderModuleDescriptor

static_assert(sizeof(ShaderModuleDescriptor) ==
                  sizeof(WGPUShaderModuleDescriptor),
              "sizeof mismatch for ShaderModuleDescriptor");
static_assert(alignof(ShaderModuleDescriptor) ==
                  alignof(WGPUShaderModuleDescriptor),
              "alignof mismatch for ShaderModuleDescriptor");

static_assert(offsetof(ShaderModuleDescriptor, nextInChain) ==
                  offsetof(WGPUShaderModuleDescriptor, nextInChain),
              "offsetof mismatch for ShaderModuleDescriptor::nextInChain");
static_assert(offsetof(ShaderModuleDescriptor, label) ==
                  offsetof(WGPUShaderModuleDescriptor, label),
              "offsetof mismatch for ShaderModuleDescriptor::label");

// ShaderModuleSPIRVDescriptor

static_assert(sizeof(ShaderModuleSPIRVDescriptor) ==
                  sizeof(WGPUShaderModuleSPIRVDescriptor),
              "sizeof mismatch for ShaderModuleSPIRVDescriptor");
static_assert(alignof(ShaderModuleSPIRVDescriptor) ==
                  alignof(WGPUShaderModuleSPIRVDescriptor),
              "alignof mismatch for ShaderModuleSPIRVDescriptor");

static_assert(offsetof(ShaderModuleSPIRVDescriptor, codeSize) ==
                  offsetof(WGPUShaderModuleSPIRVDescriptor, codeSize),
              "offsetof mismatch for ShaderModuleSPIRVDescriptor::codeSize");
static_assert(offsetof(ShaderModuleSPIRVDescriptor, code) ==
                  offsetof(WGPUShaderModuleSPIRVDescriptor, code),
              "offsetof mismatch for ShaderModuleSPIRVDescriptor::code");

// ShaderModuleWGSLDescriptor

static_assert(sizeof(ShaderModuleWGSLDescriptor) ==
                  sizeof(WGPUShaderModuleWGSLDescriptor),
              "sizeof mismatch for ShaderModuleWGSLDescriptor");
static_assert(alignof(ShaderModuleWGSLDescriptor) ==
                  alignof(WGPUShaderModuleWGSLDescriptor),
              "alignof mismatch for ShaderModuleWGSLDescriptor");

static_assert(offsetof(ShaderModuleWGSLDescriptor, source) ==
                  offsetof(WGPUShaderModuleWGSLDescriptor, source),
              "offsetof mismatch for ShaderModuleWGSLDescriptor::source");

// StencilFaceState

static_assert(sizeof(StencilFaceState) == sizeof(WGPUStencilFaceState),
              "sizeof mismatch for StencilFaceState");
static_assert(alignof(StencilFaceState) == alignof(WGPUStencilFaceState),
              "alignof mismatch for StencilFaceState");

static_assert(offsetof(StencilFaceState, compare) ==
                  offsetof(WGPUStencilFaceState, compare),
              "offsetof mismatch for StencilFaceState::compare");
static_assert(offsetof(StencilFaceState, failOp) ==
                  offsetof(WGPUStencilFaceState, failOp),
              "offsetof mismatch for StencilFaceState::failOp");
static_assert(offsetof(StencilFaceState, depthFailOp) ==
                  offsetof(WGPUStencilFaceState, depthFailOp),
              "offsetof mismatch for StencilFaceState::depthFailOp");
static_assert(offsetof(StencilFaceState, passOp) ==
                  offsetof(WGPUStencilFaceState, passOp),
              "offsetof mismatch for StencilFaceState::passOp");

// StorageTextureBindingLayout

static_assert(sizeof(StorageTextureBindingLayout) ==
                  sizeof(WGPUStorageTextureBindingLayout),
              "sizeof mismatch for StorageTextureBindingLayout");
static_assert(alignof(StorageTextureBindingLayout) ==
                  alignof(WGPUStorageTextureBindingLayout),
              "alignof mismatch for StorageTextureBindingLayout");

static_assert(offsetof(StorageTextureBindingLayout, nextInChain) ==
                  offsetof(WGPUStorageTextureBindingLayout, nextInChain),
              "offsetof mismatch for StorageTextureBindingLayout::nextInChain");
static_assert(offsetof(StorageTextureBindingLayout, access) ==
                  offsetof(WGPUStorageTextureBindingLayout, access),
              "offsetof mismatch for StorageTextureBindingLayout::access");
static_assert(offsetof(StorageTextureBindingLayout, format) ==
                  offsetof(WGPUStorageTextureBindingLayout, format),
              "offsetof mismatch for StorageTextureBindingLayout::format");
static_assert(
    offsetof(StorageTextureBindingLayout, viewDimension) ==
        offsetof(WGPUStorageTextureBindingLayout, viewDimension),
    "offsetof mismatch for StorageTextureBindingLayout::viewDimension");

// SurfaceDescriptor

static_assert(sizeof(SurfaceDescriptor) == sizeof(WGPUSurfaceDescriptor),
              "sizeof mismatch for SurfaceDescriptor");
static_assert(alignof(SurfaceDescriptor) == alignof(WGPUSurfaceDescriptor),
              "alignof mismatch for SurfaceDescriptor");

static_assert(offsetof(SurfaceDescriptor, nextInChain) ==
                  offsetof(WGPUSurfaceDescriptor, nextInChain),
              "offsetof mismatch for SurfaceDescriptor::nextInChain");
static_assert(offsetof(SurfaceDescriptor, label) ==
                  offsetof(WGPUSurfaceDescriptor, label),
              "offsetof mismatch for SurfaceDescriptor::label");

// SurfaceDescriptorFromAndroidNativeWindow

static_assert(sizeof(SurfaceDescriptorFromAndroidNativeWindow) ==
                  sizeof(WGPUSurfaceDescriptorFromAndroidNativeWindow),
              "sizeof mismatch for SurfaceDescriptorFromAndroidNativeWindow");
static_assert(alignof(SurfaceDescriptorFromAndroidNativeWindow) ==
                  alignof(WGPUSurfaceDescriptorFromAndroidNativeWindow),
              "alignof mismatch for SurfaceDescriptorFromAndroidNativeWindow");

static_assert(
    offsetof(SurfaceDescriptorFromAndroidNativeWindow, window) ==
        offsetof(WGPUSurfaceDescriptorFromAndroidNativeWindow, window),
    "offsetof mismatch for SurfaceDescriptorFromAndroidNativeWindow::window");

// SurfaceDescriptorFromCanvasHTMLSelector

static_assert(sizeof(SurfaceDescriptorFromCanvasHTMLSelector) ==
                  sizeof(WGPUSurfaceDescriptorFromCanvasHTMLSelector),
              "sizeof mismatch for SurfaceDescriptorFromCanvasHTMLSelector");
static_assert(alignof(SurfaceDescriptorFromCanvasHTMLSelector) ==
                  alignof(WGPUSurfaceDescriptorFromCanvasHTMLSelector),
              "alignof mismatch for SurfaceDescriptorFromCanvasHTMLSelector");

static_assert(
    offsetof(SurfaceDescriptorFromCanvasHTMLSelector, selector) ==
        offsetof(WGPUSurfaceDescriptorFromCanvasHTMLSelector, selector),
    "offsetof mismatch for SurfaceDescriptorFromCanvasHTMLSelector::selector");

// SurfaceDescriptorFromMetalLayer

static_assert(sizeof(SurfaceDescriptorFromMetalLayer) ==
                  sizeof(WGPUSurfaceDescriptorFromMetalLayer),
              "sizeof mismatch for SurfaceDescriptorFromMetalLayer");
static_assert(alignof(SurfaceDescriptorFromMetalLayer) ==
                  alignof(WGPUSurfaceDescriptorFromMetalLayer),
              "alignof mismatch for SurfaceDescriptorFromMetalLayer");

static_assert(offsetof(SurfaceDescriptorFromMetalLayer, layer) ==
                  offsetof(WGPUSurfaceDescriptorFromMetalLayer, layer),
              "offsetof mismatch for SurfaceDescriptorFromMetalLayer::layer");

// SurfaceDescriptorFromWaylandSurface

static_assert(sizeof(SurfaceDescriptorFromWaylandSurface) ==
                  sizeof(WGPUSurfaceDescriptorFromWaylandSurface),
              "sizeof mismatch for SurfaceDescriptorFromWaylandSurface");
static_assert(alignof(SurfaceDescriptorFromWaylandSurface) ==
                  alignof(WGPUSurfaceDescriptorFromWaylandSurface),
              "alignof mismatch for SurfaceDescriptorFromWaylandSurface");

static_assert(
    offsetof(SurfaceDescriptorFromWaylandSurface, display) ==
        offsetof(WGPUSurfaceDescriptorFromWaylandSurface, display),
    "offsetof mismatch for SurfaceDescriptorFromWaylandSurface::display");
static_assert(
    offsetof(SurfaceDescriptorFromWaylandSurface, surface) ==
        offsetof(WGPUSurfaceDescriptorFromWaylandSurface, surface),
    "offsetof mismatch for SurfaceDescriptorFromWaylandSurface::surface");

// SurfaceDescriptorFromWindowsCoreWindow

static_assert(sizeof(SurfaceDescriptorFromWindowsCoreWindow) ==
                  sizeof(WGPUSurfaceDescriptorFromWindowsCoreWindow),
              "sizeof mismatch for SurfaceDescriptorFromWindowsCoreWindow");
static_assert(alignof(SurfaceDescriptorFromWindowsCoreWindow) ==
                  alignof(WGPUSurfaceDescriptorFromWindowsCoreWindow),
              "alignof mismatch for SurfaceDescriptorFromWindowsCoreWindow");

static_assert(
    offsetof(SurfaceDescriptorFromWindowsCoreWindow, coreWindow) ==
        offsetof(WGPUSurfaceDescriptorFromWindowsCoreWindow, coreWindow),
    "offsetof mismatch for SurfaceDescriptorFromWindowsCoreWindow::coreWindow");

// SurfaceDescriptorFromWindowsHWND

static_assert(sizeof(SurfaceDescriptorFromWindowsHWND) ==
                  sizeof(WGPUSurfaceDescriptorFromWindowsHWND),
              "sizeof mismatch for SurfaceDescriptorFromWindowsHWND");
static_assert(alignof(SurfaceDescriptorFromWindowsHWND) ==
                  alignof(WGPUSurfaceDescriptorFromWindowsHWND),
              "alignof mismatch for SurfaceDescriptorFromWindowsHWND");

static_assert(
    offsetof(SurfaceDescriptorFromWindowsHWND, hinstance) ==
        offsetof(WGPUSurfaceDescriptorFromWindowsHWND, hinstance),
    "offsetof mismatch for SurfaceDescriptorFromWindowsHWND::hinstance");
static_assert(offsetof(SurfaceDescriptorFromWindowsHWND, hwnd) ==
                  offsetof(WGPUSurfaceDescriptorFromWindowsHWND, hwnd),
              "offsetof mismatch for SurfaceDescriptorFromWindowsHWND::hwnd");

// SurfaceDescriptorFromWindowsSwapChainPanel

static_assert(sizeof(SurfaceDescriptorFromWindowsSwapChainPanel) ==
                  sizeof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel),
              "sizeof mismatch for SurfaceDescriptorFromWindowsSwapChainPanel");
static_assert(
    alignof(SurfaceDescriptorFromWindowsSwapChainPanel) ==
        alignof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel),
    "alignof mismatch for SurfaceDescriptorFromWindowsSwapChainPanel");

static_assert(offsetof(SurfaceDescriptorFromWindowsSwapChainPanel,
                       swapChainPanel) ==
                  offsetof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel,
                           swapChainPanel),
              "offsetof mismatch for "
              "SurfaceDescriptorFromWindowsSwapChainPanel::swapChainPanel");

// SurfaceDescriptorFromXlibWindow

static_assert(sizeof(SurfaceDescriptorFromXlibWindow) ==
                  sizeof(WGPUSurfaceDescriptorFromXlibWindow),
              "sizeof mismatch for SurfaceDescriptorFromXlibWindow");
static_assert(alignof(SurfaceDescriptorFromXlibWindow) ==
                  alignof(WGPUSurfaceDescriptorFromXlibWindow),
              "alignof mismatch for SurfaceDescriptorFromXlibWindow");

static_assert(offsetof(SurfaceDescriptorFromXlibWindow, display) ==
                  offsetof(WGPUSurfaceDescriptorFromXlibWindow, display),
              "offsetof mismatch for SurfaceDescriptorFromXlibWindow::display");
static_assert(offsetof(SurfaceDescriptorFromXlibWindow, window) ==
                  offsetof(WGPUSurfaceDescriptorFromXlibWindow, window),
              "offsetof mismatch for SurfaceDescriptorFromXlibWindow::window");

// SwapChainDescriptor

static_assert(sizeof(SwapChainDescriptor) == sizeof(WGPUSwapChainDescriptor),
              "sizeof mismatch for SwapChainDescriptor");
static_assert(alignof(SwapChainDescriptor) == alignof(WGPUSwapChainDescriptor),
              "alignof mismatch for SwapChainDescriptor");

static_assert(offsetof(SwapChainDescriptor, nextInChain) ==
                  offsetof(WGPUSwapChainDescriptor, nextInChain),
              "offsetof mismatch for SwapChainDescriptor::nextInChain");
static_assert(offsetof(SwapChainDescriptor, label) ==
                  offsetof(WGPUSwapChainDescriptor, label),
              "offsetof mismatch for SwapChainDescriptor::label");
static_assert(offsetof(SwapChainDescriptor, usage) ==
                  offsetof(WGPUSwapChainDescriptor, usage),
              "offsetof mismatch for SwapChainDescriptor::usage");
static_assert(offsetof(SwapChainDescriptor, format) ==
                  offsetof(WGPUSwapChainDescriptor, format),
              "offsetof mismatch for SwapChainDescriptor::format");
static_assert(offsetof(SwapChainDescriptor, width) ==
                  offsetof(WGPUSwapChainDescriptor, width),
              "offsetof mismatch for SwapChainDescriptor::width");
static_assert(offsetof(SwapChainDescriptor, height) ==
                  offsetof(WGPUSwapChainDescriptor, height),
              "offsetof mismatch for SwapChainDescriptor::height");
static_assert(offsetof(SwapChainDescriptor, presentMode) ==
                  offsetof(WGPUSwapChainDescriptor, presentMode),
              "offsetof mismatch for SwapChainDescriptor::presentMode");
static_assert(offsetof(SwapChainDescriptor, implementation) ==
                  offsetof(WGPUSwapChainDescriptor, implementation),
              "offsetof mismatch for SwapChainDescriptor::implementation");

// TextureBindingLayout

static_assert(sizeof(TextureBindingLayout) == sizeof(WGPUTextureBindingLayout),
              "sizeof mismatch for TextureBindingLayout");
static_assert(alignof(TextureBindingLayout) ==
                  alignof(WGPUTextureBindingLayout),
              "alignof mismatch for TextureBindingLayout");

static_assert(offsetof(TextureBindingLayout, nextInChain) ==
                  offsetof(WGPUTextureBindingLayout, nextInChain),
              "offsetof mismatch for TextureBindingLayout::nextInChain");
static_assert(offsetof(TextureBindingLayout, sampleType) ==
                  offsetof(WGPUTextureBindingLayout, sampleType),
              "offsetof mismatch for TextureBindingLayout::sampleType");
static_assert(offsetof(TextureBindingLayout, viewDimension) ==
                  offsetof(WGPUTextureBindingLayout, viewDimension),
              "offsetof mismatch for TextureBindingLayout::viewDimension");
static_assert(offsetof(TextureBindingLayout, multisampled) ==
                  offsetof(WGPUTextureBindingLayout, multisampled),
              "offsetof mismatch for TextureBindingLayout::multisampled");

// TextureDataLayout

static_assert(sizeof(TextureDataLayout) == sizeof(WGPUTextureDataLayout),
              "sizeof mismatch for TextureDataLayout");
static_assert(alignof(TextureDataLayout) == alignof(WGPUTextureDataLayout),
              "alignof mismatch for TextureDataLayout");

static_assert(offsetof(TextureDataLayout, nextInChain) ==
                  offsetof(WGPUTextureDataLayout, nextInChain),
              "offsetof mismatch for TextureDataLayout::nextInChain");
static_assert(offsetof(TextureDataLayout, offset) ==
                  offsetof(WGPUTextureDataLayout, offset),
              "offsetof mismatch for TextureDataLayout::offset");
static_assert(offsetof(TextureDataLayout, bytesPerRow) ==
                  offsetof(WGPUTextureDataLayout, bytesPerRow),
              "offsetof mismatch for TextureDataLayout::bytesPerRow");
static_assert(offsetof(TextureDataLayout, rowsPerImage) ==
                  offsetof(WGPUTextureDataLayout, rowsPerImage),
              "offsetof mismatch for TextureDataLayout::rowsPerImage");

// TextureViewDescriptor

static_assert(sizeof(TextureViewDescriptor) ==
                  sizeof(WGPUTextureViewDescriptor),
              "sizeof mismatch for TextureViewDescriptor");
static_assert(alignof(TextureViewDescriptor) ==
                  alignof(WGPUTextureViewDescriptor),
              "alignof mismatch for TextureViewDescriptor");

static_assert(offsetof(TextureViewDescriptor, nextInChain) ==
                  offsetof(WGPUTextureViewDescriptor, nextInChain),
              "offsetof mismatch for TextureViewDescriptor::nextInChain");
static_assert(offsetof(TextureViewDescriptor, label) ==
                  offsetof(WGPUTextureViewDescriptor, label),
              "offsetof mismatch for TextureViewDescriptor::label");
static_assert(offsetof(TextureViewDescriptor, format) ==
                  offsetof(WGPUTextureViewDescriptor, format),
              "offsetof mismatch for TextureViewDescriptor::format");
static_assert(offsetof(TextureViewDescriptor, dimension) ==
                  offsetof(WGPUTextureViewDescriptor, dimension),
              "offsetof mismatch for TextureViewDescriptor::dimension");
static_assert(offsetof(TextureViewDescriptor, baseMipLevel) ==
                  offsetof(WGPUTextureViewDescriptor, baseMipLevel),
              "offsetof mismatch for TextureViewDescriptor::baseMipLevel");
static_assert(offsetof(TextureViewDescriptor, mipLevelCount) ==
                  offsetof(WGPUTextureViewDescriptor, mipLevelCount),
              "offsetof mismatch for TextureViewDescriptor::mipLevelCount");
static_assert(offsetof(TextureViewDescriptor, baseArrayLayer) ==
                  offsetof(WGPUTextureViewDescriptor, baseArrayLayer),
              "offsetof mismatch for TextureViewDescriptor::baseArrayLayer");
static_assert(offsetof(TextureViewDescriptor, arrayLayerCount) ==
                  offsetof(WGPUTextureViewDescriptor, arrayLayerCount),
              "offsetof mismatch for TextureViewDescriptor::arrayLayerCount");
static_assert(offsetof(TextureViewDescriptor, aspect) ==
                  offsetof(WGPUTextureViewDescriptor, aspect),
              "offsetof mismatch for TextureViewDescriptor::aspect");

// VertexAttribute

static_assert(sizeof(VertexAttribute) == sizeof(WGPUVertexAttribute),
              "sizeof mismatch for VertexAttribute");
static_assert(alignof(VertexAttribute) == alignof(WGPUVertexAttribute),
              "alignof mismatch for VertexAttribute");

static_assert(offsetof(VertexAttribute, format) ==
                  offsetof(WGPUVertexAttribute, format),
              "offsetof mismatch for VertexAttribute::format");
static_assert(offsetof(VertexAttribute, offset) ==
                  offsetof(WGPUVertexAttribute, offset),
              "offsetof mismatch for VertexAttribute::offset");
static_assert(offsetof(VertexAttribute, shaderLocation) ==
                  offsetof(WGPUVertexAttribute, shaderLocation),
              "offsetof mismatch for VertexAttribute::shaderLocation");

// BindGroupDescriptor

static_assert(sizeof(BindGroupDescriptor) == sizeof(WGPUBindGroupDescriptor),
              "sizeof mismatch for BindGroupDescriptor");
static_assert(alignof(BindGroupDescriptor) == alignof(WGPUBindGroupDescriptor),
              "alignof mismatch for BindGroupDescriptor");

static_assert(offsetof(BindGroupDescriptor, nextInChain) ==
                  offsetof(WGPUBindGroupDescriptor, nextInChain),
              "offsetof mismatch for BindGroupDescriptor::nextInChain");
static_assert(offsetof(BindGroupDescriptor, label) ==
                  offsetof(WGPUBindGroupDescriptor, label),
              "offsetof mismatch for BindGroupDescriptor::label");
static_assert(offsetof(BindGroupDescriptor, layout) ==
                  offsetof(WGPUBindGroupDescriptor, layout),
              "offsetof mismatch for BindGroupDescriptor::layout");
static_assert(offsetof(BindGroupDescriptor, entryCount) ==
                  offsetof(WGPUBindGroupDescriptor, entryCount),
              "offsetof mismatch for BindGroupDescriptor::entryCount");
static_assert(offsetof(BindGroupDescriptor, entries) ==
                  offsetof(WGPUBindGroupDescriptor, entries),
              "offsetof mismatch for BindGroupDescriptor::entries");

// BindGroupLayoutEntry

static_assert(sizeof(BindGroupLayoutEntry) == sizeof(WGPUBindGroupLayoutEntry),
              "sizeof mismatch for BindGroupLayoutEntry");
static_assert(alignof(BindGroupLayoutEntry) ==
                  alignof(WGPUBindGroupLayoutEntry),
              "alignof mismatch for BindGroupLayoutEntry");

static_assert(offsetof(BindGroupLayoutEntry, nextInChain) ==
                  offsetof(WGPUBindGroupLayoutEntry, nextInChain),
              "offsetof mismatch for BindGroupLayoutEntry::nextInChain");
static_assert(offsetof(BindGroupLayoutEntry, binding) ==
                  offsetof(WGPUBindGroupLayoutEntry, binding),
              "offsetof mismatch for BindGroupLayoutEntry::binding");
static_assert(offsetof(BindGroupLayoutEntry, visibility) ==
                  offsetof(WGPUBindGroupLayoutEntry, visibility),
              "offsetof mismatch for BindGroupLayoutEntry::visibility");
static_assert(offsetof(BindGroupLayoutEntry, buffer) ==
                  offsetof(WGPUBindGroupLayoutEntry, buffer),
              "offsetof mismatch for BindGroupLayoutEntry::buffer");
static_assert(offsetof(BindGroupLayoutEntry, sampler) ==
                  offsetof(WGPUBindGroupLayoutEntry, sampler),
              "offsetof mismatch for BindGroupLayoutEntry::sampler");
static_assert(offsetof(BindGroupLayoutEntry, texture) ==
                  offsetof(WGPUBindGroupLayoutEntry, texture),
              "offsetof mismatch for BindGroupLayoutEntry::texture");
static_assert(offsetof(BindGroupLayoutEntry, storageTexture) ==
                  offsetof(WGPUBindGroupLayoutEntry, storageTexture),
              "offsetof mismatch for BindGroupLayoutEntry::storageTexture");

// BlendState

static_assert(sizeof(BlendState) == sizeof(WGPUBlendState),
              "sizeof mismatch for BlendState");
static_assert(alignof(BlendState) == alignof(WGPUBlendState),
              "alignof mismatch for BlendState");

static_assert(offsetof(BlendState, color) == offsetof(WGPUBlendState, color),
              "offsetof mismatch for BlendState::color");
static_assert(offsetof(BlendState, alpha) == offsetof(WGPUBlendState, alpha),
              "offsetof mismatch for BlendState::alpha");

// CompilationInfo

static_assert(sizeof(CompilationInfo) == sizeof(WGPUCompilationInfo),
              "sizeof mismatch for CompilationInfo");
static_assert(alignof(CompilationInfo) == alignof(WGPUCompilationInfo),
              "alignof mismatch for CompilationInfo");

static_assert(offsetof(CompilationInfo, nextInChain) ==
                  offsetof(WGPUCompilationInfo, nextInChain),
              "offsetof mismatch for CompilationInfo::nextInChain");
static_assert(offsetof(CompilationInfo, messageCount) ==
                  offsetof(WGPUCompilationInfo, messageCount),
              "offsetof mismatch for CompilationInfo::messageCount");
static_assert(offsetof(CompilationInfo, messages) ==
                  offsetof(WGPUCompilationInfo, messages),
              "offsetof mismatch for CompilationInfo::messages");

// ComputePassDescriptor

static_assert(sizeof(ComputePassDescriptor) ==
                  sizeof(WGPUComputePassDescriptor),
              "sizeof mismatch for ComputePassDescriptor");
static_assert(alignof(ComputePassDescriptor) ==
                  alignof(WGPUComputePassDescriptor),
              "alignof mismatch for ComputePassDescriptor");

static_assert(offsetof(ComputePassDescriptor, nextInChain) ==
                  offsetof(WGPUComputePassDescriptor, nextInChain),
              "offsetof mismatch for ComputePassDescriptor::nextInChain");
static_assert(offsetof(ComputePassDescriptor, label) ==
                  offsetof(WGPUComputePassDescriptor, label),
              "offsetof mismatch for ComputePassDescriptor::label");
static_assert(
    offsetof(ComputePassDescriptor, timestampWriteCount) ==
        offsetof(WGPUComputePassDescriptor, timestampWriteCount),
    "offsetof mismatch for ComputePassDescriptor::timestampWriteCount");
static_assert(offsetof(ComputePassDescriptor, timestampWrites) ==
                  offsetof(WGPUComputePassDescriptor, timestampWrites),
              "offsetof mismatch for ComputePassDescriptor::timestampWrites");

// DepthStencilState

static_assert(sizeof(DepthStencilState) == sizeof(WGPUDepthStencilState),
              "sizeof mismatch for DepthStencilState");
static_assert(alignof(DepthStencilState) == alignof(WGPUDepthStencilState),
              "alignof mismatch for DepthStencilState");

static_assert(offsetof(DepthStencilState, nextInChain) ==
                  offsetof(WGPUDepthStencilState, nextInChain),
              "offsetof mismatch for DepthStencilState::nextInChain");
static_assert(offsetof(DepthStencilState, format) ==
                  offsetof(WGPUDepthStencilState, format),
              "offsetof mismatch for DepthStencilState::format");
static_assert(offsetof(DepthStencilState, depthWriteEnabled) ==
                  offsetof(WGPUDepthStencilState, depthWriteEnabled),
              "offsetof mismatch for DepthStencilState::depthWriteEnabled");
static_assert(offsetof(DepthStencilState, depthCompare) ==
                  offsetof(WGPUDepthStencilState, depthCompare),
              "offsetof mismatch for DepthStencilState::depthCompare");
static_assert(offsetof(DepthStencilState, stencilFront) ==
                  offsetof(WGPUDepthStencilState, stencilFront),
              "offsetof mismatch for DepthStencilState::stencilFront");
static_assert(offsetof(DepthStencilState, stencilBack) ==
                  offsetof(WGPUDepthStencilState, stencilBack),
              "offsetof mismatch for DepthStencilState::stencilBack");
static_assert(offsetof(DepthStencilState, stencilReadMask) ==
                  offsetof(WGPUDepthStencilState, stencilReadMask),
              "offsetof mismatch for DepthStencilState::stencilReadMask");
static_assert(offsetof(DepthStencilState, stencilWriteMask) ==
                  offsetof(WGPUDepthStencilState, stencilWriteMask),
              "offsetof mismatch for DepthStencilState::stencilWriteMask");
static_assert(offsetof(DepthStencilState, depthBias) ==
                  offsetof(WGPUDepthStencilState, depthBias),
              "offsetof mismatch for DepthStencilState::depthBias");
static_assert(offsetof(DepthStencilState, depthBiasSlopeScale) ==
                  offsetof(WGPUDepthStencilState, depthBiasSlopeScale),
              "offsetof mismatch for DepthStencilState::depthBiasSlopeScale");
static_assert(offsetof(DepthStencilState, depthBiasClamp) ==
                  offsetof(WGPUDepthStencilState, depthBiasClamp),
              "offsetof mismatch for DepthStencilState::depthBiasClamp");

// ImageCopyBuffer

static_assert(sizeof(ImageCopyBuffer) == sizeof(WGPUImageCopyBuffer),
              "sizeof mismatch for ImageCopyBuffer");
static_assert(alignof(ImageCopyBuffer) == alignof(WGPUImageCopyBuffer),
              "alignof mismatch for ImageCopyBuffer");

static_assert(offsetof(ImageCopyBuffer, nextInChain) ==
                  offsetof(WGPUImageCopyBuffer, nextInChain),
              "offsetof mismatch for ImageCopyBuffer::nextInChain");
static_assert(offsetof(ImageCopyBuffer, layout) ==
                  offsetof(WGPUImageCopyBuffer, layout),
              "offsetof mismatch for ImageCopyBuffer::layout");
static_assert(offsetof(ImageCopyBuffer, buffer) ==
                  offsetof(WGPUImageCopyBuffer, buffer),
              "offsetof mismatch for ImageCopyBuffer::buffer");

// ImageCopyTexture

static_assert(sizeof(ImageCopyTexture) == sizeof(WGPUImageCopyTexture),
              "sizeof mismatch for ImageCopyTexture");
static_assert(alignof(ImageCopyTexture) == alignof(WGPUImageCopyTexture),
              "alignof mismatch for ImageCopyTexture");

static_assert(offsetof(ImageCopyTexture, nextInChain) ==
                  offsetof(WGPUImageCopyTexture, nextInChain),
              "offsetof mismatch for ImageCopyTexture::nextInChain");
static_assert(offsetof(ImageCopyTexture, texture) ==
                  offsetof(WGPUImageCopyTexture, texture),
              "offsetof mismatch for ImageCopyTexture::texture");
static_assert(offsetof(ImageCopyTexture, mipLevel) ==
                  offsetof(WGPUImageCopyTexture, mipLevel),
              "offsetof mismatch for ImageCopyTexture::mipLevel");
static_assert(offsetof(ImageCopyTexture, origin) ==
                  offsetof(WGPUImageCopyTexture, origin),
              "offsetof mismatch for ImageCopyTexture::origin");
static_assert(offsetof(ImageCopyTexture, aspect) ==
                  offsetof(WGPUImageCopyTexture, aspect),
              "offsetof mismatch for ImageCopyTexture::aspect");

// ProgrammableStageDescriptor

static_assert(sizeof(ProgrammableStageDescriptor) ==
                  sizeof(WGPUProgrammableStageDescriptor),
              "sizeof mismatch for ProgrammableStageDescriptor");
static_assert(alignof(ProgrammableStageDescriptor) ==
                  alignof(WGPUProgrammableStageDescriptor),
              "alignof mismatch for ProgrammableStageDescriptor");

static_assert(offsetof(ProgrammableStageDescriptor, nextInChain) ==
                  offsetof(WGPUProgrammableStageDescriptor, nextInChain),
              "offsetof mismatch for ProgrammableStageDescriptor::nextInChain");
static_assert(offsetof(ProgrammableStageDescriptor, module) ==
                  offsetof(WGPUProgrammableStageDescriptor, module),
              "offsetof mismatch for ProgrammableStageDescriptor::module");
static_assert(offsetof(ProgrammableStageDescriptor, entryPoint) ==
                  offsetof(WGPUProgrammableStageDescriptor, entryPoint),
              "offsetof mismatch for ProgrammableStageDescriptor::entryPoint");
static_assert(
    offsetof(ProgrammableStageDescriptor, constantCount) ==
        offsetof(WGPUProgrammableStageDescriptor, constantCount),
    "offsetof mismatch for ProgrammableStageDescriptor::constantCount");
static_assert(offsetof(ProgrammableStageDescriptor, constants) ==
                  offsetof(WGPUProgrammableStageDescriptor, constants),
              "offsetof mismatch for ProgrammableStageDescriptor::constants");

// RenderPassColorAttachment

static_assert(sizeof(RenderPassColorAttachment) ==
                  sizeof(WGPURenderPassColorAttachment),
              "sizeof mismatch for RenderPassColorAttachment");
static_assert(alignof(RenderPassColorAttachment) ==
                  alignof(WGPURenderPassColorAttachment),
              "alignof mismatch for RenderPassColorAttachment");

static_assert(offsetof(RenderPassColorAttachment, view) ==
                  offsetof(WGPURenderPassColorAttachment, view),
              "offsetof mismatch for RenderPassColorAttachment::view");
static_assert(offsetof(RenderPassColorAttachment, resolveTarget) ==
                  offsetof(WGPURenderPassColorAttachment, resolveTarget),
              "offsetof mismatch for RenderPassColorAttachment::resolveTarget");
static_assert(offsetof(RenderPassColorAttachment, loadOp) ==
                  offsetof(WGPURenderPassColorAttachment, loadOp),
              "offsetof mismatch for RenderPassColorAttachment::loadOp");
static_assert(offsetof(RenderPassColorAttachment, storeOp) ==
                  offsetof(WGPURenderPassColorAttachment, storeOp),
              "offsetof mismatch for RenderPassColorAttachment::storeOp");
static_assert(offsetof(RenderPassColorAttachment, clearColor) ==
                  offsetof(WGPURenderPassColorAttachment, clearColor),
              "offsetof mismatch for RenderPassColorAttachment::clearColor");
static_assert(offsetof(RenderPassColorAttachment, clearValue) ==
                  offsetof(WGPURenderPassColorAttachment, clearValue),
              "offsetof mismatch for RenderPassColorAttachment::clearValue");

// RequiredLimits

static_assert(sizeof(RequiredLimits) == sizeof(WGPURequiredLimits),
              "sizeof mismatch for RequiredLimits");
static_assert(alignof(RequiredLimits) == alignof(WGPURequiredLimits),
              "alignof mismatch for RequiredLimits");

static_assert(offsetof(RequiredLimits, nextInChain) ==
                  offsetof(WGPURequiredLimits, nextInChain),
              "offsetof mismatch for RequiredLimits::nextInChain");
static_assert(offsetof(RequiredLimits, limits) ==
                  offsetof(WGPURequiredLimits, limits),
              "offsetof mismatch for RequiredLimits::limits");

// SupportedLimits

static_assert(sizeof(SupportedLimits) == sizeof(WGPUSupportedLimits),
              "sizeof mismatch for SupportedLimits");
static_assert(alignof(SupportedLimits) == alignof(WGPUSupportedLimits),
              "alignof mismatch for SupportedLimits");

static_assert(offsetof(SupportedLimits, nextInChain) ==
                  offsetof(WGPUSupportedLimits, nextInChain),
              "offsetof mismatch for SupportedLimits::nextInChain");
static_assert(offsetof(SupportedLimits, limits) ==
                  offsetof(WGPUSupportedLimits, limits),
              "offsetof mismatch for SupportedLimits::limits");

// TextureDescriptor

static_assert(sizeof(TextureDescriptor) == sizeof(WGPUTextureDescriptor),
              "sizeof mismatch for TextureDescriptor");
static_assert(alignof(TextureDescriptor) == alignof(WGPUTextureDescriptor),
              "alignof mismatch for TextureDescriptor");

static_assert(offsetof(TextureDescriptor, nextInChain) ==
                  offsetof(WGPUTextureDescriptor, nextInChain),
              "offsetof mismatch for TextureDescriptor::nextInChain");
static_assert(offsetof(TextureDescriptor, label) ==
                  offsetof(WGPUTextureDescriptor, label),
              "offsetof mismatch for TextureDescriptor::label");
static_assert(offsetof(TextureDescriptor, usage) ==
                  offsetof(WGPUTextureDescriptor, usage),
              "offsetof mismatch for TextureDescriptor::usage");
static_assert(offsetof(TextureDescriptor, dimension) ==
                  offsetof(WGPUTextureDescriptor, dimension),
              "offsetof mismatch for TextureDescriptor::dimension");
static_assert(offsetof(TextureDescriptor, size) ==
                  offsetof(WGPUTextureDescriptor, size),
              "offsetof mismatch for TextureDescriptor::size");
static_assert(offsetof(TextureDescriptor, format) ==
                  offsetof(WGPUTextureDescriptor, format),
              "offsetof mismatch for TextureDescriptor::format");
static_assert(offsetof(TextureDescriptor, mipLevelCount) ==
                  offsetof(WGPUTextureDescriptor, mipLevelCount),
              "offsetof mismatch for TextureDescriptor::mipLevelCount");
static_assert(offsetof(TextureDescriptor, sampleCount) ==
                  offsetof(WGPUTextureDescriptor, sampleCount),
              "offsetof mismatch for TextureDescriptor::sampleCount");
static_assert(offsetof(TextureDescriptor, viewFormatCount) ==
                  offsetof(WGPUTextureDescriptor, viewFormatCount),
              "offsetof mismatch for TextureDescriptor::viewFormatCount");
static_assert(offsetof(TextureDescriptor, viewFormats) ==
                  offsetof(WGPUTextureDescriptor, viewFormats),
              "offsetof mismatch for TextureDescriptor::viewFormats");

// VertexBufferLayout

static_assert(sizeof(VertexBufferLayout) == sizeof(WGPUVertexBufferLayout),
              "sizeof mismatch for VertexBufferLayout");
static_assert(alignof(VertexBufferLayout) == alignof(WGPUVertexBufferLayout),
              "alignof mismatch for VertexBufferLayout");

static_assert(offsetof(VertexBufferLayout, arrayStride) ==
                  offsetof(WGPUVertexBufferLayout, arrayStride),
              "offsetof mismatch for VertexBufferLayout::arrayStride");
static_assert(offsetof(VertexBufferLayout, stepMode) ==
                  offsetof(WGPUVertexBufferLayout, stepMode),
              "offsetof mismatch for VertexBufferLayout::stepMode");
static_assert(offsetof(VertexBufferLayout, attributeCount) ==
                  offsetof(WGPUVertexBufferLayout, attributeCount),
              "offsetof mismatch for VertexBufferLayout::attributeCount");
static_assert(offsetof(VertexBufferLayout, attributes) ==
                  offsetof(WGPUVertexBufferLayout, attributes),
              "offsetof mismatch for VertexBufferLayout::attributes");

// BindGroupLayoutDescriptor

static_assert(sizeof(BindGroupLayoutDescriptor) ==
                  sizeof(WGPUBindGroupLayoutDescriptor),
              "sizeof mismatch for BindGroupLayoutDescriptor");
static_assert(alignof(BindGroupLayoutDescriptor) ==
                  alignof(WGPUBindGroupLayoutDescriptor),
              "alignof mismatch for BindGroupLayoutDescriptor");

static_assert(offsetof(BindGroupLayoutDescriptor, nextInChain) ==
                  offsetof(WGPUBindGroupLayoutDescriptor, nextInChain),
              "offsetof mismatch for BindGroupLayoutDescriptor::nextInChain");
static_assert(offsetof(BindGroupLayoutDescriptor, label) ==
                  offsetof(WGPUBindGroupLayoutDescriptor, label),
              "offsetof mismatch for BindGroupLayoutDescriptor::label");
static_assert(offsetof(BindGroupLayoutDescriptor, entryCount) ==
                  offsetof(WGPUBindGroupLayoutDescriptor, entryCount),
              "offsetof mismatch for BindGroupLayoutDescriptor::entryCount");
static_assert(offsetof(BindGroupLayoutDescriptor, entries) ==
                  offsetof(WGPUBindGroupLayoutDescriptor, entries),
              "offsetof mismatch for BindGroupLayoutDescriptor::entries");

// ColorTargetState

static_assert(sizeof(ColorTargetState) == sizeof(WGPUColorTargetState),
              "sizeof mismatch for ColorTargetState");
static_assert(alignof(ColorTargetState) == alignof(WGPUColorTargetState),
              "alignof mismatch for ColorTargetState");

static_assert(offsetof(ColorTargetState, nextInChain) ==
                  offsetof(WGPUColorTargetState, nextInChain),
              "offsetof mismatch for ColorTargetState::nextInChain");
static_assert(offsetof(ColorTargetState, format) ==
                  offsetof(WGPUColorTargetState, format),
              "offsetof mismatch for ColorTargetState::format");
static_assert(offsetof(ColorTargetState, blend) ==
                  offsetof(WGPUColorTargetState, blend),
              "offsetof mismatch for ColorTargetState::blend");
static_assert(offsetof(ColorTargetState, writeMask) ==
                  offsetof(WGPUColorTargetState, writeMask),
              "offsetof mismatch for ColorTargetState::writeMask");

// ComputePipelineDescriptor

static_assert(sizeof(ComputePipelineDescriptor) ==
                  sizeof(WGPUComputePipelineDescriptor),
              "sizeof mismatch for ComputePipelineDescriptor");
static_assert(alignof(ComputePipelineDescriptor) ==
                  alignof(WGPUComputePipelineDescriptor),
              "alignof mismatch for ComputePipelineDescriptor");

static_assert(offsetof(ComputePipelineDescriptor, nextInChain) ==
                  offsetof(WGPUComputePipelineDescriptor, nextInChain),
              "offsetof mismatch for ComputePipelineDescriptor::nextInChain");
static_assert(offsetof(ComputePipelineDescriptor, label) ==
                  offsetof(WGPUComputePipelineDescriptor, label),
              "offsetof mismatch for ComputePipelineDescriptor::label");
static_assert(offsetof(ComputePipelineDescriptor, layout) ==
                  offsetof(WGPUComputePipelineDescriptor, layout),
              "offsetof mismatch for ComputePipelineDescriptor::layout");
static_assert(offsetof(ComputePipelineDescriptor, compute) ==
                  offsetof(WGPUComputePipelineDescriptor, compute),
              "offsetof mismatch for ComputePipelineDescriptor::compute");

// DeviceDescriptor

static_assert(sizeof(DeviceDescriptor) == sizeof(WGPUDeviceDescriptor),
              "sizeof mismatch for DeviceDescriptor");
static_assert(alignof(DeviceDescriptor) == alignof(WGPUDeviceDescriptor),
              "alignof mismatch for DeviceDescriptor");

static_assert(offsetof(DeviceDescriptor, nextInChain) ==
                  offsetof(WGPUDeviceDescriptor, nextInChain),
              "offsetof mismatch for DeviceDescriptor::nextInChain");
static_assert(offsetof(DeviceDescriptor, label) ==
                  offsetof(WGPUDeviceDescriptor, label),
              "offsetof mismatch for DeviceDescriptor::label");
static_assert(offsetof(DeviceDescriptor, requiredFeaturesCount) ==
                  offsetof(WGPUDeviceDescriptor, requiredFeaturesCount),
              "offsetof mismatch for DeviceDescriptor::requiredFeaturesCount");
static_assert(offsetof(DeviceDescriptor, requiredFeatures) ==
                  offsetof(WGPUDeviceDescriptor, requiredFeatures),
              "offsetof mismatch for DeviceDescriptor::requiredFeatures");
static_assert(offsetof(DeviceDescriptor, requiredLimits) ==
                  offsetof(WGPUDeviceDescriptor, requiredLimits),
              "offsetof mismatch for DeviceDescriptor::requiredLimits");
static_assert(offsetof(DeviceDescriptor, defaultQueue) ==
                  offsetof(WGPUDeviceDescriptor, defaultQueue),
              "offsetof mismatch for DeviceDescriptor::defaultQueue");

// RenderPassDescriptor

static_assert(sizeof(RenderPassDescriptor) == sizeof(WGPURenderPassDescriptor),
              "sizeof mismatch for RenderPassDescriptor");
static_assert(alignof(RenderPassDescriptor) ==
                  alignof(WGPURenderPassDescriptor),
              "alignof mismatch for RenderPassDescriptor");

static_assert(offsetof(RenderPassDescriptor, nextInChain) ==
                  offsetof(WGPURenderPassDescriptor, nextInChain),
              "offsetof mismatch for RenderPassDescriptor::nextInChain");
static_assert(offsetof(RenderPassDescriptor, label) ==
                  offsetof(WGPURenderPassDescriptor, label),
              "offsetof mismatch for RenderPassDescriptor::label");
static_assert(
    offsetof(RenderPassDescriptor, colorAttachmentCount) ==
        offsetof(WGPURenderPassDescriptor, colorAttachmentCount),
    "offsetof mismatch for RenderPassDescriptor::colorAttachmentCount");
static_assert(offsetof(RenderPassDescriptor, colorAttachments) ==
                  offsetof(WGPURenderPassDescriptor, colorAttachments),
              "offsetof mismatch for RenderPassDescriptor::colorAttachments");
static_assert(
    offsetof(RenderPassDescriptor, depthStencilAttachment) ==
        offsetof(WGPURenderPassDescriptor, depthStencilAttachment),
    "offsetof mismatch for RenderPassDescriptor::depthStencilAttachment");
static_assert(offsetof(RenderPassDescriptor, occlusionQuerySet) ==
                  offsetof(WGPURenderPassDescriptor, occlusionQuerySet),
              "offsetof mismatch for RenderPassDescriptor::occlusionQuerySet");
static_assert(
    offsetof(RenderPassDescriptor, timestampWriteCount) ==
        offsetof(WGPURenderPassDescriptor, timestampWriteCount),
    "offsetof mismatch for RenderPassDescriptor::timestampWriteCount");
static_assert(offsetof(RenderPassDescriptor, timestampWrites) ==
                  offsetof(WGPURenderPassDescriptor, timestampWrites),
              "offsetof mismatch for RenderPassDescriptor::timestampWrites");

// VertexState

static_assert(sizeof(VertexState) == sizeof(WGPUVertexState),
              "sizeof mismatch for VertexState");
static_assert(alignof(VertexState) == alignof(WGPUVertexState),
              "alignof mismatch for VertexState");

static_assert(offsetof(VertexState, nextInChain) ==
                  offsetof(WGPUVertexState, nextInChain),
              "offsetof mismatch for VertexState::nextInChain");
static_assert(offsetof(VertexState, module) ==
                  offsetof(WGPUVertexState, module),
              "offsetof mismatch for VertexState::module");
static_assert(offsetof(VertexState, entryPoint) ==
                  offsetof(WGPUVertexState, entryPoint),
              "offsetof mismatch for VertexState::entryPoint");
static_assert(offsetof(VertexState, constantCount) ==
                  offsetof(WGPUVertexState, constantCount),
              "offsetof mismatch for VertexState::constantCount");
static_assert(offsetof(VertexState, constants) ==
                  offsetof(WGPUVertexState, constants),
              "offsetof mismatch for VertexState::constants");
static_assert(offsetof(VertexState, bufferCount) ==
                  offsetof(WGPUVertexState, bufferCount),
              "offsetof mismatch for VertexState::bufferCount");
static_assert(offsetof(VertexState, buffers) ==
                  offsetof(WGPUVertexState, buffers),
              "offsetof mismatch for VertexState::buffers");

// FragmentState

static_assert(sizeof(FragmentState) == sizeof(WGPUFragmentState),
              "sizeof mismatch for FragmentState");
static_assert(alignof(FragmentState) == alignof(WGPUFragmentState),
              "alignof mismatch for FragmentState");

static_assert(offsetof(FragmentState, nextInChain) ==
                  offsetof(WGPUFragmentState, nextInChain),
              "offsetof mismatch for FragmentState::nextInChain");
static_assert(offsetof(FragmentState, module) ==
                  offsetof(WGPUFragmentState, module),
              "offsetof mismatch for FragmentState::module");
static_assert(offsetof(FragmentState, entryPoint) ==
                  offsetof(WGPUFragmentState, entryPoint),
              "offsetof mismatch for FragmentState::entryPoint");
static_assert(offsetof(FragmentState, constantCount) ==
                  offsetof(WGPUFragmentState, constantCount),
              "offsetof mismatch for FragmentState::constantCount");
static_assert(offsetof(FragmentState, constants) ==
                  offsetof(WGPUFragmentState, constants),
              "offsetof mismatch for FragmentState::constants");
static_assert(offsetof(FragmentState, targetCount) ==
                  offsetof(WGPUFragmentState, targetCount),
              "offsetof mismatch for FragmentState::targetCount");
static_assert(offsetof(FragmentState, targets) ==
                  offsetof(WGPUFragmentState, targets),
              "offsetof mismatch for FragmentState::targets");

// RenderPipelineDescriptor

static_assert(sizeof(RenderPipelineDescriptor) ==
                  sizeof(WGPURenderPipelineDescriptor),
              "sizeof mismatch for RenderPipelineDescriptor");
static_assert(alignof(RenderPipelineDescriptor) ==
                  alignof(WGPURenderPipelineDescriptor),
              "alignof mismatch for RenderPipelineDescriptor");

static_assert(offsetof(RenderPipelineDescriptor, nextInChain) ==
                  offsetof(WGPURenderPipelineDescriptor, nextInChain),
              "offsetof mismatch for RenderPipelineDescriptor::nextInChain");
static_assert(offsetof(RenderPipelineDescriptor, label) ==
                  offsetof(WGPURenderPipelineDescriptor, label),
              "offsetof mismatch for RenderPipelineDescriptor::label");
static_assert(offsetof(RenderPipelineDescriptor, layout) ==
                  offsetof(WGPURenderPipelineDescriptor, layout),
              "offsetof mismatch for RenderPipelineDescriptor::layout");
static_assert(offsetof(RenderPipelineDescriptor, vertex) ==
                  offsetof(WGPURenderPipelineDescriptor, vertex),
              "offsetof mismatch for RenderPipelineDescriptor::vertex");
static_assert(offsetof(RenderPipelineDescriptor, primitive) ==
                  offsetof(WGPURenderPipelineDescriptor, primitive),
              "offsetof mismatch for RenderPipelineDescriptor::primitive");
static_assert(offsetof(RenderPipelineDescriptor, depthStencil) ==
                  offsetof(WGPURenderPipelineDescriptor, depthStencil),
              "offsetof mismatch for RenderPipelineDescriptor::depthStencil");
static_assert(offsetof(RenderPipelineDescriptor, multisample) ==
                  offsetof(WGPURenderPipelineDescriptor, multisample),
              "offsetof mismatch for RenderPipelineDescriptor::multisample");
static_assert(offsetof(RenderPipelineDescriptor, fragment) ==
                  offsetof(WGPURenderPipelineDescriptor, fragment),
              "offsetof mismatch for RenderPipelineDescriptor::fragment");

// Adapter

static_assert(sizeof(Adapter) == sizeof(WGPUAdapter),
              "sizeof mismatch for Adapter");
static_assert(alignof(Adapter) == alignof(WGPUAdapter),
              "alignof mismatch for Adapter");

auto Adapter::create_device(DeviceDescriptor const *descriptor) const
    -> Device {
  auto result = wgpuAdapterCreateDevice(
      get(), reinterpret_cast<WGPUDeviceDescriptor const *>(descriptor));
  return Device::acquire(result);
}
auto Adapter::enumerate_features(FeatureName *features) const -> size_t {
  auto result = wgpuAdapterEnumerateFeatures(
      get(), reinterpret_cast<WGPUFeatureName *>(features));
  return result;
}
auto Adapter::get_limits(SupportedLimits *limits) const -> bool {
  auto result = wgpuAdapterGetLimits(
      get(), reinterpret_cast<WGPUSupportedLimits *>(limits));
  return result;
}
void Adapter::get_properties(AdapterProperties *properties) const {
  wgpuAdapterGetProperties(
      get(), reinterpret_cast<WGPUAdapterProperties *>(properties));
}
auto Adapter::has_feature(FeatureName feature) const -> bool {
  auto result =
      wgpuAdapterHasFeature(get(), static_cast<WGPUFeatureName>(feature));
  return result;
}
void Adapter::request_device(DeviceDescriptor const *descriptor,
                             RequestDeviceCallback callback,
                             void *userdata) const {
  wgpuAdapterRequestDevice(
      get(), reinterpret_cast<WGPUDeviceDescriptor const *>(descriptor),
      callback, reinterpret_cast<void *>(userdata));
}
void Adapter::wgpu_reference(WGPUAdapter handle) {
  if (handle != nullptr) {
    wgpuAdapterReference(handle);
  }
}
void Adapter::wgpu_release(WGPUAdapter handle) {
  if (handle != nullptr) {
    wgpuAdapterRelease(handle);
  }
}

// BindGroup

static_assert(sizeof(BindGroup) == sizeof(WGPUBindGroup),
              "sizeof mismatch for BindGroup");
static_assert(alignof(BindGroup) == alignof(WGPUBindGroup),
              "alignof mismatch for BindGroup");

void BindGroup::set_label(char const *label) const {
  wgpuBindGroupSetLabel(get(), reinterpret_cast<char const *>(label));
}
void BindGroup::wgpu_reference(WGPUBindGroup handle) {
  if (handle != nullptr) {
    wgpuBindGroupReference(handle);
  }
}
void BindGroup::wgpu_release(WGPUBindGroup handle) {
  if (handle != nullptr) {
    wgpuBindGroupRelease(handle);
  }
}

// BindGroupLayout

static_assert(sizeof(BindGroupLayout) == sizeof(WGPUBindGroupLayout),
              "sizeof mismatch for BindGroupLayout");
static_assert(alignof(BindGroupLayout) == alignof(WGPUBindGroupLayout),
              "alignof mismatch for BindGroupLayout");

void BindGroupLayout::set_label(char const *label) const {
  wgpuBindGroupLayoutSetLabel(get(), reinterpret_cast<char const *>(label));
}
void BindGroupLayout::wgpu_reference(WGPUBindGroupLayout handle) {
  if (handle != nullptr) {
    wgpuBindGroupLayoutReference(handle);
  }
}
void BindGroupLayout::wgpu_release(WGPUBindGroupLayout handle) {
  if (handle != nullptr) {
    wgpuBindGroupLayoutRelease(handle);
  }
}

// Buffer

static_assert(sizeof(Buffer) == sizeof(WGPUBuffer),
              "sizeof mismatch for Buffer");
static_assert(alignof(Buffer) == alignof(WGPUBuffer),
              "alignof mismatch for Buffer");

void Buffer::destroy() const { wgpuBufferDestroy(get()); }
auto Buffer::get_const_mapped_range(size_t offset, size_t size) const
    -> void const * {
  auto result = wgpuBufferGetConstMappedRange(get(), offset, size);
  return result;
}
auto Buffer::get_mapped_range(size_t offset, size_t size) const -> void * {
  auto result = wgpuBufferGetMappedRange(get(), offset, size);
  return result;
}
auto Buffer::get_size() const -> u64 {
  auto result = wgpuBufferGetSize(get());
  return result;
}
auto Buffer::get_usage() const -> BufferUsage {
  auto result = wgpuBufferGetUsage(get());
  return static_cast<BufferUsage>(result);
}
void Buffer::map_async(MapMode mode, size_t offset, size_t size,
                       BufferMapCallback callback, void *userdata) const {
  wgpuBufferMapAsync(get(), static_cast<WGPUMapMode>(mode), offset, size,
                     callback, reinterpret_cast<void *>(userdata));
}
void Buffer::set_label(char const *label) const {
  wgpuBufferSetLabel(get(), reinterpret_cast<char const *>(label));
}
void Buffer::unmap() const { wgpuBufferUnmap(get()); }
void Buffer::wgpu_reference(WGPUBuffer handle) {
  if (handle != nullptr) {
    wgpuBufferReference(handle);
  }
}
void Buffer::wgpu_release(WGPUBuffer handle) {
  if (handle != nullptr) {
    wgpuBufferRelease(handle);
  }
}

// CommandBuffer

static_assert(sizeof(CommandBuffer) == sizeof(WGPUCommandBuffer),
              "sizeof mismatch for CommandBuffer");
static_assert(alignof(CommandBuffer) == alignof(WGPUCommandBuffer),
              "alignof mismatch for CommandBuffer");

void CommandBuffer::set_label(char const *label) const {
  wgpuCommandBufferSetLabel(get(), reinterpret_cast<char const *>(label));
}
void CommandBuffer::wgpu_reference(WGPUCommandBuffer handle) {
  if (handle != nullptr) {
    wgpuCommandBufferReference(handle);
  }
}
void CommandBuffer::wgpu_release(WGPUCommandBuffer handle) {
  if (handle != nullptr) {
    wgpuCommandBufferRelease(handle);
  }
}

// CommandEncoder

static_assert(sizeof(CommandEncoder) == sizeof(WGPUCommandEncoder),
              "sizeof mismatch for CommandEncoder");
static_assert(alignof(CommandEncoder) == alignof(WGPUCommandEncoder),
              "alignof mismatch for CommandEncoder");

auto CommandEncoder::begin_compute_pass(
    ComputePassDescriptor const *descriptor) const -> ComputePassEncoder {
  auto result = wgpuCommandEncoderBeginComputePass(
      get(), reinterpret_cast<WGPUComputePassDescriptor const *>(descriptor));
  return ComputePassEncoder::acquire(result);
}
auto CommandEncoder::begin_render_pass(
    RenderPassDescriptor const *descriptor) const -> RenderPassEncoder {
  auto result = wgpuCommandEncoderBeginRenderPass(
      get(), reinterpret_cast<WGPURenderPassDescriptor const *>(descriptor));
  return RenderPassEncoder::acquire(result);
}
void CommandEncoder::clear_buffer(Buffer const &buffer, u64 offset,
                                  u64 size) const {
  wgpuCommandEncoderClearBuffer(get(), buffer.get(), offset, size);
}
void CommandEncoder::copy_buffer_to_buffer(Buffer const &source,
                                           u64 sourceOffset,
                                           Buffer const &destination,
                                           u64 destinationOffset,
                                           u64 size) const {
  wgpuCommandEncoderCopyBufferToBuffer(get(), source.get(), sourceOffset,
                                       destination.get(), destinationOffset,
                                       size);
}
void CommandEncoder::copy_buffer_to_texture(ImageCopyBuffer const *source,
                                            ImageCopyTexture const *destination,
                                            Extent3D const *copySize) const {
  wgpuCommandEncoderCopyBufferToTexture(
      get(), reinterpret_cast<WGPUImageCopyBuffer const *>(source),
      reinterpret_cast<WGPUImageCopyTexture const *>(destination),
      reinterpret_cast<WGPUExtent3D const *>(copySize));
}
void CommandEncoder::copy_texture_to_buffer(ImageCopyTexture const *source,
                                            ImageCopyBuffer const *destination,
                                            Extent3D const *copySize) const {
  wgpuCommandEncoderCopyTextureToBuffer(
      get(), reinterpret_cast<WGPUImageCopyTexture const *>(source),
      reinterpret_cast<WGPUImageCopyBuffer const *>(destination),
      reinterpret_cast<WGPUExtent3D const *>(copySize));
}
void CommandEncoder::copy_texture_to_texture(
    ImageCopyTexture const *source, ImageCopyTexture const *destination,
    Extent3D const *copySize) const {
  wgpuCommandEncoderCopyTextureToTexture(
      get(), reinterpret_cast<WGPUImageCopyTexture const *>(source),
      reinterpret_cast<WGPUImageCopyTexture const *>(destination),
      reinterpret_cast<WGPUExtent3D const *>(copySize));
}
void CommandEncoder::copy_texture_to_texture_internal(
    ImageCopyTexture const *source, ImageCopyTexture const *destination,
    Extent3D const *copySize) const {
  wgpuCommandEncoderCopyTextureToTextureInternal(
      get(), reinterpret_cast<WGPUImageCopyTexture const *>(source),
      reinterpret_cast<WGPUImageCopyTexture const *>(destination),
      reinterpret_cast<WGPUExtent3D const *>(copySize));
}
auto CommandEncoder::finish(CommandBufferDescriptor const *descriptor) const
    -> CommandBuffer {
  auto result = wgpuCommandEncoderFinish(
      get(), reinterpret_cast<WGPUCommandBufferDescriptor const *>(descriptor));
  return CommandBuffer::acquire(result);
}
void CommandEncoder::inject_validation_error(char const *message) const {
  wgpuCommandEncoderInjectValidationError(
      get(), reinterpret_cast<char const *>(message));
}
void CommandEncoder::insert_debug_marker(char const *markerLabel) const {
  wgpuCommandEncoderInsertDebugMarker(
      get(), reinterpret_cast<char const *>(markerLabel));
}
void CommandEncoder::pop_debug_group() const {
  wgpuCommandEncoderPopDebugGroup(get());
}
void CommandEncoder::push_debug_group(char const *groupLabel) const {
  wgpuCommandEncoderPushDebugGroup(get(),
                                   reinterpret_cast<char const *>(groupLabel));
}
void CommandEncoder::resolve_query_set(QuerySet const &querySet, u32 firstQuery,
                                       u32 queryCount,
                                       Buffer const &destination,
                                       u64 destinationOffset) const {
  wgpuCommandEncoderResolveQuerySet(get(), querySet.get(), firstQuery,
                                    queryCount, destination.get(),
                                    destinationOffset);
}
void CommandEncoder::set_label(char const *label) const {
  wgpuCommandEncoderSetLabel(get(), reinterpret_cast<char const *>(label));
}
void CommandEncoder::write_buffer(Buffer const &buffer, u64 bufferOffset,
                                  uint8_t const *data, u64 size) const {
  wgpuCommandEncoderWriteBuffer(get(), buffer.get(), bufferOffset,
                                reinterpret_cast<uint8_t const *>(data), size);
}
void CommandEncoder::write_timestamp(QuerySet const &querySet,
                                     u32 queryIndex) const {
  wgpuCommandEncoderWriteTimestamp(get(), querySet.get(), queryIndex);
}
void CommandEncoder::wgpu_reference(WGPUCommandEncoder handle) {
  if (handle != nullptr) {
    wgpuCommandEncoderReference(handle);
  }
}
void CommandEncoder::wgpu_release(WGPUCommandEncoder handle) {
  if (handle != nullptr) {
    wgpuCommandEncoderRelease(handle);
  }
}

// ComputePassEncoder

static_assert(sizeof(ComputePassEncoder) == sizeof(WGPUComputePassEncoder),
              "sizeof mismatch for ComputePassEncoder");
static_assert(alignof(ComputePassEncoder) == alignof(WGPUComputePassEncoder),
              "alignof mismatch for ComputePassEncoder");

void ComputePassEncoder::dispatch(u32 workgroupCountX, u32 workgroupCountY,
                                  u32 workgroupCountZ) const {
  wgpuComputePassEncoderDispatch(get(), workgroupCountX, workgroupCountY,
                                 workgroupCountZ);
}
void ComputePassEncoder::dispatch_indirect(Buffer const &indirectBuffer,
                                           u64 indirectOffset) const {
  wgpuComputePassEncoderDispatchIndirect(get(), indirectBuffer.get(),
                                         indirectOffset);
}
void ComputePassEncoder::dispatch_workgroups(u32 workgroupCountX,
                                             u32 workgroupCountY,
                                             u32 workgroupCountZ) const {
  wgpuComputePassEncoderDispatchWorkgroups(get(), workgroupCountX,
                                           workgroupCountY, workgroupCountZ);
}
void ComputePassEncoder::dispatch_workgroups_indirect(
    Buffer const &indirectBuffer, u64 indirectOffset) const {
  wgpuComputePassEncoderDispatchWorkgroupsIndirect(get(), indirectBuffer.get(),
                                                   indirectOffset);
}
void ComputePassEncoder::end() const { wgpuComputePassEncoderEnd(get()); }
void ComputePassEncoder::end_pass() const {
  wgpuComputePassEncoderEndPass(get());
}
void ComputePassEncoder::insert_debug_marker(char const *markerLabel) const {
  wgpuComputePassEncoderInsertDebugMarker(
      get(), reinterpret_cast<char const *>(markerLabel));
}
void ComputePassEncoder::pop_debug_group() const {
  wgpuComputePassEncoderPopDebugGroup(get());
}
void ComputePassEncoder::push_debug_group(char const *groupLabel) const {
  wgpuComputePassEncoderPushDebugGroup(
      get(), reinterpret_cast<char const *>(groupLabel));
}
void ComputePassEncoder::set_bind_group(u32 groupIndex, BindGroup const &group,
                                        u32 dynamicOffsetCount,
                                        u32 const *dynamicOffsets) const {
  wgpuComputePassEncoderSetBindGroup(
      get(), groupIndex, group.get(), dynamicOffsetCount,
      reinterpret_cast<u32 const *>(dynamicOffsets));
}
void ComputePassEncoder::set_label(char const *label) const {
  wgpuComputePassEncoderSetLabel(get(), reinterpret_cast<char const *>(label));
}
void ComputePassEncoder::set_pipeline(ComputePipeline const &pipeline) const {
  wgpuComputePassEncoderSetPipeline(get(), pipeline.get());
}
void ComputePassEncoder::write_timestamp(QuerySet const &querySet,
                                         u32 queryIndex) const {
  wgpuComputePassEncoderWriteTimestamp(get(), querySet.get(), queryIndex);
}
void ComputePassEncoder::wgpu_reference(WGPUComputePassEncoder handle) {
  if (handle != nullptr) {
    wgpuComputePassEncoderReference(handle);
  }
}
void ComputePassEncoder::wgpu_release(WGPUComputePassEncoder handle) {
  if (handle != nullptr) {
    wgpuComputePassEncoderRelease(handle);
  }
}

// ComputePipeline

static_assert(sizeof(ComputePipeline) == sizeof(WGPUComputePipeline),
              "sizeof mismatch for ComputePipeline");
static_assert(alignof(ComputePipeline) == alignof(WGPUComputePipeline),
              "alignof mismatch for ComputePipeline");

auto ComputePipeline::get_bind_group_layout(u32 groupIndex) const
    -> BindGroupLayout {
  auto result = wgpuComputePipelineGetBindGroupLayout(get(), groupIndex);
  return BindGroupLayout::acquire(result);
}
void ComputePipeline::set_label(char const *label) const {
  wgpuComputePipelineSetLabel(get(), reinterpret_cast<char const *>(label));
}
void ComputePipeline::wgpu_reference(WGPUComputePipeline handle) {
  if (handle != nullptr) {
    wgpuComputePipelineReference(handle);
  }
}
void ComputePipeline::wgpu_release(WGPUComputePipeline handle) {
  if (handle != nullptr) {
    wgpuComputePipelineRelease(handle);
  }
}

// Device

static_assert(sizeof(Device) == sizeof(WGPUDevice),
              "sizeof mismatch for Device");
static_assert(alignof(Device) == alignof(WGPUDevice),
              "alignof mismatch for Device");

auto Device::create_bind_group(BindGroupDescriptor const *descriptor) const
    -> BindGroup {
  auto result = wgpuDeviceCreateBindGroup(
      get(), reinterpret_cast<WGPUBindGroupDescriptor const *>(descriptor));
  return BindGroup::acquire(result);
}
auto Device::create_bind_group_layout(
    BindGroupLayoutDescriptor const *descriptor) const -> BindGroupLayout {
  auto result = wgpuDeviceCreateBindGroupLayout(
      get(),
      reinterpret_cast<WGPUBindGroupLayoutDescriptor const *>(descriptor));
  return BindGroupLayout::acquire(result);
}
auto Device::create_buffer(BufferDescriptor const *descriptor) const -> Buffer {
  auto result = wgpuDeviceCreateBuffer(
      get(), reinterpret_cast<WGPUBufferDescriptor const *>(descriptor));
  return Buffer::acquire(result);
}
auto Device::create_command_encoder(
    CommandEncoderDescriptor const *descriptor) const -> CommandEncoder {
  auto result = wgpuDeviceCreateCommandEncoder(
      get(),
      reinterpret_cast<WGPUCommandEncoderDescriptor const *>(descriptor));
  return CommandEncoder::acquire(result);
}
auto Device::create_compute_pipeline(
    ComputePipelineDescriptor const *descriptor) const -> ComputePipeline {
  auto result = wgpuDeviceCreateComputePipeline(
      get(),
      reinterpret_cast<WGPUComputePipelineDescriptor const *>(descriptor));
  return ComputePipeline::acquire(result);
}
void Device::create_compute_pipeline_async(
    ComputePipelineDescriptor const *descriptor,
    CreateComputePipelineAsyncCallback callback, void *userdata) const {
  wgpuDeviceCreateComputePipelineAsync(
      get(),
      reinterpret_cast<WGPUComputePipelineDescriptor const *>(descriptor),
      callback, reinterpret_cast<void *>(userdata));
}
auto Device::create_error_buffer() const -> Buffer {
  auto result = wgpuDeviceCreateErrorBuffer(get());
  return Buffer::acquire(result);
}
auto Device::create_error_external_texture() const -> ExternalTexture {
  auto result = wgpuDeviceCreateErrorExternalTexture(get());
  return ExternalTexture::acquire(result);
}
auto Device::create_error_texture(TextureDescriptor const *descriptor) const
    -> Texture {
  auto result = wgpuDeviceCreateErrorTexture(
      get(), reinterpret_cast<WGPUTextureDescriptor const *>(descriptor));
  return Texture::acquire(result);
}
auto Device::create_external_texture(
    ExternalTextureDescriptor const *externalTextureDescriptor) const
    -> ExternalTexture {
  auto result = wgpuDeviceCreateExternalTexture(
      get(), reinterpret_cast<WGPUExternalTextureDescriptor const *>(
                 externalTextureDescriptor));
  return ExternalTexture::acquire(result);
}
auto Device::create_pipeline_layout(
    PipelineLayoutDescriptor const *descriptor) const -> PipelineLayout {
  auto result = wgpuDeviceCreatePipelineLayout(
      get(),
      reinterpret_cast<WGPUPipelineLayoutDescriptor const *>(descriptor));
  return PipelineLayout::acquire(result);
}
auto Device::create_query_set(QuerySetDescriptor const *descriptor) const
    -> QuerySet {
  auto result = wgpuDeviceCreateQuerySet(
      get(), reinterpret_cast<WGPUQuerySetDescriptor const *>(descriptor));
  return QuerySet::acquire(result);
}
auto Device::create_render_bundle_encoder(
    RenderBundleEncoderDescriptor const *descriptor) const
    -> RenderBundleEncoder {
  auto result = wgpuDeviceCreateRenderBundleEncoder(
      get(),
      reinterpret_cast<WGPURenderBundleEncoderDescriptor const *>(descriptor));
  return RenderBundleEncoder::acquire(result);
}
auto Device::create_render_pipeline(
    RenderPipelineDescriptor const *descriptor) const -> RenderPipeline {
  auto result = wgpuDeviceCreateRenderPipeline(
      get(),
      reinterpret_cast<WGPURenderPipelineDescriptor const *>(descriptor));
  return RenderPipeline::acquire(result);
}
void Device::create_render_pipeline_async(
    RenderPipelineDescriptor const *descriptor,
    CreateRenderPipelineAsyncCallback callback, void *userdata) const {
  wgpuDeviceCreateRenderPipelineAsync(
      get(), reinterpret_cast<WGPURenderPipelineDescriptor const *>(descriptor),
      callback, reinterpret_cast<void *>(userdata));
}
auto Device::create_sampler(SamplerDescriptor const *descriptor) const
    -> Sampler {
  auto result = wgpuDeviceCreateSampler(
      get(), reinterpret_cast<WGPUSamplerDescriptor const *>(descriptor));
  return Sampler::acquire(result);
}
auto Device::create_shader_module(
    ShaderModuleDescriptor const *descriptor) const -> ShaderModule {
  auto result = wgpuDeviceCreateShaderModule(
      get(), reinterpret_cast<WGPUShaderModuleDescriptor const *>(descriptor));
  return ShaderModule::acquire(result);
}
auto Device::create_swap_chain(Surface const &surface,
                               SwapChainDescriptor const *descriptor) const
    -> SwapChain {
  auto result = wgpuDeviceCreateSwapChain(
      get(), surface.get(),
      reinterpret_cast<WGPUSwapChainDescriptor const *>(descriptor));
  return SwapChain::acquire(result);
}
auto Device::create_texture(TextureDescriptor const *descriptor) const
    -> Texture {
  auto result = wgpuDeviceCreateTexture(
      get(), reinterpret_cast<WGPUTextureDescriptor const *>(descriptor));
  return Texture::acquire(result);
}
void Device::destroy() const { wgpuDeviceDestroy(get()); }
auto Device::enumerate_features(FeatureName *features) const -> size_t {
  auto result = wgpuDeviceEnumerateFeatures(
      get(), reinterpret_cast<WGPUFeatureName *>(features));
  return result;
}
void Device::force_loss(DeviceLostReason type, char const *message) const {
  wgpuDeviceForceLoss(get(), static_cast<WGPUDeviceLostReason>(type),
                      reinterpret_cast<char const *>(message));
}
auto Device::get_adapter() const -> Adapter {
  auto result = wgpuDeviceGetAdapter(get());
  return Adapter::acquire(result);
}
auto Device::get_limits(SupportedLimits *limits) const -> bool {
  auto result = wgpuDeviceGetLimits(
      get(), reinterpret_cast<WGPUSupportedLimits *>(limits));
  return result;
}
auto Device::get_queue() const -> Queue {
  auto result = wgpuDeviceGetQueue(get());
  return Queue::acquire(result);
}
auto Device::has_feature(FeatureName feature) const -> bool {
  auto result =
      wgpuDeviceHasFeature(get(), static_cast<WGPUFeatureName>(feature));
  return result;
}
void Device::inject_error(ErrorType type, char const *message) const {
  wgpuDeviceInjectError(get(), static_cast<WGPUErrorType>(type),
                        reinterpret_cast<char const *>(message));
}
auto Device::pop_error_scope(ErrorCallback callback, void *userdata) const
    -> bool {
  auto result = wgpuDevicePopErrorScope(get(), callback,
                                        reinterpret_cast<void *>(userdata));
  return result;
}
void Device::push_error_scope(ErrorFilter filter) const {
  wgpuDevicePushErrorScope(get(), static_cast<WGPUErrorFilter>(filter));
}
void Device::set_device_lost_callback(DeviceLostCallback callback,
                                      void *userdata) const {
  wgpuDeviceSetDeviceLostCallback(get(), callback,
                                  reinterpret_cast<void *>(userdata));
}
void Device::set_label(char const *label) const {
  wgpuDeviceSetLabel(get(), reinterpret_cast<char const *>(label));
}
void Device::set_logging_callback(LoggingCallback callback,
                                  void *userdata) const {
  wgpuDeviceSetLoggingCallback(get(), callback,
                               reinterpret_cast<void *>(userdata));
}
void Device::set_uncaptured_error_callback(ErrorCallback callback,
                                           void *userdata) const {
  wgpuDeviceSetUncapturedErrorCallback(get(), callback,
                                       reinterpret_cast<void *>(userdata));
}
void Device::tick() const { wgpuDeviceTick(get()); }
void Device::wgpu_reference(WGPUDevice handle) {
  if (handle != nullptr) {
    wgpuDeviceReference(handle);
  }
}
void Device::wgpu_release(WGPUDevice handle) {
  if (handle != nullptr) {
    wgpuDeviceRelease(handle);
  }
}

// ExternalTexture

static_assert(sizeof(ExternalTexture) == sizeof(WGPUExternalTexture),
              "sizeof mismatch for ExternalTexture");
static_assert(alignof(ExternalTexture) == alignof(WGPUExternalTexture),
              "alignof mismatch for ExternalTexture");

void ExternalTexture::destroy() const { wgpuExternalTextureDestroy(get()); }
void ExternalTexture::set_label(char const *label) const {
  wgpuExternalTextureSetLabel(get(), reinterpret_cast<char const *>(label));
}
void ExternalTexture::wgpu_reference(WGPUExternalTexture handle) {
  if (handle != nullptr) {
    wgpuExternalTextureReference(handle);
  }
}
void ExternalTexture::wgpu_release(WGPUExternalTexture handle) {
  if (handle != nullptr) {
    wgpuExternalTextureRelease(handle);
  }
}

// Instance

static_assert(sizeof(Instance) == sizeof(WGPUInstance),
              "sizeof mismatch for Instance");
static_assert(alignof(Instance) == alignof(WGPUInstance),
              "alignof mismatch for Instance");

auto Instance::create_surface(SurfaceDescriptor const *descriptor) const
    -> Surface {
  auto result = wgpuInstanceCreateSurface(
      get(), reinterpret_cast<WGPUSurfaceDescriptor const *>(descriptor));
  return Surface::acquire(result);
}
void Instance::request_adapter(RequestAdapterOptions const *options,
                               RequestAdapterCallback callback,
                               void *userdata) const {
  wgpuInstanceRequestAdapter(
      get(), reinterpret_cast<WGPURequestAdapterOptions const *>(options),
      callback, reinterpret_cast<void *>(userdata));
}
void Instance::wgpu_reference(WGPUInstance handle) {
  if (handle != nullptr) {
    wgpuInstanceReference(handle);
  }
}
void Instance::wgpu_release(WGPUInstance handle) {
  if (handle != nullptr) {
    wgpuInstanceRelease(handle);
  }
}

// PipelineLayout

static_assert(sizeof(PipelineLayout) == sizeof(WGPUPipelineLayout),
              "sizeof mismatch for PipelineLayout");
static_assert(alignof(PipelineLayout) == alignof(WGPUPipelineLayout),
              "alignof mismatch for PipelineLayout");

void PipelineLayout::set_label(char const *label) const {
  wgpuPipelineLayoutSetLabel(get(), reinterpret_cast<char const *>(label));
}
void PipelineLayout::wgpu_reference(WGPUPipelineLayout handle) {
  if (handle != nullptr) {
    wgpuPipelineLayoutReference(handle);
  }
}
void PipelineLayout::wgpu_release(WGPUPipelineLayout handle) {
  if (handle != nullptr) {
    wgpuPipelineLayoutRelease(handle);
  }
}

// QuerySet

static_assert(sizeof(QuerySet) == sizeof(WGPUQuerySet),
              "sizeof mismatch for QuerySet");
static_assert(alignof(QuerySet) == alignof(WGPUQuerySet),
              "alignof mismatch for QuerySet");

void QuerySet::destroy() const { wgpuQuerySetDestroy(get()); }
auto QuerySet::get_count() const -> u32 {
  auto result = wgpuQuerySetGetCount(get());
  return result;
}
auto QuerySet::get_type() const -> QueryType {
  auto result = wgpuQuerySetGetType(get());
  return static_cast<QueryType>(result);
}
void QuerySet::set_label(char const *label) const {
  wgpuQuerySetSetLabel(get(), reinterpret_cast<char const *>(label));
}
void QuerySet::wgpu_reference(WGPUQuerySet handle) {
  if (handle != nullptr) {
    wgpuQuerySetReference(handle);
  }
}
void QuerySet::wgpu_release(WGPUQuerySet handle) {
  if (handle != nullptr) {
    wgpuQuerySetRelease(handle);
  }
}

// Queue

static_assert(sizeof(Queue) == sizeof(WGPUQueue), "sizeof mismatch for Queue");
static_assert(alignof(Queue) == alignof(WGPUQueue),
              "alignof mismatch for Queue");

void Queue::copy_texture_for_browser(
    ImageCopyTexture const *source, ImageCopyTexture const *destination,
    Extent3D const *copySize,
    CopyTextureForBrowserOptions const *options) const {
  wgpuQueueCopyTextureForBrowser(
      get(), reinterpret_cast<WGPUImageCopyTexture const *>(source),
      reinterpret_cast<WGPUImageCopyTexture const *>(destination),
      reinterpret_cast<WGPUExtent3D const *>(copySize),
      reinterpret_cast<WGPUCopyTextureForBrowserOptions const *>(options));
}
void Queue::on_submitted_work_done(u64 signalValue,
                                   QueueWorkDoneCallback callback,
                                   void *userdata) const {
  wgpuQueueOnSubmittedWorkDone(get(), signalValue, callback,
                               reinterpret_cast<void *>(userdata));
}
void Queue::set_label(char const *label) const {
  wgpuQueueSetLabel(get(), reinterpret_cast<char const *>(label));
}
void Queue::submit(u32 commandCount, CommandBuffer const *commands) const {
  wgpuQueueSubmit(get(), commandCount,
                  reinterpret_cast<WGPUCommandBuffer const *>(commands));
}
void Queue::write_buffer(Buffer const &buffer, u64 bufferOffset,
                         void const *data, size_t size) const {
  wgpuQueueWriteBuffer(get(), buffer.get(), bufferOffset,
                       reinterpret_cast<void const *>(data), size);
}
void Queue::write_texture(ImageCopyTexture const *destination, void const *data,
                          size_t dataSize, TextureDataLayout const *dataLayout,
                          Extent3D const *writeSize) const {
  wgpuQueueWriteTexture(
      get(), reinterpret_cast<WGPUImageCopyTexture const *>(destination),
      reinterpret_cast<void const *>(data), dataSize,
      reinterpret_cast<WGPUTextureDataLayout const *>(dataLayout),
      reinterpret_cast<WGPUExtent3D const *>(writeSize));
}
void Queue::wgpu_reference(WGPUQueue handle) {
  if (handle != nullptr) {
    wgpuQueueReference(handle);
  }
}
void Queue::wgpu_release(WGPUQueue handle) {
  if (handle != nullptr) {
    wgpuQueueRelease(handle);
  }
}

// RenderBundle

static_assert(sizeof(RenderBundle) == sizeof(WGPURenderBundle),
              "sizeof mismatch for RenderBundle");
static_assert(alignof(RenderBundle) == alignof(WGPURenderBundle),
              "alignof mismatch for RenderBundle");

void RenderBundle::wgpu_reference(WGPURenderBundle handle) {
  if (handle != nullptr) {
    wgpuRenderBundleReference(handle);
  }
}
void RenderBundle::wgpu_release(WGPURenderBundle handle) {
  if (handle != nullptr) {
    wgpuRenderBundleRelease(handle);
  }
}

// RenderBundleEncoder

static_assert(sizeof(RenderBundleEncoder) == sizeof(WGPURenderBundleEncoder),
              "sizeof mismatch for RenderBundleEncoder");
static_assert(alignof(RenderBundleEncoder) == alignof(WGPURenderBundleEncoder),
              "alignof mismatch for RenderBundleEncoder");

void RenderBundleEncoder::draw(u32 vertexCount, u32 instanceCount,
                               u32 firstVertex, u32 firstInstance) const {
  wgpuRenderBundleEncoderDraw(get(), vertexCount, instanceCount, firstVertex,
                              firstInstance);
}
void RenderBundleEncoder::draw_indexed(u32 indexCount, u32 instanceCount,
                                       u32 firstIndex, int32_t baseVertex,
                                       u32 firstInstance) const {
  wgpuRenderBundleEncoderDrawIndexed(get(), indexCount, instanceCount,
                                     firstIndex, baseVertex, firstInstance);
}
void RenderBundleEncoder::draw_indexed_indirect(Buffer const &indirectBuffer,
                                                u64 indirectOffset) const {
  wgpuRenderBundleEncoderDrawIndexedIndirect(get(), indirectBuffer.get(),
                                             indirectOffset);
}
void RenderBundleEncoder::draw_indirect(Buffer const &indirectBuffer,
                                        u64 indirectOffset) const {
  wgpuRenderBundleEncoderDrawIndirect(get(), indirectBuffer.get(),
                                      indirectOffset);
}
auto RenderBundleEncoder::finish(RenderBundleDescriptor const *descriptor) const
    -> RenderBundle {
  auto result = wgpuRenderBundleEncoderFinish(
      get(), reinterpret_cast<WGPURenderBundleDescriptor const *>(descriptor));
  return RenderBundle::acquire(result);
}
void RenderBundleEncoder::insert_debug_marker(char const *markerLabel) const {
  wgpuRenderBundleEncoderInsertDebugMarker(
      get(), reinterpret_cast<char const *>(markerLabel));
}
void RenderBundleEncoder::pop_debug_group() const {
  wgpuRenderBundleEncoderPopDebugGroup(get());
}
void RenderBundleEncoder::push_debug_group(char const *groupLabel) const {
  wgpuRenderBundleEncoderPushDebugGroup(
      get(), reinterpret_cast<char const *>(groupLabel));
}
void RenderBundleEncoder::set_bind_group(u32 groupIndex, BindGroup const &group,
                                         u32 dynamicOffsetCount,
                                         u32 const *dynamicOffsets) const {
  wgpuRenderBundleEncoderSetBindGroup(
      get(), groupIndex, group.get(), dynamicOffsetCount,
      reinterpret_cast<u32 const *>(dynamicOffsets));
}
void RenderBundleEncoder::set_index_buffer(Buffer const &buffer,
                                           IndexFormat format, u64 offset,
                                           u64 size) const {
  wgpuRenderBundleEncoderSetIndexBuffer(
      get(), buffer.get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderBundleEncoder::set_label(char const *label) const {
  wgpuRenderBundleEncoderSetLabel(get(), reinterpret_cast<char const *>(label));
}
void RenderBundleEncoder::set_pipeline(RenderPipeline const &pipeline) const {
  wgpuRenderBundleEncoderSetPipeline(get(), pipeline.get());
}
void RenderBundleEncoder::set_vertex_buffer(u32 slot, Buffer const &buffer,
                                            u64 offset, u64 size) const {
  wgpuRenderBundleEncoderSetVertexBuffer(get(), slot, buffer.get(), offset,
                                         size);
}
void RenderBundleEncoder::wgpu_reference(WGPURenderBundleEncoder handle) {
  if (handle != nullptr) {
    wgpuRenderBundleEncoderReference(handle);
  }
}
void RenderBundleEncoder::wgpu_release(WGPURenderBundleEncoder handle) {
  if (handle != nullptr) {
    wgpuRenderBundleEncoderRelease(handle);
  }
}

// RenderPassEncoder

static_assert(sizeof(RenderPassEncoder) == sizeof(WGPURenderPassEncoder),
              "sizeof mismatch for RenderPassEncoder");
static_assert(alignof(RenderPassEncoder) == alignof(WGPURenderPassEncoder),
              "alignof mismatch for RenderPassEncoder");

void RenderPassEncoder::begin_occlusion_query(u32 queryIndex) const {
  wgpuRenderPassEncoderBeginOcclusionQuery(get(), queryIndex);
}
void RenderPassEncoder::draw(u32 vertexCount, u32 instanceCount,
                             u32 firstVertex, u32 firstInstance) const {
  wgpuRenderPassEncoderDraw(get(), vertexCount, instanceCount, firstVertex,
                            firstInstance);
}
void RenderPassEncoder::draw_indexed(u32 indexCount, u32 instanceCount,
                                     u32 firstIndex, int32_t baseVertex,
                                     u32 firstInstance) const {
  wgpuRenderPassEncoderDrawIndexed(get(), indexCount, instanceCount, firstIndex,
                                   baseVertex, firstInstance);
}
void RenderPassEncoder::draw_indexed_indirect(Buffer const &indirectBuffer,
                                              u64 indirectOffset) const {
  wgpuRenderPassEncoderDrawIndexedIndirect(get(), indirectBuffer.get(),
                                           indirectOffset);
}
void RenderPassEncoder::draw_indirect(Buffer const &indirectBuffer,
                                      u64 indirectOffset) const {
  wgpuRenderPassEncoderDrawIndirect(get(), indirectBuffer.get(),
                                    indirectOffset);
}
void RenderPassEncoder::end() const { wgpuRenderPassEncoderEnd(get()); }
void RenderPassEncoder::end_occlusion_query() const {
  wgpuRenderPassEncoderEndOcclusionQuery(get());
}
void RenderPassEncoder::end_pass() const {
  wgpuRenderPassEncoderEndPass(get());
}
void RenderPassEncoder::execute_bundles(u32 bundleCount,
                                        RenderBundle const *bundles) const {
  wgpuRenderPassEncoderExecuteBundles(
      get(), bundleCount, reinterpret_cast<WGPURenderBundle const *>(bundles));
}
void RenderPassEncoder::insert_debug_marker(char const *markerLabel) const {
  wgpuRenderPassEncoderInsertDebugMarker(
      get(), reinterpret_cast<char const *>(markerLabel));
}
void RenderPassEncoder::pop_debug_group() const {
  wgpuRenderPassEncoderPopDebugGroup(get());
}
void RenderPassEncoder::push_debug_group(char const *groupLabel) const {
  wgpuRenderPassEncoderPushDebugGroup(
      get(), reinterpret_cast<char const *>(groupLabel));
}
void RenderPassEncoder::set_bind_group(u32 groupIndex, BindGroup const &group,
                                       u32 dynamicOffsetCount,
                                       u32 const *dynamicOffsets) const {
  wgpuRenderPassEncoderSetBindGroup(
      get(), groupIndex, group.get(), dynamicOffsetCount,
      reinterpret_cast<u32 const *>(dynamicOffsets));
}
void RenderPassEncoder::set_blend_constant(Color const *color) const {
  wgpuRenderPassEncoderSetBlendConstant(
      get(), reinterpret_cast<WGPUColor const *>(color));
}
void RenderPassEncoder::set_index_buffer(Buffer const &buffer,
                                         IndexFormat format, u64 offset,
                                         u64 size) const {
  wgpuRenderPassEncoderSetIndexBuffer(
      get(), buffer.get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderPassEncoder::set_label(char const *label) const {
  wgpuRenderPassEncoderSetLabel(get(), reinterpret_cast<char const *>(label));
}
void RenderPassEncoder::set_pipeline(RenderPipeline const &pipeline) const {
  wgpuRenderPassEncoderSetPipeline(get(), pipeline.get());
}
void RenderPassEncoder::set_scissor_rect(u32 x, u32 y, u32 width,
                                         u32 height) const {
  wgpuRenderPassEncoderSetScissorRect(get(), x, y, width, height);
}
void RenderPassEncoder::set_stencil_reference(u32 reference) const {
  wgpuRenderPassEncoderSetStencilReference(get(), reference);
}
void RenderPassEncoder::set_vertex_buffer(u32 slot, Buffer const &buffer,
                                          u64 offset, u64 size) const {
  wgpuRenderPassEncoderSetVertexBuffer(get(), slot, buffer.get(), offset, size);
}
void RenderPassEncoder::set_viewport(float x, float y, float width,
                                     float height, float minDepth,
                                     float maxDepth) const {
  wgpuRenderPassEncoderSetViewport(get(), x, y, width, height, minDepth,
                                   maxDepth);
}
void RenderPassEncoder::write_timestamp(QuerySet const &querySet,
                                        u32 queryIndex) const {
  wgpuRenderPassEncoderWriteTimestamp(get(), querySet.get(), queryIndex);
}
void RenderPassEncoder::wgpu_reference(WGPURenderPassEncoder handle) {
  if (handle != nullptr) {
    wgpuRenderPassEncoderReference(handle);
  }
}
void RenderPassEncoder::wgpu_release(WGPURenderPassEncoder handle) {
  if (handle != nullptr) {
    wgpuRenderPassEncoderRelease(handle);
  }
}

// RenderPipeline

static_assert(sizeof(RenderPipeline) == sizeof(WGPURenderPipeline),
              "sizeof mismatch for RenderPipeline");
static_assert(alignof(RenderPipeline) == alignof(WGPURenderPipeline),
              "alignof mismatch for RenderPipeline");

auto RenderPipeline::get_bind_group_layout(u32 groupIndex) const
    -> BindGroupLayout {
  auto result = wgpuRenderPipelineGetBindGroupLayout(get(), groupIndex);
  return BindGroupLayout::acquire(result);
}
void RenderPipeline::set_label(char const *label) const {
  wgpuRenderPipelineSetLabel(get(), reinterpret_cast<char const *>(label));
}
void RenderPipeline::wgpu_reference(WGPURenderPipeline handle) {
  if (handle != nullptr) {
    wgpuRenderPipelineReference(handle);
  }
}
void RenderPipeline::wgpu_release(WGPURenderPipeline handle) {
  if (handle != nullptr) {
    wgpuRenderPipelineRelease(handle);
  }
}

// Sampler

static_assert(sizeof(Sampler) == sizeof(WGPUSampler),
              "sizeof mismatch for Sampler");
static_assert(alignof(Sampler) == alignof(WGPUSampler),
              "alignof mismatch for Sampler");

void Sampler::set_label(char const *label) const {
  wgpuSamplerSetLabel(get(), reinterpret_cast<char const *>(label));
}
void Sampler::wgpu_reference(WGPUSampler handle) {
  if (handle != nullptr) {
    wgpuSamplerReference(handle);
  }
}
void Sampler::wgpu_release(WGPUSampler handle) {
  if (handle != nullptr) {
    wgpuSamplerRelease(handle);
  }
}

// ShaderModule

static_assert(sizeof(ShaderModule) == sizeof(WGPUShaderModule),
              "sizeof mismatch for ShaderModule");
static_assert(alignof(ShaderModule) == alignof(WGPUShaderModule),
              "alignof mismatch for ShaderModule");

void ShaderModule::get_compilation_info(CompilationInfoCallback callback,
                                        void *userdata) const {
  wgpuShaderModuleGetCompilationInfo(get(), callback,
                                     reinterpret_cast<void *>(userdata));
}
void ShaderModule::set_label(char const *label) const {
  wgpuShaderModuleSetLabel(get(), reinterpret_cast<char const *>(label));
}
void ShaderModule::wgpu_reference(WGPUShaderModule handle) {
  if (handle != nullptr) {
    wgpuShaderModuleReference(handle);
  }
}
void ShaderModule::wgpu_release(WGPUShaderModule handle) {
  if (handle != nullptr) {
    wgpuShaderModuleRelease(handle);
  }
}

// Surface

static_assert(sizeof(Surface) == sizeof(WGPUSurface),
              "sizeof mismatch for Surface");
static_assert(alignof(Surface) == alignof(WGPUSurface),
              "alignof mismatch for Surface");

void Surface::wgpu_reference(WGPUSurface handle) {
  if (handle != nullptr) {
    wgpuSurfaceReference(handle);
  }
}
void Surface::wgpu_release(WGPUSurface handle) {
  if (handle != nullptr) {
    wgpuSurfaceRelease(handle);
  }
}

// SwapChain

static_assert(sizeof(SwapChain) == sizeof(WGPUSwapChain),
              "sizeof mismatch for SwapChain");
static_assert(alignof(SwapChain) == alignof(WGPUSwapChain),
              "alignof mismatch for SwapChain");

void SwapChain::configure(TextureFormat format, TextureUsage allowedUsage,
                          u32 width, u32 height) const {
  wgpuSwapChainConfigure(get(), static_cast<WGPUTextureFormat>(format),
                         static_cast<WGPUTextureUsage>(allowedUsage), width,
                         height);
}
auto SwapChain::get_current_texture_view() const -> TextureView {
  auto result = wgpuSwapChainGetCurrentTextureView(get());
  return TextureView::acquire(result);
}
void SwapChain::present() const { wgpuSwapChainPresent(get()); }
void SwapChain::wgpu_reference(WGPUSwapChain handle) {
  if (handle != nullptr) {
    wgpuSwapChainReference(handle);
  }
}
void SwapChain::wgpu_release(WGPUSwapChain handle) {
  if (handle != nullptr) {
    wgpuSwapChainRelease(handle);
  }
}

// Texture

static_assert(sizeof(Texture) == sizeof(WGPUTexture),
              "sizeof mismatch for Texture");
static_assert(alignof(Texture) == alignof(WGPUTexture),
              "alignof mismatch for Texture");

auto Texture::create_view(TextureViewDescriptor const *descriptor) const
    -> TextureView {
  auto result = wgpuTextureCreateView(
      get(), reinterpret_cast<WGPUTextureViewDescriptor const *>(descriptor));
  return TextureView::acquire(result);
}
void Texture::destroy() const { wgpuTextureDestroy(get()); }
auto Texture::get_depth_or_array_layers() const -> u32 {
  auto result = wgpuTextureGetDepthOrArrayLayers(get());
  return result;
}
auto Texture::get_dimension() const -> TextureDimension {
  auto result = wgpuTextureGetDimension(get());
  return static_cast<TextureDimension>(result);
}
auto Texture::get_format() const -> TextureFormat {
  auto result = wgpuTextureGetFormat(get());
  return static_cast<TextureFormat>(result);
}
auto Texture::get_height() const -> u32 {
  auto result = wgpuTextureGetHeight(get());
  return result;
}
auto Texture::get_mip_level_count() const -> u32 {
  auto result = wgpuTextureGetMipLevelCount(get());
  return result;
}
auto Texture::get_sample_count() const -> u32 {
  auto result = wgpuTextureGetSampleCount(get());
  return result;
}
auto Texture::get_usage() const -> TextureUsage {
  auto result = wgpuTextureGetUsage(get());
  return static_cast<TextureUsage>(result);
}
auto Texture::get_width() const -> u32 {
  auto result = wgpuTextureGetWidth(get());
  return result;
}
void Texture::set_label(char const *label) const {
  wgpuTextureSetLabel(get(), reinterpret_cast<char const *>(label));
}
void Texture::wgpu_reference(WGPUTexture handle) {
  if (handle != nullptr) {
    wgpuTextureReference(handle);
  }
}
void Texture::wgpu_release(WGPUTexture handle) {
  if (handle != nullptr) {
    wgpuTextureRelease(handle);
  }
}

// TextureView

static_assert(sizeof(TextureView) == sizeof(WGPUTextureView),
              "sizeof mismatch for TextureView");
static_assert(alignof(TextureView) == alignof(WGPUTextureView),
              "alignof mismatch for TextureView");

void TextureView::set_label(char const *label) const {
  wgpuTextureViewSetLabel(get(), reinterpret_cast<char const *>(label));
}
void TextureView::wgpu_reference(WGPUTextureView handle) {
  if (handle != nullptr) {
    wgpuTextureViewReference(handle);
  }
}
void TextureView::wgpu_release(WGPUTextureView handle) {
  if (handle != nullptr) {
    wgpuTextureViewRelease(handle);
  }
}

// Function

auto CreateInstance(InstanceDescriptor const *descriptor) -> Instance {
  auto result = wgpuCreateInstance(
      reinterpret_cast<WGPUInstanceDescriptor const *>(descriptor));
  return Instance::acquire(result);
}
auto GetProcAddress(Device device, char const *procName) -> Proc {
  auto result = wgpuGetProcAddress(device.get(),
                                   reinterpret_cast<char const *>(procName));
  return reinterpret_cast<Proc>(result);
}

} // namespace moon::gpu