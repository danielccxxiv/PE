
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/log1p.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/integer.hpp>
#include <boost/unordered_map.hpp>

#include "../../../../Misc/pow_functions.hpp"

using namespace std;

using namespace boost;
using namespace boost::math;
using namespace boost::math::constants;
using namespace boost::multiprecision;

static unordered_map<long, cpp_bin_float_100> bin_search_map;

cpp_bin_float_100 rand_search_evalue(long n);

cpp_bin_float_100 bin_search_evalue(long n);

#endif
