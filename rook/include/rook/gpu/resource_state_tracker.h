#pragma once

#include "rook/base.h"

#include "types.h"

#include <EASTL/map.h>

namespace rook::gpu {
class Resource;

class ResourceStateTracker {
public:
  ResourceStateTracker(Resource &resource);
  auto has_resource_state() const -> bool;
  auto get_resource_state() const -> ResourceState;
  void set_resource_state(ResourceState state);
  auto get_subresource_state(uint32_t mip_level, uint32_t array_layer) const
      -> ResourceState;
  void set_subresource_state(uint32_t mip_level, uint32_t array_layer,
                             ResourceState state);
  void merge(ResourceStateTracker const &other);

private:
  Resource &m_resource;
  eastl::map<eastl::tuple<uint32_t, uint32_t>, ResourceState>
      m_subresource_states;
  eastl::map<ResourceState, size_t> m_subresource_state_groups;
  ResourceState m_resource_state = ResourceState::eUnknown;
};
} // namespace rook::gpu