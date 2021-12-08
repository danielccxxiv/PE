
#include "main.hpp"

int main(int argc, char** argv) {
	long n = 1000000;
	long k = 20000;
	int i;
	cpp_bin_float_100 chip = 1;
	cpp_bin_float_100 v = 1;
	for(i = 1; i < k; i++) {
		v *= (n - i);
		v /= n;
	}
	chip -= v;
	for(i = 0; i < (int) (k / 2); i++) {
		v *= ((k - (2 * i)) * (k - (2 * i + 1)));
		v /= ((2 * (i + 1)) * (n - k + i + 1));
		chip -= v;
	}
	cout << setprecision(numeric_limits<cpp_bin_float_100>::max_digits10)
		<< chip << endl;
	return 0;
}
