
#include <cstdint>

#include <boost/math/special_functions/log1p.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

typedef std::int32_t int32_t;
typedef boost::multiprecision::cpp_bin_float_100 cpp_bin_float_100;

template<class T> T gcd(T a, T b) {
	T temp;
	while(b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

template<class T, class E> T pow_int_mod(T base, E exponent, T mod) {
    if(base >= mod) {
        base %= mod;
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

template<class T, class L> bool miller_rabin_det_backend(T num) {
    if(!(num & 1)) {
        return false;
    }
    T d = num >> 1;
    int32_t r = 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    L num_cast = static_cast<L>(num);
    L max_residue = num_cast - 1;
    cpp_bin_float_100 log_val = boost::math::log1p((cpp_bin_float_100) num);
    int32_t limit = static_cast<int32_t>(2.0 * log_val * log_val) + 1;
    L x;
    bool loop_check;
    for(int32_t i = 2; i < limit; i++) {
        if(gcd<T>(num, static_cast<T>(i)) != 1) {
            return false;
        }
        loop_check = true;
        x = pow_int_mod<L, T>(i, d, num_cast);
        if((x != 1) && (x != max_residue)) {
            for(int32_t j = 1; j < r; j++) {
                x = (x * x) % num_cast;
                if(x == max_residue) {
                    loop_check = false;
                    break;
                }
            }
            if(loop_check) {
                return false;
            }
        }
    }
    return true;
}
