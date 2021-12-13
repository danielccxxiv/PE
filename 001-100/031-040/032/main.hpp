
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

#include <boost/unordered_set.hpp>

#include "../../../Misc/Digit_Manipulation/unordered_digit_hash.hpp"

static int64_t pandigital_hash = unordered_digit_hash<int32_t, int32_t, int64_t>(123456789);

void loop(int32_t* arr, int32_t level, boost::unordered_set<int32_t>& data);

#endif
