#pragma once

namespace moon::gpu::dx12 {
auto CreateInstance(InstanceDescriptor const *descriptor = nullptr) -> Instance;
} // namespace moon::gpu::dx12