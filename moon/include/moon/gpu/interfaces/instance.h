#pragma once

#include "moon/base.h"

namespace moon::gpu {
class IInstance : zinc::non_copyable {
  public:
    static auto Create(InstanceDescriptor const * = nullptr) -> IInstance;
};
} // moon::gpu