#include "device.h"

#include "adapter.h"

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
}
} // namespace rook::gpu::dx12