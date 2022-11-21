#pragma once

#include "rook/gpu.h"

#include "common.h"

#include "program.h"

#include <EASTL/map.h>

namespace rook::gpu::dx12 {
class DX12Device;
class DX12BindingSetLayout;
class DX12GPUDescriptorPoolRange;

class DX12BindingSet : public BindingSet {
public:
  DX12BindingSet(DX12Device &device,
                 eastl::shared_ptr<DX12BindingSetLayout> const &layout);
  void
  write_bindings(eastl::vector<BindingDescriptor> const &bindings) override;

  auto apply(ComPtr<ID3D12GraphicsCommandList> const &command_list)
      -> eastl::vector<ComPtr<ID3D12DescriptorHeap>>;

private:
  DX12Device &m_device;
  eastl::shared_ptr<DX12BindingSetLayout> m_layout;
  eastl::map<D3D12_DESCRIPTOR_HEAP_TYPE,
             eastl::shared_ptr<DX12GPUDescriptorPoolRange>>
      m_ranges;
};
} // namespace rook::gpu::dx12