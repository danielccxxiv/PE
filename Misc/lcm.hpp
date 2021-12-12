
#ifndef LCM_HPP
#define LCM_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include "gcd.hpp"

// Well defined only for non-negative inputs excluding (0, 0)
template<class T> T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}

#endif
