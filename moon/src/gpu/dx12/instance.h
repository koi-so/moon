#pragma once

#include "moon/gpu.h"

#include "common.h"

namespace moon::gpu::dx12 {
class MOON_API DX12Instance : public gpu::Instance {
public:
  DX12Instance();
  auto get_adapters() -> zinc::vector<zinc::shared<gpu::Adapter>> override;

  auto get_factory() -> ComPtr<IDXGIFactory4>;

private:
  ComPtr<IDXGIFactory4> m_dxgi_factory;
};
} // namespace moon::gpu::dx12