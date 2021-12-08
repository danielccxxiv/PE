
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <iostream>
#include <string>

#include <boost/filesystem/fstream.hpp>

static const int num_len = 1000;
static const int prod_len = 13;

int read_file(std::string filename, int** param);

long product(int* digits, int start);

#endif
