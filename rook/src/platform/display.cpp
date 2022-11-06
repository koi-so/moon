#include "rook/platform/display.h"

#include <EASTL/sort.h>

namespace rook::platform {
void Display::FinaliseDisplayModes(
    eastl::vector<DisplayAttributes> &display_attributes) {
  eastl::sort(display_attributes.begin(), display_attributes.end(),
              CompareDisplayStrictWeakOrder);
  // TODO: Remove duplicates
  // display_attributes.erase(std::unique(display_attributes.begin(),
  // 																		 display_attributes.end()),
  // 												 display_attributes.end());
}
} // namespace rook::platform