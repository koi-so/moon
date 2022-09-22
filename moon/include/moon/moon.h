#pragma once

#include "base.h"

MOON_API auto get_num_optional() -> zinc::option<i32>;

MOON_API auto some_tuple() -> zinc::tuple<i32, bool>;