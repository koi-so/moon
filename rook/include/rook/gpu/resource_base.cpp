#include "resource_base.h"

namespace rook::gpu {
ResourceBase::ResourceBase() : m_resource_state_tracker(*this) {}

auto ResourceBase::get_resource_type() const -> ResourceType {
  return p_resource_type;
}

auto ResourceBase::get_format() const -> Format { return p_format; }

auto ResourceBase::get_memory_type() const -> MemoryType {
  return m_memory_type;
}

void ResourceBase::update_upload_buffer(uint64_t buffer_offset,
                                        void const *data, uint64_t num_bytes) {
  void *dst_data = map() + buffer_offset;
  memcpy(dst_data, data, num_bytes);
  unmap();
}

void ResourceBase::update_upload_buffer_with_texture_data(
    uint64_t buffer_offset, uint32_t buffer_row_pitch,
    uint32_t buffer_depth_pitch, const void *src_data, uint32_t src_row_pitch,
    uint32_t src_depth_pitch, uint32_t num_rows, uint32_t num_slices) {
  void *dst_data = map() + buffer_offset;
  for (uint32_t z = 0; z < num_slices; ++z) {
    uint8_t *dest_slice =
        reinterpret_cast<uint8_t *>(dst_data) + buffer_depth_pitch * z;
    uint8_t const *src_slice =
        reinterpret_cast<uint8_t const *>(src_data) + src_depth_pitch * z;
    for (uint32_t y = 0; y < num_rows; ++y) {
      memcpy(dest_slice + buffer_row_pitch * y, src_slice + src_row_pitch * y,
             src_row_pitch);
    }
  }
  unmap();
}

auto ResourceBase::get_initial_state() const -> ResourceState {
  return m_initial_state;
}

auto ResourceBase::is_back_buffer() const -> bool { return p_is_back_buffer; }

void ResourceBase::set_initial_state(ResourceState state) {
  m_initial_state = state;
  m_resource_state_tracker.set_resource_state(m_initial_state);
}

auto ResourceBase::get_global_resource_state_tracker()
    -> ResourceStateTracker & {
  return m_resource_state_tracker;
}

auto ResourceBase::get_global_resource_state_tracker() const
    -> ResourceStateTracker const & {
  return m_resource_state_tracker;
}
} // namespace rook::gpu