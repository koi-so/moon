#pragma once

#include "moon/gpu.h"

#include "common.h"

namespace moon::gpu::dx12 {
class DX12Instance;
class MOON_API DX12Adapter : public gpu::Adapter {
public:
  DX12Adapter(DX12Instance &instance, ComPtr<IDXGIAdapter1> const &adapter);
  [[nodiscard]] auto get_name() const -> const zinc::string & override;
  auto create_device() -> zinc::shared<Device> override;

  auto get_instance() -> DX12Instance &;
  auto get_adapter() -> ComPtr<IDXGIAdapter1>;

private:
  DX12Instance &m_instance;
  ComPtr<IDXGIAdapter1> m_adapter;
  zinc::string m_name;
};
} // namespace moon::gpu::dx12