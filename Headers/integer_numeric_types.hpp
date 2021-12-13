
#ifndef INTEGER_NUMERIC_TYPES_HPP
#define INTEGER_NUMERIC_TYPES_HPP

#include <cstddef>
#include <cstdint>

#include <boost/multiprecision/cpp_int.hpp>

typedef std::size_t size_t;
typedef std::int8_t int8_t;
typedef std::uint8_t uint8_t;
typedef std::int16_t int16_t;
typedef std::uint16_t uint16_t;
typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef boost::multiprecision::int128_t int128_t;
typedef boost::multiprecision::uint128_t uint128_t;
typedef boost::multiprecision::int256_t int256_t;
typedef boost::multiprecision::uint256_t uint256_t;
typedef boost::multiprecision::int512_t int512_t;
typedef boost::multiprecision::uint512_t uint512_t;
typedef boost::multiprecision::int1024_t int1024_t;
typedef boost::multiprecision::uint1024_t uint1024_t;
typedef boost::multiprecision::cpp_int cpp_int;

#endif
