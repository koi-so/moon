#include "view.h"

#include "device.h"
#include "format_helper.h"
#include "format_translate.h"
#include "resource.h"

namespace rook::gpu::dx12 {
DX12View::DX12View(DX12Device &device,
                   eastl::shared_ptr<DX12Resource> const &resource,
                   ViewDescriptor const &view_desc)
    : m_device(device), m_resource(resource), m_view_desc(view_desc) {
  if (m_view_desc.view_type == ViewType::eShadingRateSource) {
    return;
  }

  m_handle = m_device.get_cpu_descriptor_pool().allocate_descriptor(
      m_view_desc.view_type);

  if (m_resource) {
    create_view();
  }

  if (m_view_desc.bindless) {
    EASTL_ASSERT(m_view_desc.view_type != ViewType::eUnknown);
    EASTL_ASSERT(m_view_desc.view_type != ViewType::eRenderTarget);
    EASTL_ASSERT(m_view_desc.view_type != ViewType::eDepthStencil);
    if (m_view_desc.view_type == ViewType::eSampler) {
      m_range = eastl::make_shared<DX12GPUDescriptorPoolRange>(
          m_device.get_gpu_descriptor_pool().allocate(
              D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, 1));
    } else {
      m_range = eastl::make_shared<DX12GPUDescriptorPoolRange>(
          m_device.get_gpu_descriptor_pool().allocate(
              D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, 1));
    }
    m_range->copy_cpu_handle(0, m_handle->get_cpu_handle());
  }
}

auto DX12View::get_handle() -> D3D12_CPU_DESCRIPTOR_HANDLE {
  return m_handle->get_cpu_handle();
}

void DX12View::create_view() {
  switch (m_view_desc.view_type) {
  case ViewType::eTexture:
  case ViewType::eBuffer:
  case ViewType::eStructuredBuffer:
    create_srv();
    break;
  case ViewType::eAccelerationStructure:
    create_ras();
    break;
  case ViewType::eRWTexture:
  case ViewType::eRWBuffer:
  case ViewType::eRWStructuredBuffer:
    create_uav();
    break;
  case ViewType::eConstantBuffer:
    create_cbv();
    break;
  case ViewType::eSampler:
    create_sampler();
    break;
  case ViewType::eRenderTarget:
    create_rtv();
    break;
  case ViewType::eDepthStencil:
    create_dsv();
    break;
  default:
    EASTL_ASSERT(false);
    break;
  }
}

void DX12View::create_srv() {
  D3D12_SHADER_RESOURCE_VIEW_DESC srv_desc = {};
  srv_desc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
  srv_desc.Format = m_resource->p_desc.Format;

  if (IsTypelessDepthStencil(srv_desc.Format)) {
    if (m_view_desc.plane_slice == 0) {
      srv_desc.Format = DepthReadFromTypeless(srv_desc.Format);
    } else {
      srv_desc.Format = StencilReadFromTypeless(srv_desc.Format);
    }
  }

  auto setup_mips = [&](uint32_t &most_detailed_mip, uint32_t &mip_levels) {
    most_detailed_mip = get_base_mip_level();
    mip_levels = get_level_count();
  };

  switch (m_view_desc.dimension) {
  case ViewDimension::eTexture1D: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE1D;
    setup_mips(srv_desc.Texture1D.MostDetailedMip,
               srv_desc.Texture1D.MipLevels);
    break;
  }
  case ViewDimension::eTexture1DArray: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE1DARRAY;
    srv_desc.Texture1DArray.FirstArraySlice = get_base_array_layer();
    srv_desc.Texture1DArray.ArraySize = get_layer_count();
    setup_mips(srv_desc.Texture1DArray.MostDetailedMip,
               srv_desc.Texture1DArray.MipLevels);
    break;
  }
  case ViewDimension::eTexture2D: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
    srv_desc.Texture2D.PlaneSlice = m_view_desc.plane_slice;
    setup_mips(srv_desc.Texture2D.MostDetailedMip,
               srv_desc.Texture2D.MipLevels);
    break;
  }
  case ViewDimension::eTexture2DArray: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DARRAY;
    srv_desc.Texture2DArray.PlaneSlice = m_view_desc.plane_slice;
    srv_desc.Texture2DArray.FirstArraySlice = get_base_array_layer();
    srv_desc.Texture2DArray.ArraySize = get_layer_count();
    setup_mips(srv_desc.Texture2DArray.MostDetailedMip,
               srv_desc.Texture2DArray.MipLevels);
    break;
  }
  case ViewDimension::eTexture2DMS: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DMS;
    break;
  }
  case ViewDimension::eTexture2DMSArray: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY;
    srv_desc.Texture2DMSArray.FirstArraySlice = get_base_array_layer();
    srv_desc.Texture2DMSArray.ArraySize = get_layer_count();
    break;
  }
  case ViewDimension::eTexture3D: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE3D;
    setup_mips(srv_desc.Texture3D.MostDetailedMip,
               srv_desc.Texture3D.MipLevels);
    break;
  }
  case ViewDimension::eTextureCube: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBE;
    setup_mips(srv_desc.TextureCube.MostDetailedMip,
               srv_desc.TextureCube.MipLevels);
    break;
  }
  case ViewDimension::eTextureCubeArray: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURECUBEARRAY;
    srv_desc.TextureCubeArray.First2DArrayFace = get_base_array_layer() / 6;
    srv_desc.TextureCubeArray.NumCubes = get_layer_count() / 6;
    setup_mips(srv_desc.TextureCubeArray.MostDetailedMip,
               srv_desc.TextureCubeArray.MipLevels);
    break;
  }
  case ViewDimension::eBuffer: {
    srv_desc.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
    uint32_t stride = 0;
    if (m_view_desc.view_type == ViewType::eBuffer) {
      srv_desc.Format = static_cast<DXGI_FORMAT>(
          TranslateFormatToDX12Format(m_view_desc.buffer_format)
              .DXGIFormat.DDS);
      stride = gli::detail::bits_per_pixel(m_view_desc.buffer_format) / 8;
    } else {
      assert(m_view_desc.view_type == ViewType::eStructuredBuffer);
      srv_desc.Buffer.StructureByteStride = m_view_desc.structure_stride;
      stride = srv_desc.Buffer.StructureByteStride;
    }
    uint64_t size = std::min(m_resource->desc.Width, m_view_desc.buffer_size);
    srv_desc.Buffer.FirstElement = m_view_desc.offset / stride;
    srv_desc.Buffer.NumElements = (size - m_view_desc.offset) / (stride);
    break;
  }
  default: {
    assert(false);
    break;
  }
  }

  m_device.GetDevice()->CreateShaderResourceView(
      m_resource->resource.Get(), &srv_desc, m_handle->GetCpuHandle());
}
} // namespace rook::gpu::dx12