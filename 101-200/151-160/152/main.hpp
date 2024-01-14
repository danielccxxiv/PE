
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include "../../../Headers/boost_integer_numeric_types.hpp"
#include <iostream>

#include <vector>

static std::vector<int32_t> reciprocal_list = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12,
	13, 14, 15, 16, 18, 20, 21, 24, 27, 28, 30, 32, 35, 36, 39, 40, 42, 45, 48,
	52, 54, 56, 60, 63, 64, 65, 70, 72, 80};

static std::vector<int256_t> element_list;
static std::vector<int256_t> sum_list;
static std::vector<bool> bl;

// static std::vector<int32_t> reciprocal_list = {2, 3, 4, 5, 6, 7, 8, 9, 10,
// 	11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 28, 30,
// 	32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 48, 49, 50, 51, 52, 54, 55,
// 	56, 57, 60, 63, 64, 65, 66, 68, 70, 72, 75, 76, 77, 78, 80};

void loop(int256_t target, int32_t level, int64_t& count);

#endif
