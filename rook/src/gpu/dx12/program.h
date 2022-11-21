#pragma once

#include "rook/gpu.h"
#include "rook/gpu/program_base.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Device;

class DX12Program : public ProgramBase {
public:
  DX12Program(DX12Device &device,
              eastl::vector<eastl::shared_ptr<Shader>> const &shaders);
};
} // namespace rook::gpu::dx12