
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include "../../../../Misc/pow_functions.hpp"

using namespace std;

static const int N = 1000000;
static const int T = 990000;
static const int PM = 524287;

typedef struct disjoint_set {
	int node, rank, size;
	disjoint_set* parent;

	disjoint_set(int node) {
		this->node = node;
		this->parent = this;
		this->rank = 0;
		this->size = 1;
	}

	disjoint_set* find() {
		if (this != parent) {
			parent = parent->find();
		}
		return parent;
	}

	static disjoint_set* merge(disjoint_set* a, disjoint_set* b) {
		a = a->find();
		b = b->find();
		if (a == b) {
			return a;
		}
		if (a->rank > b->rank) {
			b->parent = a;
			a->size += b->size;
		} else if (a->rank < b->rank) {
			a->parent = b;
			b->size += a->size;
		} else {
			b->parent = a;
			a->size += b->size;
			a->rank++;
		}
		return a;
	}
} disjoint_set;

#endif
