#include "moon/moon.h"
#include "zinc/zinc.h"

auto get_num_optional() -> zinc::option<i32> { return zinc::Some<i32>(42); }

auto some_tuple() -> zinc::tuple<i32, bool> {
  return zinc::make_tuple(69, true);
}