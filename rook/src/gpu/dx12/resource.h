#pragma once

#include "rook/gpu.h"
#include "rook/gpu/resource_base.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Device;

class DX12Resource : public ResourceBase {
public:
  DX12Resource(DX12Device &device);

  void commit_memory(MemoryType memory_type) override final;
  void bind_memory(eastl::shared_ptr<Memory> const &memory,
                   uint64_t offset) override;
  auto get_width() const -> uint64_t override final;
  auto get_height() const -> uint32_t override final;
  auto get_layer_count() const -> uint16_t override final;
  auto get_level_count() const -> uint16_t override final;
  auto get_sample_count() const -> uint32_t override final;
  auto get_acceleration_structure_handle() const -> uint64_t override final;
  void set_name(eastl::string const &name) override final;
  auto map() -> uint8_t * override final;
  void unmap() override final;
  bool allow_common_state_promotion(ResourceState state_after) override final;
  auto get_memory_requirements() const -> MemoryRequirements override final;

  ComPtr<ID3D12Resource> p_resource;
  D3D12_RESOURCE_DESC p_desc{};
  D3D12_SAMPLER_DESC p_sampler_desc{};
  D3D12_GPU_VIRTUAL_ADDRESS p_acceleration_structure_handle{};

private:
  DX12Device &m_device;
};
} // namespace rook::gpu::dx12