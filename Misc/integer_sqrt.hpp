
#ifndef INTEGER_SQRT_HPP
#define INTEGER_SQRT_HPP

#include "../Headers/std_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types_macros.hpp"

#include <algorithm>
#include <cstring>
#include <limits>

template<class T, class R> R int_sqrt_backend_fixed_width(const T& num);
template<class C, class R> R int_sqrt_backend_fixed_width_calctype(const C& num);
template<class T, class R> R int_sqrt_backend_arbitrary_width(const T& num);
uint32_t uint32_sqrt(const uint32_t num);
uint64_t uint64_sqrt(const uint64_t num);

template<class T, class R = T, class C = R, bool INT_SQRT_SAFETY_CHECK = true, bool INT_SQRT_CALCTYPE = false> R int_sqrt(const T num) {
    static_assert(std::numeric_limits<T>::is_integer);
    static_assert(std::numeric_limits<R>::is_integer);
    static_assert(std::numeric_limits<C>::is_integer);
    static constexpr bool T_cast_uint32 = std::numeric_limits<T>::is_bounded && (std::numeric_limits<T>::digits < 33);
    static constexpr bool T_cast_uint64 = std::numeric_limits<T>::is_bounded && (std::numeric_limits<T>::digits > 32) && (std::numeric_limits<T>::digits < 65);
    static constexpr bool T_fixed_width_large = std::numeric_limits<T>::is_bounded && (std::numeric_limits<T>::digits > 64);
    static constexpr bool T_arbitrary_width = !(std::numeric_limits<T>::is_bounded);
    static constexpr bool C_fixed_width_large = std::numeric_limits<C>::is_bounded && (std::numeric_limits<T>::digits > 64);
    static constexpr bool C_arbitrary_width = !(std::numeric_limits<C>::is_bounded);
    if(INT_SQRT_SAFETY_CHECK && std::numeric_limits<T>::is_signed) {
        if(num < 0) {
            throw "int_sqrt<T, R, C, INT_SQRT_SAFETY_CHECK, INT_SQRT_CALCTYPE>(T num): invalid input (num is negative)";
        }
    }
    if(T_cast_uint32) {
        return (R) (uint32_sqrt((uint32_t) num));
    } else if(T_cast_uint64) {
        return (R) (uint64_sqrt((uint64_t) num));
    } else if(T_fixed_width_large && !(INT_SQRT_CALCTYPE)) {
        return int_sqrt_backend_fixed_width<T, R>(num);
    } else if(T_arbitrary_width && !(INT_SQRT_CALCTYPE)) {
        return int_sqrt_backend_arbitrary_width<T, R>(num);
    } else if(C_fixed_width_large && INT_SQRT_CALCTYPE) {
        return int_sqrt_backend_fixed_width_calctype<C, R>((C) num);
    } else if(C_arbitrary_width && INT_SQRT_CALCTYPE) {
        return int_sqrt_backend_arbitrary_width<C, R>((C) num);
    } else {
        throw "int_sqrt<T, R, C, INT_SQRT_SAFETY_CHECK, INT_SQRT_CALCTYPE>(T num): typecheck implementation";
    }
}

inline int32_t isqrt_32_clz(uint32_t num) {
    if(sizeof(unsigned int) == 4) {
        return __builtin_clz(num);
    } else if(sizeof(unsigned long) == 4) {
        return __builtin_clzl(num);
    } else {
        throw "isqrt_32_clz(uint32_t num): no builtin clz methods for 32-bit unsigned integers";
    }
}

inline int32_t isqrt_64_clz(uint64_t num) {
    if(sizeof(unsigned int) == 8) {
        return __builtin_clz(num);
    } else if(sizeof(unsigned long) == 8) {
        return __builtin_clzl(num);
    } else if (sizeof(unsigned long long) == 8) {
        return __builtin_clzll(num);
    } else {
        throw "isqrt_64_clz(uint64_t num): no builtin clz methods for 64-bit unsigned integers";
    }
}

inline uint32_t isqrt_32_mdown(uint32_t a, uint32_t b) {
    return static_cast<uint32_t>((static_cast<uint64_t>(a) * b) >> 32);
}

template<class T, class R> R int_sqrt_backend_fixed_width(const T& num) {
    static constexpr int32_t T_size = (((std::numeric_limits<T>::is_bounded ? std::numeric_limits<T>::digits : 0) + 63) >> 6) << 6;
    int32_t num_digit_count = -1;
    for(int32_t i = 0; i < (T_size / 64); i++) {
        num_digit_count = isqrt_64_clz((uint64_t) (num >> (T_size - ((i + 1) << 6))));
        if(num_digit_count < 64) {
            num_digit_count = T_size - (i << 6) - num_digit_count;
            break;
        } else {
            num_digit_count = -1;
        }
    }
    if(num_digit_count < 33) {
        return (R) (uint32_sqrt((uint32_t) num));
    } else if(num_digit_count < 65) {
        return (R) (uint64_sqrt((uint64_t) num));
    }
    num_digit_count = (((num_digit_count + 1) >> 1) << 1) - 64;
    BOOST_UINT(2 * T_size) num_cast = (BOOST_UINT(2 * T_size)) num;
    BOOST_UINT(2 * T_size) x = ((BOOST_UINT(2 * T_size)) (uint64_sqrt((uint64_t) (num_cast >> num_digit_count)))) << (num_digit_count >> 1);
    BOOST_UINT(2 * T_size) x_delta_numer;
    BOOST_UINT(2 * T_size) x_delta_denom;
    BOOST_UINT(2 * T_size) num_cast_denom_term = num_cast << 2;
    BOOST_UINT(2 * T_size) error = num_cast - (x * x);
    while(error > (x << 1)) {
        x_delta_numer = x * error;
        x_delta_denom = num_cast_denom_term - (3 * error);
        x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : 1);
        error = num_cast - (x * x);
    }
    return (R) x;
}

template<class C, class R> R int_sqrt_backend_fixed_width_calctype(const C& num) {
    static constexpr int32_t C_size = (((std::numeric_limits<C>::is_bounded ? std::numeric_limits<C>::digits : 0) + 63) >> 6) << 6;
    static const C const_0x00000001 = (C) 1;
    int32_t num_digit_count = -1;
    for(int32_t i = 0; i < (C_size / 64); i++) {
        num_digit_count = isqrt_64_clz((uint64_t) (num >> (C_size - ((i + 1) << 6))));
        if(num_digit_count < 64) {
            num_digit_count = C_size - (i << 6) - num_digit_count;
            break;
        } else {
            num_digit_count = -1;
        }
    }
    if(num_digit_count < 33) {
        return (R) (uint32_sqrt((uint32_t) num));
    } else if(num_digit_count < 65) {
        return (R) (uint64_sqrt((uint64_t) num));
    }
    num_digit_count = (((num_digit_count + 1) >> 1) << 1) - 64;
    C x = ((C) (uint64_sqrt((uint64_t) (num >> num_digit_count)))) << (num_digit_count >> 1);
    C x_delta_numer;
    C x_delta_denom;
    C num_cast_denom_term = num << 2;
    C error = num - (x * x);
    while(error > (x << 1)) {
        x_delta_numer = x * error;
        x_delta_denom = num_cast_denom_term - (3 * error);
        x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : const_0x00000001);
        error = num - (x * x);
    }
    return (R) x;
}

template<class T, class R> R int_sqrt_backend_arbitrary_width(const T& num) {
    static const T const_0x00000001 = (T) 1;
    int32_t num_digit_count = 1;
    while((num >> (num_digit_count << 6)) > 0) {
        num_digit_count++;
    }
    if(num_digit_count == 1) {
        return (R) uint64_sqrt((uint64_t) num);
    }
    num_digit_count = (num_digit_count << 6) - isqrt_64_clz((uint64_t) (num >> ((num_digit_count << 6) - 64)));
    num_digit_count = (((num_digit_count + 1) >> 1) << 1) - 64;
    T x = ((T) uint64_sqrt((uint64_t) (num >> num_digit_count))) << (num_digit_count >> 1);
    T x_delta_numer;
    T x_delta_denom;
    T num_cast_denom_term = num << 2;
    T error = num - (x * x);
    while(error > (x << 1)) {
        x_delta_numer = x * error;
        x_delta_denom = num_cast_denom_term - (3 * error);
        x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : const_0x00000001);
        error = num - (x * x);
    }
    return (R) x;
}

static const uint32_t int_sqrt_32_calc_tab[96] = {
    0xFA0BFAFA, 0xEE6B2AEE, 0xE5F02AE5, 0xDAF26ED9, 0xD2F002D0, 0xC890C2C4, 0xC1037ABB, 0xB9A75AB2,
    0xB4DA42AC, 0xADCEA2A3, 0xA6F27A9A, 0xA279C294, 0x9BEB4A8B, 0x97A5CA85, 0x9163427C, 0x8D4FCA76,
    0x89500270, 0x8563BA6A, 0x818AC264, 0x7DC4EA5E, 0x7A120258, 0x7671DA52, 0x72E4424C, 0x6F690A46,
    0x6DB24243, 0x6A52423D, 0x67042637, 0x6563C234, 0x62302A2E, 0x609CEA2B, 0x5D836A25, 0x5BFD1A22,
    0x58FD421C, 0x5783AE19, 0x560E4A16, 0x53300210, 0x51C7120D, 0x50623A0A, 0x4DA4C204, 0x4C4C1601,
    0x4AF769FE, 0x49A6B9FB, 0x485A01F8, 0x471139F5, 0x45CC59F2, 0x448B5DEF, 0x4214FDE9, 0x40DF89E6,
    0x3FADE1E3, 0x3E8001E0, 0x3D55E1DD, 0x3C2F79DA, 0x3C2F79DA, 0x3B0CC5D7, 0x39EDC1D4, 0x38D265D1,
    0x37BAA9CE, 0x36A689CB, 0x359601C8, 0x348909C5, 0x348909C5, 0x337F99C2, 0x3279ADBF, 0x317741BC,
    0x30784DB9, 0x30784DB9, 0x2F7CC9B6, 0x2E84B1B3, 0x2D9001B0, 0x2D9001B0, 0x2C9EB1AD, 0x2BB0B9AA,
    0x2BB0B9AA, 0x2AC615A7, 0x29DEC1A4, 0x29DEC1A4, 0x28FAB5A1, 0x2819E99E, 0x2819E99E, 0x273C599B,
    0x273C599B, 0x26620198, 0x258AD995, 0x258AD995, 0x24B6D992, 0x24B6D992, 0x23E5FD8F, 0x2318418C,
    0x2318418C, 0x224D9D89, 0x224D9D89, 0x21860986, 0x21860986, 0x20C18183, 0x20C18183, 0x20000180
};

uint32_t uint32_sqrt(const uint32_t num) {
    if(num < 2) {
        return num;
    }
    uint32_t scal = isqrt_32_clz(num) & 0xFFFFFFFE;
    uint32_t b = num << scal;
    uint32_t t = int_sqrt_32_calc_tab[(b >> 25) - 32];
    uint32_t r = (t << 22) - isqrt_32_mdown(b, t);
    r = (isqrt_32_mdown(isqrt_32_mdown(r, 0x30000000 - isqrt_32_mdown(r, isqrt_32_mdown(r, b))), b) - 1) >> ((scal >> 1) + 11);
    return (num > (r * (r + 2))) ? (++r) : r;
}

uint64_t uint64_sqrt(const uint64_t num) {
    int32_t num_digit_count = 64 - isqrt_64_clz(num);
    if(num_digit_count < 33) {
        return static_cast<uint64_t>(uint32_sqrt(static_cast<uint32_t>(num)));
    }
    int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 32;
    uint64_t x = static_cast<uint64_t>(uint32_sqrt(static_cast<uint32_t>(num >> shift_value))) << (shift_value >> 1);
    uint64_t x_delta_numer;
    uint64_t x_delta_denom;
    uint64_t error = num - x * x;
    while(error > (x << 1)) {
        shift_value = std::max(((num_digit_count + 3) >> 1) - isqrt_64_clz(error), 2);
        error >>= shift_value;
        x_delta_numer = x * error;
        x_delta_denom = (num >> (shift_value - 2)) - 3 * error;
        x += ((x_delta_numer >= x_delta_denom) ? ((x_delta_numer << 1) / x_delta_denom) : 1);
        error = num - x * x;
    }
    return x;
}

#endif
