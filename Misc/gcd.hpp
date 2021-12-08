
#ifndef GCD_HPP
#define GCD_HPP

template<class T> T gcd(T a, T b) {
    if(a < 0) {
        a = -a;
    }
    if(b < 0) {
        b = -b;
    }
	T temp;
	while(b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

#endif
