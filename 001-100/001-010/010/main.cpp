
#include "main.hpp"

int main() {
    uint64_t sum = 0;
    uint32_t val = prime<uint32_t>::iter.next_prime();
    while(val < N) {
        sum += val;
        val = prime<uint32_t>::iter.next_prime();
    }
    std::cout << sum << std::endl;
	return 0;
}
