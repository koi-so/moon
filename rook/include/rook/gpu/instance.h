#pragma once

#include "rook/base.h"

#include "adapter.h"
#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/vector.h>

namespace rook::gpu {
class Instance : public interface {
public:
  ~Instance() override = default;
  virtual auto get_adapters() -> eastl::vector<eastl::shared_ptr<Adapter>> = 0;
};

ROOK_API auto CreateInstance(BackendType type) -> eastl::shared_ptr<Instance>;
} // namespace rook::gpu