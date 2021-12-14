
#include "main.hpp"

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
