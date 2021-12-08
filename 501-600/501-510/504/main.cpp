
#include "main.hpp"

int main(int argc, char** argv) {
	int i, j, m;
	m = 101;
	bool* is_square = new bool[2 * m * m + 1];
	for(i = 0; i < (2 * m * m + 1); i++) {
		is_square[i] = false;
	}
	for(i = 1; i < (1 + (3 * m) / 2); i++) {
		if(i * i > 2 * m * m) {
			break;
		}
		is_square[i * i] = true;
	}
	int* term_list = new int[m * m];
	for(i = 1; i < m; i++) {
		for(j = i; j < m; j++) {
			term_list[m * i + j] = i * j - gcd(i, j);
			term_list[m * j + i] = term_list[m * i + j];
		}
	}
	int a, b, c, d, k, area, count;
	count = 0;
	for(a = 1; a < m; a++) {
		for(b = a; b < m; b++) {
			for(c = a; c < m; c++) {
				if(a == b) {
					k = c;
				} else {
					k = b;
				}
				for(d = k; d < m; d++) {
					area = (term_list[m * a + b] + term_list[m * b + c]
						+ term_list[m * c + d] + term_list[m * d + a]) / 2 + 1;
					if(is_square[area]) {
						if(a == b) {
							if(b == c) {
								if(c == d) {
									count++;
								} else {
									count += 4;
								}
							} else if(b == d) {
								count += 4;
							} else if(c == d) {
								count += 4;
							} else {
								count += 8;
							}
						} else if(a == c) {
							if(b == d) {
								count += 2;
							} else {
								count += 4;
							}
						} else if(b == c) {
							if(b == d) {
								count += 4;
							} else {
								count += 8;
							}
						} else if(b == d) {
							count += 4;
						} else if(c == d) {
							count += 8;
						} else {
							count += 8;
						}
					}
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
