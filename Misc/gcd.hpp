
#ifndef GCD_HPP
#define GCD_HPP

// Well defined only for non-negative inputs
template<class T> T gcd(T a, T b) {
	T temp;
	while(b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

#endif
