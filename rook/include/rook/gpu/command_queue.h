#pragma once

#include "rook/base.h"

#include "command_list.h"
#include "fence.h"
#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/vector.h>

namespace rook::gpu {
class CommandQueue : public interface {
public:
  ~CommandQueue() override = default;
  virtual void wait(eastl::shared_ptr<Fence> const &fence, uint64_t value) = 0;
  virtual void signal(eastl::shared_ptr<Fence> const &fence,
                      uint64_t value) = 0;
  virtual void execute_command_lists(
      eastl::vector<eastl::shared_ptr<CommandList>> const &command_lists) = 0;
};
} // namespace rook::gpu