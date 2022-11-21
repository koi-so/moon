#pragma once

#include "rook/gpu.h"

#include "common.h"
#include "cpu_descriptor_pool.h"
#include "gpu_descriptor_pool.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/vector.h>

namespace rook::gpu::dx12 {
class DX12Adapter;
class DX12CommandQueue;
class ROOK_API DX12Device : public gpu::Device {
public:
  DX12Device(DX12Adapter &adapter);
  auto allocate_memory(uint64_t size, MemoryType memory_type,
                       uint32_t memory_type_bits)
      -> eastl::shared_ptr<Memory> override;
  auto get_command_queue(CommandListType type)
      -> eastl::shared_ptr<CommandQueue> override;
  [[nodiscard]] auto get_texture_data_pitch_alignment() const
      -> uint32_t override;
  auto create_swapchain(WindowHandle window, uint32_t width, uint32_t height,
                        uint32_t frame_count, bool vsync)
      -> eastl::shared_ptr<Swapchain> override;
  auto create_command_list(CommandListType type)
      -> eastl::shared_ptr<CommandList> override;
  auto create_fence(uint64_t initial_value)
      -> eastl::shared_ptr<Fence> override;
  auto create_texture(TextureType type, uint32_t bind_flag, Format format,
                      uint32_t sample_count, int width, int height, int depth,
                      int mip_levels) -> eastl::shared_ptr<Resource> override;
  auto create_buffer(uint32_t bind_flag, uint32_t buffer_size)
      -> eastl::shared_ptr<Resource> override;
  auto create_sampler(SamplerDescriptor const &desc)
      -> eastl::shared_ptr<Resource> override;
  auto create_view(eastl::shared_ptr<Resource> const resource,
                   ViewDescriptor const &view_desc)
      -> eastl::shared_ptr<View> override;
  auto create_binding_set_layout(eastl::vector<BindKey> const &descs)
      -> eastl::shared_ptr<BindingSetLayout> override;
  auto create_binding_set(eastl::shared_ptr<BindingSetLayout> const &layout)
      -> eastl::shared_ptr<BindingSet> override;
  auto create_render_pass(RenderPassDescriptor const &desc)
      -> eastl::shared_ptr<RenderPass> override;
  auto create_frame_buffer(FrameBufferDescriptor const &desc)
      -> eastl::shared_ptr<FrameBuffer> override;
  auto create_shader(eastl::vector<uint8_t> const &blob,
                     ShaderBlobType blob_type, ShaderType shader_type)
      -> eastl::shared_ptr<Shader> override;
  auto compile_shader(const ShaderDescriptor &desc)
      -> eastl::shared_ptr<Shader> override;
  auto create_program(const eastl::vector<eastl::shared_ptr<Shader>> &shaders)
      -> eastl::shared_ptr<Program> override;
  auto create_graphics_pipeline(const GraphicsPipelineDescriptor &desc)
      -> eastl::shared_ptr<Pipeline> override;
  auto create_compute_pipeline(const ComputePipelineDescriptor &desc)
      -> eastl::shared_ptr<Pipeline> override;
  auto create_ray_tracing_pipeline(const RayTracingPipelineDescriptor &desc)
      -> eastl::shared_ptr<Pipeline> override;
  auto
  create_acceleration_structure(AccelerationStructureType type,
                                const eastl::shared_ptr<Resource> &resource,
                                uint64_t offset)
      -> eastl::shared_ptr<Resource> override;
  auto create_query_heap(QueryHeapType type, uint32_t count)
      -> eastl::shared_ptr<QueryHeap> override;
  [[nodiscard]] auto is_dxr_supported() const -> bool override;
  [[nodiscard]] auto is_ray_query_supported() const -> bool override;
  [[nodiscard]] auto is_variable_rate_shading_supported() const
      -> bool override;
  [[nodiscard]] auto is_mesh_shading_supported() const -> bool override;
  [[nodiscard]] auto is_draw_indirect_count_supported() const -> bool override;
  [[nodiscard]] auto is_geometry_shader_supported() const -> bool override;
  [[nodiscard]] auto get_shading_rate_image_tile_size() const
      -> uint32_t override;
  [[nodiscard]] auto get_memory_budget() const -> MemoryBudget override;
  [[nodiscard]] auto get_shader_group_handle_size() const -> uint32_t override;
  [[nodiscard]] auto get_shader_record_alignment() const -> uint32_t override;
  [[nodiscard]] auto get_shader_table_alignment() const -> uint32_t override;
  [[nodiscard]] auto get_blas_prebuild_info(
      const eastl::vector<RaytracingGeometryDescriptor> &descs,
      BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo override;
  [[nodiscard]] auto
  get_tlas_prebuild_info(uint32_t instance_count,
                         BuildAccelerationStructureFlags flags) const
      -> RaytracingASPrebuildInfo override;

  auto get_adapter() -> DX12Adapter &;
  auto get_device() -> ComPtr<ID3D12Device>;
  auto get_cpu_descriptor_pool() -> DX12CPUDescriptorPool &;
  auto get_gpu_descriptor_pool() -> DX12GPUDescriptorPool &;
  [[nodiscard]] auto is_render_passes_supported() const -> bool;
  [[nodiscard]] auto is_under_graphics_debugger() const -> bool;
  [[nodiscard]] auto is_create_not_zeroed_available() const -> bool;
  auto get_command_signature(D3D12_INDIRECT_ARGUMENT_TYPE type, uint32_t stride)
      -> ID3D12CommandSignature *;

private:
  [[nodiscard]] auto get_acceleration_structure_prebuild_info(
      const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS &inputs) const
      -> RaytracingASPrebuildInfo;

  DX12Adapter &m_adapter;
  ComPtr<ID3D12Device> m_device;
  ComPtr<ID3D12Device5> m_device5;
  eastl::map<CommandListType, eastl::shared_ptr<DX12CommandQueue>>
      m_command_queues;
  DX12CPUDescriptorPool m_cpu_descriptor_pool;
  DX12GPUDescriptorPool m_gpu_descriptor_pool;
  bool m_is_dxr_supported = false;
  bool m_is_ray_query_supported = false;
  bool m_is_render_passes_supported = false;
  bool m_is_variable_rate_shading_supported = false;
  bool m_is_mesh_shading_supported = false;
  uint32_t m_shading_rate_image_tile_size = 0;
  bool m_is_under_graphics_debugger = false;
  bool m_is_create_not_zeroed_available = false;
  eastl::map<eastl::pair<D3D12_INDIRECT_ARGUMENT_TYPE, uint32_t>,
             ComPtr<ID3D12CommandSignature>>
      m_command_signature_cache;
};

auto ConvertState(ResourceState state) -> D3D12_RESOURCE_STATES;
auto GetHeapType(MemoryType memory_type) -> D3D12_HEAP_TYPE;
auto FillRaytracingGeometryDescriptor(const BufferDescriptor &vertex,
                                      const BufferDescriptor &index,
                                      RaytracingGeometryFlags flags)
    -> D3D12_RAYTRACING_GEOMETRY_DESC;
auto Convert(BuildAccelerationStructureFlags flags)
    -> D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS;
} // namespace rook::gpu::dx12