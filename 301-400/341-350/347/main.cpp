
#include "main.hpp"

int main(int argc, char** argv) {
	int i, j;
	long total = 0;
	arr = prime_gen(N / 2, &len);
	for(i = 0; i < len; i++) {
		for(j = 0; j < i; j++) {
			if((N / arr[i]) < arr[j]) {
				break;
			}
			total += m_func(arr[i], arr[j], N, arr[i] * arr[j]);
		}
	}
	cout << total << endl;
	return 0;
}

int m_func(int p, int q, int lim, int cur) {
	int nxt = cur;
	while(!((lim / nxt) < q)) {
		nxt *= q;
	}
	if((lim / cur) < p) {
		return nxt;
	}
	return max(m_func(p, q, lim, cur * p), nxt);
}
