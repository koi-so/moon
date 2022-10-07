#pragma once

#include "moon/base.h"

#include "spatial.h"

namespace moon::platform {
struct DisplayAttributes {
  Extent2D resolution;
  u32 refresh_rate{0};
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

auto MOON_API CompareDisplayStrictWeakOrder(DisplayAttributes const &lhs,
                                            DisplayAttributes const &rhs)
    -> bool;

auto MOON_API GetExtentRatio(Extent2D const &extent) -> Extent2D;
} // namespace moon::platform