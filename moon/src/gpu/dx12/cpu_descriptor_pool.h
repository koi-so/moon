#pragma once

#include "moon/gpu.h"

#include "common.h"

#include "cpu_descriptor_pool_typed.h"

namespace moon::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorPool {
public:
  DX12CPUDescriptorPool(DX12Device &device);
  auto allocate_descriptor(ViewType view_type)
      -> zinc::shared<DX12CPUDescriptorHandle>;

private:
  auto select_heap(ViewType view_type) -> DX12CPUDescriptorPoolTyped &;

  DX12Device &m_device;
  DX12CPUDescriptorPoolTyped m_resource;
  DX12CPUDescriptorPoolTyped m_sampler;
  DX12CPUDescriptorPoolTyped m_rtv;
  DX12CPUDescriptorPoolTyped m_dsv;
};
} // namespace moon::gpu::dx12