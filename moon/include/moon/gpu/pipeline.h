#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class Pipeline : public zinc::interface {
public:
  ~Pipeline() override = default;
  virtual auto get_type() const -> PipelineType = 0;
  virtual auto get_ray_tracing_shader_group_handles(u32 first_group,
                                                    u32 group_count) const
      -> zinc::vector<u8> = 0;
};
} // namespace moon::gpu