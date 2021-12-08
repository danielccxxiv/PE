
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cstring>
#include <iostream>

#include <boost/functional/hash.hpp>
#include <boost/intrusive/unordered_set.hpp>
#include <boost/multiprecision/integer.hpp>

using namespace std;

using namespace boost;
using namespace boost::intrusive;
using namespace boost::multiprecision;

static const int N = 600;
static const int S1 = 4;
static const int S2 = 3;
static const long m = 1000000007;
static long* Comb = new long[(N / S1) * S2];
static const int hash_size = 5000;

typedef struct group : unordered_set_base_hook<> {
	int* count;
	int total;
	long num;
	
	group() {
		count = new int[S1];
		memset(count, '\0', S1 * sizeof(int));
		count[S1 - 1] = N / S1;
		total = N / S2;
		num = 1;
	}
	
	group(group* g) {
		count = new int[S1];
		int i;
		for(i = 0; i < S1; i++) {
			count[i] = g->count[i];
		}
		total = g->total;
		num = g->num;
	}
	
	friend bool operator==(const group& g1, const group& g2) {
		int i;
		for(i = 0; i < S1; i++) {
			if(g1.count[i] != g2.count[i]) {
				return false;
			}
		}
		return true;
	}
	
	friend size_t hash_value(const group& g) {
		size_t seed = 0;
		int i;
		for(i = 0; i < S1; i++) {
			hash_combine(seed, g.count[i]);
		}
		return seed;
	}
} group;

typedef unordered_set<group> u_set;

int next_groups(group* g, u_set& s, u_set::insert_commit_data& s_commit,
	std::pair<u_set::iterator, bool>& ins);

int iter_next_group(group* g, int n, int ll, int* k, u_set& s,
	u_set::insert_commit_data& s_commit, std::pair<u_set::iterator,
	bool>& ins);

int print_group(group* g);

#endif
