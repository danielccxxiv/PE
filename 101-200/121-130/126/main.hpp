
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include <boost/heap/priority_queue.hpp>

typedef struct layer {
	int a, b, c, k, n;

	layer(int a, int b, int c, int k) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->k = k;
		this->n = 4 * k * (k + a + b + c - 1) + 2 * (a * b + a * c + b * c);
	}

	bool operator==(const layer& o) const {
		return (this->a == (&o)->a) && (this->b == (&o)->b)
			&& (this->c == (&o)->c) && (this->k == (&o)->k);
	}
} layer;

typedef struct layer_compare {
	bool operator()(const layer* q1, const layer* q2) const {
		if(q1->n < q2->n) {
			return false;
		}
		if(q1->n > q2->n) {
			return true;
		}
		if(q1->a < q2->a) {
			return false;
		}
		if(q1->a > q2->a) {
			return true;
		}
		if(q1->b < q2->b) {
			return false;
		}
		if(q1->b > q2->b) {
			return true;
		}
		if(q1->c < q2->c) {
			return false;
		}
		if(q1->c > q2->c) {
			return true;
		}
		if(q1->k < q2->k) {
			return false;
		}
		if(q1->k > q2->k) {
			return true;
		}
		return false;
	}
} layer_compare;

layer** next_layers(const layer& l, int* len);

#endif
