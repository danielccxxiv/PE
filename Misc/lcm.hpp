
#ifndef LCM_HPP
#define LCM_HPP

#include "gcd.hpp"

template<class T> T lcm(T a, T b) {
	return (a / gcd(a, b)) * b;
}

#endif
