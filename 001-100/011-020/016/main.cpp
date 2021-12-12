
#include "main.hpp"

int main() {
	std::cout << digit_sum<uint1024_t, uint32_t>(pow_int<uint1024_t, uint32_t>(2, 1000)) << std::endl;
	return 0;
}
