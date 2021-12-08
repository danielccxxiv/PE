
#include "main.hpp"

int main(int argc, char** argv) {
	int len, p_len, i, j, cur, sum;
	long ans = 0;
	cur = 0;
	sum = 0;
	int* arr = prime_gen(N, &len);
	for(i = 0; i < len; i++) {
		sum += arr[i];
	}
	int* p_lst = prime_gen(sum, &p_len);
	long* sum_lst = new long[sum + 1];
	for(i = 0; i < (sum + 1); i++) {
		sum_lst[i] = 0;
	}
	sum_lst[0] = 1;
	for(i = 0; i < len; i++) {
		for(j = cur; j > -1; j--) {
			sum_lst[arr[i] + j] += sum_lst[j];
			sum_lst[arr[i] + j] %= m;
		}
		cur += arr[i];
	}
	for(i = 0; i < p_len; i++) {
		ans += sum_lst[p_lst[i]];
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}
