#pragma once

#include "moon/base.h"

#include "memory.h"
#include "types.h"

namespace moon::gpu {
struct MemoryRequirements {
  u64 size;
  u64 alignment;
  u32 memory_type_bits;
};

class Resource : public zinc::interface {
public:
  ~Resource() override = default;
  virtual void commit_memory(MemoryType memory_type) = 0;
  virtual void bind_memory(zinc::shared<Memory> const &memory, u64 offset) = 0;
  [[nodiscard]] virtual auto get_resource_type() const -> ResourceType = 0;
  [[nodiscard]] virtual auto get_format() const -> Format = 0;
  [[nodiscard]] virtual auto get_memory_type() const -> MemoryType = 0;
  [[nodiscard]] virtual auto get_width() const -> u32 = 0;
  [[nodiscard]] virtual auto get_height() const -> u64 = 0;
  [[nodiscard]] virtual auto get_depth() const -> u32 = 0;
  [[nodiscard]] virtual auto get_layer_count() const -> u16 = 0;
  [[nodiscard]] virtual auto get_level_count() const -> u16 = 0;
  [[nodiscard]] virtual auto get_sample_count() const -> u32 = 0;
  virtual auto get_acceleration_structure_handle() -> u64 = 0;
  virtual void set_name(zinc::string const &name) = 0;
  virtual auto map() -> vptr = 0;
  virtual void unmap() = 0;
  virtual void update_upload_buffer(u64 buffer_offset, const void *data,
                                    u64 bytes) = 0;
  virtual void update_upload_buffer_with_texture_data(
      u64 buffer_offset, u32 buffer_row_pitch, u32 buffer_depth_pitch,
      const void *src_data, u32 src_row_pitch, u32 src_depth_pitch,
      u32 num_rows, u32 num_slices) = 0;
  virtual auto allow_common_state_promotion(ResourceState state_after)
      -> bool = 0;
  [[nodiscard]] virtual auto get_initial_state() const -> ResourceState = 0;
  [[nodiscard]] virtual auto get_memory_requirements() const
      -> MemoryRequirements = 0;
  [[nodiscard]] virtual auto is_back_buffer() const -> bool = 0;
};
} // namespace moon::gpu