
#include "main.hpp"

int main() {
	int64_t num = 1;
	for(int64_t i = 1; i <= limit; i++) {
		num = lcm<int64_t>(num, i);
	}
	std::cout << num << std::endl;
}
