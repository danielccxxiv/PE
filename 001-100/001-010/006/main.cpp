
#include "main.hpp"

int main() {
	int32_t square_of_sums = (num * (num + 1)) / 2;
	square_of_sums *= square_of_sums;
	int32_t sum_of_squares = (num * (num + 1) * (2 * num + 1)) / 6;
	std::cout << square_of_sums - sum_of_squares << std::endl;
	return 0;
}
