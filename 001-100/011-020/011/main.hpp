
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <algorithm>
#include <iostream>

#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

static const int N = 20;

int read_file(std::string filename, int** param);

#endif
