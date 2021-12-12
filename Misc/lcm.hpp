
#ifndef LCM_HPP
#define LCM_HPP

#include "gcd.hpp"

// Well defined only for non-negative inputs excluding (0, 0)
template<class T> T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}

#endif
