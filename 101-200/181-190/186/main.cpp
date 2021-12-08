
#include "main.hpp"

int main(int argc, char** argv) {
	int i, fr, f0, f1, c0, c1;
	long cur, count, res;
	disjoint_set** arr = new disjoint_set*[N];
	for (i = 0; i < N; i++) {
		arr[i] = new disjoint_set(i);
	}
	fr = 55;
	f0 = 0;
	f1 = 31;
	cur = 0;
	count = 0;
	int* rnd = new int[fr];
	for (i = 0; i < fr; i++) {
		res = pow_mod(i + 1, 3, N);
		res = (300007 * res + 100003) % N;
		rnd[i] = (res - ((200003 * (i + 1)) % N) + N) % N;
	}
	disjoint_set* x;
	while((arr[PM]->find())->size < T) {
		if (cur < fr) {
			c0 = rnd[cur];
		} else {
			rnd[cur % fr] = (rnd[(cur + f0) % fr] + rnd[(cur + f1) % fr]) % N;
			c0 = rnd[cur % fr];
		}
		cur++;
		if (cur < fr) {
			c1 = rnd[cur];
		} else {
			rnd[cur % fr] = (rnd[(cur + f0) % fr] + rnd[(cur + f1) % fr]) % N;
			c1 = rnd[cur % fr];
		}
		cur++;
		if (c0 == c1) {
			continue;
		}
		x = disjoint_set::merge(arr[c0], arr[c1]);
		count++;
	}
	cout << count << endl;
	return 0;
}
