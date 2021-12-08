
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/math/special_functions/pow.hpp>
#include <boost/math/special_functions/round.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/integer.hpp>
#include <boost/numeric/conversion/cast.hpp>

#include <primecount.hpp>
#include <primesieve.hpp>

using namespace std;

using namespace boost;
using namespace boost::math;
using namespace boost::multiprecision;

static long N = pow(10, 10);
static long lim = boost::multiprecision::sqrt(N);

typedef struct element {
	long num;
	int prime;
	bool sub;
};

cpp_int problem();

#endif
