#pragma once

#include "moon/gpu.h"

#include "common.h"

namespace moon::gpu::dx12 {
class DX12Adapter;
class DX12CommandQueue;
class MOON_API DX12Device : public gpu::Device {
public:
  DX12Device(DX12Adapter &adapter);
  auto allocate_memory(u64 size, MemoryType memory_type, u32 memory_type_bits)
      -> zinc::shared<Memory> override;
  auto get_command_queue(CommandListType type)
      -> zinc::shared<CommandQueue> override;
  [[nodiscard]] auto get_texture_data_pitch_alignment() const -> u32 override;
  auto create_swapchain(WindowHandle window, u32 width, u32 height,
                        u32 frame_count, bool vsync)
      -> zinc::shared<Swapchain> override;
  auto create_command_list(CommandListType type)
      -> zinc::shared<CommandList> override;
  auto create_fence(u64 initial_value) -> zinc::shared<Fence> override;
  auto create_texture(TextureType type, u32 bind_flag, Format format,
                      u32 sample_count, int width, int height, int depth,
                      int mip_levels) -> zinc::shared<Resource> override;
  auto create_buffer(u32 bind_flag, u32 buffer_size)
      -> zinc::shared<Resource> override;
  auto create_sampler(SamplerDescriptor const &desc)
      -> zinc::shared<Resource> override;
  auto create_view(zinc::shared<Resource> const resource,
                   ViewDescriptor const &view_desc)
      -> zinc::shared<View> override;
  auto create_binding_set_layout(zinc::vector<BindKey> const &descs)
      -> zinc::shared<BindingSetLayout> override;
  auto create_binding_set(zinc::shared<BindingSetLayout> const &layout)
      -> zinc::shared<BindingSet> override;
  auto create_render_pass(RenderPassDescriptor const &desc)
      -> zinc::shared<RenderPass> override;
  auto create_frame_buffer(FrameBufferDescriptor const &desc)
      -> zinc::shared<FrameBuffer> override;
  auto create_shader(zinc::vector<u8> const &blob, ShaderBlobType blob_type,
                     ShaderType shader_type) -> zinc::shared<Shader> override;

  auto get_adapter() -> DX12Adapter &;
  auto get_device() -> ComPtr<ID3D12Device>;
};
} // namespace moon::gpu::dx12