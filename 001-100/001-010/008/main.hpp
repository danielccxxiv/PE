
#ifndef MAIN_HPP
#define	MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <boost/filesystem/fstream.hpp>

static const size_t num_len = 1000;
static const size_t prod_len = 13;

void read_file(std::string filename, int32_t** param);
int64_t product(int32_t* digits, size_t start);

#endif
