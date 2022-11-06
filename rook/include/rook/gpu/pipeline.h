#pragma once

#include "rook/base.h"

#include "types.h"

#include <EASTL/vector.h>

namespace rook::gpu {
class Pipeline : public interface {
public:
  ~Pipeline() override = default;
  [[nodiscard]] virtual auto get_type() const -> PipelineType = 0;
  [[nodiscard]] virtual auto
  get_ray_tracing_shader_group_handles(uint32_t first_group,
                                       uint32_t group_count) const
      -> eastl::vector<uint8_t> = 0;
};
} // namespace rook::gpu