
#include "main.hpp"

int main(int argc, char** argv) {
	double* T = new double[N + 1];
	double* Q = new double[N + 1];
	double* P = new double[N + 1];
	int* Tk = new int[N + 1];
	int* Qk = new int[N + 1];
	p = 0;
	T[1] = 1;
	Q[1] = 0;
	P[0] = 1;
	Tk[1] = 1;
	double sum, m, w;
	sum = 0;
	int i, j, k, Tk_lim, Tk_max;
	for(k = 0; k < 50; k++) {
		Tk_max = N;
		p += 0.01;
		for(i = 0; i < N; i++) {
			P[i + 1] = P[i] * (1 - p);
		}
		for(i = 2; i < (N + 1); i++) {
			m = N;
			for(j = 1; j < i; j++) {
				w = (1 - P[j]) * (Q[j] + T[i - j]) / (1 - P[i]);
				if(w > m) {
					break;
				}
				w += (1 + ((P[j] - P[i]) * Q[i - j]) / (1 - P[i]));
				if(w < m) {
					m = w;
					Qk[i] = j;
				}
			}
			Q[i] = m;
			m = 1 + (1 - P[i]) * Q[i];
			Tk[i] = i;
			Tk_lim = min((i / 2) + 1, Tk_max);
			for(j = 1; j < Tk_lim; j++) {
				if(Tk[i - j] > j && Tk[i - j] < (i - j)) {
					continue;
				}
				w = T[j] + T[i - j];
				if(w < m) {
					m = w;
					Tk[i] = max(j, Tk[i - j]);
				}
			}
			T[i] = m;
			if(Tk[i] < i) {
				Tk_max = min(Tk_max, i);
			}
		}
		sum += T[N];
	}
	cout.precision(6);
	cout << fixed << sum << endl;
	return 0;
}
