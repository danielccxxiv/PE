
#include "main.hpp"

int main(int argc, char** argv) {
	int sum = 0;
	int n = 0;
    int fib = fibonacci<int>(n);
    while(fib <= limit) {
        if(fib % 2 == 0) {
            sum += fib;
        }
        n++;
        fib = fibonacci<int>(n);
    }
	std::cout << sum << std::endl;
	return 0;
}
