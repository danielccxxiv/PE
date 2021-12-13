
#include "main.hpp"

int main() {
    int64_t sum = 0;
    int32_t val = prime<int32_t>::iter.next_prime();
    while(val < N) {
        sum += val;
        val = prime<int32_t>::iter.next_prime();
    }
    std::cout << sum << std::endl;
	return 0;
}
