
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/heap/fibonacci_heap.hpp>

#include "../../../../Misc/Factorize/factorize.hpp"

using namespace std;

using namespace boost::heap;

int add_Aints(fibonacci_heap<int128_t, compare<greater<int128_t> > >& data,
	factors* fact, int128_t p);

int add_Aint_loop(fibonacci_heap<int128_t, compare<greater<int128_t> > >& data,
	int128_t p, int128_t* primes, int* exp, int len, int n, int128_t cur,
	int128_t num, int128_t lim);

#endif
