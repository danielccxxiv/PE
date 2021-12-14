
#include "main.hpp"

int main() {
    primesieve::iterator prime_iter;
    int32_t num = prime_iter.next_prime();
    int32_t max_pandigital_prime = 0;
    int32_t digits = 1;
    int32_t reset_limit = pow_int<int32_t, int32_t>(10, digits);
    int32_t pandigital = 1;
    int32_t pandigital_hash = unordered_digit_hash<int32_t, int32_t>(pandigital);
    while(num < 7654322) {
        if(num >= reset_limit) {
            digits++;
            reset_limit *= 10;
            pandigital = 10 * pandigital + digits;
            pandigital_hash = unordered_digit_hash<int32_t, int32_t>(pandigital);
        }
        if(unordered_digit_hash<int32_t, int32_t>(num) == pandigital_hash) {
            max_pandigital_prime = num;
        }
        num = prime_iter.next_prime();
    }
    std::cout << max_pandigital_prime << std::endl;
	return 0;
}
