
#ifndef POW_FUNCTIONS_HPP
#define POW_FUNCTIONS_HPP

#include <stdexcept>

static bool pow_mod_safety = false;

// Throws exception for negative exponents
template<class T, class E> T pow(T base, E exponent) {
    if(exponent < 0) {
        throw std::invalid_argument("pow: negative exponent");
    }
	if(exponent == 0) {
		return (T) 1;
	}
    T result = 1;
    while(exponent != 0) {
        if(exponent % 2 == 0) {
            base *= base;
            exponent /= 2;
        } else {
            result *= base;
            exponent -= 1;
        }
    }
	return result;
}

// Throws exception for negative exponents and mod less than 2
template<class T, class E> T pow_mod(T base, E exponent, T mod, bool safety = false) {
    if(mod < 2) {
        throw std::invalid_argument("pow_mod: mod less than 2");
    }
    if(exponent < 0) {
        throw std::invalid_argument("pow_mod: negative exponent");
    }
    if(exponent == 0) {
		return (T) 1;
	}
    if(base < 0) {
        base = (mod - ((-base) % mod)) % mod;
    } else {
        base = base % mod;
    }
    T result = 1;
    if(safety) {
        T prod;
        T arg0;
        T arg1;
        while(exponent != 0) {
            prod = 0;
            arg0 = base;
            if(exponent % 2 == 0) {
                arg1 = base;
                while(arg0 != 0) {
                    if(arg0 % 2 == 0) {
                        arg1 = (arg1 + arg1) % mod;
                        arg0 /= 2;
                    } else {
                        prod = (prod + arg1) % mod;
                        arg0 -= 1;
                    }
                }
                base = prod;
                exponent /= 2;
            } else {
                arg1 = result;
                while(arg0 != 0) {
                    if(arg0 % 2 == 0) {
                        arg1 = (arg1 + arg1) % mod;
                        arg0 /= 2;
                    } else {
                        prod = (prod + arg1) % mod;
                        arg0 -= 1;
                    }
                }
                result = prod;
                exponent -= 1;
            }
        }
    } else {
        while(exponent != 0) {
            if(exponent % 2 == 0) {
                base = (base * base) % mod;
                exponent /= 2;
            } else {
                result = (result * base) % mod;
                exponent -= 1;
            }
        }
    }
	return result;
}

template<class T> T mult_mod(T a, T b, T mod) {
    if(mod < 2) {
        throw std::invalid_argument("mult_mod: mod less than 2");
    }
    if(a < 0) {
        a = (mod - ((-a) % mod)) % mod;
    } else {
        a = a % mod;
    }
    if(a == 0) {
        return 0;
    }
    if(b < 0) {
        b = (mod - ((-b) % mod)) % mod;
    } else {
        b = b % mod;
    }
	if(b == 0) {
        return 0;
    }
    T result = 0;
    if(b > a) {
        while(a != 0) {
            if(a % 2 == 0) {
                b = (b + b) % mod;
                a /= 2;
            } else {
                result = (result + b) % mod;
                a -= 1;
            }
        }
    } else {
        while(b != 0) {
            if(b % 2 == 0) {
                a = (a + a) % mod;
                b /= 2;
            } else {
                result = (result + a) % mod;
                b -= 1;
            }
        }
    }
	return result;
}

#endif
