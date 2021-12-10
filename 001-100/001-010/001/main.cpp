
#include "main.hpp"

int main() {
	uint32_t sum3 = (limit - 1) / 3;
	sum3 = 3 * sum3 * (sum3 + 1) / 2;
	uint32_t sum5 = (limit - 1) / 5;
	sum5 = 5 * sum5 * (sum5 + 1) / 2;
	uint32_t sum15 = (limit - 1) / 15;
	sum15 = 15 * sum15 * (sum15 + 1) / 2;
	uint32_t result = sum3 + sum5 - sum15;
	std::cout << result << std::endl;
	return 0;
}
