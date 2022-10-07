#pragma once

#include "moon/base.h"
#include "type_conversions.h"

namespace moon::gpu::native {
class IInstance;
class IAdapter;

struct MOON_API NativeDeviceDescriptor {
  NativeDeviceDescriptor();
  ~NativeDeviceDescriptor();

  zinc::vector<zinc::string_view> required_features;
  zinc::vector<zinc::string_view> force_enabled_toggles;
  zinc::vector<zinc::string_view> force_disabled_toggles;

  const WGPURequiredLimits *required_limits = nullptr;
};

struct ToggleInfo {
  zinc::string_view name;
  zinc::string_view description;
  zinc::string_view url;
};

struct FeatureInfo {
  zinc::string_view name;
  zinc::string_view description;
  zinc::string_view url;

  enum class FeatureState { Stable = 0, Experimental = 1 };
  FeatureState state;
};

class MOON_API Adapter {
public:
  Adapter();
  Adapter(IAdapter *implementation);
  ~Adapter();

  Adapter(const Adapter &other);
  auto operator=(Adapter const &other) -> Adapter &;

  void get_properties(AdapterProperties *properties) const;

  [[nodiscard]] auto get_supported_extensions() const
      -> zinc::vector<zinc::string>;
  [[nodiscard]] auto get_supported_features() const
      -> zinc::vector<FeatureInfo>;
  auto get_limits(SupportedLimits *limits) const -> bool;

  void set_use_tiered_limits(bool use_tiered_limits);

  explicit operator bool() const;

  auto create_device(NativeDeviceDescriptor const *descriptor) -> WGPUDevice;
  auto create_device(DeviceDescriptor const *descriptor) -> WGPUDevice;
  auto create_device(WGPUDeviceDescriptor const *descriptor = nullptr)
      -> WGPUDevice;

  void request_device(NativeDeviceDescriptor const *descriptor,
                      WGPURequestDeviceCallback callback, vptr userdata);
  void request_device(DeviceDescriptor const *descriptor,
                      WGPURequestDeviceCallback callback, vptr userdata);
  void request_device(WGPUDeviceDescriptor const *descriptor,
                      WGPURequestDeviceCallback callback, vptr userdata);

  [[nodiscard]] auto get() const -> WGPUAdapter;

private:
  IAdapter *m_implementation = nullptr;
};

struct MOON_API IAdapterDiscoveryOptions {
public:
  WGPUBackendType const backend_type;

protected:
  explicit IAdapterDiscoveryOptions(WGPUBackendType backend_type);
};

enum class BackendValidationLevel { Full, Partial, Disabled };

class MOON_API Instance : public zinc::non_copyable {
public:
  explicit Instance(WGPUInstanceDescriptor *descriptor = nullptr);
  ~Instance();

  void discover_default_adapters();
  auto discover_adapters(IAdapterDiscoveryOptions const *options);

  auto get_adapters() -> zinc::vector<Adapter>;

  auto get_toggle_info(zinc::string_view name) -> ToggleInfo const *;
  auto get_feature_info(WGPUFeatureName feature) -> FeatureInfo const *;

  void enable_validation(bool enable);
  void set_validation_level(BackendValidationLevel validation_level);

  void enable_begin_capture_on_startup(bool begin_capture_on_startup);

  // TODO: Move this to Wengpu API
  // void set_platform()

  auto get() -> WGPUInstance;

private:
  IInstance *m_implementation = nullptr;
};

MOON_API auto GetProcs() -> const GPUProcTable &;
MOON_API auto GetTogglesUsed(WGPUDevice device) -> zinc::vector<zinc::string>;
MOON_API auto GetFeaturesUsed(WGPUDevice device)
    -> zinc::vector<WGPUFeatureName>;
MOON_API auto IsTextureSubresourceInitialized(
    WGPUTexture texture, u32 baseMipLevel, u32 levelCount, u32 baseArrayLayer,
    u32 layerCount, WGPUTextureAspect aspect = WGPUTextureAspect_All) -> bool;
MOON_API auto DeviceTick(WGPUDevice device) -> bool;
} // namespace moon::gpu::native