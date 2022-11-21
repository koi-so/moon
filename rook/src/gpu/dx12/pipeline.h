#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Pipeline : public Pipeline {
public:
  virtual ~DX12Pipeline() = default;
  virtual auto get_root_signature() const
      -> ComPtr<ID3D12RootSignature> const & = 0;
  auto get_ray_tracing_shader_group_handles(uint32_t girst_group,
                                            uint32_t group_count) const
      -> eastl::vector<uint8_t> override;
};
} // namespace rook::gpu::dx12