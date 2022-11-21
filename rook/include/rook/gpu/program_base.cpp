#include "program_base.h"

namespace rook::gpu {
ProgramBase::ProgramBase(
    eastl::vector<eastl::shared_ptr<Shader>> const &shaders)
    : m_shaders(shaders) {
  for (auto const &shader : m_shaders) {
    m_shaders_by_type[shader->get_type()] = shader;
    auto bindings = shader->get_bindings();
    m_bindings.insert(m_bindings.begin(), bindings.begin(), bindings.end());

    // TODO: Reflection
  }
}

auto ProgramBase::has_shader(ShaderType type) const -> bool {
  return m_shaders_by_type.count(type) != 0;
}

auto ProgramBase::get_shader(ShaderType type) const
    -> eastl::shared_ptr<Shader> {
  return m_shaders_by_type.at(type);
}

auto ProgramBase::get_shaders() const
    -> eastl::vector<eastl::shared_ptr<Shader>> const & {
  return m_shaders;
}

auto ProgramBase::get_bindings() const -> eastl::vector<BindKey> const & {
  return m_bindings;
}

auto ProgramBase::get_entry_points() const
    -> eastl::vector<EntryPoint> const & {
  return m_entry_points;
}
} // namespace rook::gpu