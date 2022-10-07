#include "moon/platform/display.h"

namespace moon::platform {
void Display::FinaliseDisplayModes(
    zinc::vector<DisplayAttributes> &display_attributes) {
  zinc::sort(display_attributes.begin(), display_attributes.end(),
             CompareDisplayStrictWeakOrder);
  // TODO: Remove duplicates
  // display_attributes.erase(std::unique(display_attributes.begin(),
  // 																		 display_attributes.end()),
  // 												 display_attributes.end());
}
} // namespace moon::platform