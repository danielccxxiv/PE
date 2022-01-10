
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

inline int isqrt_uint64_clz(uint64_t num) {
    if(num) {
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
    return 64;
}

template<class C> inline int isqrt_C_clz(C num) {
    static constexpr int C_digits = (std::numeric_limits<C>::is_bounded ? std::numeric_limits<C>::digits : 0);
    static constexpr int C_align_64 = ((std::numeric_limits<C>::is_bounded ? (std::numeric_limits<C>::digits + 63) : 0) >> 6) << 6;
    int num_clz;
    for(int i = 0; i < (C_align_64 / 64); i++) {
        num_clz = isqrt_uint64_clz(static_cast<uint64_t>(num >> (C_align_64 - ((i + 1) << 6))));
        if(num_clz != 64) {
            return ((C_digits - C_align_64) + (i << 6) + num_clz);
        }
    }
    return C_digits;
}

template<class C, class R, bool SHIFT> inline R int_sqrt_details(C num) {
    static constexpr int C_digits = (std::numeric_limits<C>::is_bounded ? std::numeric_limits<C>::digits : 0);
    static constexpr bool C_eq_int32 = std::is_same<C, int32_t>::value;
    static constexpr bool C_eq_int64 = std::is_same<C, int64_t>::value;
    static constexpr bool C_cast_uint32 = std::numeric_limits<C>::is_bounded && (C_digits < 33);
    static constexpr bool C_cast_uint64 = std::numeric_limits<C>::is_bounded && (C_digits > 32) && (C_digits < 65);
    static constexpr bool C_fixed_width = std::numeric_limits<C>::is_bounded;
    if(C_eq_int32) {
        return static_cast<R>(static_cast<int32_t>(std::sqrt(static_cast<double>(static_cast<int32_t>(num)))));
    } else if(C_eq_int64) {
        if(num >> 52) { // 2 ** 52 or greater
            int64_t num_sqrt = static_cast<int64_t>(std::sqrt(static_cast<double>(static_cast<int64_t>(num) - static_cast<int64_t>(0x04000000))));
            return static_cast<R>((static_cast<int64_t>(num) > (num_sqrt * (num_sqrt + static_cast<int64_t>(2)))) ? (++num_sqrt) : num_sqrt);
        } else { // less than 2 ** 52
            return static_cast<R>(static_cast<int64_t>(std::sqrt(static_cast<double>(static_cast<int64_t>(num)))));
        }
    } else if(C_cast_uint32) {
        return static_cast<R>(static_cast<uint32_t>(std::sqrt(static_cast<double>(static_cast<uint32_t>(num)))));
    } else if(C_cast_uint64) {
        if(num >> 52) { // 2 ** 52 or greater
            uint64_t num_sqrt = static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num) - static_cast<uint64_t>(0x04000000))));
            return static_cast<R>((static_cast<uint64_t>(num) > (num_sqrt * (num_sqrt + static_cast<uint64_t>(2)))) ? (++num_sqrt) : num_sqrt);
        } else { // less than 2 ** 52
            return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
        }
    } else if(SHIFT) {
        int num_digit_count = C_digits - isqrt_C_clz<C>(num);
        if(num_digit_count < 53) {
            return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
        }
        int shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
        C x = (static_cast<C>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num >> shift_value)))))) << (shift_value >> 1);
        C error = num - (x * x);
        C x_delta_numer;
        C x_delta_denom;
        while(error > (x << 1)) {
            shift_value = std::max(((num_digit_count + 1) >> 1) - isqrt_C_clz(error), 1);
            error >>= (shift_value--);
            x_delta_numer = x * error;
            x_delta_denom = (num >> shift_value) - (error + (error >> 1));
            if(x_delta_numer >= x_delta_denom) {
                x += (x_delta_numer / x_delta_denom);
            } else {
                return static_cast<R>(++x);
            }
            error = num - (x * x);
        }
        return static_cast<R>(x);
    } else {
        int num_digit_count = (C_fixed_width ? (C_digits - isqrt_C_clz<C>(num)) : 64);
        if(!(C_fixed_width)) {
            while((num >> num_digit_count) != static_cast<C>(0)) {
                num_digit_count += 64;
            }
            num_digit_count -= isqrt_uint64_clz(static_cast<uint64_t>(num >> (num_digit_count - 64)));
        }
        if(num_digit_count < 53) {
            return static_cast<R>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num)))));
        }
        int shift_value = (((num_digit_count + 1) >> 1) << 1) - 52;
        C x = (static_cast<C>(static_cast<uint64_t>(std::sqrt(static_cast<double>(static_cast<uint64_t>(num >> shift_value)))))) << (shift_value >> 1);
        C error = num - (x * x);
        C num_cast_denom_term = num << 1;
        C x_delta_numer;
        C x_delta_denom;
        while(error > (x << 1)) {
            x_delta_numer = x * error;
            x_delta_denom = num_cast_denom_term - (error + (error >> 1));
            if(x_delta_numer >= x_delta_denom) {
                x += (x_delta_numer / x_delta_denom);
            } else {
                return static_cast<R>(++x);
            }
            error = num - (x * x);
        }
        return static_cast<R>(x);
    }
}

template<class T, class R = T, class C = T, bool SIGN_CHECK = true, bool SHIFT = std::numeric_limits<C>::is_bounded> R int_sqrt(T num) {
    static_assert(std::numeric_limits<T>::is_integer);
    static_assert(std::numeric_limits<R>::is_integer);
    static_assert(std::numeric_limits<C>::is_integer);
    static_assert((!(SHIFT)) || std::numeric_limits<C>::is_bounded);
    if(std::is_same<T, C>::value) {
        if(SIGN_CHECK && std::numeric_limits<C>::is_signed) {
            if(static_cast<C>(num) < static_cast<C>(0)) {
                throw "int_sqrt<T, R, C, SIGN_CHECK, SHIFT>(T num): invalid input (num is negative)";
            }
        }
        return int_sqrt_details<C, R, SHIFT>(static_cast<C>(num));
    } else {
        C num_cast = static_cast<C>(num);
        if(SIGN_CHECK && std::numeric_limits<C>::is_signed) {
            if(num_cast < static_cast<C>(0)) {
                throw "int_sqrt<T, R, C, SIGN_CHECK, SHIFT>(T num): invalid input (num is negative)";
            }
        }
        return int_sqrt_details<C, R, SHIFT>(num_cast);
    }
}

#endif
