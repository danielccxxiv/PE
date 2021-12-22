
#ifndef INTEGER_POW_FUNCTIONS_HPP
#define INTEGER_POW_FUNCTIONS_HPP

#include "../Headers/std_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types_macros.hpp"

#include <cstring>

template<class T> integer_pow_functions_constants {
    static const T pow_mod_type_cast_limit;
}

template<class T> const integer_pow_functions_constants<T>::T pow_mod_type_cast_limit = floor_sqrt<T>(std::numeric_limits<T>::max()) + 1;

// Expected sanitization of inputs:
// both integer types, non-negative exponent
// class B: base type
// class E: exponent type
// class R: return type
// class C: type used in calculations (choose for no overflow)
template<class B, class E, class R = B, class C = R> R pow_int(B base, E exponent) {
    static_assert(std::numeric_limits<B>::is_integer);
    static_assert(std::numeric_limits<E>::is_integer);
    static_assert(std::numeric_limits<R>::is_integer);
    static_assert(std::numeric_limits<C>::is_integer);
    if(std::numeric_limits<E>::is_signed) {
        if(exponent < 0) {
            throw "pow_int<B, E, R, C>(B base, E exponent): negative exponent";
        }
    }
    if(std::is_same<B, C>::value && std::is_same<C, R>::value) {
        R result = 1;
        while(exponent) {
            if(exponent & 1) {
                result *= base;
                exponent -= 1;
            } else {
                base *= base;
                exponent >>= 1;
            }
        }
        return result;
    } else if(std::is_same<B, C>::value && !(std::is_same<C, R>::value)) {
        C result = 1;
        while(exponent) {
            if(exponent & 1) {
                result *= base;
                exponent -= 1;
            } else {
                base *= base;
                exponent >>= 1;
            }
        }
        return static_cast<R>(result);
    } else if(!(std::is_same<B, C>::value) && std::is_same<C, R>::value) {
        R result = 1;
        R base_cast = static_cast<R>(base);
        while(exponent) {
            if(exponent & 1) {
                result *= base_cast;
                exponent -= 1;
            } else {
                base_cast *= base_cast;
                exponent >>= 1;
            }
        }
        return result;
    } else if(!(std::is_same<B, C>::value) && !(std::is_same<C, R>::value)){
        C result = 1;
        C base_cast = static_cast<C>(base);
        while(exponent) {
            if(exponent & 1) {
                result *= base_cast;
                exponent -= 1;
            } else {
                base_cast *= base_cast;
                exponent >>= 1;
            }
        }
        return static_cast<R>(result);
    } else {
        throw "pow_int<B, E, R, C>(B base, E exponent): implementation error";
    }
}

// Expected sanitization of inputs:
// all integer types, non-negative base, non-negative exponent, mod greater than 1
// class B: base type
// class E: exponent type
// class R: return type
// class C: type used in calculations (choose for no overflow)
// C is void by defualt with specific classes chosen depending on B and R
template<class B, class E, class R = B, class C = void> R pow_int_mod(B base, E exponent, B mod) {
    static_assert(std::numeric_limits<B>::is_integer);
    static_assert(std::numeric_limits<E>::is_integer);
    static_assert(std::numeric_limits<R>::is_integer);
    static_assert(std::is_same<C, void>::value || std::numeric_limits<C>::is_integer);
    if(std::numeric_limits<B>::is_signed) {
        if(base < 0) {
            throw "pow_int_mod<B, E, R, C>(B base, E exponent, B mod): negative base";
        }
    }
    if(std::numeric_limits<E>::is_signed) {
        if(exponent < 0) {
            throw "pow_int_mod<B, E, R, C>(B base, E exponent, B mod): negative exponent";
        }
    }
    if(mod < 2) {
        throw "pow_int_mod<B, E, R, C>(B base, E exponent, B mod): mod less than 2";
    }
    if(std::is_same<C, void>::value && (std::numeric_limits<B>::digits <= 32) && std::is_same<B, R>) {
        if(mod < integer_pow_functions_constants<int32_t>::pow_mod_type_cast_limit) {
            R result = 1;
            base %= mod;
            while(exponent) {
                while(!(exponent & 1)) {
                    base = (base * base) % mod;
                    exponent >>= 1;
                }
                result = (result * base) % mod;
                exponent -= 1;
                // if(exponent & 1) {
                //     result = (result * base) % mod;
                //     exponent -= 1;
                // } else {
                //     base = (base * base) % mod;
                //     exponent >>= 1;
                // }
            }
            return result;
        } else {
            uint64_t result = 1;
            uint64_t base_cast = static_cast<uint64_t>(base);
            uint64_t mod_cast = static_cast<uint64_t>(mod);
            while(exponent) {
                if(exponent & 1) {
                    result = (result * base_cast) % mod_cast;
                    exponent -= 1;
                } else {
                    base_cast = (base_cast * base_cast) % mod_cast;
                    exponent >>= 1;
                }
            }
        }
    }
    if(std::is_same<C, void>::value && std::numeric_limits<B>::is_bounded && std::is_same<B, R>::value) {
        if(mod < integer_pow_functions_constants<B>::pow_mod_type_cast_limit) {
            R result = 1;
            base %= mod;
            while(exponent) {
                if(exponent & 1) {
                    result = (result * base) % mod;
                    exponent -= 1;
                } else {
                    base = (base * base) % mod;
                    exponent >>= 1;
                }
            }
            return result;
        } else {
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) result = 1;
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) base_cast = static_cast<BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2)>(base);
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) mod_cast = static_cast<BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2)>(mod);
            while(exponent) {
                if(exponent & 1) {
                    result = (result * base_cast) % mod_cast;
                    exponent -= 1;
                } else {
                    base_cast = (base_cast * base_cast) % mod_cast;
                    exponent >>= 1;
                }
            }
            return static_cast<R>(result);
        }
    } else if(std::is_same<C, void>::value && std::numeric_limits<B>::is_bounded && !(std::is_same<B, R>::value)) {
        if(mod < integer_pow_functions_constants<B>::pow_mod_type_cast_limit) {
            B result = 1;
            base %= mod;
            while(exponent) {
                if(exponent & 1) {
                    result = (result * base) % mod;
                    exponent -= 1;
                } else {
                    base = (base * base) % mod;
                    exponent >>= 1;
                }
            }
            return static_cast<R>(result);
        } else {
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) result = 1;
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) base_cast = static_cast<BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2)>(base);
            BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2) mod_cast = static_cast<BOOST_UINT(((std::numeric_limits<B>::digits + 1) >> 1) << 2)>(mod);
            while(exponent) {
                if(exponent & 1) {
                    result = (result * base_cast) % mod_cast;
                    exponent -= 1;
                } else {
                    base_cast = (base_cast * base_cast) % mod_cast;
                    exponent >>= 1;
                }
            }
            return static_cast<R>(result);
        }
    } else if(std::is_same<C, void>::value && std::is_same<B, cpp_int>::value && std::is_same<B, cpp_int>::value) {
        R result = 1;
        while(exponent) {
            if(exponent & 1) {
                result = (result * base) % mod;
                exponent -= 1;
            } else {
                base = (base * base) % mod;
                exponent >>= 1;
            }
        }
        return result;
    } else if(std::is_same<C, void>::value && std::is_same<B, cpp_int>::value && !(std::is_same<B, cpp_int>::value)) {
        B result = 1;
        while(exponent) {
            if(exponent & 1) {
                result = (result * base) % mod;
                exponent -= 1;
            } else {
                base = (base * base) % mod;
                exponent >>= 1;
            }
        }
        return static_cast<R>(result);
    } else if(std::is_same<C, void>::value && !(std::is_same<B, cpp_int>::value) && std::is_same<R, cpp_int>::value) {
        R result = 1;
        R base_cast = static_cast<R>(base);
        R mod_cast = static_cast<R>(mod);
        while(exponent) {
            if(exponent & 1) {
                result = (result * base_cast) % mod_cast;
                exponent -= 1;
            } else {
                base_cast = (base_cast * base_cast) % mod_cast;
                exponent >>= 1;
            }
        }
        return result;
    } else if(std::is_same<C, void>::value && !(std::is_same<B, cpp_int>::value) && !(std::is_same<R, cpp_int>::value)) {
        cpp_int result = 1;
        cpp_int base_cast = static_cast<cpp_int>(base);
        cpp_int mod_cast = static_cast<cpp_int>(mod);
        while(exponent) {
            if(exponent & 1) {
                result = (result * base_cast) % mod_cast;
                exponent -= 1;
            } else {
                base_cast = (base_cast * base_cast) % mod_cast;
                exponent >>= 1;
            }
        }
        return static_cast<R>(result);
    } else if(!(std::is_same<C, void>::value) && std::is_same<B, C>::value && std::is_same<C, R>::value) {
        R result = 1;
        while(exponent) {
            if(exponent & 1) {
                result = (result * base) % mod;
                exponent -= 1;
            } else {
                base = (base * base) % mod;
                exponent >>= 1;
            }
        }
        return result;
    } else if(!(std::is_same<C, void>::value) && std::is_same<B, C>::value && !(std::is_same<C, R>::value)) {
        C result = 1;
        while(exponent) {
            if(exponent & 1) {
                result = (result * base) % mod;
                exponent -= 1;
            } else {
                base = (base * base) % mod;
                exponent >>= 1;
            }
        }
        return static_cast<R>(result);
    } else if(!(std::is_same<C, void>::value) && !(std::is_same<B, C>::value) && std::is_same<C, R>::value) {
        R result = 1;
        R base_cast = static_cast<R>(base);
        R mod_cast = static_cast<R>(mod);
        while(exponent) {
            if(exponent & 1) {
                result = (result * base_cast) % mod_cast;
                exponent -= 1;
            } else {
                base_cast = (base_cast * base_cast) % mod_cast;
                exponent >>= 1;
            }
        }
        return result;
    } else if(!(std::is_same<C, void>::value) && !(std::is_same<B, C>::value) && !(std::is_same<C, R>::value)) {
        C result = 1;
        C base_cast = static_cast<C>(base);
        C mod_cast = static_cast<C>(mod);
        while(exponent) {
            if(exponent & 1) {
                result = (result * base_cast) % mod_cast;
                exponent -= 1;
            } else {
                base_cast = (base_cast * base_cast) % mod_cast;
                exponent >>= 1;
            }
        }
        return static<R>(result);
    } else {
        throw "pow_int_mod<B, E, R, C>(B base, E exponent, B mod): implementation error";
    }
}

#endif
