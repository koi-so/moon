#pragma once

#include "rook/base.h"

#include "types.h"

#include "binding_set.h"
#include "pipeline.h"
#include "query_heap.h"

#include <EASTL/array.h>

namespace rook::gpu {
class CommandList : public interface {
public:
  ~CommandList() override = default;
  virtual void reset() = 0;
  virtual void close() = 0;
  virtual void bind_pipeline(eastl::shared_ptr<Pipeline> const &pipeline) = 0;
  virtual void
  bind_binding_set(eastl::shared_ptr<BindingSet> const &binding_set) = 0;
  virtual void
  begin_render_pass(eastl::shared_ptr<RenderPass> const &render_pass) = 0;
  virtual void end_render_pass() = 0;
  virtual void begin_event(eastl::string const &name) = 0;
  virtual void end_event() = 0;
  virtual void draw(uint32_t vertex_count, uint32_t instance_count,
                    uint32_t first_vertex, uint32_t first_instance) = 0;
  virtual void draw_indexed(uint32_t index_count, uint32_t instance_count,
                            uint32_t first_index, int32_t vertex_offset,
                            uint32_t first_instance) = 0;
  virtual void draw_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                             uint64_t argument_buffer_offset) = 0;
  virtual void
  draw_indexed_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                        uint64_t argument_buffer_offset) = 0;
  virtual void
  draw_indirect_count(eastl::shared_ptr<Resource> const &argument_buffer,
                      uint64_t argument_buffer_offset,
                      eastl::shared_ptr<Resource> const &count_buffer,
                      uint64_t count_buffer_offset, uint32_t max_draw_count,
                      uint32_t stride) = 0;
  virtual void draw_indexed_indirect_count(
      eastl::shared_ptr<Resource> const &argument_buffer,
      uint64_t argument_buffer_offset,
      eastl::shared_ptr<Resource> const &count_buffer,
      uint64_t count_buffer_offset, uint32_t max_draw_count,
      uint32_t stride) = 0;
  virtual void dispatch(uint32_t thread_group_count_x,
                        uint32_t thread_group_count_y,
                        uint32_t thread_group_count_z) = 0;
  virtual void
  dispatch_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                    uint64_t argument_buffer_offset) = 0;
  virtual void dispatch_mesh(uint32_t thread_group_count_x) = 0;
  virtual void dispatch_rays(RayTracingShaderTables const &shader_tables,
                             uint32_t width, uint32_t height,
                             uint32_t depth) = 0;
  virtual void resource_barrier(
      eastl::vector<ResourceBarrierDescriptor> const &barriers) = 0;
  virtual void
  uav_resource_barrier(eastl::shared_ptr<Resource> const &resource) = 0;
  virtual void set_viewport(float x, float y, float width, float height) = 0;
  virtual void set_scissor_rect(uint32_t left, uint32_t top, uint32_t right,
                                uint32_t bottom) = 0;
  virtual void ia_set_index_buffer(eastl::shared_ptr<Resource> const &buffer,
                                   Format format) = 0;
  virtual void
  ia_set_vertex_buffer(uint32_t slot,
                       eastl::shared_ptr<Resource> const &buffer) = 0;
  virtual void rs_set_shading_rate(
      ShadingRate rate,
      eastl::array<ShadingRateCombiner, 2> const &combiners) = 0;
  virtual void build_bottom_level_as(
      eastl::shared_ptr<Resource> const &src,
      eastl::shared_ptr<Resource> const &dst,
      eastl::shared_ptr<Resource> const &scratch, uint32_t scratch_offset,
      eastl::vector<RaytracingGeometryDescriptor> const &descs,
      BuildAccelerationStructureFlags flags) = 0;
  virtual void
  build_top_level_as(eastl::shared_ptr<Resource> const &src,
                     eastl::shared_ptr<Resource> const &dst,
                     eastl::shared_ptr<Resource> const &scratch,
                     uint32_t scratch_offset,
                     eastl::shared_ptr<Resource> const &instance_data,
                     uint64_t instance_offset, uint32_t instance_count,
                     BuildAccelerationStructureFlags flags) = 0;
  virtual void
  copy_acceleration_structure(eastl::shared_ptr<Resource> const &src,
                              eastl::shared_ptr<Resource> const &dst,
                              CopyAccelerationStructureMode mode) = 0;
  virtual void copy_buffer(eastl::shared_ptr<Resource> const &src,
                           eastl::shared_ptr<Resource> const &dst,
                           uint64_t src_offset, uint64_t dst_offset,
                           eastl::vector<BufferCopyRegion> const &regions) = 0;
  virtual void copy_buffer_to_texture(
      eastl::shared_ptr<Resource> const &src,
      eastl::shared_ptr<Resource> const &dst_tex,
      eastl::vector<BufferToTextureCopyRegion> const &regions) = 0;
  virtual void write_acceleration_structures_properties(
      eastl::vector<eastl::shared_ptr<Resource>> const &acceleration_structures,
      eastl::shared_ptr<QueryHeap> const &query_heap, uint32_t first_query) = 0;
  virtual void
  resolve_query_data(eastl::shared_ptr<QueryHeap> const &query_heap,
                     uint32_t first_query, uint32_t query_count,
                     eastl::shared_ptr<Resource> const &dst_buffer,
                     uint64_t dst_offset) = 0;
};
} // namespace rook::gpu