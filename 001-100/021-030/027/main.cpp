
#include "main.hpp"

int main() {
    std::vector<int32_t> primes;
    primesieve::generate_primes(2001001, &primes);
    int32_t max_len = 0;
    int32_t prod = 0;
    int32_t val;
    for(int32_t a = -1000; a < 1001; a++) {
        for(int32_t b = -1000; b < 1001; b++) {
            for(int32_t n = 0; n < 1001; n++) {
                val = (n + a) * n + b;
                if((val < 0) || (binary_search<int32_t>(primes, val, 0, primes.size()) < 0)) {
                    break;
                }
                if(n > max_len) {
                    max_len = n;
                    prod = a * b;
                }
            }
        }
    }
    std::cout << prod << std::endl;
    return 0;
}
