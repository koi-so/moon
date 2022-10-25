#pragma once

#include "moon/base.h"

#include "shader.h"
#include "shader_reflection.h"
#include "types.h"

namespace moon::gpu {
class Program : public zinc::interface {
public:
  ~Program() override = default;
  virtual auto has_shader(ShaderType type) const -> bool = 0;
  virtual auto get_shader(ShaderType type) const -> zinc::shared<Shader> = 0;
  virtual auto get_shaders() const
      -> zinc::vector<zinc::shared<Shader>> const & = 0;
  virtual auto get_bindings() const -> zinc::vector<BindKey> const & = 0;
  virtual auto get_entry_points() const -> zinc::vector<EntryPoint> const & = 0;
};
} // namespace moon::gpu