
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/multiprecision/cpp_bin_float.hpp>

using namespace std;

using namespace boost::multiprecision;

static const long N = 10000000000;
static const int T = 4000;
static const int K = 200;
static cpp_bin_float_100 c = 0;

cpp_bin_float_100 term_integrate(long n, int j);

#endif
