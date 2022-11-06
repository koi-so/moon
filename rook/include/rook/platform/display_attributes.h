#pragma once

#include "rook/base.h"

#include "spatial.h"

#include <cstdint>

namespace rook::platform {
struct DisplayAttributes {
  Extent2D resolution;
  uint32_t refresh_rate{0};
};

// operators
inline auto operator==(const DisplayAttributes &lhs,
                       const DisplayAttributes &rhs) -> bool {
  return lhs.resolution == rhs.resolution &&
         lhs.refresh_rate == rhs.refresh_rate;
};
inline auto operator!=(const DisplayAttributes &lhs,
                       const DisplayAttributes &rhs) -> bool {
  return !(lhs == rhs);
};

auto ROOK_API CompareDisplayStrictWeakOrder(DisplayAttributes const &lhs,
                                            DisplayAttributes const &rhs)
    -> bool;

auto ROOK_API GetExtentRatio(Extent2D const &extent) -> Extent2D;
} // namespace rook::platform