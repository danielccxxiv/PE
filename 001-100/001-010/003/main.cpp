
#include "main.hpp"

int main() {
    prime_factor_list<int64_t>* x = factor<int64_t, int32_t, true>(N);
    std::cout << x->primes[x->len - 1] << std::endl;
	return 0;
}
