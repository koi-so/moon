#include "binding_set_layout.h"

#include "device.h"
#include "gpu_descriptor_pool_range.h"
#include "program.h"

#include <EASTL/deque.h>

namespace rook::gpu::dx12 {
auto GetVisibility(ShaderType shader_type) -> D3D12_SHADER_VISIBILITY {
  D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL;
  switch (shader_type) {
  case ShaderType::eVertex:
    visibility = D3D12_SHADER_VISIBILITY_VERTEX;
    break;
  case ShaderType::ePixel:
    visibility = D3D12_SHADER_VISIBILITY_PIXEL;
    break;
  case ShaderType::eCompute:
    visibility = D3D12_SHADER_VISIBILITY_ALL;
    break;
  case ShaderType::eGeometry:
    visibility = D3D12_SHADER_VISIBILITY_GEOMETRY;
    break;
  case ShaderType::eAmplification:
    visibility = D3D12_SHADER_VISIBILITY_AMPLIFICATION;
    break;
  case ShaderType::eMesh:
    visibility = D3D12_SHADER_VISIBILITY_MESH;
    break;
  case ShaderType::eUnknown:
  case ShaderType::eLibrary:
    break;
  }
  return visibility;
}

auto GetRangeType(ViewType view_type) -> D3D12_DESCRIPTOR_RANGE_TYPE {
  D3D12_DESCRIPTOR_RANGE_TYPE range_type;
  switch (view_type) {
  case ViewType::eTexture:
  case ViewType::eBuffer:
  case ViewType::eStructuredBuffer:
  case ViewType::eAccelerationStructure:
    return D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
  case ViewType::eRWTexture:
  case ViewType::eRWBuffer:
  case ViewType::eRWStructuredBuffer:
    return D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
  case ViewType::eConstantBuffer:
    return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
  case ViewType::eSampler:
    return D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
  default:
    EASTL_ASSERT_MSG(false, "wrong view type");
  }
}

auto GetHeapType(ViewType view_type) -> D3D12_DESCRIPTOR_HEAP_TYPE {
  D3D12_DESCRIPTOR_RANGE_TYPE range_type;
  switch (GetRangeType(view_type)) {
  case D3D12_DESCRIPTOR_RANGE_TYPE_SRV:
  case D3D12_DESCRIPTOR_RANGE_TYPE_UAV:
  case D3D12_DESCRIPTOR_RANGE_TYPE_CBV:
    return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
  case D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER:
    return D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
  default:
    EASTL_ASSERT_MSG(false, "wrong view type");
  }
}

DX12BindingSetLayout::DX12BindingSetLayout(DX12Device &device,
                                           eastl::vector<BindKey> const &descs)
    : m_device(device) {
  eastl::vector<D3D12_ROOT_PARAMETER> root_parameters;
  using RootKey = eastl::pair<D3D12_DESCRIPTOR_HEAP_TYPE, ShaderType>;
  eastl::map<RootKey, eastl::vector<D3D12_DESCRIPTOR_RANGE>>
      descriptor_table_ranges;
  eastl::map<RootKey, size_t> descriptor_table_offset;
  eastl::deque<D3D12_DESCRIPTOR_RANGE> bindless_ranges;

  auto add_root_table = [&](ShaderType shader_type, size_t range_count,
                            const D3D12_DESCRIPTOR_RANGE *ranges) {
    D3D12_ROOT_DESCRIPTOR_TABLE descriptor_table = {};
    descriptor_table.NumDescriptorRanges = range_count;
    descriptor_table.pDescriptorRanges = ranges;

    size_t root_param_index = root_parameters.size();
    auto root_parameter = root_parameters.push_back();
    root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    root_parameter.DescriptorTable = descriptor_table;
    root_parameter.ShaderVisibility = GetVisibility(shader_type);
    return root_param_index;
  };

  auto add_bindless_range = [&](ShaderType shader_type, ViewType view_type,
                                uint32_t base_slot, uint32_t space) {
    auto &descriptor_table_range = bindless_ranges.push_back();
    descriptor_table_range.RangeType = GetRangeType(view_type);
    descriptor_table_range.NumDescriptors = UINT_MAX;
    descriptor_table_range.BaseShaderRegister = base_slot;
    descriptor_table_range.RegisterSpace = space;
    size_t root_param_index =
        add_root_table(shader_type, 1, &descriptor_table_range);
    m_descriptor_tables[root_param_index].heap_type = GetHeapType(view_type);
    m_descriptor_tables[root_param_index].heap_offset = 0;
    m_descriptor_tables[root_param_index].bindless = true;
    switch (shader_type) {
    case ShaderType::eCompute:
    case ShaderType::eLibrary:
      m_descriptor_tables[root_param_index].is_compute = true;
      break;
    case ShaderType::eUnknown:
    case ShaderType::eVertex:
    case ShaderType::ePixel:
    case ShaderType::eGeometry:
    case ShaderType::eAmplification:
    case ShaderType::eMesh:
      break;
    }
  };

  for (const auto &bind_key : descs) {
    if (bind_key.count == eastl::numeric_limits<uint32_t>::max()) {
      add_bindless_range(bind_key.shader_type, bind_key.view_type,
                         bind_key.slot, bind_key.space);
      continue;
    }

    D3D12_DESCRIPTOR_HEAP_TYPE heap_type = GetHeapType(bind_key.view_type);
    auto layout = m_layout[bind_key];
    layout.heap_type = heap_type;
    layout.heap_offset = m_heap_descriptors[heap_type];

    RootKey key = {heap_type, bind_key.shader_type};
    if (!descriptor_table_offset.count(key)) {
      descriptor_table_offset[key] = m_heap_descriptors[heap_type];
    }

    auto range = descriptor_table_ranges[key].emplace_back();
    range.RangeType = GetRangeType(bind_key.view_type);
    range.NumDescriptors = bind_key.count;
    range.BaseShaderRegister = bind_key.slot;
    range.RegisterSpace = bind_key.space;
    range.OffsetInDescriptorsFromTableStart =
        layout.heap_offset - descriptor_table_offset[key];

    m_heap_descriptors[heap_type] += bind_key.count;
  }

  for (const auto &ranges : descriptor_table_ranges) {
    size_t root_param_index = add_root_table(
        ranges.first.second, ranges.second.size(), ranges.second.data());
    m_descriptor_tables[root_param_index].heap_type = ranges.first.first;
    m_descriptor_tables[root_param_index].heap_offset =
        descriptor_table_offset[ranges.first];
    switch (ranges.first.second) {
    case ShaderType::eCompute:
    case ShaderType::eLibrary:
      m_descriptor_tables[root_param_index].is_compute = true;
      break;
    case ShaderType::eUnknown:
    case ShaderType::eVertex:
    case ShaderType::ePixel:
    case ShaderType::eGeometry:
    case ShaderType::eAmplification:
    case ShaderType::eMesh:
      break;
    }
  }

  D3D12_ROOT_SIGNATURE_FLAGS root_signature_flags =
      D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT |
      D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS |
      D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS;

  CD3DX12_ROOT_SIGNATURE_DESC root_signature_desc = {};
  root_signature_desc.Init(static_cast<uint32_t>(root_parameters.size()),
                           root_parameters.data(), 0, nullptr,
                           root_signature_flags);

  ComPtr<ID3DBlob> signature;
  ComPtr<ID3DBlob> error_blob;
  ASSERT_SUCCEEDED(D3D12SerializeRootSignature(&root_signature_desc,
                                               D3D_ROOT_SIGNATURE_VERSION_1,
                                               &signature, &error_blob),
                   "%s", static_cast<char *>(error_blob->GetBufferPointer()));
  ASSERT_SUCCEEDED(device.get_device()->CreateRootSignature(
      0, signature->GetBufferPointer(), signature->GetBufferSize(),
      IID_PPV_ARGS(&m_root_signature)));
}
} // namespace rook::gpu::dx12