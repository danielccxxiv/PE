
#ifndef GCD_HPP
#define GCD_HPP

#include "../Headers/std_integer_numeric_types.hpp"

template<class T> T gcd(const T& a, const T& b) {
    T a_cast = a;
    T b_cast = b;
	T t;
	while(b_cast != 0) {
		t = b_cast;
		b_cast = a_cast % b_cast;
		a_cast = t;
	}
	return a_cast;
}

template<class T> T lcm(const T& a, const T& b) {
	return (a / gcd(a, b)) * b;
}

#endif
