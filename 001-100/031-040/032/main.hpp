
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <boost/unordered_set.hpp>

#include "../../../Misc/Digit_Manipulation/unordered_digit_hash.hpp"

static int64_t pandigital_hash = unordered_digit_hash<int32_t, int32_t, int64_t>(123456789);

void loop(int32_t* arr, int32_t level, boost::unordered_set<int32_t>& data);

#endif
