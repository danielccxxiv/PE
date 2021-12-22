
#ifndef INTEGER_SQRT_HPP
#define INTEGER_SQRT_HPP

#include "../Headers/std_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types.hpp"
#include "../Headers/boost_integer_numeric_types_macros.hpp"

#include <cstring>

template<class T> int32_t int_sqrt_lg_bit_loop_max() {
    size_t max_bits_check = std::numeric_limits<T>::digits >> 1;
    size_t lg_bit_loop = 1;
    while(max_bits_check) {
        max_bits_check >>= 1;
        lg_bit_loop <<= 1;
    }
    return lg_bit_loop;
}

template<class T> T int_sqrt(T num) {
    static_assert(std::numeric_limits<T>::is_integer);
    if(std::numeric_limits<T>::is_signed) {
        if(num < 0) {
            throw "int_sqrt<T>(T num): negative input";
        }
    }
    if(std::numeric_limits<T>::is_bounded && (std::numeric_limits<T>::digits & 1)) {
        BOOST_UINT(std::numeric_limits<T>::digits + 1) num_cast = static_cast<BOOST_UINT(std::numeric_limits<T>::digits + 1)>(num);

    }
}
















//


template<> int32_t floor_sqrt<int32_t>(int32_t num) {
    if(num < 0) {
        throw "floor_sqrt<int32_t>: negative input";
    } else if(num == 0) {
        return 0;
    }
    int32_t x = 1;
    int32_t lg_test = num;
    if(lg_test >> 16) {
        lg_test >>= 16;
        x <<= 8;
    }
    if(lg_test >> 8) {
        lg_test >>= 8;
        x <<= 4;
    }
    if(lg_test >> 4) {
        lg_test >>= 4;
        x <<= 2;
    }
    if(lg_test >> 2) {
        lg_test >>= 2;
        x <<= 1;
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    int32_t y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

template<> uint32_t floor_sqrt<uint32_t>(uint32_t num) {
    if(num == 0) {
        return 0;
    }
    uint32_t x = 1;
    uint32_t lg_test = num;
    if(lg_test >> 16) {
        lg_test >>= 16;
        x <<= 8;
    }
    if(lg_test >> 8) {
        lg_test >>= 8;
        x <<= 4;
    }
    if(lg_test >> 4) {
        lg_test >>= 4;
        x <<= 2;
    }
    if(lg_test >> 2) {
        lg_test >>= 2;
        x <<= 1;
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    uint32_t y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

template<> int64_t floor_sqrt<int64_t>(int64_t num) {
    if(num < 0) {
        throw "floor_sqrt<int64_t>: negative input";
    } else if(num == 0) {
        return 0;
    }
    int64_t x = 1;
    int64_t lg_test = num;
    if(lg_test >> 32) {
        lg_test >>= 32;
        x <<= 16;
    }
    if(lg_test >> 16) {
        lg_test >>= 16;
        x <<= 8;
    }
    if(lg_test >> 8) {
        lg_test >>= 8;
        x <<= 4;
    }
    if(lg_test >> 4) {
        lg_test >>= 4;
        x <<= 2;
    }
    if(lg_test >> 2) {
        lg_test >>= 2;
        x <<= 1;
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    int64_t y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

template<> uint64_t floor_sqrt<uint64_t>(uint64_t num) {
    if(num == 0) {
        return 0;
    }
    uint64_t x = 1;
    uint64_t lg_test = num;
    if(lg_test >> 32) {
        lg_test >>= 32;
        x <<= 16;
    }
    if(lg_test >> 16) {
        lg_test >>= 16;
        x <<= 8;
    }
    if(lg_test >> 8) {
        lg_test >>= 8;
        x <<= 4;
    }
    if(lg_test >> 4) {
        lg_test >>= 4;
        x <<= 2;
    }
    if(lg_test >> 2) {
        lg_test >>= 2;
        x <<= 1;
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    uint64_t y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

// template<> int128_t floor_sqrt<int128_t>(int128_t num) {
//     if(num < 0) {
//         throw "floor_sqrt<int128_t>: negative input";
//     } else if(num == 0) {
//         return 0;
//     }
//     int128_t x = 1;
//     int128_t lg_test = num;
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     int128_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> uint128_t floor_sqrt<uint128_t>(uint128_t num) {
//     if(num == 0) {
//         return 0;
//     }
//     uint128_t x = 1;
//     uint128_t lg_test = num;
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     uint128_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> int256_t floor_sqrt<int256_t>(int256_t num) {
//     if(num < 0) {
//         throw "floor_sqrt<int256_t>: negative input";;
//     } else if(num == 0) {
//         return 0;
//     }
//     int256_t x = 1;
//     int256_t lg_test = num;
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     int256_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> uint256_t floor_sqrt<uint256_t>(uint256_t num) {
//     if(num == 0) {
//         return 0;
//     }
//     uint256_t x = 1;
//     uint256_t lg_test = num;
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     uint256_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> int512_t floor_sqrt<int512_t>(int512_t num) {
//     if(num < 0) {
//         throw "floor_sqrt<int512_t>: negative input";
//     } else if(num == 0) {
//         return 0;
//     }
//     int512_t x = 1;
//     int512_t lg_test = num;
//     if(lg_test >> 256) {
//         lg_test >>= 256;
//         x <<= 128;
//     }
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     int512_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> uint512_t floor_sqrt<uint512_t>(uint512_t num) {
//     if(num == 0) {
//         return 0;
//     }
//     uint512_t x = 1;
//     uint512_t lg_test = num;
//     if(lg_test >> 256) {
//         lg_test >>= 256;
//         x <<= 128;
//     }
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     uint512_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> int1024_t floor_sqrt<int1024_t>(int1024_t num) {
//     if(num < 0) {
//         throw "floor_sqrt<int1024_t>: negative input";
//     } else if(num == 0) {
//         return 0;
//     }
//     int1024_t x = 1;
//     int1024_t lg_test = num;
//     if(lg_test >> 512) {
//         lg_test >>= 512;
//         x <<= 256;
//     }
//     if(lg_test >> 256) {
//         lg_test >>= 256;
//         x <<= 128;
//     }
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     int1024_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }
//
// template<> uint1024_t floor_sqrt<uint1024_t>(uint1024_t num) {
//     if(num == 0) {
//         return 0;
//     }
//     uint1024_t x = 1;
//     uint1024_t lg_test = num;
//     if(lg_test >> 512) {
//         lg_test >>= 512;
//         x <<= 256;
//     }
//     if(lg_test >> 256) {
//         lg_test >>= 256;
//         x <<= 128;
//     }
//     if(lg_test >> 128) {
//         lg_test >>= 128;
//         x <<= 64;
//     }
//     if(lg_test >> 64) {
//         lg_test >>= 64;
//         x <<= 32;
//     }
//     if(lg_test >> 32) {
//         lg_test >>= 32;
//         x <<= 16;
//     }
//     if(lg_test >> 16) {
//         lg_test >>= 16;
//         x <<= 8;
//     }
//     if(lg_test >> 8) {
//         lg_test >>= 8;
//         x <<= 4;
//     }
//     if(lg_test >> 4) {
//         lg_test >>= 4;
//         x <<= 2;
//     }
//     if(lg_test >> 2) {
//         lg_test >>= 2;
//         x <<= 1;
//     }
//     if(lg_test >> 1) {
//         x <<= 1;
//     } else {
//         x |= (x >> 1);
//     }
//     uint1024_t y = (x + (num / x)) >> 1;
//     while(x > y) {
//         x = y;
//         y = (x + (num / x)) >> 1;
//     }
//     return x;
// }

template<> cpp_int floor_sqrt(cpp_int num) {
    if(num < 0) {
        throw "floor_sqrt<cpp_int>: negative input";
    } else if(num == 0) {
        return 0;
    }
    size_t lg_num = 1;
    cpp_int lg_test = 2;
    if(lg_test <= num) {
        lg_test <<= 1;
    }
    while(lg_test <= num) {
        lg_num <<= 1;
        lg_test <<= lg_num;
    }
    lg_test = num;
    cpp_int x = 1;
    while(lg_num > 1) {
        if(lg_test >> lg_num) {
            lg_test >>= lg_num;
            lg_num >>= 1;
            x <<= lg_num;
        }
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    cpp_int y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

template<class T> T floor_sqrt(T num) {
    static const size_t lg_bit_loop_max = floor_sqrt_lg_bit_loop_max<T>();
    if(num < 0) {
        throw "floor_sqrt<T>: negative input";
    } else if(num == 0) {
        return 0;
    }
    size_t lg_bit_loop = lg_bit_loop_max;
    T x = 1;
    T lg_test = num;
    while(lg_bit_loop > 1) {
        if(lg_test >> lg_bit_loop) {
            lg_test >>= lg_bit_loop;
            lg_bit_loop >>= 1;
            x <<= lg_bit_loop;
        } else {
            lg_bit_loop >>= 1;
        }
    }
    if(lg_test >> 1) {
        x <<= 1;
    } else {
        x |= (x >> 1);
    }
    T y = (x + (num / x)) >> 1;
    while(x > y) {
        x = y;
        y = (x + (num / x)) >> 1;
    }
    return x;
}

#endif
