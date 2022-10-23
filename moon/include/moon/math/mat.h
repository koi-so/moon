#pragma once

#include "vec.h"

namespace moon::math {
template <typename T, usize R, usize C> struct mat {
public:
  static constexpr usize rows = R;
  static constexpr usize cols = C;
  static constexpr bool square = R == C;

  using value_type = T;
  using row_type = vec<value_type, cols>;
  using matrix_type = mat<value_type, rows, cols>;

private:
  row_type m_data[rows]{};

public:
  mat();
  mat(value_type data[rows * cols]);

  inline auto operator[](const usize i) -> row_type & { return m_data[i]; }
  inline auto operator[](const usize i) const -> const row_type & {
    return m_data[i];
  }

  inline auto x() const -> const row_type & { return m_data[0]; }
  inline auto y() const -> const row_type & { return m_data[1]; }
  inline auto z() const -> const row_type & { return m_data[2]; }
  inline auto w() const -> const row_type & { return m_data[3]; }

  inline auto xy() const -> mat<value_type, 2, cols> {
    return mat<value_type, 2, cols>{m_data[0], m_data[1]};
  }
  inline auto xyz() const -> mat<value_type, 3, cols> {
    return mat<value_type, 3, cols>{m_data[0], m_data[1], m_data[2]};
  }

  inline auto r() const -> const row_type & { return m_data[0]; }
  inline auto g() const -> const row_type & { return m_data[1]; }
  inline auto b() const -> const row_type & { return m_data[2]; }
  inline auto a() const -> const row_type & { return m_data[3]; }

  inline auto rg() const -> mat<value_type, 2, cols> {
    return mat<value_type, 2, cols>{m_data[0], m_data[1]};
  }
  inline auto rgb() const -> mat<value_type, 3, cols> {
    return mat<value_type, 3, cols>{m_data[0], m_data[1], m_data[2]};
  }
  inline auto rgba() const -> mat<value_type, 4, cols> {
    return mat<value_type, 4, cols>{m_data[0], m_data[1], m_data[2], m_data[3]};
  }
};

// 1x

using mat1x1 = mat<u32, 1, 1>;
using mat1x2 = mat<u32, 1, 2>;
using mat1x3 = mat<u32, 1, 3>;
using mat1x4 = mat<u32, 1, 4>;

using imat1x1 = mat<i32, 1, 1>;
using imat1x2 = mat<i32, 1, 2>;
using imat1x3 = mat<i32, 1, 3>;
using imat1x4 = mat<i32, 1, 4>;

// 2x

using mat2x1 = mat<u32, 2, 1>;
using mat2x2 = mat<u32, 2, 2>;
using mat2x3 = mat<u32, 2, 3>;
using mat2x4 = mat<u32, 2, 4>;

using imat2x1 = mat<i32, 2, 1>;
using imat2x2 = mat<i32, 2, 2>;
using imat2x3 = mat<i32, 2, 3>;
using imat2x4 = mat<i32, 2, 4>;

// 3x
using mat3x1 = mat<u32, 3, 1>;
using mat3x2 = mat<u32, 3, 2>;
using mat3x3 = mat<u32, 3, 3>;
using mat3x4 = mat<u32, 3, 4>;

using imat3x1 = mat<i32, 3, 1>;
using imat3x2 = mat<i32, 3, 2>;
using imat3x3 = mat<i32, 3, 3>;
using imat3x4 = mat<i32, 3, 4>;

// 4x
using mat4x1 = mat<u32, 4, 1>;
using mat4x2 = mat<u32, 4, 2>;
using mat4x3 = mat<u32, 4, 3>;
using mat4x4 = mat<u32, 4, 4>;

using imat4x1 = mat<i32, 4, 1>;
using imat4x2 = mat<i32, 4, 2>;
using imat4x3 = mat<i32, 4, 3>;
using imat4x4 = mat<i32, 4, 4>;
} // namespace moon::math