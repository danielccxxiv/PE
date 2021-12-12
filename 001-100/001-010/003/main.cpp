
#include "main.hpp"

int main() {
    prime_factor_list<uint64_t>* x = factor<uint64_t, uint32_t, true>(N);
    std::cout << x->primes[x->len - 1] << std::endl;
	return 0;
}
