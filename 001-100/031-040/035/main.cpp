
#include "main.hpp"

int main() {
    std::vector<int32_t> prime_list;
    primesieve::generate_primes(limit - 1, &prime_list);
    boost::unordered_set<int32_t> circular_prime_set;
    int32_t p;
    int32_t digits;
    int32_t last_digit;
    bool invalid_test;
    for(size_t i = 0; i < prime_list.size(); i++) {
        p = prime_list[i];
        digits = digit_count<int32_t, int32_t>(p);
        last_digit = p % 10;
        invalid_test = false;
        for(int32_t j = 0; j < (digits - 1); j++) {
            p /= 10;
            if(((p % 10) > last_digit) || ((p % 2) == 0) || ((p % 5) == 0)) {
                invalid_test = true;
                break;
            }
        }
        if(invalid_test) {
            continue;
        }
        invalid_test = false;
        p = prime_list[i];
        for(int32_t j = 0; j < (digits - 1); j++) {
            p = (p / 10) + (p % 10) * pow_int<int32_t, int32_t>(10, digits - 1);
            if(binary_search<int32_t>(prime_list, p, 0, prime_list.size()) < 0) {
                invalid_test = true;
                break;
            }
        }
        if(invalid_test) {
            continue;
        }
        p = prime_list[i];
        circular_prime_set.emplace(p);
        for(int32_t j = 0; j < (digits - 1); j++) {
            p = (p / 10) + (p % 10) * pow_int<int32_t, int32_t>(10, digits - 1);
            circular_prime_set.emplace(p);
        }
    }
    std::cout << circular_prime_set.size() << std::endl;
	return 0;
}
