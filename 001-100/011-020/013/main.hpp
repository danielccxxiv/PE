
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdint>
#include <iostream>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include "../../../Misc/Digit_Manipulation/digit_count.hpp"
#include "../../../Misc/pow_functions.hpp"

typedef boost::multiprecision::uint256_t uint256_t;

static const uint32_t N = 100;

void read_file(std::string filename, uint256_t** param);

#endif
