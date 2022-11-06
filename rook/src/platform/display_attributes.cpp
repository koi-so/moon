#include "rook/platform/display_attributes.h"

namespace rook::platform {
auto ROOK_API CompareDisplayStrictWeakOrder(DisplayAttributes const &lhs,
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

static auto ComputeGCD(uint32_t a, uint32_t b) -> uint32_t {
  while (b != 0) {
    auto r = a % b;
    a = b;
    b = r;
  }
  return a;
}

auto ROOK_API GetExtentRatio(Extent2D const &extent) -> Extent2D {
  auto gcd = ComputeGCD(extent.width, extent.height);
  return {extent.width / gcd, extent.height / gcd};
}
} // namespace rook::platform