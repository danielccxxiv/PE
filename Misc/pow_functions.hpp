
#ifndef POW_FUNCTIONS_HPP
#define POW_FUNCTIONS_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

// Expected sanitization of inputs:
// both integer types, non-negative exponent
template<class T, class E> T pow_int(T base, E exponent) {
    T result = 1;
    while(exponent != 0) {
        if(exponent & 1) {
            result *= base;
            exponent -= 1;
        } else {
            base *= base;
            exponent >>= 1;
        }
    }
	return result;
}

// Template with no safety (possible overflows)
// Expected sanitization of inputs:
// both integer types, non-negative base, non-negative exponent, mod greater than 1
template<class T, class E> T pow_int_mod(T base, E exponent, T mod) {
    if(base >= mod) {
        base = base % mod;
    }
    T result = 1;
    while(exponent != 0) {
        if(exponent & 1) {
            result = (result * base) % mod;
            exponent -= 1;
        } else {
            base = (base * base) % mod;
            exponent >>= 1;
        }
    }
    return result;
}

// Template with some safety (overflow handling)
// Expected sanitization of inputs:
// both integer types, non-negative base, non-negative exponent, mod greater than 1
template<class T, class E> T pow_int_mod_ofl_check(T base, E exponent, T mod) {
    if(base >= mod) {
        base = base % mod;
    }
    T result = 1;
    T prod;
    T arg0;
    T arg1;
    T temp;
    while(exponent != 0) {
        prod = 0;
        arg0 = base;
        if(exponent & 1) {
            arg1 = result;
            while(arg0 != 0) {
                temp = mod - arg1;
                if(arg0 & 1) {
                    if(prod < temp) {
                        prod += arg1;
                    } else {
                        prod -= temp;
                    }
                    arg0 -= 1;
                } else {
                    if(arg1 < temp) {
                        arg1 += arg1;
                    } else {
                        arg1 -= temp;
                    }
                    arg0 >>= 1;
                }
            }
            result = prod;
            exponent -= 1;
        } else {
            arg1 = base;
            while(arg0 != 0) {
                temp = mod - arg1;
                if(arg0 & 1) {
                    if(prod < temp) {
                        prod += arg1;
                    } else {
                        prod -= temp;
                    }
                    arg0 -= 1;
                } else {
                    if(arg1 < temp) {
                        arg1 += arg1;
                    } else {
                        arg1 -= temp;
                    }
                    arg0 >>= 1;
                }
            }
            base = prod;
            exponent >>= 1;
        }
    }
    return result;
}

// Expected sanitization of inputs:
// integer type, mod greater than 1
template<class T> T mult_int_mod(T a, T b, T mod) {
    if(a < 0) {
        a = (mod - ((-a) % mod)) % mod;
    } else if(a >= mod) {
        a = a % mod;
    }
    if(b < 0) {
        b = (mod - ((-b) % mod)) % mod;
    } else if(b >= mod){
        b = b % mod;
    }
    T result = 0;
    T temp;
    if(b > a) {
        while(a != 0) {
            temp = mod - b;
            if(a & 1) {
                if(result < temp) {
                    result += b;
                } else {
                    result -= temp;
                }
                a -= 1;
            } else {
                if(b < temp) {
                    b += b;
                } else {
                    b -= temp;
                }
                a >>= 1;
            }
        }
    } else {
        while(b != 0) {
            temp = mod - a;
            if(b & 1) {
                if(result < temp) {
                    result += a;
                } else {
                    result -= temp;
                }
                b -= 1;
            } else {
                if(a < temp) {
                    a += a;
                } else {
                    a -= temp;
                }
                b >>= 1;
            }
        }
    }
	return result;
}

#endif
