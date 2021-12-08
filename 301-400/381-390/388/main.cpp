
#include "388.hpp"

cpp_int problem() {
	cpp_int total = N;
	total *= N;
	total *= N;
	int p_len;
	int* p = prime_gen(lim, &p_len);
	cout << p_len << endl;
	return total;
}
