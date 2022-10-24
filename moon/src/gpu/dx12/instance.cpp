#include "instance.h"

#include "moon/platform.h"

#include "adapter.h"

#ifdef MOON_GPU_D3D12_AGILITY
#define EXPORT_AGILITY_SDK extern "C" _declspec(dllexport)
#else
#define EXPORT_AGILITY_SDK
#endif

EXPORT_AGILITY_SDK const UINT D3D12SDKVersion = 4;
EXPORT_AGILITY_SDK const char *D3D12SDKPath = u8".\\D3D12\\";

auto EnableAgilitySDKIfExist(u32 version, const zinc::string_view &path)
    -> bool {
  if (!moon::platform::DynamicLibrary::LibraryExists("d3d12.dll")) {
    return false;
  }

  auto lib = moon::platform::DynamicLibrary::Load("d3d12.dll");
  auto D3D12GetInterfacePfn =
      (::PFN_D3D12_GET_INTERFACE)lib->LoadProcedure("D3D12GetInterface");
  if (!D3D12GetInterfacePfn) {
    return false;
  }

  ComPtr<ID3D12SDKConfiguration> sdk_configuration;
  if (FAILED(D3D12GetInterfacePfn(CLSID_D3D12SDKConfiguration,
                                  IID_PPV_ARGS(&sdk_configuration)))) {
    return false;
  }
  if (FAILED(sdk_configuration->SetSDKVersion(version, path.data()))) {
    return false;
  }
  return true;
}

#ifndef MOON_GPU_D3D12_AGILITY
static bool optional_agility_sdk =
    EnableAgilitySDKIfExist(D3D12SDKVersion, D3D12SDKPath);
#endif

namespace moon::gpu::dx12 {
DX12Instance::DX12Instance() {
  u32 flags = 0;
  static const bool debug_enabled = ::IsDebuggerPresent();

  if (debug_enabled) {
    ComPtr<ID3D12Debug> debug_controller;
    if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debug_controller)))) {
      debug_controller->EnableDebugLayer();
    }
    flags |= DXGI_CREATE_FACTORY_DEBUG;
  }

  /*ASSERT_SUCCEEDED*/ void(
      CreateDXGIFactory2(flags, IID_PPV_ARGS(&m_dxgi_factory)));
}

auto DX12Instance::get_adapters() -> zinc::vector<zinc::shared<gpu::Adapter>> {
  zinc::vector<zinc::shared<Adapter>> adapters;

  ComPtr<IDXGIFactory6> dxgi_factory6;
  m_dxgi_factory.As(&dxgi_factory6);

  auto NextAdapted = [&](u32 adapter_index, ComPtr<IDXGIAdapter1> &adapter) {
    if (dxgi_factory6)
      return dxgi_factory6->EnumAdapterByGpuPreference(
          adapter_index, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE,
          IID_PPV_ARGS(&adapter));
    else
      return m_dxgi_factory->EnumAdapters1(adapter_index, &adapter);
  };

  ComPtr<IDXGIAdapter1> adapter;
  u32 gpu_index = 0;
  for (u32 adapter_index = 0;
       DXGI_ERROR_NOT_FOUND != NextAdapted(adapter_index, adapter);
       ++adapter_index) {
    DXGI_ADAPTER_DESC1 desc = {};
    adapter->GetDesc1(&desc);
    if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
      continue;

    auto x = zinc::make_shared<DX12Adapter>(*this, adapter);
    adapters.push_back(std::move(x));
  }
  return std::move(adapters);
}

auto DX12Instance::get_factory() -> ComPtr<IDXGIFactory4> {
  return m_dxgi_factory;
}
} // namespace moon::gpu::dx12