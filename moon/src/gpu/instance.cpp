#include "instance.h"

#if ZINC_PLATFORM_WINDOWS
#endif

namespace moon::gpu::native {

#if ZINC_PLATFORM_WINDOWS
namespace dx12 {
auto CreateBackend(Instance *instance) -> Backend *;
};
#endif

Instance::Instance(InstanceDescriptor const *descriptor) {
  m_connected_backends.reset(new bool[MAX_BACKENDS]);
}

auto Instance::create_surface(SurfaceDescriptor const *descriptor)
    -> zinc::unique<ISurface> {
  return nullptr;
}

auto Instance::request_adapter(RequestAdapterOptions const *options,
                               RequestAdapterCallback callback, void *userdata)
    -> zinc::unique<IAdapter> {
  return nullptr;
}

auto Instance::ensure_backend(BackendType type) -> void {
  if (m_connected_backends[(u32)type]) {
    return;
  }

  switch (type) {
  case BackendType::Null:
    break;
  case BackendType::WebGPU:
    break;
  case BackendType::D3D11:
    break;
  case BackendType::D3D12:
    connect_backend(dx12::CreateBackend(this), type);
    break;
  case BackendType::Metal:
    break;
  case BackendType::Vulkan:
    break;
  case BackendType::OpenGL:
    break;
  case BackendType::OpenGLES:
    break;
  }
  m_connected_backends[(u32)type] = true;
}

void Instance::connect_backend(Backend *backend, BackendType expected) {
  if (!backend) {
    return;
  }

  ZINC_ASSERT(backend->get_type() != expected);
  ZINC_ASSERT(backend->get_instance() == this);
  m_backends.push_back(zinc::unique<Backend>(backend));
}

auto CreateInstance(InstanceDescriptor const *descriptor)
    -> zinc::unique<Instance> {
  return zinc::make_unique<Instance>(descriptor);
}

} // namespace moon::gpu::native