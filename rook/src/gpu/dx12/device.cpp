#include "device.h"

#include "adapter.h"
#include "command_list.h"
#include "fence.h"
#include "memory.h"
#include "resource.h"
#include "swapchain.h"
#include "view.h"

#include "format_helper.h"
#include "format_translate.h"

namespace rook::gpu::dx12 {
auto ConvertState(ResourceState state) -> D3D12_RESOURCE_STATES {
  static eastl::pair<ResourceState, D3D12_RESOURCE_STATES> mapping[] = {
      {ResourceState::eCommon, D3D12_RESOURCE_STATE_COMMON},
      {ResourceState::eVertexAndConstantBuffer,
       D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER},
      {ResourceState::eIndexBuffer, D3D12_RESOURCE_STATE_INDEX_BUFFER},
      {ResourceState::eRenderTarget, D3D12_RESOURCE_STATE_RENDER_TARGET},
      {ResourceState::eUnorderedAccess, D3D12_RESOURCE_STATE_UNORDERED_ACCESS},
      {ResourceState::eDepthStencilWrite, D3D12_RESOURCE_STATE_DEPTH_WRITE},
      {ResourceState::eDepthStencilRead, D3D12_RESOURCE_STATE_DEPTH_READ},
      {ResourceState::eNonPixelShaderResource,
       D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE},
      {ResourceState::ePixelShaderResource,
       D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE},
      {ResourceState::eIndirectArgument,
       D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT},
      {ResourceState::eCopyDest, D3D12_RESOURCE_STATE_COPY_DEST},
      {ResourceState::eCopySource, D3D12_RESOURCE_STATE_COPY_SOURCE},
      {ResourceState::eRaytracingAccelerationStructure,
       D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE},
      {ResourceState::eShadingRateSource,
       D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE},
      {ResourceState::ePresent, D3D12_RESOURCE_STATE_PRESENT},
      {ResourceState::eGenericRead, D3D12_RESOURCE_STATE_GENERIC_READ},
  };

  D3D12_RESOURCE_STATES res = {};
  for (const auto &m : mapping) {
    if (state & m.first) {
      res |= m.second;
      state &= ~m.first;
    }
  }
  EASTL_ASSERT(state == 0);
  return res;
}

auto GetHeapType(MemoryType memory_type) -> D3D12_HEAP_TYPE {
  switch (memory_type) {
  case MemoryType::eDefault:
    return D3D12_HEAP_TYPE_DEFAULT;
  case MemoryType::eUpload:
    return D3D12_HEAP_TYPE_UPLOAD;
  case MemoryType::eReadback:
    return D3D12_HEAP_TYPE_READBACK;
  default:
    EASTL_ASSERT(false);
    return D3D12_HEAP_TYPE_DEFAULT;
  }
}

static const GUID renderdoc_uuid = {
    0xa7aa6116,
    0x9c8d,
    0x4bba,
    {0x90, 0x83, 0xb4, 0xd8, 0x16, 0xb7, 0x1b, 0x78}};
static const GUID pix_uuid = {0x9f251514,
                              0x9d4d,
                              0x4902,
                              {0x9d, 0x60, 0x18, 0x98, 0x8a, 0xb7, 0xd4, 0xb5}};
static const GUID gpa_uuid = {0xccffef16,
                              0x7b69,
                              0x468f,
                              {0xbc, 0xe3, 0xcd, 0x95, 0x33, 0x69, 0xa3, 0x9a}};

DX12Device::DX12Device(DX12Adapter &adapter)
    : m_adapter(adapter), m_cpu_descriptor_pool(*this),
      m_gpu_descriptor_pool(*this) {
  ASSERT_SUCCEEDED(D3D12CreateDevice(m_adapter.get_adapter().Get(),
                                     D3D_FEATURE_LEVEL_11_1,
                                     IID_PPV_ARGS(&m_device)));
  m_device.As(&m_device5);

  ComPtr<IUnknown> renderdoc;
  if (SUCCEEDED(m_device->QueryInterface(renderdoc_uuid, &renderdoc))) {
    m_is_under_graphics_debugger |= !!renderdoc;
  }

  ComPtr<IUnknown> pix;
  if (SUCCEEDED(DXGIGetDebugInterface1(0, pix_uuid, &pix))) {
    m_is_under_graphics_debugger |= !!pix;
  }

  ComPtr<IUnknown> gpu;
  if (SUCCEEDED(m_device->QueryInterface(gpa_uuid, &gpu))) {
    m_is_under_graphics_debugger |= !!gpu;
  }

  ComPtr<IUnknown> gpa;
  if (SUCCEEDED(m_device->QueryInterface(gpa_uuid, &gpa))) {
    m_is_under_graphics_debugger |= !!gpa;
  }

  D3D12_FEATURE_DATA_D3D12_OPTIONS5 feature_support5{};
  if (SUCCEEDED(m_device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS5,
                                              &feature_support5,
                                              sizeof(feature_support5)))) {
    m_is_dxr_supported =
        feature_support5.RaytracingTier >= D3D12_RAYTRACING_TIER_1_0;
    m_is_render_passes_supported =
        feature_support5.RenderPassesTier >= D3D12_RENDER_PASS_TIER_0;
    m_is_ray_query_supported =
        feature_support5.RaytracingTier >= D3D12_RAYTRACING_TIER_1_1;
  }

  D3D12_FEATURE_DATA_D3D12_OPTIONS6 feature_support6{};
  if (SUCCEEDED(m_device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS6,
                                              &feature_support6,
                                              sizeof(feature_support6)))) {
    m_is_variable_rate_shading_supported =
        feature_support6.VariableShadingRateTier >=
        D3D12_VARIABLE_SHADING_RATE_TIER_2;
    m_shading_rate_image_tile_size = feature_support6.ShadingRateImageTileSize;
  }

  D3D12_FEATURE_DATA_D3D12_OPTIONS7 feature_support7{};
  if (SUCCEEDED(m_device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS7,
                                              &feature_support7,
                                              sizeof(feature_support7)))) {
    m_is_create_not_zeroed_available = true;
    m_is_mesh_shading_supported =
        feature_support7.MeshShaderTier >= D3D12_MESH_SHADER_TIER_1;
  }

  m_command_queues[CommandListType::eGraphics] =
      eastl::make_shared<DX12CommandQueue>(*this, CommandListType::eGraphics);
  m_command_queues[CommandListType::eCompute] =
      eastl::make_shared<DX12CommandQueue>(*this, CommandListType::eCompute);
  m_command_queues[CommandListType::eCopy] =
      eastl::make_shared<DX12CommandQueue>(*this, CommandListType::eCopy);

  static const bool debug_enabled = IsDebuggerPresent();
  if (debug_enabled) {
    ComPtr<ID3D12InfoQueue> info_queue;
    if (SUCCEEDED(m_device.As(&info_queue))) {
      info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, true);
      info_queue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, true);

      D3D12_MESSAGE_SEVERITY severities[] = {D3D12_MESSAGE_SEVERITY_INFO};

      D3D12_MESSAGE_ID deny_ids[] = {
          D3D12_MESSAGE_ID_COPY_DESCRIPTORS_INVALID_RANGES,
      };

      D3D12_INFO_QUEUE_FILTER filter{};
      filter.DenyList.NumSeverities = eastl::size(severities);
      filter.DenyList.pSeverityList = severities;
      filter.DenyList.NumIDs = eastl::size(deny_ids);
      filter.DenyList.pIDList = deny_ids;

      info_queue->PushStorageFilter(&filter);
    }
  }
}

auto DX12Device::allocate_memory(uint64_t size, MemoryType memory_type,
                                 uint32_t memory_type_bits)
    -> eastl::shared_ptr<Memory> {
  return eastl::make_shared<DX12Memory>(*this, size, memory_type,
                                        memory_type_bits);
}

auto DX12Device::get_command_queue(CommandListType type)
    -> eastl::shared_ptr<CommandQueue> {
  return eastl::static_pointer_cast<CommandQueue>(m_command_queues.at(type));
};

auto DX12Device::get_texture_data_pitch_alignment() const -> uint32_t {
  return D3D12_TEXTURE_DATA_PITCH_ALIGNMENT;
}

auto DX12Device::create_swapchain(WindowHandle window, uint32_t width,
                                  uint32_t height, uint32_t frame_count,
                                  bool vsync) -> eastl::shared_ptr<Swapchain> {
  return eastl::make_shared<DX12Swapchain>(*this, window, width, height,
                                           frame_count, vsync);
}

auto DX12Device::create_command_list(CommandListType type)
    -> eastl::shared_ptr<CommandList> {
  return eastl::make_shared<DX12CommandList>(*this, type);
}

auto DX12Device::create_fence(uint64_t initial_value)
    -> eastl::shared_ptr<Fence> {
  return eastl::make_shared<DX12Fence>(*this, initial_value);
}

auto DX12Device::create_texture(TextureType type, uint32_t bind_flag,
                                Format format, uint32_t sample_count, int width,
                                int height, int depth, int mip_levels)
    -> eastl::shared_ptr<Resource> {
  DXGI_FORMAT dx_format = static_cast<DXGI_FORMAT>(
      TranslateFormatToDX12Format(format).DXGIFormat.DDS);
  if (bind_flag &
      static_cast<uint32_t>(static_cast<uint32_t>(BindFlag::eShaderResource))) {
    dx_format = MakeTypelessDepthStencil(dx_format);
  }

  eastl::shared_ptr<DX12Resource> res = eastl::make_shared<DX12Resource>(*this);
  res->p_resource_type = ResourceType::eTexture;
  res->p_format = format;

  D3D12_RESOURCE_DESC desc = {};
  switch (type) {
  case TextureType::e1D:
    desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE1D;
    break;
  case TextureType::e2D:
    desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    break;
  case TextureType::e3D:
    desc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE3D;
    break;
  }
  desc.Width = width;
  desc.Height = height;
  desc.DepthOrArraySize = depth;
  desc.MipLevels = mip_levels;
  desc.Format = dx_format;

  D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS ms_check_desc = {};
  ms_check_desc.Format = desc.Format;
  ms_check_desc.SampleCount = sample_count;
  m_device->CheckFeatureSupport(D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS,
                                &ms_check_desc, sizeof(ms_check_desc));
  desc.SampleDesc.Count = sample_count;
  desc.SampleDesc.Quality = ms_check_desc.NumQualityLevels - 1;

  if (bind_flag &
      static_cast<uint32_t>(static_cast<uint32_t>(BindFlag::eRenderTarget)))
    desc.Flags |= D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
  if (bind_flag &
      static_cast<uint32_t>(static_cast<uint32_t>(BindFlag::eDepthStencil)))
    desc.Flags |= D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
  if (bind_flag &
      static_cast<uint32_t>(static_cast<uint32_t>(BindFlag::eUnorderedAccess)))
    desc.Flags |= D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;

  res->p_desc = desc;
  res->set_initial_state(ResourceState::eCommon);
  // return eastl::static_pointer_cast<Resource>(res);
  return res;
}

auto DX12Device::create_buffer(uint32_t bind_flag, uint32_t buffer_size)
    -> eastl::shared_ptr<Resource> {
  if (buffer_size == 0)
    return {};

  eastl::shared_ptr<DX12Resource> res = eastl::make_shared<DX12Resource>(*this);

  if (bind_flag & static_cast<uint32_t>(BindFlag::eConstantBuffer))
    buffer_size = (buffer_size + 255) & ~255;

  auto desc = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);

  res->p_resource_type = ResourceType::eBuffer;

  ResourceState state = ResourceState::eCommon;
  if (bind_flag & static_cast<uint32_t>(BindFlag::eRenderTarget)) {
    desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;
  }
  if (bind_flag & static_cast<uint32_t>(BindFlag::eDepthStencil)) {
    desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
  }
  if (bind_flag & static_cast<uint32_t>(BindFlag::eUnorderedAccess)) {
    desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
  }
  if (bind_flag & static_cast<uint32_t>(BindFlag::eAccelerationStructure)) {
    state = ResourceState::eRaytracingAccelerationStructure;
    desc.Flags = D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS;
  }

  res->p_desc = desc;
  res->set_initial_state(state);
  return res;
}

auto DX12Device::create_sampler(const SamplerDescriptor &desc)
    -> eastl::shared_ptr<Resource> {

  eastl::shared_ptr<DX12Resource> res = eastl::make_shared<DX12Resource>(*this);
  D3D12_SAMPLER_DESC &sampler_desc = res->p_sampler_desc;

  switch (desc.filter) {
  case SamplerFilter::eAnisotropic:
    sampler_desc.Filter = D3D12_FILTER_ANISOTROPIC;
    break;
  case SamplerFilter::eMinMagMipLinear:
    sampler_desc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
    break;
  case SamplerFilter::eComparisonMinMagMipLinear:
    sampler_desc.Filter = D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR;
    break;
  }

  switch (desc.mode) {
  case SamplerTextureAddressMode::eWrap:
    sampler_desc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    sampler_desc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    sampler_desc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    break;
  case SamplerTextureAddressMode::eClamp:
    sampler_desc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    sampler_desc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    sampler_desc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    break;
  }

  switch (desc.func) {
  case SamplerComparisonFunc::eNever:
    sampler_desc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
    break;
  case SamplerComparisonFunc::eAlways:
    sampler_desc.ComparisonFunc = D3D12_COMPARISON_FUNC_ALWAYS;
    break;
  case SamplerComparisonFunc::eLess:
    sampler_desc.ComparisonFunc = D3D12_COMPARISON_FUNC_LESS;
    break;
  }

  sampler_desc.MinLOD = 0;
  sampler_desc.MaxLOD = eastl::numeric_limits<float>::max();
  sampler_desc.MaxAnisotropy = 1;

  return res;
}

auto DX12Device::create_view(eastl::shared_ptr<Resource> const &resource,
                             ViewDescriptor const &view_desc)
    -> eastl::shared_ptr<View> {
  return eastl::make_shared<DX12View>(
      *this, eastl::static_pointer_cast<DX12Resource>(resource), view_desc);
}
} // namespace rook::gpu::dx12