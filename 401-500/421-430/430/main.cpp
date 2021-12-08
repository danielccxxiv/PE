
#include "main.hpp"

int main(int argc, char** argv) {
	c += 1;
	c /= N;
	c += 1;
	c /= N;
	c *= 2;
	cpp_bin_float_100 sum = N / 2;
	cpp_bin_float_100* coef = new cpp_bin_float_100[K + 1];
	int i;
	coef[0] = 1;
	for(i = 0; i < K; i++) {
		sum += (term_integrate(N, T - i) * coef[i]);
		coef[i + 1] = -coef[i] * c * (T - i) / (i + 1);
	}
	cout << setprecision(numeric_limits<cpp_bin_float_100>::max_digits10)
		<< sum << endl;
	return 0;
}

cpp_bin_float_100 term_integrate(long n, int j) {
	cpp_bin_float_100 ret = n;
	ret /= (4 * j + 2);
	return ret;
}
