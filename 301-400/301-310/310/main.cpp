
#include "main.hpp"

int main(int argc, char** argv) {
	int lim = 100001;
	int* nsum = new int[lim];
	int i, j;
	int* mark = new int[lim];
	for(i = 0; i < lim; i++) {
		nsum[i] = 0;
		mark[i] = 0;
	}
	for(i = 1; i < lim; i++) {
		j = 1;
		while((j * j) < (i + 1)) {
			mark[nsum[i - (j * j)]] = i;
			j++;
		}
		j = 0;
		while(mark[j] == i) {
			j++;
		}
		nsum[i] = j;
	}
	return 0;
}
