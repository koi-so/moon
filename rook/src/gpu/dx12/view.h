#pragma once

#include "rook/gpu.h"
#include "rook/gpu/view.h"

#include "common.h"

#include "cpu_descriptor_handle.h"
#include "gpu_descriptor_pool_range.h"

namespace rook::gpu::dx12 {
class DX12Device;
class DX12Resource;

class DX12View : public View {
public:
  DX12View(DX12Device &device, eastl::shared_ptr<DX12Resource> const &resource,
           ViewDescriptor const &view_desc);
  auto get_descriptor_id() const -> uint32_t override;
  auto get_base_mip_level() const -> uint32_t override;
  auto get_level_count() const -> uint32_t override;
  auto get_base_array_layer() const -> uint32_t override;
  auto get_layer_count() const -> uint32_t override;

  auto get_handle() -> D3D12_CPU_DESCRIPTOR_HANDLE;

private:
  void create_view();
  void create_srv();
  void create_ras();
  void create_uav();
  void create_rtv();
  void create_dsv();
  void create_cbv();
  void create_sampler();

  DX12Device &m_device;
  eastl::shared_ptr<DX12Resource> m_resource;
  ViewDescriptor m_view_desc;
  eastl::shared_ptr<DX12CPUDescriptorHandle> m_handle;
  eastl::shared_ptr<DX12GPUDescriptorPoolRange> m_range;
};
}; // namespace rook::gpu::dx12