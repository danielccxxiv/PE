
#include "main.hpp"

int main() {
	uint32_t sum = 0;
	uint32_t n = 0;
    uint32_t fib = fibonacci<uint32_t>(n);
    while(fib <= limit) {
        if(fib % 2 == 0) {
            sum += fib;
        }
        n++;
        fib = fibonacci<uint32_t>(n);
    }
	std::cout << sum << std::endl;
	return 0;
}
