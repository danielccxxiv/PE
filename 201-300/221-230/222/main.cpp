
#include "main.hpp"

int main(int argc, char** argv) {
	uint i, j, k, prev, count, lim;
	for(i = 0; i < N; i++) {
		arr[i] *= 1000;
	}
	W *= 1000;
	Wsqrt = std::sqrt(W);
	uint* pwrs = new uint[N];
	pwrs[0] = 1;
	for(i = 1; i < N; i++) {
		pwrs[i] = 2 * pwrs[i - 1];
	}
	lim = pwrs[N - 1] * 2;
	config* data = new config[lim];
	data[0].num = 0;
	for(i = 0; i < N; i++) {
		data[pwrs[i]].num = 1;
		data[pwrs[i]].len = new double(2 * arr[i]);
		data[pwrs[i]].last = new int(i);
	}
	for(i = 1; i < lim; i++) {
		data[i].num = bit_count(i);
		if(data[i].num == 1) {
			continue;
		}
		data[i].len = new double[data[i].num];
		data[i].last = new int[data[i].num];
		count = 0;
		for(j = 0; j < N; j++) {
			if((i ^ pwrs[j]) < i) {
				prev = i - pwrs[j];
				data[i].last[count] = j;
				data[i].len[count] = 1000000000;
				for(k = 0; k < data[prev].num; k++) {
					data[i].len[count] = min(data[i].len[count],
						data[prev].len[k] - arr[data[prev].last[k]] + arr[j]
						+ Wsqrt * std::sqrt(2 * (arr[data[prev].last[k]]
						+ arr[j]) - W));
				}
				count++;
			}
		}
	}
	double ans = 1000000000;
	for(i = 0; i < N; i++) {
		ans = min(ans, data[lim - 1].len[i]);
	}
	cout << (int)(ans + 0.5) << endl;
	return 0;
}
