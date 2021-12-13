
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

#include <boost/container/set.hpp>

#include "../../../Misc/binary_search.hpp"
#include "../../../Misc/pow_functions.hpp"
#include "../../../Misc/Sequences/prime_sequence.hpp"

static boost::container::set<int32_t> wc_primes;

int32_t loop_wildcard(bool* wc_arr, int32_t len, int32_t level, int32_t wildcard_limit, int32_t wildcard_count, int32_t offset);
int32_t loop_fill(bool* wc_arr, int32_t len, int32_t level, int32_t base_val, int32_t offset);

#endif
