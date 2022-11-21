#pragma once

#include "rook/gpu.h"
#include "rook/gpu/binding_set_layout.h"

#include "common.h"

#include "program.h"

#include <EASTL/map.h>

namespace rook::gpu::dx12 {
class DX12Device;

struct BindingLayout {
  D3D12_DESCRIPTOR_HEAP_TYPE heap_type;
  size_t heap_offset;
};

struct DescriptorTableDescriptor {
  D3D12_DESCRIPTOR_HEAP_TYPE heap_type;
  size_t heap_offset;
  bool bindless;
  bool is_compute;
};

class DX12BindingSetLayout : public BindingSetLayout {
public:
  DX12BindingSetLayout(DX12Device &device, eastl::vector<BindKey> const &descs);

  auto get_heap_descriptors() const
      -> eastl::map<D3D12_DESCRIPTOR_HEAP_TYPE, size_t> const &;
  auto get_layout() const -> eastl::map<BindKey, BindingLayout> const &;
  auto get_descriptor_tables() const
      -> eastl::map<uint32_t, DescriptorTableDescriptor> const &;
  auto get_root_signature() const -> ComPtr<ID3D12RootSignature> const &;

private:
  DX12Device &m_device;
  eastl::map<D3D12_DESCRIPTOR_HEAP_TYPE, size_t> m_heap_descriptors;
  eastl::map<BindKey, BindingLayout> m_layout;
  eastl::map<uint32_t, DescriptorTableDescriptor> m_descriptor_tables;
  ComPtr<ID3D12RootSignature> m_root_signature;
};
} // namespace rook::gpu::dx12