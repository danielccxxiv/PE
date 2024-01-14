
#include "main.hpp"

/*
Uses external library primesieve and sums over the function next_prime() in a
while loop.
*/

int main() {
    primesieve::iterator prime_iter;
    int64_t sum = 0;
    int32_t val = prime_iter.next_prime();
    while(val < N) {
        sum += val;
        val = prime_iter.next_prime();
    }
    std::cout << sum << std::endl;
	return 0;
}
