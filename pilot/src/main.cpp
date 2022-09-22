#include "moon/moon.h"
#include "zinc/tuple.h"

#include <iostream>

auto main() -> int {
  auto num = get_num_optional();
  std::cout << num.value() << std::endl;

  auto t = some_tuple();
  std::cout << zinc::get_tuple<0>(t) << std::endl;

  return 0;
}