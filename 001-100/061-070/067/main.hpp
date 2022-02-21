
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <algorithm>
#include <cstring>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

static size_t N = 100;

void read_file(std::string filename, int32_t** param);

#endif
