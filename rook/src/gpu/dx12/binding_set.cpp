#include "binding_set.h"

#include "binding_set_layout.h"
#include "device.h"
#include "gpu_descriptor_pool_range.h"

namespace rook::gpu::dx12 {
DX12BindingSet::DX12BindingSet(
    DX12Device &device, eastl::shared_ptr<DX12BindingSetLayout> const &layout)
    : m_device(device), m_layout(layout) {
  for (auto const &desc : m_layout->get_heap_descriptors()) {
    eastl::shared_ptr<DX12GPUDescriptorPoolRange> heap_range =
        eastl::make_shared<DX12GPUDescriptorPoolRange>(
            m_device.get_gpu_descriptor_pool().allocate(desc.first,
                                                        desc.second));
    m_ranges.emplace(eastl::piecewise_construct,
                     eastl::forward_as_tuple(desc.first),
                     eastl::forward_as_tuple(heap_range));
  }
}

DX12BindingSet::write_bindings(
    eastl::vector<BindingDescriptor> const &bindings) {
  for (auto const &binding : bindings) {
    if (!binding.view) {
      continue;
    }
    auto binding_layout = m_layout->get_layout().at(binding.bind_key);
    eastl::shared_ptr<DX12GPUDescriptorPoolRange> heap_range =
        m_ranges.at(binding_layout.heap_type);
    auto src_cpu_handle = binding.view
  }
}
} // namespace rook::gpu::dx12