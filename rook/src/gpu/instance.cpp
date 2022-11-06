#include "rook/gpu.h"

#if ROOK_GPU_DX12
#include "dx12/instance.h"
#endif

#include <EASTL/shared_ptr.h>

namespace rook::gpu {
auto CreateInstance(BackendType type) -> eastl::shared_ptr<Instance> {
  switch (type) {
  case BackendType::eVulkan:
#if ROOK_GPU_VULKAN
    return eastl::make_shared<vk::Instance>();
#endif
    break;
  case BackendType::eMetal:
#if ROOK_GPU_METAL
    return eastl::make_shared<mtl::Instance>();
#endif
    break;
  case BackendType::eD3D12:
#if ROOK_GPU_DX12
    return eastl::make_shared<dx12::DX12Instance>();
#endif
    break;
  };
  return nullptr;
}
}; // namespace rook::gpu