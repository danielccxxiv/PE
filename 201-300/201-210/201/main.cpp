
#include "main.hpp"

int main(int argc, char** argv) {
	int i, j, cur;
	long count = 0;
	for(i = 0; i < N; i++) {
		arr[i] = (i + 1) * (i + 1);
		if(i > (N - S - 1)) {
			limit += arr[i];
		}
	}
	data1 = new ulong[limit + 1];
	data2 = new ulong[limit + 1];
	memset(data1, 0, (limit + 1) * sizeof(ulong));
	memset(data2, 0, (limit + 1) * sizeof(ulong));
	data1[0] = 1;
	cur = 0;
	for(i = 0; i < N; i++) {
		for(j = min(cur, limit - arr[i]); j > -1; j--) {
			data2[j + arr[i]] |= (data2[j] << 1);
			data2[j + arr[i]] |= (data1[j + arr[i]] & (data1[j] << 1));
			data1[j + arr[i]] |= (data1[j] << 1);
			data1[j + arr[i]] &= (~data2[j + arr[i]]);
		}
		cur += arr[i];
	}
	for(i = 0; i <= limit; i++) {
		if((data1[i + 1] >> S) & 1) {
			count += i;
		}
	}
	cout << count << endl;
	return 0;
}
