#pragma once

#include "rook/base.h"

#include <cstdint>

namespace rook::platform {
struct Extent2D {
  Extent2D() = default;
  inline Extent2D(uint32_t width, uint32_t height)
      : width{width}, height{height} {}
  uint32_t width, height;
};
struct Extent3D {
  Extent3D() = default;
  inline Extent3D(uint32_t width, uint32_t height, uint32_t depth)
      : width{width}, height{height}, depth{depth} {}
  uint32_t width, height, depth;
};

struct Offset2D {
  Offset2D() = default;
  Offset2D(const Offset2D &) = default;

  inline Offset2D(int32_t x, int32_t y) : x{x}, y{y} {}
  int32_t x, y;
};

struct Offset3D {
  Offset3D() = default;
  Offset3D(const Offset3D &) = default;

  inline Offset3D(int32_t x, int32_t y, int32_t z) : x{x}, y{y}, z{z} {}
  int32_t x, y, z;
};

// operators
inline auto operator+(const Extent2D &lhs, const Extent2D &rhs) -> Extent2D {
  return {lhs.width + rhs.width, lhs.height + rhs.height};
}
inline auto operator-(const Extent2D &lhs, const Extent2D &rhs) -> Extent2D {
  return {lhs.width - rhs.width, lhs.height - rhs.height};
}
inline auto operator==(const Extent2D &lhs, const Extent2D &rhs) -> bool {
  return lhs.width == rhs.width && lhs.height == rhs.height;
};
inline auto operator!=(const Extent2D &lhs, const Extent2D &rhs) -> bool {
  return !(lhs == rhs);
};

inline auto operator+(const Extent3D &lhs, const Extent3D &rhs) -> Extent3D {
  return {lhs.width + rhs.width, lhs.height + rhs.height,
          lhs.depth + rhs.depth};
}
inline auto operator-(const Extent3D &lhs, const Extent3D &rhs) -> Extent3D {
  return {lhs.width - rhs.width, lhs.height - rhs.height,
          lhs.depth - rhs.depth};
}
inline auto operator==(const Extent3D &lhs, const Extent3D &rhs) -> bool {
  return lhs.width == rhs.width && lhs.height == rhs.height &&
         lhs.depth == rhs.depth;
}
inline auto operator!=(const Extent3D &lhs, const Extent3D &rhs) -> bool {
  return !(lhs == rhs);
}

inline auto operator+(const Offset2D &lhs, const Offset2D &rhs) -> Offset2D {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}
inline auto operator-(const Offset2D &lhs, const Offset2D &rhs) -> Offset2D {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}
inline auto operator==(const Offset2D &lhs, const Offset2D &rhs) -> bool {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}
inline auto operator!=(const Offset2D &lhs, const Offset2D &rhs) -> bool {
  return !(lhs == rhs);
}

inline auto operator+(const Offset3D &lhs, const Offset3D &rhs) -> Offset3D {
  return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}
inline auto operator-(const Offset3D &lhs, const Offset3D &rhs) -> Offset3D {
  return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
}
inline auto operator==(const Offset3D &lhs, const Offset3D &rhs) -> bool {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
inline auto operator!=(const Offset3D &lhs, const Offset3D &rhs) -> bool {
  return !(lhs == rhs);
}
} // namespace rook::platform