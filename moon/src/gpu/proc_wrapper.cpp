
#include "moon/gpu/types.h"

namespace moon::gpu {
static GPUProcTable g_set_procs;
static GPUProcTable g_empty_proc;

void SetWebGPUProcs(const GPUProcTable *procs) {
  if (procs) {
    g_set_procs = *procs;
  } else {
    g_set_procs = g_empty_proc;
  }
}

extern "C" {
auto wgpuCreateInstance(WGPUInstanceDescriptor const *descriptor)
    -> WGPUInstance {
  return g_set_procs.create_instance(descriptor);
}
auto wgpuGetProcAddress(WGPUDevice device, char const *procName) -> WGPUProc {
  return g_set_procs.get_proc_address(device, procName);
}

auto wgpuAdapterCreateDevice(WGPUAdapter adapter,
                             WGPUDeviceDescriptor const *descriptor)
    -> WGPUDevice {
  return g_set_procs.adapter_create_device(adapter, descriptor);
}
auto wgpuAdapterEnumerateFeatures(WGPUAdapter adapter,
                                  WGPUFeatureName *features) -> size_t {
  return g_set_procs.adapter_enumerate_features(adapter, features);
}
auto wgpuAdapterGetLimits(WGPUAdapter adapter, WGPUSupportedLimits *limits)
    -> bool {
  return g_set_procs.adapter_get_limits(adapter, limits);
}
void wgpuAdapterGetProperties(WGPUAdapter adapter,
                              WGPUAdapterProperties *properties) {
  g_set_procs.adapter_get_properties(adapter, properties);
}
auto wgpuAdapterHasFeature(WGPUAdapter adapter, WGPUFeatureName feature)
    -> bool {
  return g_set_procs.adapter_has_feature(adapter, feature);
}
void wgpuAdapterRequestDevice(WGPUAdapter adapter,
                              WGPUDeviceDescriptor const *descriptor,
                              WGPURequestDeviceCallback callback,
                              void *userdata) {
  g_set_procs.adapter_request_device(adapter, descriptor, callback, userdata);
}
void wgpuAdapterReference(WGPUAdapter adapter) {
  g_set_procs.adapter_reference(adapter);
}
void wgpuAdapterRelease(WGPUAdapter adapter) {
  g_set_procs.adapter_release(adapter);
}

void wgpuBindGroupSetLabel(WGPUBindGroup bindGroup, char const *label) {
  g_set_procs.bind_group_set_label(bindGroup, label);
}
void wgpuBindGroupReference(WGPUBindGroup bindGroup) {
  g_set_procs.bind_group_reference(bindGroup);
}
void wgpuBindGroupRelease(WGPUBindGroup bindGroup) {
  g_set_procs.bind_group_release(bindGroup);
}

void wgpuBindGroupLayoutSetLabel(WGPUBindGroupLayout bindGroupLayout,
                                 char const *label) {
  g_set_procs.bind_group_layout_set_label(bindGroupLayout, label);
}
void wgpuBindGroupLayoutReference(WGPUBindGroupLayout bindGroupLayout) {
  g_set_procs.bind_group_layout_reference(bindGroupLayout);
}
void wgpuBindGroupLayoutRelease(WGPUBindGroupLayout bindGroupLayout) {
  g_set_procs.bind_group_layout_release(bindGroupLayout);
}

void wgpuBufferDestroy(WGPUBuffer buffer) {
  g_set_procs.buffer_destroy(buffer);
}
auto wgpuBufferGetConstMappedRange(WGPUBuffer buffer, size_t offset,
                                   size_t size) -> void const * {
  return g_set_procs.buffer_get_const_mapped_range(buffer, offset, size);
}
auto wgpuBufferGetMappedRange(WGPUBuffer buffer, size_t offset, size_t size)
    -> void * {
  return g_set_procs.buffer_get_mapped_range(buffer, offset, size);
}
auto wgpuBufferGetSize(WGPUBuffer buffer) -> uint64_t {
  return g_set_procs.buffer_get_size(buffer);
}
auto wgpuBufferGetUsage(WGPUBuffer buffer) -> WGPUBufferUsage {
  return g_set_procs.buffer_get_usage(buffer);
}
void wgpuBufferMapAsync(WGPUBuffer buffer, WGPUMapModeFlags mode, size_t offset,
                        size_t size, WGPUBufferMapCallback callback,
                        void *userdata) {
  g_set_procs.buffer_map_async(buffer, mode, offset, size, callback, userdata);
}
void wgpuBufferSetLabel(WGPUBuffer buffer, char const *label) {
  g_set_procs.buffer_set_label(buffer, label);
}
void wgpuBufferUnmap(WGPUBuffer buffer) { g_set_procs.buffer_unmap(buffer); }
void wgpuBufferReference(WGPUBuffer buffer) {
  g_set_procs.buffer_reference(buffer);
}
void wgpuBufferRelease(WGPUBuffer buffer) {
  g_set_procs.buffer_release(buffer);
}

void wgpuCommandBufferSetLabel(WGPUCommandBuffer commandBuffer,
                               char const *label) {
  g_set_procs.command_buffer_set_label(commandBuffer, label);
}
void wgpuCommandBufferReference(WGPUCommandBuffer commandBuffer) {
  g_set_procs.command_buffer_reference(commandBuffer);
}
void wgpuCommandBufferRelease(WGPUCommandBuffer commandBuffer) {
  g_set_procs.command_buffer_release(commandBuffer);
}

auto wgpuCommandEncoderBeginComputePass(
    WGPUCommandEncoder commandEncoder,
    WGPUComputePassDescriptor const *descriptor) -> WGPUComputePassEncoder {
  return g_set_procs.command_encoder_begin_compute_pass(commandEncoder,
                                                        descriptor);
}
auto wgpuCommandEncoderBeginRenderPass(
    WGPUCommandEncoder commandEncoder,
    WGPURenderPassDescriptor const *descriptor) -> WGPURenderPassEncoder {
  return g_set_procs.command_encoder_begin_render_pass(commandEncoder,
                                                       descriptor);
}
void wgpuCommandEncoderClearBuffer(WGPUCommandEncoder commandEncoder,
                                   WGPUBuffer buffer, uint64_t offset,
                                   uint64_t size) {
  g_set_procs.command_encoder_clear_buffer(commandEncoder, buffer, offset,
                                           size);
}
void wgpuCommandEncoderCopyBufferToBuffer(
    WGPUCommandEncoder commandEncoder, WGPUBuffer source, uint64_t sourceOffset,
    WGPUBuffer destination, uint64_t destinationOffset, uint64_t size) {
  g_set_procs.command_encoder_copy_buffer_to_buffer(commandEncoder, source,
                                                    sourceOffset, destination,
                                                    destinationOffset, size);
}
void wgpuCommandEncoderCopyBufferToTexture(
    WGPUCommandEncoder commandEncoder, WGPUImageCopyBuffer const *source,
    WGPUImageCopyTexture const *destination, WGPUExtent3D const *copySize) {
  g_set_procs.command_encoder_copy_buffer_to_texture(commandEncoder, source,
                                                     destination, copySize);
}
void wgpuCommandEncoderCopyTextureToBuffer(
    WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const *source,
    WGPUImageCopyBuffer const *destination, WGPUExtent3D const *copySize) {
  g_set_procs.command_encoder_copy_texture_to_buffer(commandEncoder, source,
                                                     destination, copySize);
}
void wgpuCommandEncoderCopyTextureToTexture(
    WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const *source,
    WGPUImageCopyTexture const *destination, WGPUExtent3D const *copySize) {
  g_set_procs.command_encoder_copy_texture_to_texture(commandEncoder, source,
                                                      destination, copySize);
}
void wgpuCommandEncoderCopyTextureToTextureInternal(
    WGPUCommandEncoder commandEncoder, WGPUImageCopyTexture const *source,
    WGPUImageCopyTexture const *destination, WGPUExtent3D const *copySize) {
  g_set_procs.command_encoder_copy_texture_to_texture_internal(
      commandEncoder, source, destination, copySize);
}
auto wgpuCommandEncoderFinish(WGPUCommandEncoder commandEncoder,
                              WGPUCommandBufferDescriptor const *descriptor)
    -> WGPUCommandBuffer {
  return g_set_procs.command_encoder_finish(commandEncoder, descriptor);
}
void wgpuCommandEncoderInjectValidationError(WGPUCommandEncoder commandEncoder,
                                             char const *message) {
  g_set_procs.command_encoder_inject_validation_error(commandEncoder, message);
}
void wgpuCommandEncoderInsertDebugMarker(WGPUCommandEncoder commandEncoder,
                                         char const *markerLabel) {
  g_set_procs.command_encoder_insert_debug_marker(commandEncoder, markerLabel);
}
void wgpuCommandEncoderPopDebugGroup(WGPUCommandEncoder commandEncoder) {
  g_set_procs.command_encoder_pop_debug_group(commandEncoder);
}
void wgpuCommandEncoderPushDebugGroup(WGPUCommandEncoder commandEncoder,
                                      char const *groupLabel) {
  g_set_procs.command_encoder_push_debug_group(commandEncoder, groupLabel);
}
void wgpuCommandEncoderResolveQuerySet(WGPUCommandEncoder commandEncoder,
                                       WGPUQuerySet querySet,
                                       uint32_t firstQuery, uint32_t queryCount,
                                       WGPUBuffer destination,
                                       uint64_t destinationOffset) {
  g_set_procs.command_encoder_resolve_query_set(commandEncoder, querySet,
                                                firstQuery, queryCount,
                                                destination, destinationOffset);
}
void wgpuCommandEncoderSetLabel(WGPUCommandEncoder commandEncoder,
                                char const *label) {
  g_set_procs.command_encoder_set_label(commandEncoder, label);
}
void wgpuCommandEncoderWriteBuffer(WGPUCommandEncoder commandEncoder,
                                   WGPUBuffer buffer, uint64_t bufferOffset,
                                   uint8_t const *data, uint64_t size) {
  g_set_procs.command_encoder_write_buffer(commandEncoder, buffer, bufferOffset,
                                           data, size);
}
void wgpuCommandEncoderWriteTimestamp(WGPUCommandEncoder commandEncoder,
                                      WGPUQuerySet querySet,
                                      uint32_t queryIndex) {
  g_set_procs.command_encoder_write_timestamp(commandEncoder, querySet,
                                              queryIndex);
}
void wgpuCommandEncoderReference(WGPUCommandEncoder commandEncoder) {
  g_set_procs.command_encoder_reference(commandEncoder);
}
void wgpuCommandEncoderRelease(WGPUCommandEncoder commandEncoder) {
  g_set_procs.command_encoder_release(commandEncoder);
}

void wgpuComputePassEncoderDispatch(WGPUComputePassEncoder computePassEncoder,
                                    uint32_t workgroupCountX,
                                    uint32_t workgroupCountY,
                                    uint32_t workgroupCountZ) {
  g_set_procs.compute_pass_encoder_dispatch(computePassEncoder, workgroupCountX,
                                            workgroupCountY, workgroupCountZ);
}
void wgpuComputePassEncoderDispatchIndirect(
    WGPUComputePassEncoder computePassEncoder, WGPUBuffer indirectBuffer,
    uint64_t indirectOffset) {
  g_set_procs.compute_pass_encoder_dispatch_indirect(
      computePassEncoder, indirectBuffer, indirectOffset);
}
void wgpuComputePassEncoderDispatchWorkgroups(
    WGPUComputePassEncoder computePassEncoder, uint32_t workgroupCountX,
    uint32_t workgroupCountY, uint32_t workgroupCountZ) {
  g_set_procs.compute_pass_encoder_dispatch_workgroups(
      computePassEncoder, workgroupCountX, workgroupCountY, workgroupCountZ);
}
void wgpuComputePassEncoderDispatchWorkgroupsIndirect(
    WGPUComputePassEncoder computePassEncoder, WGPUBuffer indirectBuffer,
    uint64_t indirectOffset) {
  g_set_procs.compute_pass_encoder_dispatch_workgroups_indirect(
      computePassEncoder, indirectBuffer, indirectOffset);
}
void wgpuComputePassEncoderEnd(WGPUComputePassEncoder computePassEncoder) {
  g_set_procs.compute_pass_encoder_end(computePassEncoder);
}
void wgpuComputePassEncoderEndPass(WGPUComputePassEncoder computePassEncoder) {
  g_set_procs.compute_pass_encoder_end_pass(computePassEncoder);
}
void wgpuComputePassEncoderInsertDebugMarker(
    WGPUComputePassEncoder computePassEncoder, char const *markerLabel) {
  g_set_procs.compute_pass_encoder_insert_debug_marker(computePassEncoder,
                                                       markerLabel);
}
void wgpuComputePassEncoderPopDebugGroup(
    WGPUComputePassEncoder computePassEncoder) {
  g_set_procs.compute_pass_encoder_pop_debug_group(computePassEncoder);
}
void wgpuComputePassEncoderPushDebugGroup(
    WGPUComputePassEncoder computePassEncoder, char const *groupLabel) {
  g_set_procs.compute_pass_encoder_push_debug_group(computePassEncoder,
                                                    groupLabel);
}
void wgpuComputePassEncoderSetBindGroup(
    WGPUComputePassEncoder computePassEncoder, uint32_t groupIndex,
    WGPUBindGroup group, uint32_t dynamicOffsetCount,
    uint32_t const *dynamicOffsets) {
  g_set_procs.compute_pass_encoder_set_bind_group(
      computePassEncoder, groupIndex, group, dynamicOffsetCount,
      dynamicOffsets);
}
void wgpuComputePassEncoderSetLabel(WGPUComputePassEncoder computePassEncoder,
                                    char const *label) {
  g_set_procs.compute_pass_encoder_set_label(computePassEncoder, label);
}
void wgpuComputePassEncoderSetPipeline(
    WGPUComputePassEncoder computePassEncoder, WGPUComputePipeline pipeline) {
  g_set_procs.compute_pass_encoder_set_pipeline(computePassEncoder, pipeline);
}
void wgpuComputePassEncoderWriteTimestamp(
    WGPUComputePassEncoder computePassEncoder, WGPUQuerySet querySet,
    uint32_t queryIndex) {
  g_set_procs.compute_pass_encoder_write_timestamp(computePassEncoder, querySet,
                                                   queryIndex);
}
void wgpuComputePassEncoderReference(
    WGPUComputePassEncoder computePassEncoder) {
  g_set_procs.compute_pass_encoder_reference(computePassEncoder);
}
void wgpuComputePassEncoderRelease(WGPUComputePassEncoder computePassEncoder) {
  g_set_procs.compute_pass_encoder_release(computePassEncoder);
}

auto wgpuComputePipelineGetBindGroupLayout(WGPUComputePipeline computePipeline,
                                           uint32_t groupIndex)
    -> WGPUBindGroupLayout {
  return g_set_procs.compute_pipeline_get_bind_group_layout(computePipeline,
                                                            groupIndex);
}
void wgpuComputePipelineSetLabel(WGPUComputePipeline computePipeline,
                                 char const *label) {
  g_set_procs.compute_pipeline_set_label(computePipeline, label);
}
void wgpuComputePipelineReference(WGPUComputePipeline computePipeline) {
  g_set_procs.compute_pipeline_reference(computePipeline);
}
void wgpuComputePipelineRelease(WGPUComputePipeline computePipeline) {
  g_set_procs.compute_pipeline_release(computePipeline);
}

auto wgpuDeviceCreateBindGroup(WGPUDevice device,
                               WGPUBindGroupDescriptor const *descriptor)
    -> WGPUBindGroup {
  return g_set_procs.device_create_bind_group(device, descriptor);
}
auto wgpuDeviceCreateBindGroupLayout(
    WGPUDevice device, WGPUBindGroupLayoutDescriptor const *descriptor)
    -> WGPUBindGroupLayout {
  return g_set_procs.device_create_bind_group_layout(device, descriptor);
}
auto wgpuDeviceCreateBuffer(WGPUDevice device,
                            WGPUBufferDescriptor const *descriptor)
    -> WGPUBuffer {
  return g_set_procs.device_create_buffer(device, descriptor);
}
auto wgpuDeviceCreateCommandEncoder(
    WGPUDevice device, WGPUCommandEncoderDescriptor const *descriptor)
    -> WGPUCommandEncoder {
  return g_set_procs.device_create_command_encoder(device, descriptor);
}
auto wgpuDeviceCreateComputePipeline(
    WGPUDevice device, WGPUComputePipelineDescriptor const *descriptor)
    -> WGPUComputePipeline {
  return g_set_procs.device_create_compute_pipeline(device, descriptor);
}
void wgpuDeviceCreateComputePipelineAsync(
    WGPUDevice device, WGPUComputePipelineDescriptor const *descriptor,
    WGPUCreateComputePipelineAsyncCallback callback, void *userdata) {
  g_set_procs.device_create_compute_pipeline_async(device, descriptor, callback,
                                                   userdata);
}
auto wgpuDeviceCreateErrorBuffer(WGPUDevice device) -> WGPUBuffer {
  return g_set_procs.device_create_error_buffer(device);
}
auto wgpuDeviceCreateErrorExternalTexture(WGPUDevice device)
    -> WGPUExternalTexture {
  return g_set_procs.device_create_error_external_texture(device);
}
auto wgpuDeviceCreateErrorTexture(WGPUDevice device,
                                  WGPUTextureDescriptor const *descriptor)
    -> WGPUTexture {
  return g_set_procs.device_create_error_texture(device, descriptor);
}
auto wgpuDeviceCreateExternalTexture(
    WGPUDevice device,
    WGPUExternalTextureDescriptor const *externalTextureDescriptor)
    -> WGPUExternalTexture {
  return g_set_procs.device_create_external_texture(device,
                                                    externalTextureDescriptor);
}
auto wgpuDeviceCreatePipelineLayout(
    WGPUDevice device, WGPUPipelineLayoutDescriptor const *descriptor)
    -> WGPUPipelineLayout {
  return g_set_procs.device_create_pipeline_layout(device, descriptor);
}
auto wgpuDeviceCreateQuerySet(WGPUDevice device,
                              WGPUQuerySetDescriptor const *descriptor)
    -> WGPUQuerySet {
  return g_set_procs.device_create_query_set(device, descriptor);
}
auto wgpuDeviceCreateRenderBundleEncoder(
    WGPUDevice device, WGPURenderBundleEncoderDescriptor const *descriptor)
    -> WGPURenderBundleEncoder {
  return g_set_procs.device_create_render_bundle_encoder(device, descriptor);
}
auto wgpuDeviceCreateRenderPipeline(
    WGPUDevice device, WGPURenderPipelineDescriptor const *descriptor)
    -> WGPURenderPipeline {
  return g_set_procs.device_create_render_pipeline(device, descriptor);
}
void wgpuDeviceCreateRenderPipelineAsync(
    WGPUDevice device, WGPURenderPipelineDescriptor const *descriptor,
    WGPUCreateRenderPipelineAsyncCallback callback, void *userdata) {
  g_set_procs.device_create_render_pipeline_async(device, descriptor, callback,
                                                  userdata);
}
auto wgpuDeviceCreateSampler(WGPUDevice device,
                             WGPUSamplerDescriptor const *descriptor)
    -> WGPUSampler {
  return g_set_procs.device_create_sampler(device, descriptor);
}
auto wgpuDeviceCreateShaderModule(WGPUDevice device,
                                  WGPUShaderModuleDescriptor const *descriptor)
    -> WGPUShaderModule {
  return g_set_procs.device_create_shader_module(device, descriptor);
}
auto wgpuDeviceCreateSwapChain(WGPUDevice device, WGPUSurface surface,
                               WGPUSwapChainDescriptor const *descriptor)
    -> WGPUSwapChain {
  return g_set_procs.device_create_swap_chain(device, surface, descriptor);
}
auto wgpuDeviceCreateTexture(WGPUDevice device,
                             WGPUTextureDescriptor const *descriptor)
    -> WGPUTexture {
  return g_set_procs.device_create_texture(device, descriptor);
}
void wgpuDeviceDestroy(WGPUDevice device) {
  g_set_procs.device_destroy(device);
}
auto wgpuDeviceEnumerateFeatures(WGPUDevice device, WGPUFeatureName *features)
    -> size_t {
  return g_set_procs.device_enumerate_features(device, features);
}
void wgpuDeviceForceLoss(WGPUDevice device, WGPUDeviceLostReason type,
                         char const *message) {
  g_set_procs.device_force_loss(device, type, message);
}
auto wgpuDeviceGetAdapter(WGPUDevice device) -> WGPUAdapter {
  return g_set_procs.device_get_adapter(device);
}
auto wgpuDeviceGetLimits(WGPUDevice device, WGPUSupportedLimits *limits)
    -> bool {
  return g_set_procs.device_get_limits(device, limits);
}
auto wgpuDeviceGetQueue(WGPUDevice device) -> WGPUQueue {
  return g_set_procs.device_get_queue(device);
}
auto wgpuDeviceHasFeature(WGPUDevice device, WGPUFeatureName feature) -> bool {
  return g_set_procs.device_has_feature(device, feature);
}
void wgpuDeviceInjectError(WGPUDevice device, WGPUErrorType type,
                           char const *message) {
  g_set_procs.device_inject_error(device, type, message);
}
auto wgpuDevicePopErrorScope(WGPUDevice device, WGPUErrorCallback callback,
                             void *userdata) -> bool {
  return g_set_procs.device_pop_error_scope(device, callback, userdata);
}
void wgpuDevicePushErrorScope(WGPUDevice device, WGPUErrorFilter filter) {
  g_set_procs.device_push_error_scope(device, filter);
}
void wgpuDeviceSetDeviceLostCallback(WGPUDevice device,
                                     WGPUDeviceLostCallback callback,
                                     void *userdata) {
  g_set_procs.device_set_device_lost_callback(device, callback, userdata);
}
void wgpuDeviceSetLabel(WGPUDevice device, char const *label) {
  g_set_procs.device_set_label(device, label);
}
void wgpuDeviceSetLoggingCallback(WGPUDevice device,
                                  WGPULoggingCallback callback,
                                  void *userdata) {
  g_set_procs.device_set_logging_callback(device, callback, userdata);
}
void wgpuDeviceSetUncapturedErrorCallback(WGPUDevice device,
                                          WGPUErrorCallback callback,
                                          void *userdata) {
  g_set_procs.device_set_uncaptured_error_callback(device, callback, userdata);
}
void wgpuDeviceTick(WGPUDevice device) { g_set_procs.device_tick(device); }
void wgpuDeviceReference(WGPUDevice device) {
  g_set_procs.device_reference(device);
}
void wgpuDeviceRelease(WGPUDevice device) {
  g_set_procs.device_release(device);
}

void wgpuExternalTextureDestroy(WGPUExternalTexture externalTexture) {
  g_set_procs.external_texture_destroy(externalTexture);
}
void wgpuExternalTextureSetLabel(WGPUExternalTexture externalTexture,
                                 char const *label) {
  g_set_procs.external_texture_set_label(externalTexture, label);
}
void wgpuExternalTextureReference(WGPUExternalTexture externalTexture) {
  g_set_procs.external_texture_reference(externalTexture);
}
void wgpuExternalTextureRelease(WGPUExternalTexture externalTexture) {
  g_set_procs.external_texture_release(externalTexture);
}

auto wgpuInstanceCreateSurface(WGPUInstance instance,
                               WGPUSurfaceDescriptor const *descriptor)
    -> WGPUSurface {
  return g_set_procs.instance_create_surface(instance, descriptor);
}
void wgpuInstanceRequestAdapter(WGPUInstance instance,
                                WGPURequestAdapterOptions const *options,
                                WGPURequestAdapterCallback callback,
                                void *userdata) {
  g_set_procs.instance_request_adapter(instance, options, callback, userdata);
}
void wgpuInstanceReference(WGPUInstance instance) {
  g_set_procs.instance_reference(instance);
}
void wgpuInstanceRelease(WGPUInstance instance) {
  g_set_procs.instance_release(instance);
}

void wgpuPipelineLayoutSetLabel(WGPUPipelineLayout pipelineLayout,
                                char const *label) {
  g_set_procs.pipeline_layout_set_label(pipelineLayout, label);
}
void wgpuPipelineLayoutReference(WGPUPipelineLayout pipelineLayout) {
  g_set_procs.pipeline_layout_reference(pipelineLayout);
}
void wgpuPipelineLayoutRelease(WGPUPipelineLayout pipelineLayout) {
  g_set_procs.pipeline_layout_release(pipelineLayout);
}

void wgpuQuerySetDestroy(WGPUQuerySet querySet) {
  g_set_procs.query_set_destroy(querySet);
}
auto wgpuQuerySetGetCount(WGPUQuerySet querySet) -> uint32_t {
  return g_set_procs.query_set_get_count(querySet);
}
auto wgpuQuerySetGetType(WGPUQuerySet querySet) -> WGPUQueryType {
  return g_set_procs.query_set_get_type(querySet);
}
void wgpuQuerySetSetLabel(WGPUQuerySet querySet, char const *label) {
  g_set_procs.query_set_set_label(querySet, label);
}
void wgpuQuerySetReference(WGPUQuerySet querySet) {
  g_set_procs.query_set_reference(querySet);
}
void wgpuQuerySetRelease(WGPUQuerySet querySet) {
  g_set_procs.query_set_release(querySet);
}

void wgpuQueueCopyTextureForBrowser(
    WGPUQueue queue, WGPUImageCopyTexture const *source,
    WGPUImageCopyTexture const *destination, WGPUExtent3D const *copySize,
    WGPUCopyTextureForBrowserOptions const *options) {
  g_set_procs.queue_copy_texture_for_browser(queue, source, destination,
                                             copySize, options);
}
void wgpuQueueOnSubmittedWorkDone(WGPUQueue queue, uint64_t signalValue,
                                  WGPUQueueWorkDoneCallback callback,
                                  void *userdata) {
  g_set_procs.queue_on_submitted_work_done(queue, signalValue, callback,
                                           userdata);
}
void wgpuQueueSetLabel(WGPUQueue queue, char const *label) {
  g_set_procs.queue_set_label(queue, label);
}
void wgpuQueueSubmit(WGPUQueue queue, uint32_t commandCount,
                     WGPUCommandBuffer const *commands) {
  g_set_procs.queue_submit(queue, commandCount, commands);
}
void wgpuQueueWriteBuffer(WGPUQueue queue, WGPUBuffer buffer,
                          uint64_t bufferOffset, void const *data,
                          size_t size) {
  g_set_procs.queue_write_buffer(queue, buffer, bufferOffset, data, size);
}
void wgpuQueueWriteTexture(WGPUQueue queue,
                           WGPUImageCopyTexture const *destination,
                           void const *data, size_t dataSize,
                           WGPUTextureDataLayout const *dataLayout,
                           WGPUExtent3D const *writeSize) {
  g_set_procs.queue_write_texture(queue, destination, data, dataSize,
                                  dataLayout, writeSize);
}
void wgpuQueueReference(WGPUQueue queue) { g_set_procs.queue_reference(queue); }
void wgpuQueueRelease(WGPUQueue queue) { g_set_procs.queue_release(queue); }

void wgpuRenderBundleReference(WGPURenderBundle renderBundle) {
  g_set_procs.render_bundle_reference(renderBundle);
}
void wgpuRenderBundleRelease(WGPURenderBundle renderBundle) {
  g_set_procs.render_bundle_release(renderBundle);
}

void wgpuRenderBundleEncoderDraw(WGPURenderBundleEncoder renderBundleEncoder,
                                 uint32_t vertexCount, uint32_t instanceCount,
                                 uint32_t firstVertex, uint32_t firstInstance) {
  g_set_procs.render_bundle_encoder_draw(renderBundleEncoder, vertexCount,
                                         instanceCount, firstVertex,
                                         firstInstance);
}
void wgpuRenderBundleEncoderDrawIndexed(
    WGPURenderBundleEncoder renderBundleEncoder, uint32_t indexCount,
    uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex,
    uint32_t firstInstance) {
  g_set_procs.render_bundle_encoder_draw_indexed(
      renderBundleEncoder, indexCount, instanceCount, firstIndex, baseVertex,
      firstInstance);
}
void wgpuRenderBundleEncoderDrawIndexedIndirect(
    WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer,
    uint64_t indirectOffset) {
  g_set_procs.render_bundle_encoder_draw_indexed_indirect(
      renderBundleEncoder, indirectBuffer, indirectOffset);
}
void wgpuRenderBundleEncoderDrawIndirect(
    WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer indirectBuffer,
    uint64_t indirectOffset) {
  g_set_procs.render_bundle_encoder_draw_indirect(
      renderBundleEncoder, indirectBuffer, indirectOffset);
}
auto wgpuRenderBundleEncoderFinish(WGPURenderBundleEncoder renderBundleEncoder,
                                   WGPURenderBundleDescriptor const *descriptor)
    -> WGPURenderBundle {
  return g_set_procs.render_bundle_encoder_finish(renderBundleEncoder,
                                                  descriptor);
}
void wgpuRenderBundleEncoderInsertDebugMarker(
    WGPURenderBundleEncoder renderBundleEncoder, char const *markerLabel) {
  g_set_procs.render_bundle_encoder_insert_debug_marker(renderBundleEncoder,
                                                        markerLabel);
}
void wgpuRenderBundleEncoderPopDebugGroup(
    WGPURenderBundleEncoder renderBundleEncoder) {
  g_set_procs.render_bundle_encoder_pop_debug_group(renderBundleEncoder);
}
void wgpuRenderBundleEncoderPushDebugGroup(
    WGPURenderBundleEncoder renderBundleEncoder, char const *groupLabel) {
  g_set_procs.render_bundle_encoder_push_debug_group(renderBundleEncoder,
                                                     groupLabel);
}
void wgpuRenderBundleEncoderSetBindGroup(
    WGPURenderBundleEncoder renderBundleEncoder, uint32_t groupIndex,
    WGPUBindGroup group, uint32_t dynamicOffsetCount,
    uint32_t const *dynamicOffsets) {
  g_set_procs.render_bundle_encoder_set_bind_group(
      renderBundleEncoder, groupIndex, group, dynamicOffsetCount,
      dynamicOffsets);
}
void wgpuRenderBundleEncoderSetIndexBuffer(
    WGPURenderBundleEncoder renderBundleEncoder, WGPUBuffer buffer,
    WGPUIndexFormat format, uint64_t offset, uint64_t size) {
  g_set_procs.render_bundle_encoder_set_index_buffer(
      renderBundleEncoder, buffer, format, offset, size);
}
void wgpuRenderBundleEncoderSetLabel(
    WGPURenderBundleEncoder renderBundleEncoder, char const *label) {
  g_set_procs.render_bundle_encoder_set_label(renderBundleEncoder, label);
}
void wgpuRenderBundleEncoderSetPipeline(
    WGPURenderBundleEncoder renderBundleEncoder, WGPURenderPipeline pipeline) {
  g_set_procs.render_bundle_encoder_set_pipeline(renderBundleEncoder, pipeline);
}
void wgpuRenderBundleEncoderSetVertexBuffer(
    WGPURenderBundleEncoder renderBundleEncoder, uint32_t slot,
    WGPUBuffer buffer, uint64_t offset, uint64_t size) {
  g_set_procs.render_bundle_encoder_set_vertex_buffer(renderBundleEncoder, slot,
                                                      buffer, offset, size);
}
void wgpuRenderBundleEncoderReference(
    WGPURenderBundleEncoder renderBundleEncoder) {
  g_set_procs.render_bundle_encoder_reference(renderBundleEncoder);
}
void wgpuRenderBundleEncoderRelease(
    WGPURenderBundleEncoder renderBundleEncoder) {
  g_set_procs.render_bundle_encoder_release(renderBundleEncoder);
}

void wgpuRenderPassEncoderBeginOcclusionQuery(
    WGPURenderPassEncoder renderPassEncoder, uint32_t queryIndex) {
  g_set_procs.render_pass_encoder_begin_occlusion_query(renderPassEncoder,
                                                        queryIndex);
}
void wgpuRenderPassEncoderDraw(WGPURenderPassEncoder renderPassEncoder,
                               uint32_t vertexCount, uint32_t instanceCount,
                               uint32_t firstVertex, uint32_t firstInstance) {
  g_set_procs.render_pass_encoder_draw(renderPassEncoder, vertexCount,
                                       instanceCount, firstVertex,
                                       firstInstance);
}
void wgpuRenderPassEncoderDrawIndexed(WGPURenderPassEncoder renderPassEncoder,
                                      uint32_t indexCount,
                                      uint32_t instanceCount,
                                      uint32_t firstIndex, int32_t baseVertex,
                                      uint32_t firstInstance) {
  g_set_procs.render_pass_encoder_draw_indexed(renderPassEncoder, indexCount,
                                               instanceCount, firstIndex,
                                               baseVertex, firstInstance);
}
void wgpuRenderPassEncoderDrawIndexedIndirect(
    WGPURenderPassEncoder renderPassEncoder, WGPUBuffer indirectBuffer,
    uint64_t indirectOffset) {
  g_set_procs.render_pass_encoder_draw_indexed_indirect(
      renderPassEncoder, indirectBuffer, indirectOffset);
}
void wgpuRenderPassEncoderDrawIndirect(WGPURenderPassEncoder renderPassEncoder,
                                       WGPUBuffer indirectBuffer,
                                       uint64_t indirectOffset) {
  g_set_procs.render_pass_encoder_draw_indirect(renderPassEncoder,
                                                indirectBuffer, indirectOffset);
}
void wgpuRenderPassEncoderEnd(WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_end(renderPassEncoder);
}
void wgpuRenderPassEncoderEndOcclusionQuery(
    WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_end_occlusion_query(renderPassEncoder);
}
void wgpuRenderPassEncoderEndPass(WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_end_pass(renderPassEncoder);
}
void wgpuRenderPassEncoderExecuteBundles(
    WGPURenderPassEncoder renderPassEncoder, uint32_t bundleCount,
    WGPURenderBundle const *bundles) {
  g_set_procs.render_pass_encoder_execute_bundles(renderPassEncoder,
                                                  bundleCount, bundles);
}
void wgpuRenderPassEncoderInsertDebugMarker(
    WGPURenderPassEncoder renderPassEncoder, char const *markerLabel) {
  g_set_procs.render_pass_encoder_insert_debug_marker(renderPassEncoder,
                                                      markerLabel);
}
void wgpuRenderPassEncoderPopDebugGroup(
    WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_pop_debug_group(renderPassEncoder);
}
void wgpuRenderPassEncoderPushDebugGroup(
    WGPURenderPassEncoder renderPassEncoder, char const *groupLabel) {
  g_set_procs.render_pass_encoder_push_debug_group(renderPassEncoder,
                                                   groupLabel);
}
void wgpuRenderPassEncoderSetBindGroup(WGPURenderPassEncoder renderPassEncoder,
                                       uint32_t groupIndex, WGPUBindGroup group,
                                       uint32_t dynamicOffsetCount,
                                       uint32_t const *dynamicOffsets) {
  g_set_procs.render_pass_encoder_set_bind_group(
      renderPassEncoder, groupIndex, group, dynamicOffsetCount, dynamicOffsets);
}
void wgpuRenderPassEncoderSetBlendConstant(
    WGPURenderPassEncoder renderPassEncoder, WGPUColor const *color) {
  g_set_procs.render_pass_encoder_set_blend_constant(renderPassEncoder, color);
}
void wgpuRenderPassEncoderSetIndexBuffer(
    WGPURenderPassEncoder renderPassEncoder, WGPUBuffer buffer,
    WGPUIndexFormat format, uint64_t offset, uint64_t size) {
  g_set_procs.render_pass_encoder_set_index_buffer(renderPassEncoder, buffer,
                                                   format, offset, size);
}
void wgpuRenderPassEncoderSetLabel(WGPURenderPassEncoder renderPassEncoder,
                                   char const *label) {
  g_set_procs.render_pass_encoder_set_label(renderPassEncoder, label);
}
void wgpuRenderPassEncoderSetPipeline(WGPURenderPassEncoder renderPassEncoder,
                                      WGPURenderPipeline pipeline) {
  g_set_procs.render_pass_encoder_set_pipeline(renderPassEncoder, pipeline);
}
void wgpuRenderPassEncoderSetScissorRect(
    WGPURenderPassEncoder renderPassEncoder, uint32_t x, uint32_t y,
    uint32_t width, uint32_t height) {
  g_set_procs.render_pass_encoder_set_scissor_rect(renderPassEncoder, x, y,
                                                   width, height);
}
void wgpuRenderPassEncoderSetStencilReference(
    WGPURenderPassEncoder renderPassEncoder, uint32_t reference) {
  g_set_procs.render_pass_encoder_set_stencil_reference(renderPassEncoder,
                                                        reference);
}
void wgpuRenderPassEncoderSetVertexBuffer(
    WGPURenderPassEncoder renderPassEncoder, uint32_t slot, WGPUBuffer buffer,
    uint64_t offset, uint64_t size) {
  g_set_procs.render_pass_encoder_set_vertex_buffer(renderPassEncoder, slot,
                                                    buffer, offset, size);
}
void wgpuRenderPassEncoderSetViewport(WGPURenderPassEncoder renderPassEncoder,
                                      float x, float y, float width,
                                      float height, float minDepth,
                                      float maxDepth) {
  g_set_procs.render_pass_encoder_set_viewport(renderPassEncoder, x, y, width,
                                               height, minDepth, maxDepth);
}
void wgpuRenderPassEncoderWriteTimestamp(
    WGPURenderPassEncoder renderPassEncoder, WGPUQuerySet querySet,
    uint32_t queryIndex) {
  g_set_procs.render_pass_encoder_write_timestamp(renderPassEncoder, querySet,
                                                  queryIndex);
}
void wgpuRenderPassEncoderReference(WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_reference(renderPassEncoder);
}
void wgpuRenderPassEncoderRelease(WGPURenderPassEncoder renderPassEncoder) {
  g_set_procs.render_pass_encoder_release(renderPassEncoder);
}

auto wgpuRenderPipelineGetBindGroupLayout(WGPURenderPipeline renderPipeline,
                                          uint32_t groupIndex)
    -> WGPUBindGroupLayout {
  return g_set_procs.render_pipeline_get_bind_group_layout(renderPipeline,
                                                           groupIndex);
}
void wgpuRenderPipelineSetLabel(WGPURenderPipeline renderPipeline,
                                char const *label) {
  g_set_procs.render_pipeline_set_label(renderPipeline, label);
}
void wgpuRenderPipelineReference(WGPURenderPipeline renderPipeline) {
  g_set_procs.render_pipeline_reference(renderPipeline);
}
void wgpuRenderPipelineRelease(WGPURenderPipeline renderPipeline) {
  g_set_procs.render_pipeline_release(renderPipeline);
}

void wgpuSamplerSetLabel(WGPUSampler sampler, char const *label) {
  g_set_procs.sampler_set_label(sampler, label);
}
void wgpuSamplerReference(WGPUSampler sampler) {
  g_set_procs.sampler_reference(sampler);
}
void wgpuSamplerRelease(WGPUSampler sampler) {
  g_set_procs.sampler_release(sampler);
}

void wgpuShaderModuleGetCompilationInfo(WGPUShaderModule shaderModule,
                                        WGPUCompilationInfoCallback callback,
                                        void *userdata) {
  g_set_procs.shader_module_get_compilation_info(shaderModule, callback,
                                                 userdata);
}
void wgpuShaderModuleSetLabel(WGPUShaderModule shaderModule,
                              char const *label) {
  g_set_procs.shader_module_set_label(shaderModule, label);
}
void wgpuShaderModuleReference(WGPUShaderModule shaderModule) {
  g_set_procs.shader_module_reference(shaderModule);
}
void wgpuShaderModuleRelease(WGPUShaderModule shaderModule) {
  g_set_procs.shader_module_release(shaderModule);
}

void wgpuSurfaceReference(WGPUSurface surface) {
  g_set_procs.surface_reference(surface);
}
void wgpuSurfaceRelease(WGPUSurface surface) {
  g_set_procs.surface_release(surface);
}

void wgpuSwapChainConfigure(WGPUSwapChain swapChain, WGPUTextureFormat format,
                            WGPUTextureUsageFlags allowedUsage, uint32_t width,
                            uint32_t height) {
  g_set_procs.swap_chain_configure(swapChain, format, allowedUsage, width,
                                   height);
}
auto wgpuSwapChainGetCurrentTextureView(WGPUSwapChain swapChain)
    -> WGPUTextureView {
  return g_set_procs.swap_chain_get_current_texture_view(swapChain);
}
void wgpuSwapChainPresent(WGPUSwapChain swapChain) {
  g_set_procs.swap_chain_present(swapChain);
}
void wgpuSwapChainReference(WGPUSwapChain swapChain) {
  g_set_procs.swap_chain_reference(swapChain);
}
void wgpuSwapChainRelease(WGPUSwapChain swapChain) {
  g_set_procs.swap_chain_release(swapChain);
}

auto wgpuTextureCreateView(WGPUTexture texture,
                           WGPUTextureViewDescriptor const *descriptor)
    -> WGPUTextureView {
  return g_set_procs.texture_create_view(texture, descriptor);
}
void wgpuTextureDestroy(WGPUTexture texture) {
  g_set_procs.texture_destroy(texture);
}
auto wgpuTextureGetDepthOrArrayLayers(WGPUTexture texture) -> uint32_t {
  return g_set_procs.texture_get_depth_or_array_layers(texture);
}
auto wgpuTextureGetDimension(WGPUTexture texture) -> WGPUTextureDimension {
  return g_set_procs.texture_get_dimension(texture);
}
auto wgpuTextureGetFormat(WGPUTexture texture) -> WGPUTextureFormat {
  return g_set_procs.texture_get_format(texture);
}
auto wgpuTextureGetHeight(WGPUTexture texture) -> uint32_t {
  return g_set_procs.texture_get_height(texture);
}
auto wgpuTextureGetMipLevelCount(WGPUTexture texture) -> uint32_t {
  return g_set_procs.texture_get_mip_level_count(texture);
}
auto wgpuTextureGetSampleCount(WGPUTexture texture) -> uint32_t {
  return g_set_procs.texture_get_sample_count(texture);
}
auto wgpuTextureGetUsage(WGPUTexture texture) -> WGPUTextureUsage {
  return g_set_procs.texture_get_usage(texture);
}
auto wgpuTextureGetWidth(WGPUTexture texture) -> uint32_t {
  return g_set_procs.texture_get_width(texture);
}
void wgpuTextureSetLabel(WGPUTexture texture, char const *label) {
  g_set_procs.texture_set_label(texture, label);
}
void wgpuTextureReference(WGPUTexture texture) {
  g_set_procs.texture_reference(texture);
}
void wgpuTextureRelease(WGPUTexture texture) {
  g_set_procs.texture_release(texture);
}

void wgpuTextureViewSetLabel(WGPUTextureView textureView, char const *label) {
  g_set_procs.texture_view_set_label(textureView, label);
}
void wgpuTextureViewReference(WGPUTextureView textureView) {
  g_set_procs.texture_view_reference(textureView);
}
void wgpuTextureViewRelease(WGPUTextureView textureView) {
  g_set_procs.texture_view_release(textureView);
}
}

} // namespace moon::gpu