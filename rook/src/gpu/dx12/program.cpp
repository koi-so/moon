#include "program.h"

namespace rook::gpu::dx12 {
DX12Program::DX12Program(
    DX12Device &device, eastl::vector<eastl::shared_ptr<Shader>> const &shaders)
    : ProgramBase(shaders) {}
} // namespace rook::gpu::dx12