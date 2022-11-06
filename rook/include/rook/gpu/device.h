#pragma once

#include "rook/base.h"

#include "binding_set.h"
#include "command_queue.h"
#include "frame_buffer.h"
#include "memory.h"
#include "pipeline.h"
#include "query_heap.h"
#include "resource.h"
#include "shader.h"
#include "swapchain.h"
#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/vector.h>

namespace rook::gpu {
struct MemoryBudget {
  uint64_t budget;
  uint64_t usage;
};

class Device : public interface {
public:
  ~Device() override = default;
  virtual auto allocate_memory(uint64_t size, MemoryType memory_type,
                               uint32_t memory_type_bits)
      -> eastl::shared_ptr<Memory> = 0;
  virtual auto get_command_queue(CommandListType type)
      -> eastl::shared_ptr<CommandQueue> = 0;
  [[nodiscard]] virtual auto get_texture_data_pitch_alignment() const
      -> uint32_t = 0;
  virtual auto create_swapchain(WindowHandle window, uint32_t width,
                                uint32_t height, uint32_t frame_count,
                                bool vsync) -> eastl::shared_ptr<Swapchain> = 0;
  virtual auto create_command_list(CommandListType type)
      -> eastl::shared_ptr<CommandList> = 0;
  virtual auto create_fence(uint64_t initial_value)
      -> eastl::shared_ptr<Fence> = 0;
  virtual auto create_texture(TextureType type, uint32_t bind_flag,
                              Format format, uint32_t sample_count, int width,
                              int height, int depth, int mip_levels)
      -> eastl::shared_ptr<Resource> = 0;
  virtual auto create_buffer(uint32_t bind_flag, uint32_t buffer_size)
      -> eastl::shared_ptr<Resource> = 0;
  virtual auto create_sampler(SamplerDescriptor const &desc)
      -> eastl::shared_ptr<Resource> = 0;
  virtual auto create_view(eastl::shared_ptr<Resource> const resource,
                           ViewDescriptor const &view_desc)
      -> eastl::shared_ptr<View> = 0;
  virtual auto create_binding_set_layout(eastl::vector<BindKey> const &descs)
      -> eastl::shared_ptr<BindingSetLayout> = 0;
  virtual auto
  create_binding_set(eastl::shared_ptr<BindingSetLayout> const &layout)
      -> eastl::shared_ptr<BindingSet> = 0;
  virtual auto create_render_pass(RenderPassDescriptor const &desc)
      -> eastl::shared_ptr<RenderPass> = 0;
  virtual auto create_frame_buffer(FrameBufferDescriptor const &desc)
      -> eastl::shared_ptr<FrameBuffer> = 0;
  virtual auto create_shader(eastl::vector<uint8_t> const &blob,
                             ShaderBlobType blob_type, ShaderType shader_type)
      -> eastl::shared_ptr<Shader> = 0;
  virtual auto compile_shader(ShaderDescriptor const &desc)
      -> eastl::shared_ptr<Shader> = 0;
  virtual auto
  create_program(eastl::vector<eastl::shared_ptr<Shader>> const &shaders)
      -> eastl::shared_ptr<Program> = 0;
  virtual auto create_graphics_pipeline(GraphicsPipelineDescriptor const &desc)
      -> eastl::shared_ptr<Pipeline> = 0;
  virtual auto create_compute_pipeline(ComputePipelineDescriptor const &desc)
      -> eastl::shared_ptr<Pipeline> = 0;
  virtual auto
  create_ray_tracing_pipeline(RayTracingPipelineDescriptor const &desc)
      -> eastl::shared_ptr<Pipeline> = 0;
  virtual auto
  create_acceleration_structure(AccelerationStructureType type,
                                eastl::shared_ptr<Resource> const &resource,
                                uint64_t offset)
      -> eastl::shared_ptr<Resource> = 0;
  virtual auto create_query_heap(QueryHeapType type, uint32_t count)
      -> eastl::shared_ptr<QueryHeap> = 0;
  [[nodiscard]] virtual auto is_dxr_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_ray_query_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_variable_rate_shading_supported() const
      -> bool = 0;
  [[nodiscard]] virtual auto is_mesh_shading_supported() const -> bool = 0;
  [[nodiscard]] virtual auto is_draw_indirect_count_supported() const
      -> bool = 0;
  [[nodiscard]] virtual auto is_geometry_shader_supported() const -> bool = 0;
  [[nodiscard]] virtual auto get_shading_rate_image_tile_size() const
      -> uint32_t = 0;
  [[nodiscard]] virtual auto get_memory_budget() const -> MemoryBudget = 0;
  [[nodiscard]] virtual auto get_shader_group_handle_size() const
      -> uint32_t = 0;
  [[nodiscard]] virtual auto get_shader_record_alignment() const
      -> uint32_t = 0;
  [[nodiscard]] virtual auto get_shader_table_alignment() const -> uint32_t = 0;
  [[nodiscard]] virtual auto
  get_blas_prebuild_info(const eastl::vector<RaytracingGeometryDesc> &descs,
                         BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo = 0;
  [[nodiscard]] virtual auto
  get_tlas_prebuild_info(uint32_t instance_count,
                         BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo = 0;
};
} // namespace rook::gpu