#include "moon/gpu.h"

#if MOON_GPU_DX12
#include "dx12/instance.h"
#endif

namespace moon::gpu {
auto CreateInstance(BackendType type) -> zinc::shared<Instance> {
  switch (type) {
  case BackendType::eVulkan:
#if MOON_GPU_VULKAN
    return zinc::make_shared<vk::Instance>();
#endif
    break;
  case BackendType::eMetal:
#if MOON_GPU_METAL
    return zinc::make_shared<mtl::Instance>();
#endif
    break;
  case BackendType::eD3D12:
#if MOON_GPU_DX12
    return zinc::make_shared<dx12::DX12Instance>();
#endif
    break;
  };
  return nullptr;
}
}; // namespace moon::gpu