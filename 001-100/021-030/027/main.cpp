
#include "main.hpp"

int main(int argc, char** argv) {
    std::vector<int> primes;
    primesieve::generate_primes(2001001, &primes);
    int max_len = 0;
    int prod = 0;
    int val;
    for(int a = -1000; a < 1001; a++) {
        for(int b = -1000; b < 1001; b++) {
            for(int n = 0; n < 1001; n++) {
                val = (n + a) * n + b;
                if((val < 0) || (binary_search<int>(primes, val, 0, primes.size()) < 0)) {
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
