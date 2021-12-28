
#ifndef INTEGER_SQRT_HPP
#define INTEGER_SQRT_HPP

#include "../Headers/std_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types_macros.hpp"

#include <algorithm>
#include <cstring>
#include <limits>

//https://stackoverflow.com/a/70414834/17665728

static const uint32_t int_sqrt_32_calc_tab[96] = {
    0xfa0bfafa, 0xee6b2aee, 0xe5f02ae5, 0xdaf26ed9, 0xd2f002d0, 0xc890c2c4, 0xc1037abb, 0xb9a75ab2,
    0xb4da42ac, 0xadcea2a3, 0xa6f27a9a, 0xa279c294, 0x9beb4a8b, 0x97a5ca85, 0x9163427c, 0x8d4fca76,
    0x89500270, 0x8563ba6a, 0x818ac264, 0x7dc4ea5e, 0x7a120258, 0x7671da52, 0x72e4424c, 0x6f690a46,
    0x6db24243, 0x6a52423d, 0x67042637, 0x6563c234, 0x62302a2e, 0x609cea2b, 0x5d836a25, 0x5bfd1a22,
    0x58fd421c, 0x5783ae19, 0x560e4a16, 0x53300210, 0x51c7120d, 0x50623a0a, 0x4da4c204, 0x4c4c1601,
    0x4af769fe, 0x49a6b9fb, 0x485a01f8, 0x471139f5, 0x45cc59f2, 0x448b5def, 0x4214fde9, 0x40df89e6,
    0x3fade1e3, 0x3e8001e0, 0x3d55e1dd, 0x3c2f79da, 0x3c2f79da, 0x3b0cc5d7, 0x39edc1d4, 0x38d265d1,
    0x37baa9ce, 0x36a689cb, 0x359601c8, 0x348909c5, 0x348909c5, 0x337f99c2, 0x3279adbf, 0x317741bc,
    0x30784db9, 0x30784db9, 0x2f7cc9b6, 0x2e84b1b3, 0x2d9001b0, 0x2d9001b0, 0x2c9eb1ad, 0x2bb0b9aa,
    0x2bb0b9aa, 0x2ac615a7, 0x29dec1a4, 0x29dec1a4, 0x28fab5a1, 0x2819e99e, 0x2819e99e, 0x273c599b,
    0x273c599b, 0x26620198, 0x258ad995, 0x258ad995, 0x24b6d992, 0x24b6d992, 0x23e5fd8f, 0x2318418c,
    0x2318418c, 0x224d9d89, 0x224d9d89, 0x21860986, 0x21860986, 0x20c18183, 0x20c18183, 0x20000180
};

inline int32_t int_sqrt_clz32(uint32_t num) {
    if(sizeof(unsigned int) == static_cast<size_t>(4)) {
        return __builtin_clz(num);
    } else if(sizeof(unsigned long) == static_cast<size_t>(4)) {
        return __builtin_clzl(num);
    } else {
        throw "int_sqrt_clz32(uint32_t num): no builtin clz methods for 32-bit unsigned integers";
    }
}

inline int32_t int_sqrt_clz64(uint64_t num) {
    if(sizeof(unsigned int) == static_cast<size_t>(8)) {
        return __builtin_clz(num);
    } else if(sizeof(unsigned long) == static_cast<size_t>(8)) {
        return __builtin_clzl(num);
    } else if (sizeof(unsigned long long) == static_cast<size_t>(8)) {
        return __builtin_clzll(num);
    } else {
        throw "int_sqrt_clz32(uint32_t num): no builtin clz methods for 64-bit unsigned integers";
    }
}

inline uint32_t umul32_hi(uint32_t a, uint32_t b) {
    return static_cast<uint32_t>((static_cast<uint64_t>(a) * b) >> 32);
}

uint32_t uint32_sqrt(const uint32_t num) {
    if(num < 2) {
        return num;
    }
    uint32_t scal = int_sqrt_clz32(num) & 0xFFFFFFFE;
    uint32_t b = num << scal;
    uint32_t t = int_sqrt_32_calc_tab[(b >> 25) - 32];
    uint32_t r = (t << 22) - umul32_hi(b, t);
    r = (umul32_hi(umul32_hi(r, 0x30000000 - umul32_hi(r, umul32_hi(r, b))), b) - 0x00000001) >> ((scal >> 1) + 11);
    if(num > (r * (r + 2))) {
        return ++r;
    } else {
        return r;
    }
}

uint64_t uint64_sqrt(const uint64_t num) {
    int32_t num_digit_count = 64 - int_sqrt_clz64(num);
    if(num_digit_count < 33) {
        return static_cast<uint64_t>(uint32_sqrt(static_cast<uint32_t>(num)));
    }
    int32_t shift_value = (((num_digit_count + 1) >> 1) << 1) - 32;
    uint64_t x = static_cast<uint64_t>(uint32_sqrt(static_cast<uint32_t>(num >> shift_value))) << (shift_value >> 1);
    uint64_t x_delta_numer;
    uint64_t x_delta_denom;
    uint64_t error = num - x * x;
    while(error > (x << 1)) {
        shift_value = std::max(((num_digit_count + 3) >> 1) - int_sqrt_clz64(error), 2);
        error >>= shift_value;
        x_delta_numer = (x * error) << 1;
        x_delta_denom = (num >> (shift_value - 2)) - 3 * error;
        x += ((x_delta_numer >= x_delta_denom) ? (x_delta_numer / x_delta_denom) : 1);
        error = num - x * x;
    }
    return x;
}

#endif























//
