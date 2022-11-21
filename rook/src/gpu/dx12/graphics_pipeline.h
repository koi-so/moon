#pragma once

#include "rook/gpu.h"

#include "common.h"
#include "pipeline.h"

#include <EASTL/map.h>

namespace rook::gpu::dx12 {
class DX12Device;

class DX12GraphicsPipeline : public DX12Pipeline {
public:
  DX12GraphicsPipeline(DX12Device &device,
                       GraphicsPipelineDescriptor const &desc);
  auto get_type() const -> PipelineType override;
  auto get_root_signature() const
      -> ComPtr<ID3D12RootSignature> const & override;

  auto get_descriptor() const -> GraphicsPipelineDescriptor const &;
  auto get_pipeline() const -> ComPtr<ID3D12PipelineState> const &;
  auto get_stride_map() const -> eastl::map<uint32_t, uint32_t> const &;

private:
  void parse_input_layout(eastl::shared_ptr<Shader> const &shader);
  auto get_input_layout() const -> D3D12_INPUT_LAYOUT_DESC;

  DX12Device &m_device;
  GraphicsPipelineDescriptor m_desc;
  eastl::vector<D3D12_INPUT_ELEMENT_DESC> m_input_layout_descriptor;
  eastl::map<size_t, eastl::string> m_input_layout_descriptor_names;
  eastl::map<size_t, uint32_t> m_input_layout_stride;
  ComPtr<ID3D12RootSignature> m_root_signature;
  ComPtr<ID3D12PipelineState> m_pipeline_state;
};
} // namespace rook::gpu::dx12