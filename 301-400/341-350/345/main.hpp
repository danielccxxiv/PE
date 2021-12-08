
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include "../../../../Misc/bit_count.hpp"

using namespace std;

using namespace boost;

static const int N = 15;

int read_file(char* filename, int** param);

#endif
