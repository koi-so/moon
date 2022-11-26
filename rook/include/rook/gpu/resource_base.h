#pragma once

#include "resource.h"
#include "resource_state_tracker.h"

namespace rook::gpu {
class ResourceBase : public Resource {
public:
  ResourceBase();

  auto get_resource_type() const -> ResourceType override final;
  auto get_format() const -> Format override final;
  auto get_memory_type() const -> MemoryType override final;

  void update_upload_buffer(uint64_t buffer_offset, void const *data,
                            uint64_t num_bytes) override final;
  void update_upload_buffer_with_texture_data(
      uint64_t buffer_offset, uint32_t buffer_row_pitch,
      uint32_t buffer_depth_pitch, void const *src_data, uint32_t src_row_pitch,
      uint32_t src_depth_pitch, uint32_t num_rows,
      uint32_t num_slices) override final;

  auto get_initial_state() const -> ResourceState override final;
  auto is_back_buffer() const -> bool override final;

  void set_initial_state(ResourceState state);
  auto get_global_resource_state_tracker() -> ResourceStateTracker &;
  auto get_global_resource_state_tracker() const
      -> ResourceStateTracker const &;

  Format p_format = Format::UNDEFINED;
  ResourceType p_resource_type = ResourceType::eUnknown;
  eastl::shared_ptr<Resource> p_acceleration_structures_memory;
  bool p_is_back_buffer = false;

protected:
  eastl::shared_ptr<Memory> m_memory;
  MemoryType m_memory_type = MemoryType::eDefault;

private:
  ResourceStateTracker m_resource_state_tracker;
  ResourceState m_initial_state = ResourceState::eUnknown;
};
} // namespace rook::gpu