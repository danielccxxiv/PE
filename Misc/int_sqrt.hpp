
#ifndef INT_SQRT_HPP
#define INT_SQRT_HPP

#include <boost/multiprecision/cpp_int.hpp>

// Modern architecture has built in sqrt operation for floats which is faster
// than integer division

// template<class T> T int_sqrt(const T& num) {
//     return boost::multiprecision::sqrt(num);
// }
//
// template<> int32_t int_sqrt<int32_t>(const int32_t& num) {
//     if(num < 0) {
//         throw "int_sqrt<int32_t>(int32_t num): num less than 0";
//     }
//     return static_cast<int32_t>(std::sqrt(static_cast<double>(num)));
// }
//
// template<> uint32_t int_sqrt<uint32_t>(const uint32_t& num) {
//     return static_cast<uint32_t>(std::sqrt(static_cast<double>(num)));
// }
//
// template<> int64_t int_sqrt<int64_t>(const int64_t& num) {
//     if(num < 0) {
//         throw "int_sqrt<int64_t>(int64_t num): num less than 0";
//     }
//     if(num >> 52) {
//         int64_t num_sqrt = static_cast<int64_t>(std::sqrt(static_cast<double>(num - static_cast<int64_t>(0x04000000))));
//         return ((num > (num_sqrt * (num_sqrt + static_cast<int64_t>(2)))) ? (++num_sqrt) : num_sqrt);
//     } else {
//         return static_cast<int64_t>(std::sqrt(static_cast<double>(num)));
//     }
// }
//
// template<> uint64_t int_sqrt<uint64_t>(const uint64_t& num) {
//     if(num >> 52) {
//         uint64_t num_sqrt = static_cast<uint64_t>(std::sqrt(static_cast<double>(num - static_cast<uint64_t>(0x04000000))));
//         return ((num > (num_sqrt * (num_sqrt + static_cast<uint64_t>(2)))) ? (++num_sqrt) : num_sqrt);
//     } else {
//         return static_cast<uint64_t>(std::sqrt(static_cast<double>(num)));
//     }
// }

#endif
