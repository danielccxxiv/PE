
#include "main.hpp"

int main(int argc, char** argv) {
	set0 = new uint256_t[pow(2, len0)];
	set1 = new uint256_t[pow(2, len1)];
	int set_len0 = 0;
	int set_len1 = 0;
	generate_set(set0, list0, 0, len0, 1, set_len0);
	generate_set(set1, list1, 0, len1, 1, set_len1);
	quicksort(set0, set_len0);
	quicksort(set1, set_len1);
	uint256_t max_val = 0;
	uint256_t temp;
	int i = 0;
	int j = set_len1 - 1;
	while(i != set_len0 && j != -1) {
		temp = set0[i] * set1[j];
		if(temp < target) {
			if(temp > max_val) {
				max_val = temp;
			}
			i++;
		} else {
			j--;
		}
	}
	cout << max_val % ((long) pow((long) 10, (long) 16)) << endl;
	return 0;
}

int generate_set(uint256_t* nset, const int list[], int i, int len,
	uint256_t num, int& pos) {
	if(i == len ) {
		if(num <= target) {
			nset[pos] = num;
			pos++;
		}
	} else {
		generate_set(nset, list, i + 1, len, num, pos);
		generate_set(nset, list, i + 1, len, num * list[i], pos);
	}
	return 0;
}
