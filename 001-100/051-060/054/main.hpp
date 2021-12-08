
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstring>
#include <iostream>
#include <stdexcept>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include "OMPEval/omp/HandEvaluator.h"

static const int N = 1000;

int read_file(std::string filename, int** param);

#endif
