
#include "main.hpp"

int main(int argc, char** argv) {
    primesieve::iterator prime_iter;
    long prime = prime_iter.next_prime();
    int n = 0;
    int prime_count = 0;
    long val;
    while(true) {
        n++;
        val = n * (4 * n - 2) + 1;
        while(prime < val) {
            prime = prime_iter.next_prime();
        }
        if(prime == val) {
            prime_count++;
        }
        val = 4 * n * n + 1;
        while(prime < val) {
            prime = prime_iter.next_prime();
        }
        if(prime == val) {
            prime_count++;
        }
        val = n * (4 * n + 2) + 1;
        while(prime < val) {
            prime = prime_iter.next_prime();
        }
        if(prime == val) {
            prime_count++;
        }
        if((10 * prime_count) < (4 * n + 1)) {
            break;
        }
    }
    std::cout << (2 * n + 1) << std::endl;
	return 0;
}
