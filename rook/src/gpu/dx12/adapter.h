#pragma once

#include "rook/gpu.h"

#include "common.h"

namespace rook::gpu::dx12 {
class DX12Instance;
class ROOK_API DX12Adapter : public gpu::Adapter {
public:
  DX12Adapter(DX12Instance &instance, ComPtr<IDXGIAdapter1> const &adapter);
  [[nodiscard]] auto get_name() const -> const eastl::string & override;
  auto create_device() -> eastl::shared_ptr<Device> override;

  auto get_instance() -> DX12Instance &;
  auto get_adapter() -> ComPtr<IDXGIAdapter1>;

private:
  DX12Instance &m_instance;
  ComPtr<IDXGIAdapter1> m_adapter;
  eastl::string m_name;
};
} // namespace rook::gpu::dx12