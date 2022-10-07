#pragma once

#include "moon/gpu/base.h"
#include "wgpu_ref.h"

namespace moon::gpu::native {
class Surface;

auto APICreateInstance(const InstanceDescriptor *descriptor) -> IInstance *;

class IInstance final : public WGPURef<IInstance> {
public:
  static auto Create(InstanceDescriptor const *descriptor = nullptr)
      -> IInstance;

  auto CreateSerface(SurfaceDescriptor const *descriptor) -> Surface;
  auto RequestAdapter(RequestAdapterOptions const *options,
                      WGPURequestAdapterCallback callback, vptr userdata)
      -> Adapter;

private:
  void dropping() override;
};
} // namespace moon::gpu::native