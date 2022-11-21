#pragma once

#include "rook/gpu.h"

#include "common.h"

#include <EASTL/map.h>

namespace rook::gpu::dx12 {
class DX12Device;
class DX12Resource;
class DX12Pipeline;

class DX12CommandList : public CommandList {
public:
  DX12CommandList(DX12Device &device, CommandListType type);
  void reset() override;
  void close() override;
  void bind_pipeline(eastl::shared_ptr<Pipeline> const &pipeline) override;
  void
  bind_binding_set(eastl::shared_ptr<BindingSet> const &binding_set) override;
  void
  begin_render_pass(eastl::shared_ptr<RenderPass> const &render_pass) override;
  void end_render_pass() override;
  void begin_event(eastl::string const &name) override;
  void end_event() override;
  void draw(uint32_t vertex_count, uint32_t instance_count,
            uint32_t first_vertex, uint32_t first_instance) override;
  void draw_indexed(uint32_t index_count, uint32_t instance_count,
                    uint32_t first_index, int32_t vertex_offset,
                    uint32_t first_instance) override;
  void draw_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                     uint64_t argument_buffer_offset) override;
  void draw_indexed_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                             uint64_t argument_buffer_offset) override;
  void draw_indirect_count(eastl::shared_ptr<Resource> const &argument_buffer,
                           uint64_t argument_buffer_offset,
                           eastl::shared_ptr<Resource> const &count_buffer,
                           uint64_t count_buffer_offset,
                           uint32_t max_draw_count, uint32_t stride) override;
  void draw_indexed_indirect_count(
      eastl::shared_ptr<Resource> const &argument_buffer,
      uint64_t argument_buffer_offset,
      eastl::shared_ptr<Resource> const &count_buffer,
      uint64_t count_buffer_offset, uint32_t max_draw_count,
      uint32_t stride) override;
  void dispatch(uint32_t thread_group_count_x, uint32_t thread_group_count_y,
                uint32_t thread_group_count_z) override;
  void dispatch_indirect(eastl::shared_ptr<Resource> const &argument_buffer,
                         uint64_t argument_buffer_offset) override;
  void dispatch_mesh(uint32_t thread_group_count_x) override;
  void dispatch_rays(RayTracingShaderTables const &shader_tables,
                     uint32_t width, uint32_t height, uint32_t depth) override;
  void resource_barrier(
      eastl::vector<ResourceBarrierDescriptor> const &barriers) override;
  void
  uav_resource_barrier(eastl::shared_ptr<Resource> const &resource) override;
  void set_viewport(float x, float y, float width, float height) override;
  void set_scissor_rect(uint32_t left, uint32_t top, uint32_t right,
                        uint32_t bottom) override;
  void ia_set_index_buffer(eastl::shared_ptr<Resource> const &buffer,
                           Format format) override;
  void ia_set_vertex_buffer(uint32_t slot,
                            eastl::shared_ptr<Resource> const &buffer) override;
  void rs_set_shading_rate(
      ShadingRate rate,
      eastl::array<ShadingRateCombiner, 2> const &combiners) override;
  void build_bottom_level_as(
      eastl::shared_ptr<Resource> const &src,
      eastl::shared_ptr<Resource> const &dst,
      eastl::shared_ptr<Resource> const &scratch, uint32_t scratch_offset,
      eastl::vector<RaytracingGeometryDescriptor> const &descs,
      BuildAccelerationStructureFlags flags) override;
  void build_top_level_as(eastl::shared_ptr<Resource> const &src,
                          eastl::shared_ptr<Resource> const &dst,
                          eastl::shared_ptr<Resource> const &scratch,
                          uint32_t scratch_offset,
                          eastl::shared_ptr<Resource> const &instance_data,
                          uint64_t instance_offset, uint32_t instance_count,
                          BuildAccelerationStructureFlags flags) override;
  void copy_acceleration_structure(eastl::shared_ptr<Resource> const &src,
                                   eastl::shared_ptr<Resource> const &dst,
                                   CopyAccelerationStructureMode mode) override;
  void copy_buffer(eastl::shared_ptr<Resource> const &src,
                   eastl::shared_ptr<Resource> const &dst, uint64_t src_offset,
                   uint64_t dst_offset,
                   eastl::vector<BufferCopyRegion> const &regions) override;
  void copy_buffer_to_texture(
      eastl::shared_ptr<Resource> const &src,
      eastl::shared_ptr<Resource> const &dst_tex,
      eastl::vector<BufferToTextureCopyRegion> const &regions) override;
  void write_acceleration_structures_properties(
      eastl::vector<eastl::shared_ptr<Resource>> const &acceleration_structures,
      eastl::shared_ptr<QueryHeap> const &query_heap,
      uint32_t first_query) override;
  void resolve_query_data(eastl::shared_ptr<QueryHeap> const &query_heap,
                          uint32_t first_query, uint32_t query_count,
                          eastl::shared_ptr<Resource> const &dst_buffer,
                          uint64_t dst_offset) override;

  auto get_command_list() -> ComPtr<ID3D12GraphicsCommandList>;

private:
  void execute_indirect(D3D12_INDIRECT_ARGUMENT_TYPE type,
                        eastl::shared_ptr<Resource> const &argument_buffer,
                        uint64_t argument_buffer_offset,
                        eastl::shared_ptr<Resource> const &count_buffer,
                        uint64_t count_buffer_offset, uint32_t max_draw_count,
                        uint32_t stride);

  void begin_render_pass_impl(eastl::shared_ptr<RenderPass> const &render_pass,
                              eastl::shared_ptr<FrameBuffer> const &framebuffer,
                              ClearDesc const &clear_desc);
  void om_set_frame_buffer(eastl::shared_ptr<RenderPass> const &render_pass,
                           eastl::shared_ptr<FrameBuffer> const &framebuffer,
                           ClearDesc const &clear_desc);
  void ia_set_vertex_buffer_impl(uint32_t slot,
                                 eastl::shared_ptr<Resource> const &resource,
                                 uint32_t stride);
  void build_acceleration_structure(
      D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS &inputs,
      eastl::shared_ptr<Resource> const &src,
      eastl::shared_ptr<Resource> const &dst,
      eastl::shared_ptr<Resource> const &scratch, uint64_t scratch_offset);

  DX12Device &m_device;
  ComPtr<ID3D12CommandAllocator> m_command_allocator;
  ComPtr<ID3D12GraphicsCommandList> m_command_list;
  ComPtr<ID3D12GraphicsCommandList4> m_command_list4;
  ComPtr<ID3D12GraphicsCommandList5> m_command_list5;
  ComPtr<ID3D12GraphicsCommandList6> m_command_list6;
  bool m_closed = false;
  eastl::vector<ComPtr<ID3D12DescriptorHeap>> m_heaps;
  eastl::shared_ptr<DX12Pipeline> m_state;
  eastl::shared_ptr<BindingSet> m_binding_set;
  eastl::map<uint32_t, eastl::shared_ptr<Resource>> m_lazy_vertex;
  eastl::shared_ptr<View> m_shading_rate_image_view;
};
} // namespace rook::gpu::dx12