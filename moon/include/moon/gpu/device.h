#pragma once

#include "moon/base.h"

#include "command_queue.h"
#include "memory.h"
#include "resource.h"
#include "types.h"

namespace moon::gpu {
struct MemoryBudget {
  u64 budget;
  u64 usage;
};

class Device : public zinc::interface {
public:
  ~Device() override = default;
  virtual auto allocate_memory(u64 size, MemoryType memory_type,
                               u32 memory_type_bits)
      -> zinc::shared<Memory> = 0;
  virtual auto get_command_queue(CommandListType type)
      -> zinc::shared<CommandQueue> = 0;
  [[nodiscard]] virtual auto get_texture_data_pitch_alignment() const
      -> u32 = 0;
  virtual zinc::shared<Swapchain> create_swapchain(WindowHandle window,
                                                   u32 width, u32 height,
                                                   u32 frame_count,
                                                   bool vsync) = 0;
  virtual auto create_command_list(CommandListType type)
      -> zinc::shared<CommandList> = 0;
  virtual auto create_fence(u64 initial_value) -> zinc::shared<Fence> = 0;
  virtual auto create_texture(TextureType type, u32 bind_flag, Format format,
                              u32 sample_count, int width, int height,
                              int depth, int mip_levels)
      -> zinc::shared<Resource> = 0;
  virtual auto create_buffer(u32 bind_flag, u32 buffer_size)
      -> zinc::shared<Resource> = 0;
  virtual auto create_sampler(SamplerDescriptor const &desc)
      -> zinc::shared<Resource> = 0;
  virtual auto create_view(zinc::shared<Resource> const resource,
                           ViewDescriptor const &view_desc)
      -> zinc::shared<View> = 0;
  virtual auto create_binding_set_layout(zinc::vector<BindKey> const &descs)
      -> zinc::shared<BindingSetLayout> = 0;
  virtual zinc::shared<BindingSet>
  create_binding_set(zinc::shared<BindingSetLayout> const &layout) = 0;
  virtual zinc::shared<RenderPass>
  create_render_pass(RenderPassDescriptor const &desc) = 0;
  virtual zinc::shared<Framebuffer>
  create_framebuffer(FramebufferDescriptor const &desc) = 0;
  virtual zinc::shared<Shader> create_shader(zinc::vector<u8> const &blob,
                                             ShaderBlobType blob_type,
                                             ShaderType shader_type) = 0;
  virtual zinc::shared<Shader> compile_shader(ShaderDescriptor const &desc) = 0;
  virtual zinc::shared<Program>
  create_program(zinc::vector<zinc::shared<Shader>> const &shaders) = 0;
  virtual zinc::shared<Pipeline>
  create_graphics_pipeline(GraphicsPipelineDescriptor const &desc) = 0;
  virtual zinc::shared<Pipeline>
  create_compute_pipeline(ComputePipelineDescriptor const &desc) = 0;
  virtual zinc::shared<Pipeline>
  create_ray_tracing_pipeline(RayTracingPipelineDescriptor const &desc) = 0;
  virtual auto
  create_acceleration_structure(AccelerationStructureType type,
                                zinc::shared<Resource> const &resource,
                                u64 offset) -> zinc::shared<Resource> = 0;
  virtual zinc::shared<QueryHeap> create_query_heap(QueryHeapType type,
                                                    u32 count) = 0;
  [[nodiscard]] virtual auto is_dxr_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_ray_query_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_variable_rate_shading_supported() const
      -> bool = 0;
  [[nodiscard]] virtual auto is_mesh_shading_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_draw_indirect_count_supported() const
      -> bool = 0;
  [[nodiscard]] virtual auto is_geometry_shader_supported() const -> bool = 0;
  [[nodiscard]] virtual auto get_shading_rate_image_tile_size() const
      -> u32 = 0;
  [[nodiscard]] virtual auto get_memory_budget() const -> MemoryBudget = 0;
  [[nodiscard]] virtual auto get_shader_group_handle_size() const -> u32 = 0;
  [[nodiscard]] virtual auto get_shader_record_alignment() const -> u32 = 0;
  [[nodiscard]] virtual auto get_shader_table_alignment() const -> u32 = 0;
  [[nodiscard]] virtual auto
  get_blas_prebuild_info(const zinc::vector<RaytracingGeometryDesc> &descs,
                         BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo = 0;
  [[nodiscard]] virtual auto
  get_tlas_prebuild_info(u32 instance_count,
                         BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo = 0;
};
} // namespace moon::gpu