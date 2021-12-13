
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <vector>

#include "../../../Misc/floor_sqrt.hpp"

int64_t pentagonal(int32_t n);
bool is_pentagonal(int64_t num);

#endif
