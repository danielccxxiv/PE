
#include "main.hpp"

int main(int argc, char** argv) {
	uint64_t num = 1;
	for(uint64_t i = 1; i <= limit; i++) {
		num = lcm(num, i);
	}
	std::cout << num << std::endl;
}
