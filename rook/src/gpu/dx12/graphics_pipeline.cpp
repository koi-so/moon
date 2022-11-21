#include "graphics_pipeline.h"

#include "format_translate.h"

namespace rook::gpu::dx12 {
auto GetRasterizerDesc(GraphicsPipelineDescriptor const &descriptor)
    -> CD3DX12_RASTERIZER_DESC {
  CD3DX12_RASTERIZER_DESC rasterizer_desc(D3D12_DEFAULT);
  switch (descriptor.rasterizer_desc.fill_mode) {
  case FillMode::eWireframe:
    rasterizer_desc.FillMode = D3D12_FILL_MODE_WIREFRAME;
    break;
  case FillMode::eSolid:
    rasterizer_desc.FillMode = D3D12_FILL_MODE_SOLID;
    break;
  }
  switch (descriptor.rasterizer_desc.cull_mode) {
  case CullMode::eNone:
    rasterizer_desc.CullMode = D3D12_CULL_MODE_NONE;
    break;
  case CullMode::eFront:
    rasterizer_desc.CullMode = D3D12_CULL_MODE_FRONT;
    break;
  case CullMode::eBack:
    rasterizer_desc.CullMode = D3D12_CULL_MODE_BACK;
    break;
  }
  rasterizer_desc.DepthBias = descriptor.rasterizer_desc.depth_bias;
  return rasterizer_desc;
}

auto GetBlendDesc(const GraphicsPipelineDescriptor &desc)
    -> CD3DX12_BLEND_DESC {
  CD3DX12_BLEND_DESC blend_desc(D3D12_DEFAULT);
  auto convert = [](Blend type) {
    switch (type) {
    case Blend::eZero:
      return D3D12_BLEND_ZERO;
    case Blend::eSrcAlpha:
      return D3D12_BLEND_SRC_ALPHA;
    case Blend::eInvSrcAlpha:
      return D3D12_BLEND_INV_SRC_ALPHA;
    }
    return static_cast<D3D12_BLEND>(0);
  };
  auto convert_op = [](BlendOperation type) {
    switch (type) {
    case BlendOperation::eAdd:
      return D3D12_BLEND_OP_ADD;
    }
    return static_cast<D3D12_BLEND_OP>(0);
  };
  const RenderPassDescriptor &render_pass_desc =
      desc.render_pass->get_descriptor();
  for (size_t i = 0; i < render_pass_desc.colors.size(); ++i) {
    if (render_pass_desc.colors[i].format == Format::UNDEFINED)
      continue;
    decltype(auto) rt_desc = blend_desc.RenderTarget[i];
    rt_desc.BlendEnable = desc.blend_desc.blend_enable;
    rt_desc.BlendOp = convert_op(desc.blend_desc.blend_op);
    rt_desc.SrcBlend = convert(desc.blend_desc.blend_src);
    rt_desc.DestBlend = convert(desc.blend_desc.blend_dest);
    rt_desc.BlendOpAlpha = convert_op(desc.blend_desc.blend_op_alpha);
    rt_desc.SrcBlendAlpha = convert(desc.blend_desc.blend_src_alpha);
    rt_desc.DestBlendAlpha = convert(desc.blend_desc.blend_dest_apha);
    rt_desc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
  }
  return blend_desc;
}

auto Convert(ComparisonFunc func) -> D3D12_COMPARISON_FUNC {
  switch (func) {
  case ComparisonFunc::eNever:
    return D3D12_COMPARISON_FUNC_NEVER;
  case ComparisonFunc::eLess:
    return D3D12_COMPARISON_FUNC_LESS;
  case ComparisonFunc::eEqual:
    return D3D12_COMPARISON_FUNC_EQUAL;
  case ComparisonFunc::eLessEqual:
    return D3D12_COMPARISON_FUNC_LESS_EQUAL;
  case ComparisonFunc::eGreater:
    return D3D12_COMPARISON_FUNC_GREATER;
  case ComparisonFunc::eNotEqual:
    return D3D12_COMPARISON_FUNC_NOT_EQUAL;
  case ComparisonFunc::eGreaterEqual:
    return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
  case ComparisonFunc::eAlways:
    return D3D12_COMPARISON_FUNC_ALWAYS;
  default:
    EASTL_ASSERT(false);
    return D3D12_COMPARISON_FUNC_LESS;
  }
}

auto Convert(StencilOperation op) -> D3D12_STENCIL_OP {
  switch (op) {
  case StencilOperation::eKeep:
    return D3D12_STENCIL_OP_KEEP;
  case StencilOperation::eZero:
    return D3D12_STENCIL_OP_ZERO;
  case StencilOperation::eReplace:
    return D3D12_STENCIL_OP_REPLACE;
  case StencilOperation::eIncrementSat:
    return D3D12_STENCIL_OP_INCR_SAT;
  case StencilOperation::eDecrementSat:
    return D3D12_STENCIL_OP_DECR_SAT;
  case StencilOperation::eInvert:
    return D3D12_STENCIL_OP_INVERT;
  case StencilOperation::eIncrement:
    return D3D12_STENCIL_OP_INCR;
  case StencilOperation::eDecrement:
    return D3D12_STENCIL_OP_DECR;
  default:
    EASTL_ASSERT(false);
    return D3D12_STENCIL_OP_KEEP;
  }
}

auto Convert(const StencilOperationDescriptor &desc)
    -> D3D12_DEPTH_STENCILOP_DESC {
  D3D12_DEPTH_STENCILOP_DESC res = {};
  res.StencilFailOp = Convert(desc.fail_op);
  res.StencilPassOp = Convert(desc.pass_op);
  res.StencilDepthFailOp = Convert(desc.depth_fail_op);
  res.StencilFunc = Convert(desc.func);
  return res;
}

auto GetDepthStencilDesc(const DepthStencilDescriptor &desc,
                         DXGI_FORMAT dsv_format)
    -> CD3DX12_DEPTH_STENCIL_DESC1 {
  CD3DX12_DEPTH_STENCIL_DESC1 depth_stencil_desc(D3D12_DEFAULT);
  depth_stencil_desc.DepthEnable = desc.depth_test_enable;
  depth_stencil_desc.DepthWriteMask = desc.depth_write_enable
                                          ? D3D12_DEPTH_WRITE_MASK_ALL
                                          : D3D12_DEPTH_WRITE_MASK_ZERO;
  depth_stencil_desc.DepthBoundsTestEnable = desc.depth_bounds_test_enable;
  depth_stencil_desc.DepthFunc = Convert(desc.depth_func);
  depth_stencil_desc.StencilEnable = desc.stencil_enable;
  depth_stencil_desc.StencilReadMask = desc.stencil_read_mask;
  depth_stencil_desc.StencilWriteMask = desc.stencil_write_mask;
  depth_stencil_desc.FrontFace = Convert(desc.front_face);
  depth_stencil_desc.BackFace = Convert(desc.back_face);

  if (dsv_format == static_cast<uint32_t>(DXGI_FORMAT_UNKNOWN)) {
    depth_stencil_desc.DepthEnable = false;
  }

  return depth_stencil_desc;
}

auto GetRTVFormats(const GraphicsPipelineDescriptor &desc)
    -> D3D12_RT_FORMAT_ARRAY {
  const RenderPassDescriptor &render_pass_desc =
      desc.render_pass->get_descriptor();
  D3D12_RT_FORMAT_ARRAY rt_formats = {};
  for (size_t i = 0; i < render_pass_desc.colors.size(); ++i) {
    if (render_pass_desc.colors[i].format == Format::UNDEFINED)
      continue;
    rt_formats.NumRenderTargets = i + 1;
    rt_formats.RTFormats[i] = static_cast<DXGI_FORMAT>(
        TranslateFormatToDX12Format(render_pass_desc.colors[i].format)
            .DXGIFormat.DDS);
  }
  return rt_formats;
}

DXGI_FORMAT GetDSVFormat(const GraphicsPipelineDescriptor &desc) {
  const RenderPassDescriptor &render_pass_desc =
      desc.render_pass->get_descriptor();
  if (render_pass_desc.depth_stencil.format == Format::UNDEFINED)
    return static_cast<DXGI_FORMAT>(DXGI_FORMAT_UNKNOWN);
  return static_cast<DXGI_FORMAT>(
      TranslateFormatToDX12Format(render_pass_desc.depth_stencil.format)
          .DXGIFormat.DDS);
}
} // namespace rook::gpu::dx12