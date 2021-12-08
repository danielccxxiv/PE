
#include "main.hpp"

int main(int argc, char** argv) {
	bin_search_map[0] = 0.0;
	bin_search_map[1] = 1.0;
	cout << setprecision(numeric_limits<cpp_bin_float_100>::max_digits10)
		<< rand_search_evalue(pow((long) 10, (long) 10))
		- bin_search_evalue(pow((long) 10, (long) 10)) << endl;
	return 0;
}

cpp_bin_float_100 rand_search_evalue(long n) {
	cpp_bin_float_100 val = 2.0 * (boost::math::log1p(n - 1.0)
		+ euler<cpp_bin_float_100>());
	val -= (3.0 * (1.0 - (1.0 / (n + 1.0))));
	val *= (1.0 + (1.0 / n));
	return val;
}

cpp_bin_float_100 bin_search_evalue(long n) {
	unordered_map<long, cpp_bin_float_100>::iterator it
		= bin_search_map.find(n);
	if(it != bin_search_map.end()) {
		return it->second;
	}
	long k = (n + 1) / 2;
	cpp_bin_float_100 val = 1.0 + ((k - 1.0) * bin_search_evalue(k - 1.0)
		+ (n - k) * bin_search_evalue(n - k)) / n;
	bin_search_map[n] = val;
	return val;
}
