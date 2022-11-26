#pragma once

#include "rook/base.h"

#include "memory.h"
#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>

namespace rook::gpu {
struct MemoryRequirements {
  uint64_t size;
  uint64_t alignment;
  uint32_t memory_type_bits;
};

class Resource : public interface {
public:
  ~Resource() override = default;
  virtual void commit_memory(MemoryType memory_type) = 0;
  virtual void bind_memory(eastl::shared_ptr<Memory> const &memory,
                           uint64_t offset) = 0;
  [[nodiscard]] virtual auto get_resource_type() const -> ResourceType = 0;
  [[nodiscard]] virtual auto get_format() const -> Format = 0;
  [[nodiscard]] virtual auto get_memory_type() const -> MemoryType = 0;
  [[nodiscard]] virtual auto get_width() const -> uint64_t = 0;
  [[nodiscard]] virtual auto get_height() const -> uint32_t = 0;
  [[nodiscard]] virtual auto get_layer_count() const -> uint16_t = 0;
  [[nodiscard]] virtual auto get_level_count() const -> uint16_t = 0;
  [[nodiscard]] virtual auto get_sample_count() const -> uint32_t = 0;
  virtual auto get_acceleration_structure_handle() const -> uint64_t = 0;
  virtual void set_name(eastl::string const &name) = 0;
  virtual auto map() -> uint8_t * = 0;
  virtual void unmap() = 0;
  virtual void update_upload_buffer(uint64_t buffer_offset, const void *data,
                                    uint64_t bytes) = 0;
  virtual void update_upload_buffer_with_texture_data(
      uint64_t buffer_offset, uint32_t buffer_row_pitch,
      uint32_t buffer_depth_pitch, const void *src_data, uint32_t src_row_pitch,
      uint32_t src_depth_pitch, uint32_t num_rows, uint32_t num_slices) = 0;
  virtual auto allow_common_state_promotion(ResourceState state_after)
      -> bool = 0;
  [[nodiscard]] virtual auto get_initial_state() const -> ResourceState = 0;
  [[nodiscard]] virtual auto get_memory_requirements() const
      -> MemoryRequirements = 0;
  [[nodiscard]] virtual auto is_back_buffer() const -> bool = 0;
};
} // namespace rook::gpu