#pragma once

#include "rook/base.h"

#include "shader.h"
#include "shader_reflection.h"
#include "types.h"

#include <EASTL/shared_ptr.h>
#include <EASTL/vector.h>

namespace rook::gpu {
class Program : public interface {
public:
  ~Program() override = default;
  [[nodiscard]] virtual auto has_shader(ShaderType type) const -> bool = 0;
  [[nodiscard]] virtual auto get_shader(ShaderType type) const
      -> eastl::shared_ptr<Shader> = 0;
  [[nodiscard]] virtual auto get_shaders() const
      -> eastl::vector<eastl::shared_ptr<Shader>> const & = 0;
  [[nodiscard]] virtual auto get_bindings() const
      -> eastl::vector<BindKey> const & = 0;
  [[nodiscard]] virtual auto get_entry_points() const
      -> eastl::vector<EntryPoint> const & = 0;
};
} // namespace rook::gpu