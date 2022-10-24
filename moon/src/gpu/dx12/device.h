#pragma once

#include "moon/gpu.h"

#include "common.h"

namespace moon::gpu::dx12 {
struct MemoryBudget {
  u64 budget;
  u64 usage;
};

class MOON_API DX12Device : public gpu::Device {};
} // namespace moon::gpu::dx12