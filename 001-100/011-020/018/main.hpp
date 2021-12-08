
#ifndef MAIN_HPP
#define MAIN_HPP

#include <algorithm>
#include <cstring>
#include <iostream>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

static int N = 15;

int read_file(std::string filename, int** param);

#endif
