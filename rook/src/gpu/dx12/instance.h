#pragma once

#include "rook/gpu.h"

#include "common.h"

#include <EASTL/shared_array.h>
#include <EASTL/vector.h>

namespace rook::gpu::dx12 {
class ROOK_API DX12Instance : public gpu::Instance {
public:
  DX12Instance();
  auto get_adapters()
      -> eastl::vector<eastl::shared_ptr<gpu::Adapter>> override;

  auto get_factory() -> ComPtr<IDXGIFactory4>;

private:
  ComPtr<IDXGIFactory4> m_dxgi_factory;
};
} // namespace rook::gpu::dx12