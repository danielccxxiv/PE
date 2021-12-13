
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

static int32_t limit = 1000000;
static int32_t* data = new int32_t[limit];

int32_t collatz(int32_t n);

#endif
