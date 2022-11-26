#include "resource_state_tracker.h"
#include "resource.h"

namespace rook::gpu {
ResourceStateTracker::ResourceStateTracker(Resource &resource)
    : m_resource(resource) {}

auto ResourceStateTracker::has_resource_state() const -> bool {
  return m_subresource_states.empty();
}

auto ResourceStateTracker::get_resource_state() const -> ResourceState {
  return m_resource_state;
}

void ResourceStateTracker::set_resource_state(ResourceState state) {
  m_subresource_states.clear();
  m_resource_state = state;
  m_subresource_state_groups.clear();
}

auto ResourceStateTracker::get_subresource_state(uint32_t mip_level,
                                                 uint32_t array_layer) const
    -> ResourceState {
  auto it =
      m_subresource_states.find(eastl::make_tuple(mip_level, array_layer));
  if (it != m_subresource_states.end()) {
    return it->second;
  }
  return m_resource_state;
}

void ResourceStateTracker::set_subresource_state(uint32_t mip_level,
                                                 uint32_t array_layer,
                                                 ResourceState state) {
  if (has_resource_state() && get_resource_state() == state) {
    return;
  }
  eastl::tuple<uint32_t, uint32_t> key = {mip_level, array_layer};
  if (m_subresource_states.count(key)) {
    if (--m_subresource_state_groups[m_subresource_states[key]] == 0) {
      m_subresource_state_groups.erase(m_subresource_states[key]);
    }
  }
  m_subresource_states[key] = state;
  ++m_subresource_state_groups[state];
  if (m_subresource_state_groups.size() == 1 &&
      m_subresource_state_groups.begin()->second ==
          m_resource.get_layer_count() * m_resource.get_level_count()) {
    m_subresource_state_groups.clear();
    m_subresource_states.clear();
    m_resource_state = m_subresource_state_groups.begin()->first;
  }
}

void ResourceStateTracker::merge(ResourceStateTracker const &other) {
  if (other.has_resource_state()) {
    auto state = other.get_resource_state();
    if (state != ResourceState::eUnknown) {
      set_resource_state(state);
    }
  } else {
    for (uint32_t i = 0; i < other.m_resource.get_level_count(); ++i) {
      for (uint32_t j = 0; j < other.m_resource.get_layer_count(); ++j) {
        auto state = other.get_subresource_state(i, j);
        if (state != ResourceState::eUnknown)
          set_subresource_state(i, j, state);
      }
    }
  }
}
} // namespace rook::gpu