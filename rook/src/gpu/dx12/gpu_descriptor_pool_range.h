#pragma once

#include "rook/base.h"
#include "rook/gpu.h"

#include "common.h"

#include <EASTL/functional.h>
#include <EASTL/shared_ptr.h>
#include <EASTL/string.h>
#include <EASTL/unique_ptr.h>

namespace rook::gpu::dx12 {
class DX12Device;
class DX12GPUDescriptorPoolTyped;

class DX12GPUDescriptorPoolRange {
public:
  using Ptr = eastl::shared_ptr<DX12GPUDescriptorPoolRange>;
  DX12GPUDescriptorPoolRange(DX12GPUDescriptorPoolTyped &pool,
                             DX12Device &device,
                             ComPtr<ID3D12DescriptorHeap> &heap,
                             D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle,
                             D3D12_GPU_DESCRIPTOR_HANDLE &gpu_handle,
                             ComPtr<ID3D12DescriptorHeap> &heap_readable,
                             D3D12_CPU_DESCRIPTOR_HANDLE &cpu_handle_readable,
                             size_t offset, size_t size,
                             uint32_t increment_size,
                             D3D12_DESCRIPTOR_HEAP_TYPE type);
  DX12GPUDescriptorPoolRange(DX12GPUDescriptorPoolRange &&other);
  ~DX12GPUDescriptorPoolRange();

  void copy_cpu_handle(size_t dst_offset, D3D12_CPU_DESCRIPTOR_HANDLE handle);
  [[nodiscard]] auto get_gpu_handle(size_t offset = 0) const
      -> D3D12_GPU_DESCRIPTOR_HANDLE;

  [[nodiscard]] auto get_heap() const -> ComPtr<ID3D12DescriptorHeap> const &;

  [[nodiscard]] auto get_size() const -> size_t;
  [[nodiscard]] auto get_offset() const -> size_t;

private:
  [[nodiscard]] auto get_cpu_handle(D3D12_CPU_DESCRIPTOR_HANDLE handle,
                                    size_t offset = 0) const
      -> D3D12_CPU_DESCRIPTOR_HANDLE;

  eastl::reference_wrapper<DX12GPUDescriptorPoolTyped> m_pool;
  eastl::reference_wrapper<DX12Device> m_device;
  eastl::reference_wrapper<ComPtr<ID3D12DescriptorHeap>> m_heap;
  eastl::reference_wrapper<D3D12_CPU_DESCRIPTOR_HANDLE> m_cpu_handle;
  eastl::reference_wrapper<D3D12_GPU_DESCRIPTOR_HANDLE> m_gpu_handle;
  eastl::reference_wrapper<ComPtr<ID3D12DescriptorHeap>> m_heap_readable;
  eastl::reference_wrapper<D3D12_CPU_DESCRIPTOR_HANDLE> m_cpu_handle_readable;
  size_t m_offset;
  size_t m_size;
  uint32_t m_increment_size;
  D3D12_DESCRIPTOR_HEAP_TYPE m_type;
  eastl::unique_ptr<DX12GPUDescriptorPoolRange,
                    eastl::function<void(DX12GPUDescriptorPoolRange *)>>
      m_callback;
};
} // namespace rook::gpu::dx12