
#ifndef GCD_HPP
#define GCD_HPP

// #include <cstdlib>

// Standard euclidean algorithm implementation as seen on
// https://en.wikipedia.org/wiki/Euclidean_algorithm

// template<class T> T gcd(const T& a, const T& b) {
// 	T a_cast = a;
// 	T b_cast = b;
// 	T t;
// 	while(b_cast != 0) {
// 		t = b_cast;
// 		b_cast = a_cast % b_cast;
// 		a_cast = t;
// 	}
// 	return a_cast;
// }
//
// template<class T> T lcm(const T& a, const T& b) {
// 	return (a / gcd(a, b)) * b;
// }

// Solutions to the equation at + bs = gcd(a, b), where a and b are given
// non-negative integers.
// The return value is r and the values t and s are returned through the pointer
// parameters (exceptions in the NULL pointer case). The value of t is always
// guaranteed to be greater or equal to 0.
//
// The implementation is given by
// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

template<class T> T ext_gcd(const T& a, const T& b, T* t_return, T* s_return) {
	if(a <= 0) {
		throw "ext_gcd with bad argument: a <= 0";
	}
	if(b <= 0) {
		throw "ext_gcd with bad argument: b <= 0";
	}
	T old_r = a;
	T r = b;
	T old_s = 1;
	T s = 0;
	T old_t = 0;
	T t = 1;
	T quotient;
	T temp;
	while(r != 0) {
		quotient = old_r / r;
		temp = old_r;
		old_r = r;
		r = temp - quotient * r;
		temp = old_s;
		old_s = s;
		s = (temp + (a - quotient * s)) % a;
		temp = old_t;
		old_t = t;
		t = (temp + (b - quotient * t)) % b;
	}
	if(t_return != nullptr) {
		*t_return = old_t;
	}
	if(s_return != nullptr) {
		*s_return = old_s;
	}
	return old_r;
}

#endif



















//
