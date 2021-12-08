
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>

#include <boost/container/set.hpp>

#include <primesieve.hpp>

#include "../../../Misc/binary_search.hpp"
#include "../../../Misc/pow_functions.hpp"

static boost::container::set<int> wc_primes;
static std::vector<int> prime_list;

int loop_wildcard(bool* wc_arr, int len, int level, int wildcard_limit, int wildcard_count, int offset);
int loop_fill(bool* wc_arr, int len, int level, int base_val, int offset);

#endif
