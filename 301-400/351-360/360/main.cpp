
#include "main.hpp"

int main(int argc, char** argv) {
	unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m = new unordered_map<long, unordered_set<sq_pair, sq_hash>*>;
	int* primes;
	int p_len;
	primes = prime_gen(MAX_PRIME, &p_len);
	sq_pair** q = new sq_pair*[1];
	q[0] = new sq_pair;
	(q[0])->a = 0;
	(q[0])->b = 0;
	insert_pairs(m, 0, q, 1);
	q = new sq_pair*[1];
	q[0] = new sq_pair;
	(q[0])->a = 0;
	(q[0])->b = 1;
	insert_pairs(m, 1, q, 1);
	q = new sq_pair*[1];
	q[0] = new sq_pair;
	(q[0])->a = 1;
	(q[0])->b = 1;
	insert_pairs(m, 2, q, 1);

	long sum = 0;
	long a;
	long b;
	long c;
	long lim0 = MAX_PRIME;
	long lim1 = (long)(MAX_PRIME / std::sqrt(2));
	long lim2 = (long)(MAX_PRIME / std::sqrt(3));
	unordered_set<sq_pair, sq_hash>* w;
	for(c = MAX_PRIME; c > lim2; c--) {
		w = find_pairs(m, lim0 * lim0 - c * c, primes, p_len);
		for(const auto &elem : *w) {
			if(b > c) {
				continue;
			}
			a = (&elem)->a;
			b = (&elem)-> b;
			if(a == 0) {
				if(b == 0) {
					sum += (6 * c);
				} else if(b == c) {
					sum += (12 * (b + c));
				} else {
					sum += (24 * (b + c));
				}
			} else if(a == b) {
				if(b == c) {
					sum += (8 * (a + b + c));
				} else {
					sum += (24 * (a + b + c));
				}
			} else if(b == c) {
				sum += (24 * (a + b + c));
			} else {
				sum += (48 * (a + b + c));
			}
		}
	}

	return sum * 1024;
}

unordered_set<sq_pair, sq_hash>* find_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n, int* primes, int p_len) {
	if(m->count(n) == 1) {
		return m->at(n);
	}
	//////////////////for (int i = 0; i < )
}

int insert_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n, sq_pair** lst, int c) {
	int i;
	unordered_set<sq_pair, sq_hash>* w;
	if(m->count(n) == 0) {
		w = new unordered_set<sq_pair, sq_hash>;
		for(i = 0; i < c; i++) {
			w->insert(*(lst[i]));
		}
		m->insert(make_pair(n, w));
		return 0;
	}
	w = m->at(n);
	for(i = 0; i < c; i++) {
		w->insert(*(lst[i]));
	}
	return 0;
}

int create_pairs(unordered_map<long, unordered_set<sq_pair, sq_hash>*>* m, long n1, long n2, sq_pair** r) {
	unordered_set<sq_pair, sq_hash>* w1 = m->at(n1);
	unordered_set<sq_pair, sq_hash>* w2 = m->at(n2);
	int l1 = w1->size();
	int l2 = w2->size();
	r = new sq_pair*[2 * l1 * l2];
	int i = 0;
	int j = 0;
	for(const auto &elem1 : *w1) {
		for(const auto &elem2 : *w2) {
			combine_pair(&elem1, &elem2, r + 2 * (i * l2 + j));
			j++;
		}
		i++;
	}
	return 0;
}

int combine_pair(const sq_pair* x, const sq_pair* y, sq_pair** r) {
	r[0] = new sq_pair;
	r[1] = new sq_pair;
	r[0]->a = abs(x->a * y->b - x->b * y->a);
	r[0]->b = x->a * y->a + x->b * y->b;
	r[2]->a = abs(x->a * y->a - x->b * y->b);
	r[1]->b = x->a * y->b + x->b * y->a;
	reorder(r[0]);
	reorder(r[1]);
	return 0;
}

int reorder(sq_pair* x) {
	if(x->a > x->b) swap(&(x->a), &(x->b));
	return 0;
}
