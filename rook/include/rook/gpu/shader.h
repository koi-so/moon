#pragma once

#include "rook/base.h"

#include "types.h"

namespace rook::gpu {
class Shader : public interface {
public:
  ~Shader() override = default;
  [[nodiscard]] virtual auto get_type() const -> ShaderType = 0;
  [[nodiscard]] virtual auto get_blob() const
      -> eastl::vector<uint8_t> const & = 0;
  [[nodiscard]] virtual auto get_id(eastl::string const &entry_point) const
      -> uint64_t = 0;
  [[nodiscard]] virtual auto get_bind_key(eastl::string const &name) const
      -> BindKey = 0;
  [[nodiscard]] virtual auto get_resource_bindings() const
      -> eastl::vector<ResourceBindingDescriptor> const & = 0;
  [[nodiscard]] virtual auto get_resource_binding(BindKey const &bind_key) const
      -> ResourceBindingDescriptor const & = 0;
  [[nodiscard]] virtual auto get_input_layouts() const
      -> eastl::vector<InputLayoutDescriptor> const & = 0;
  [[nodiscard]] virtual auto
  get_input_layout_location(eastl::string const &semantic_name) const
      -> uint32_t = 0;
  [[nodiscard]] virtual auto get_bindings() const
      -> eastl::vector<BindKey> const & = 0;
  // TODO: Shader reflection
  // virtual const std::shared_ptr<ShaderReflection> &GetReflection() const = 0;
};
} // namespace rook::gpu