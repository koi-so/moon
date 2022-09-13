#include "moon/moon.h"

#include <iostream>

auto main() -> int {
  auto num = get_num_optional();
  std::cout << num.value() << std::endl;
  return 0;
}