
#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>

#include <boost/functional/hash.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

#include "../../../../Misc/functions.hpp"
#include "../../../../Misc/Sort/sort.hpp"

#define MAX_PRIME 9765625

using namespace std;

using namespace boost::multiprecision;

struct sq_pair {
	long a, b;

	bool operator==(const sq_pair& o) const {
		return a == (&o)->a and b == (&o)->b;
	}
};

struct sq_hash {
	size_t operator()(const sq_pair& k) const {
		size_t seed = 0;
		boost::hash_combine(seed, boost::hash_value((&k)->a));
		boost::hash_combine(seed, boost::hash_value((&k)->b));
		return seed;
	}
};

long problem();

unordered_set<sq_pair, sq_hash>* find_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n, int* primes, int p_len);

int insert_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n, sq_pair** lst, int c);

int create_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n1, long n2, sq_pair** r);

int combine_pair(const sq_pair* x, const sq_pair* y, sq_pair**);

int reorder(sq_pair* x);

#endif
