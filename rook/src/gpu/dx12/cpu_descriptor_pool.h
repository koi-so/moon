#pragma once

#include "rook/gpu.h"

#include "common.h"
#include "cpu_descriptor_pool_typed.h"

#include <EASTL/shared_ptr.h>

namespace rook::gpu::dx12 {
class DX12Device;

class DX12CPUDescriptorPool {
public:
  DX12CPUDescriptorPool(DX12Device &device);
  auto allocate_descriptor(ViewType view_type)
      -> eastl::shared_ptr<DX12CPUDescriptorHandle>;

private:
  auto select_heap(ViewType view_type) -> DX12CPUDescriptorPoolTyped &;

  DX12Device &m_device;
  DX12CPUDescriptorPoolTyped m_resource;
  DX12CPUDescriptorPoolTyped m_sampler;
  DX12CPUDescriptorPoolTyped m_rtv;
  DX12CPUDescriptorPoolTyped m_dsv;
};
} // namespace rook::gpu::dx12