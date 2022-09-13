#include "moon/moon.h"
#include "zinc/zinc.h"

auto get_num_optional() -> zinc::option<i32> { return zinc::some<i32>(42); }