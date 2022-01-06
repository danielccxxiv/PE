
#ifndef INTEGER_SQRT_HPP
#define INTEGER_SQRT_HPP

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <type_traits>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

template<class T> int32_t isqrt_T_clz(const T& num);

inline int32_t isqrt_int64_clz(const int64_t& num) {
    if(sizeof(unsigned int) == 8) {
        return __builtin_clz(static_cast<uint64_t>(num));
    } else if(sizeof(unsigned long) == 8) {
        return __builtin_clzl(static_cast<uint64_t>(num));
    } else if(sizeof(unsigned long long) == 8) {
        return __builtin_clzll(static_cast<uint64_t>(num));
    } else {
        throw "isqrt_int64_clz(int64_t num): no builtin clz methods for 64-bit unsigned integers";
    }
}

inline int32_t isqrt_uint64_clz(const uint64_t& num) {
    if(sizeof(unsigned int) == 8) {
        return __builtin_clz(static_cast<uint64_t>(num));
    } else if(sizeof(unsigned long) == 8) {
        return __builtin_clzl(static_cast<uint64_t>(num));
    } else if(sizeof(unsigned long long) == 8) {
        return __builtin_clzll(static_cast<uint64_t>(num));
    } else {
        throw "isqrt_uint64_clz(uint64_t num): no builtin clz methods for 64-bit unsigned integers";
    }
}

template<class T, class R = T, class C = T, bool SIGN_CHECK = true, bool CALCTYPE = false, bool SHIFT = true> R int_sqrt(const T& num) {
    static constexpr int32_t T_digits = (std::numeric_limits<T>::is_bounded ? std::numeric_limits<T>::digits : 0);
    static constexpr int32_t C_digits = (std::numeric_limits<C>::is_bounded ? std::numeric_limits<C>::digits : 0);
    static constexpr bool T_eq_int32 = std::is_same<T, int32_t>::value;
    static constexpr bool T_eq_int64 = std::is_same<T, int64_t>::value;
    static constexpr bool T_cast_uint32 = std::numeric_limits<T>::is_bounded && (T_digits < 33);
    static constexpr bool T_cast_uint64 = std::numeric_limits<T>::is_bounded && (T_digits > 32) && (T_digits < 65);
    static constexpr bool T_fixed_width = std::numeric_limits<T>::is_bounded;
    static constexpr bool C_fixed_width = std::numeric_limits<C>::is_bounded;
    static constexpr bool T_eq_C = std::is_same<T, C>::value;
    static_assert(std::numeric_limits<T>::is_integer);
    static_assert(std::numeric_limits<R>::is_integer);
    static_assert(std::numeric_limits<C>::is_integer);
    static_assert((!(SHIFT)) || ((!(CALCTYPE) && T_fixed_width) || (CALCTYPE && C_fixed_width)));
    if(SIGN_CHECK && std::numeric_limits<T>::is_signed) {
        if(num < static_cast<T>(0)) {
            throw "int_sqrt<T, R, C, SIGN_CHECK, CALCTYPE, SHIFT>(T num): invalid input (num is negative)";
        }
    }
    if(T_eq_int32) {
        return static_cast<R>(static_cast<int32_t>(std::sqrt(static_cast<double>(static_cast<int32_t>(num)))));
    } else if(T_eq_int64) {
        if(isqrt_int64_clz(static_cast<int64_t>(num)) < 12) { // 2 ** 52 or greater
            int64_t num_sqrt = static_cast<int64_t>(std::sqrt(static_cast<double>((static_cast<int64_t>(num) >> 12) << 12)));
            return static_cast<R>((static_cast<int64_t>(num) > (num_sqrt * (num_sqrt + 2))) ? (++num_sqrt) : num_sqrt);
        } else { // less than 2 ** 52
            return static_cast<R>(static_cast<int64_t>(std::sqrt(static_cast<double>(static_cast<int64_t>(num)))));
        }
    } else if(T_cast_uint32) {
        return static_cast<R>(static_cast<uint32_t>(std::sqrt(static_cast<double>(static_cast<uint32_t>(num)))));
    } else if(T_cast_uint64) {
        if(isqrt_uint64_clz(static_cast<uint64_t>(num)) < 12) { // 2 ** 52 or greater
            uint64_t num_sqrt = static_cast<uint64_t>(std::sqrt(static_cast<double>((static_cast<uint64_t>(num) >> 12) << 12)));
            return static_cast<R>((static_cast<uint64_t>(num) > (num_sqrt * (num_sqrt + 2))) ? (++num_sqrt) : num_sqrt);
        } else { // less than 2 ** 52
            return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
        }
    } else if((!(CALCTYPE)) || (CALCTYPE && T_eq_C)) {
        if(T_fixed_width) {
            int32_t num_digit_count = T_digits - isqrt_T_clz<T>(num);
            if(num_digit_count < 53) {
                return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
            }
            int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
            T x = (static_cast<T>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num >> shift_value)))))) << (shift_value >> 1);
            T x_delta_numer;
            T x_delta_denom;
            T error = num - (x * x);
            if(SHIFT) {
                while(error > (x << 1)) {
                    shift_value = std::max(((num_digit_count + 3) >> 1) - isqrt_T_clz(error), 2);
                    error >>= shift_value;
                    x_delta_numer = x * error;
                    x_delta_denom = (num >> (shift_value - 2)) - (static_cast<T>(3) * error);
                    x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<T>(1));
                    error = num - (x * x);
                }
            } else {
                T num_cast_denom_term = num << 2;
                while(error > (x << 1)) {
                    x_delta_numer = x * error;
                    x_delta_denom = num_cast_denom_term - (static_cast<T>(3) * error);
                    x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<T>(1));
                    error = num - (x * x);
                }
            }
            return static_cast<R>(x);
        } else {
            int32_t num_digit_count = 64;
            while((num >> num_digit_count) != static_cast<T>(0)) {
                num_digit_count += 64;
            }
            num_digit_count -= isqrt_uint64_clz(static_cast<uint64_t>(num >> (num_digit_count - 64)));
            if(num_digit_count < 53) {
                return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
            }
            int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
            T x = static_cast<T>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num >> shift_value))))) << (shift_value >> 1);
            T x_delta_numer;
            T x_delta_denom;
            T error = num - (x * x);
            T num_cast_denom_term = num << 2;
            while(error > (x << 1)) {
                x_delta_numer = x * error;
                x_delta_denom = num_cast_denom_term - (static_cast<T>(3) * error);
                x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<T>(1));
                error = num - (x * x);
            }
            return static_cast<R>(x);
        }
    } else if(CALCTYPE) {
        if(C_fixed_width) {
            C num_cast = static_cast<C>(num);
            int32_t num_digit_count = C_digits - isqrt_T_clz<C>(num_cast);
            if(num_digit_count < 53) {
                return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num_cast)))));
            }
            int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
            C x = static_cast<C>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num_cast >> shift_value))))) << (shift_value >> 1);
            C x_delta_numer;
            C x_delta_denom;
            C error = num_cast - (x * x);
            if(SHIFT) {
                while(error > (x << 1)) {
                    shift_value = std::max(((num_digit_count + 3) >> 1) - isqrt_T_clz(error), 2);
                    error >>= shift_value;
                    x_delta_numer = x * error;
                    x_delta_denom = (num_cast >> (shift_value - 2)) - (static_cast<C>(3) * error);
                    x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<C>(1));
                    error = num_cast - (x * x);
                }
            } else {
                C num_cast_denom_term = num_cast << 2;
                while(error > (x << 1)) {
                    x_delta_numer = x * error;
                    x_delta_denom = num_cast_denom_term - (static_cast<C>(3) * error);
                    x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<C>(1));
                    error = num_cast - (x * x);
                }
            }
            return static_cast<R>(x);
        } else {
            C num_cast = static_cast<C>(num);
            int32_t num_digit_count = 64;
            while((num_cast >> num_digit_count) != static_cast<C>(0)) {
                num_digit_count += 64;
            }
            num_digit_count -= isqrt_uint64_clz(static_cast<uint64_t>(num_cast >> (num_digit_count - 64)));
            if(num_digit_count < 53) {
                return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num_cast)))));
            }
            int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
            C x = static_cast<C>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num >> shift_value))))) << (shift_value >> 1);
            C x_delta_numer;
            C x_delta_denom;
            C error = num_cast - (x * x);
            C num_cast_denom_term = num_cast << 2;
            while(error > (x << 1)) {
                x_delta_numer = x * error;
                x_delta_denom = num_cast_denom_term - (static_cast<C>(3) * error);
                x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : static_cast<C>(1));
                error = num_cast - (x * x);
            }
            return static_cast<R>(x);
        }
    } else {
        throw "int_sqrt<T, R, C, INT_SQRT_SAFETY_CHECK, INT_SQRT_CALCTYPE>(T num): typecheck implementation";
    }
}

template<class T> int32_t isqrt_T_clz(const T& num) {
    static constexpr int32_t T_digits = (std::numeric_limits<T>::is_bounded ? std::numeric_limits<T>::digits : 0);
    static constexpr int32_t T_align_64 = ((std::numeric_limits<T>::is_bounded ? (std::numeric_limits<T>::digits + 63) : 0) >> 6) << 6;
    int32_t num_clz;
    for(int32_t i = 0; i < (T_align_64 / 64); i++) {
        num_clz = isqrt_uint64_clz(static_cast<uint64_t>(num >> (T_align_64 - ((i + 1) << 6))));
        if(num_clz != 64) {
            return ((T_digits - T_align_64) + (i << 6) + num_clz);
        }
    }
    return T_digits;
}

#endif
