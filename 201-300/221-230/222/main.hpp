
#ifndef MAIN_HPP
#define MAIN_HPP

#include <algorithm>
#include <cmath>
#include <iostream>

#include "../../../../Misc/bit_count.hpp"

using namespace std;

static int W = 100;
static double Wsqrt = std::sqrt(W);

static const int N = 21;

static int arr[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
	45, 46, 47, 48, 49, 50};

typedef struct config {
	double* len;
	int* last;
	int num;
} config;

#endif
