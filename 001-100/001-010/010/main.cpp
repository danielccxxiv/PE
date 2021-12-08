
#include "main.hpp"

int main(int argc, char** argv) {
	primesieve::iterator prime_iter;
    long sum = 0;
    int val = prime_iter.next_prime();
    while(val < N) {
        sum += val;
        val = prime_iter.next_prime();
    }
    std::cout << sum << std::endl;
	return 0;
}
