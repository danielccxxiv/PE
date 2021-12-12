
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

static uint32_t limit = 1000000;
static int32_t* data = new int32_t[limit];

int32_t collatz(uint32_t n);

#endif
