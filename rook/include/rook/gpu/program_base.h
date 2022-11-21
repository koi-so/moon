#pragma once

#include "program.h"

#include <EASTL/map.h>

namespace rook::gpu {
class ProgramBase : public Program {
public:
  ProgramBase(eastl::vector<eastl::shared_ptr<Shader>> const &shaders);

  auto has_shader(ShaderType type) const -> bool override final;
  auto get_shader(ShaderType type) const
      -> eastl::shared_ptr<Shader> override final;
  auto get_shaders() const
      -> eastl::vector<eastl::shared_ptr<Shader>> const & override final;
  auto get_bindings() const -> eastl::vector<BindKey> const & override final;
  auto get_entry_points() const
      -> eastl::vector<EntryPoint> const & override final;

protected:
  eastl::map<ShaderType, eastl::shared_ptr<Shader>> m_shaders_by_type;
  eastl::vector<eastl::shared_ptr<Shader>> m_shaders;
  eastl::vector<BindKey> m_bindings;
  eastl::vector<EntryPoint> m_entry_points;
};
} // namespace rook::gpu