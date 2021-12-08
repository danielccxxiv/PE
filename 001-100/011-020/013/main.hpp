
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include "../../../Misc/Digit_Manipulation/digit_count.hpp"
#include "../../../Misc/pow_functions.hpp"

typedef boost::multiprecision::int256_t int256_t;

static const int N = 100;

int read_file(std::string filename, int256_t** param);

#endif
