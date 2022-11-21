#include "pipeline.h"

namespace rook::gpu::dx12 {
auto DX12Pipeline::get_ray_tracing_shader_group_handles(
    uint32_t girst_group, uint32_t group_count) const
    -> eastl::vector<uint8_t> {
  return {};
}
} // namespace rook::gpu::dx12