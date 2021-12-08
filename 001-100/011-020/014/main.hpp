
#ifndef MAIN_HPP
#define	MAIN_HPP

#include <iostream>

#include <boost/unordered_map.hpp>

static int limit = 1000000;
static int* data_arr = new int[limit];
static boost::unordered_map<long, int> data_map;
static boost::unordered_map<long, int>::iterator data_iter;

int collatz(long n);

#endif
