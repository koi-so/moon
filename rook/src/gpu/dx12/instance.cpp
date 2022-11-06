#include "instance.h"

#include "rook/platform.h"

#include "adapter.h"

#ifdef ROOK_GPU_D3D12_AGILITY
#define EXPORT_AGILITY_SDK extern "C" _declspec(dllexport)
#else
#define EXPORT_AGILITY_SDK
#endif

EXPORT_AGILITY_SDK const UINT D3D12SDKVersion = 4;
EXPORT_AGILITY_SDK const char *D3D12SDKPath = u8".\\D3D12\\";

auto EnableAgilitySDKIfExist(uint32_t version, const eastl::string_view &path)
    -> bool {
  auto cpath = eastl::string(path);
  cpath += "D3D12Core.dll";
  if (!rook::platform::DynamicLibrary::LibraryExists(cpath.data())) {
    return false;
  }

  auto lib = rook::platform::DynamicLibrary::Load("d3d12");
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

#ifndef ROOK_GPU_D3D12_AGILITY
static bool optional_agility_sdk =
    EnableAgilitySDKIfExist(D3D12SDKVersion, D3D12SDKPath);
#endif

namespace rook::gpu::dx12 {
DX12Instance::DX12Instance() {
  uint32_t flags = 0;
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

auto DX12Instance::get_adapters()
    -> eastl::vector<eastl::shared_ptr<gpu::Adapter>> {
  eastl::vector<eastl::shared_ptr<Adapter>> adapters;

  ComPtr<IDXGIFactory6> dxgi_factory6;
  m_dxgi_factory.As(&dxgi_factory6);

  auto NextAdapted = [&](uint32_t adapter_index,
                         ComPtr<IDXGIAdapter1> &adapter) {
    if (dxgi_factory6)
      return dxgi_factory6->EnumAdapterByGpuPreference(
          adapter_index, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE,
          IID_PPV_ARGS(&adapter));
    else
      return m_dxgi_factory->EnumAdapters1(adapter_index, &adapter);
  };

  ComPtr<IDXGIAdapter1> adapter;
  uint32_t gpu_index = 0;
  for (uint32_t adapter_index = 0;
       DXGI_ERROR_NOT_FOUND != NextAdapted(adapter_index, adapter);
       ++adapter_index) {
    DXGI_ADAPTER_DESC1 desc = {};
    adapter->GetDesc1(&desc);
    if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
      continue;

    adapters.emplace_back(eastl::make_shared<DX12Adapter>(*this, adapter));
  }
  return std::move(adapters);
}

auto DX12Instance::get_factory() -> ComPtr<IDXGIFactory4> {
  return m_dxgi_factory;
}
} // namespace rook::gpu::dx12