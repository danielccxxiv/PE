
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <boost/container/set.hpp>

#include "../../../Misc/binary_search.hpp"
#include "../../../Misc/pow_functions.hpp"
#include "../../../Misc/Sequences/prime_sequence.hpp"

static boost::container::set<int32_t> wc_primes;

int32_t loop_wildcard(bool* wc_arr, int32_t len, int32_t level, int32_t wildcard_limit, int32_t wildcard_count, int32_t offset);
int32_t loop_fill(bool* wc_arr, int32_t len, int32_t level, int32_t base_val, int32_t offset);

#endif
