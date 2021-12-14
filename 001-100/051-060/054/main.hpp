
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <cstring>
#include <stdexcept>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include "OMPEval/omp/HandEvaluator.h"

static const int32_t N = 1000;

void read_file(std::string filename, int32_t** param);

#endif
