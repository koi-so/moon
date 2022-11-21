#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class Resource;

class View : public interface {
public:
  virtual ~View() = default;
  virtual auto get_resource() -> eastl::shared_ptr<Resource> = 0;
  virtual auto get_descriptor_id() const -> uint32_t = 0;
  virtual auto get_base_mip_level() const -> uint32_t = 0;
  virtual auto get_level_count() const -> uint32_t = 0;
  virtual auto get_base_array_layer() const -> uint32_t = 0;
  virtual auto get_layer_count() const -> uint32_t = 0;
};
} // namespace rook::gpu