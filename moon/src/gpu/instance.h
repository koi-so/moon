#pragma once

#include "moon/base.h"

#include "moon/gpu.h"

#include "adapter.h"
#include "backend.h"
#include "surface.h"

namespace moon::gpu::native {
class MOON_API Instance : zinc::non_copyable {
public:
  Instance(InstanceDescriptor const * = nullptr);

  // API
  auto create_surface(SurfaceDescriptor const *) -> zinc::unique<ISurface>;
  auto request_adapter(RequestAdapterOptions const *options,
                       RequestAdapterCallback callback, void *userdata)
      -> zinc::unique<IAdapter>;

  void ensure_backend(BackendType type);
  void connect_backend(Backend *backend, BackendType expected);

private:
  static constexpr i8 MAX_BACKENDS = 10;

  zinc::vector<zinc::unique<Backend>> m_backends{};
  zinc::scoped_array<bool> m_connected_backends;
};

MOON_API auto CreateInstance(InstanceDescriptor const * = nullptr)
    -> zinc::unique<Instance>;
} // namespace moon::gpu::native