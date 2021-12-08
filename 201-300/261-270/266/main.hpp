
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstdlib>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include "../../../../Misc/pow_functions.hpp"
#include "../../../../Misc/Sort/sort.hpp"

using namespace std;

using namespace boost::multiprecision;

static const uint256_t target = static_cast<uint256_t>("2323218950681478446587180516177954548");
static const int list0[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
	47, 53, 59, 61, 67, 71, 73};
static const int list1[] = {79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
	137, 139, 149, 151, 157, 163, 167, 173, 179, 181};
static const int len0 = 21;
static const int len1 = 21;
static uint256_t* set0;
static uint256_t* set1;

int generate_set(uint256_t* nset, const int list[], int i, int len,
	uint256_t num, int& pos);

#endif
