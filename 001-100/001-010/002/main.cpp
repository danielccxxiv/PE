
#include "main.hpp"

/*
This program loops through numbers created by a custom fibonacci function and
adds all of the even ones up to the limit.
*/

int main() {
	int32_t sum = 0;
	int32_t n = 0;
    int32_t fib = fibonacci<int32_t>(n);
    while(fib <= limit) {
        if(fib % 2 == 0) {
            sum += fib;
        }
        n++;
        fib = fibonacci<int32_t>(n);
    }
	std::cout << sum << std::endl;
	return 0;
}
