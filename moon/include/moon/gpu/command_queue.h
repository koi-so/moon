#pragma once

#include "moon/base.h"

#include "command_list.h"
#include "fence.h"
#include "types.h"


namespace moon::gpu {
class CommandQueue : public zinc::interface {
public:
  ~CommandQueue() override = default;
  virtual void wait(zinc::shared<Fence> const &fence, u64 value) = 0;
  virtual void signal(zinc::shared<Fence> const &fence, u64 value) = 0;
  virtual void execute_command_lists(
      zinc::vector<zinc::shared<CommandList>> const &command_lists) = 0;
};
} // namespace moon::gpu