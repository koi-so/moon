#include "adapter.h"

namespace rook::gpu::dx12 {
DX12Adapter::DX12Adapter(DX12Instance &instance,
                         ComPtr<IDXGIAdapter1> const &adapter)
    : m_instance(instance), m_adapter(adapter) {
  DXGI_ADAPTER_DESC1 desc;
  m_adapter->GetDesc1(&desc);
  char name[128];
  WideCharToMultiByte(CP_UTF8, 0, desc.Description, -1, name, 128, nullptr,
                      nullptr);
  m_name = name;
}

auto DX12Adapter::get_name() const -> const eastl::string & { return m_name; }

auto DX12Adapter::create_device() -> eastl::shared_ptr<Device> {
  // return zinc::make_shared<DX12Device>(*this);
  return nullptr;
}

auto DX12Adapter::get_instance() -> DX12Instance & { return m_instance; }

auto DX12Adapter::get_adapter() -> ComPtr<IDXGIAdapter1> { return m_adapter; }
} // namespace rook::gpu::dx12