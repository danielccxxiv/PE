
#include "main.hpp"

int main(int argc, char** argv) {
	long num = 1;
	for(long i = 1; i <= limit; i++) {
		num = lcm(num, i);
	}
	std::cout << num << std::endl;
}
