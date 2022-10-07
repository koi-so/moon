#include "moon/platform/display_attributes.h"

namespace moon::platform {
auto MOON_API CompareDisplayStrictWeakOrder(DisplayAttributes const &lhs,
                                            DisplayAttributes const &rhs)
    -> bool {
  const auto lhsNumPixels = lhs.resolution.width * lhs.resolution.height;
  const auto rhsNumPixels = rhs.resolution.width * rhs.resolution.height;

  if (lhsNumPixels < rhsNumPixels)
    return true;
  if (lhsNumPixels > rhsNumPixels)
    return false;

  return (lhs.refresh_rate < rhs.refresh_rate);
}

static auto ComputeGCD(u32 a, u32 b) -> u32 {
  while (b != 0) {
    auto r = a % b;
    a = b;
    b = r;
  }
  return a;
}

auto MOON_API GetExtentRatio(Extent2D const &extent) -> Extent2D {
  auto gcd = ComputeGCD(extent.width, extent.height);
  return {extent.width / gcd, extent.height / gcd};
}
} // namespace moon::platform