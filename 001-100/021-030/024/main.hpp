
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

#include "../../../Misc/Sequences/factorial.hpp"

static const int32_t N = 10;
static const int64_t val = 999999;

void lex_reorder(int32_t* arr, size_t len, int64_t val);

#endif
