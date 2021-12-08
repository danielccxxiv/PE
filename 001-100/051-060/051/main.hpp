
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/container/set.hpp>

#include "../../../Misc/binary_search.hpp"
#include "../../../Misc/pow_functions.hpp"
#include "../../../Misc/Sequences/prime.hpp"

static boost::container::set<int> wc_primes;

int loop_wildcard(bool* wc_arr, int len, int level, int wildcard_limit, int wildcard_count, int offset);
int loop_fill(bool* wc_arr, int len, int level, int base_val, int offset);

#endif
