
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstddef>
#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <boost/multiprecision/cpp_int.hpp>

#include "../../../Misc/Digit_Manipulation/digit_sum.hpp"
#include "../../../Misc/Sequences/factorial.hpp"

typedef boost::multiprecision::int1024_t int1024_t;

#endif
