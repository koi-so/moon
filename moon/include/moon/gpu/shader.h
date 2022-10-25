#pragma once

#include "moon/base.h"

#include "types.h"

namespace moon::gpu {
class Shader : public zinc::interface {
public:
  ~Shader() override = default;
  virtual auto get_type() const -> ShaderType = 0;
  virtual auto get_blob() const -> zinc::vector<u8> const & = 0;
  virtual auto get_id(zinc::string const &entry_point) const -> u64 = 0;
  virtual auto get_bind_key(zinc::string const &name) const -> BindKey = 0;
  virtual auto get_resource_bindings() const
      -> zinc::vector<ResourceBindingDescriptor> const & = 0;
  virtual auto get_resource_binding(BindKey const &bind_key) const
      -> ResourceBindingDescriptor const & = 0;
  virtual auto get_input_layouts() const
      -> zinc::vector<InputLayoutDescriptor> const & = 0;
  virtual auto
  get_input_layout_location(zinc::string const &semantic_name) const -> u32 = 0;
  // TODO: Shader reflection
  // virtual const std::shared_ptr<ShaderReflection> &GetReflection() const = 0;
};
} // namespace moon::gpu