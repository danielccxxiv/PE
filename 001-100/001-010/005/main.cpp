
#include "main.hpp"

/*
Uses an external lcm function using the formula lcm(a, b) = (a / gcd(a, b)) * b
and the euclidean algorithm for calculating gcd(a, b), then loops over the
given range.
*/

int main() {
	int64_t num = 1;
	for(int64_t i = 1; i <= limit; i++) {
		num = lcm<int64_t>(num, i);
	}
	std::cout << num << std::endl;
}
