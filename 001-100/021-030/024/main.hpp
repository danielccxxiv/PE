
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

#include "../../../Misc/Sequences/factorial.hpp"

static const uint32_t N = 10;
static const uint64_t val = 999999;

void lex_reorder(uint32_t* arr, uint32_t len, uint64_t val);

#endif
