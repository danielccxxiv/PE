
#include "main.hpp"

int main(int argc, char** argv) {
	int128_t p = 1;
	int128_t lim = 5;
	int128_t prev = 0;
	int count = 0;
	fibonacci_heap<int128_t, compare<greater<int128_t> > > data;
	data.push(6);
	factors* fact;
	while(true) {
		if(data.top() == prev) {
			data.pop();
			continue;
		}
		while(data.top() > lim) {
			p++;
			lim = (4 * p * p + 1) * p;
			fact = check_seive(p * p + 1);
			add_Aints(data, fact, p);
		}
		prev = data.top();
		data.pop();
		count++;
		if(count == 150000) {
			break;
		}
	}
	cout << prev << endl;
	return 0;
}

int add_Aints(fibonacci_heap<int128_t, compare<greater<int128_t> > >& data,
	factors* fact, int128_t p) {
	int128_t lim = round_sqrt(fact->num);
	add_Aint_loop(data, p, fact->primes, fact->exp, fact->len, 0, 1, fact->num,
		lim);
	return 0;
}

int add_Aint_loop(fibonacci_heap<int128_t, compare<greater<int128_t> > >& data,
	int128_t p, int128_t* primes, int* exp, int len, int n, int128_t cur,
	int128_t num, int128_t lim) {
	if(n == len) {
		data.push((cur + p) * (num / cur + p) * p);
	} else {
		int i;
		int mx = exp[n] + 1;
		for(i = 0; i < mx; i++) {
			add_Aint_loop(data, p, primes, exp, len, n + 1, cur, num, lim);
			cur *= primes[n];
			if(cur > lim) {
				return 0;
			}
		}
	}
	return 0;
}
