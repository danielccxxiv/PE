
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include "../../../Headers/boost_integer_numeric_types.hpp"
#include <iostream>

#include <cstring>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>

#include "../../../Misc/Digit_Manipulation/digit_count.hpp"
#include "../../../Misc/pow_int.hpp"

static const size_t N = 100;

void read_file(std::string filename, int256_t** param);

#endif
