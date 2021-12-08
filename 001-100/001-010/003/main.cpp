
#include "main.hpp"

int main(int argc, char** argv) {
    prime_factor_list<long>* x = factor<long, true>(N);
    std::cout << x->primes[x->len - 1] << std::endl;
	return 0;
}
