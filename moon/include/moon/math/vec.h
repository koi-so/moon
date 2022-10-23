#pragma once

#include "moon/base.h"

namespace moon::math {
// similar vec to glm
template <typename T, usize N> struct vec {
public:
  static constexpr usize size = N;
  using value_type = T;

private:
  value_type m_data[N]{};

public:
  auto operator[](const usize i) -> value_type & { return m_data[i]; }
  auto operator[](const usize i) const -> const value_type & {
    return m_data[i];
  }

  inline auto abs() const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = ::abs(m_data[i]);
    }
    return result;
  }

  inline auto operator-() const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = -m_data[i];
    }
    return result;
  }

  inline auto operator+(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] + other[i];
    }
    return result;
  }

  inline auto operator+(f32 other) const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] + other;
    }
    return result;
  }

  inline auto operator-(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] - other[i];
    }
    return result;
  }

  inline auto operator-(f32 other) const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] - other;
    }
    return result;
  }

  inline auto operator*(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] * other[i];
    }
    return result;
  }

  inline auto operator*(f32 other) const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] * other;
    }
    return result;
  }

  inline auto dot(const vec<value_type, size> &other) const -> value_type {
    value_type result = 0;
    for (usize i = 0; i < size; ++i) {
      result += m_data[i] * other[i];
    }
    return result;
  }

  inline auto cross(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    static_assert(size == 3, "cross product only defined for 3d vectors");
    return vec<value_type, size>{m_data[1] * other[2] - m_data[2] * other[1],
                                 m_data[2] * other[0] - m_data[0] * other[2],
                                 m_data[0] * other[1] - m_data[1] * other[0]};
  }

  inline auto length() const -> value_type { return ::sqrt(dot(*this)); }

  inline auto lerp(const vec<value_type, size> &other, f32 t) const
      -> vec<value_type, size> {
    return *this + (other - *this) * t;
  }

  inline auto normalize() const -> vec<value_type, size> {
    value_type mag = magnitude();
    vec<value_type, size> result;
    for (usize i = 0; i < size; i++) {
      result[i] = m_data[i] / mag;
    }
    return result;
  }

  inline auto min(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] < other[i] ? m_data[i] : other[i];
    }
    return result;
  }

  inline auto max(const vec<value_type, size> &other) const
      -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = m_data[i] > other[i] ? m_data[i] : other[i];
    }
    return result;
  }

  inline auto reciprocal() const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = 1 / m_data[i];
    }
    return result;
  }

  inline auto tangent() const -> vec<value_type, size> {
    vec<value_type, size> result;
    for (usize i = 0; i < size; ++i) {
      result[i] = ::tan(m_data[i]);
    }
    return result;
  }

  // swizzles
  inline auto x() const -> const value_type & { return m_data[0]; }
  inline auto y() const -> const value_type & { return m_data[1]; }
  inline auto z() const -> const value_type & { return m_data[2]; }
  inline auto w() const -> const value_type & { return m_data[3]; }

  inline auto xy() const -> vec<value_type, 2> {
    return vec<value_type, 2>{m_data[0], m_data[1]};
  }
  inline auto xyz() const -> vec<value_type, 3> {
    return vec<value_type, 3>{m_data[0], m_data[1], m_data[2]};
  }

  inline auto r() const -> const value_type & { return m_data[0]; }
  inline auto g() const -> const value_type & { return m_data[1]; }
  inline auto b() const -> const value_type & { return m_data[2]; }
  inline auto a() const -> const value_type & { return m_data[3]; }

  inline auto rg() const -> vec<value_type, 2> {
    return vec<value_type, 2>{m_data[0], m_data[1]};
  }
  inline auto rgb() const -> vec<value_type, 3> {
    return vec<value_type, 3>{m_data[0], m_data[1], m_data[2]};
  }
  inline auto rgba() const -> vec<value_type, 4> {
    return vec<value_type, 4>{m_data[0], m_data[1], m_data[2], m_data[3]};
  }
};

using vec2 = vec<u32, 2>;
using vec3 = vec<u32, 3>;
using vec4 = vec<u32, 4>;

using ivec2 = vec<i32, 2>;
using ivec3 = vec<i32, 3>;
using ivec4 = vec<i32, 4>;

using fvec2 = vec<f32, 2>;
using fvec3 = vec<f32, 3>;
using fvec4 = vec<f32, 4>;

using lvec2 = vec<u64, 2>;
using lvec3 = vec<u64, 3>;
using lvec4 = vec<u64, 4>;

using livec2 = vec<i64, 2>;
using livec3 = vec<i64, 3>;
using livec4 = vec<i64, 4>;

using lfvec2 = vec<f64, 2>;
using lfvec3 = vec<f64, 3>;
using lfvec4 = vec<f64, 4>;
} // namespace moon::math