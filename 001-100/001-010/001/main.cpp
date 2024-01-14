
#include "main.hpp"

/*
This program uses the formula for the sum of the first n natural numbers
applied to 3 and 5 as well as discounting the double counted multiples of 15.
*/

int main() {
	int32_t sum3 = (limit - 1) / 3;
	sum3 = 3 * sum3 * (sum3 + 1) / 2;
	int32_t sum5 = (limit - 1) / 5;
	sum5 = 5 * sum5 * (sum5 + 1) / 2;
	int32_t sum15 = (limit - 1) / 15;
	sum15 = 15 * sum15 * (sum15 + 1) / 2;
	int32_t result = sum3 + sum5 - sum15;
	std::cout << result << std::endl;
	return 0;
}
