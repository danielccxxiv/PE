
#include "main.hpp"

int main() {
	std::cout << digit_sum<uint1024_t, uint32_t>(factorial<uint1024_t>(100)) << std::endl;
	return 0;
}
