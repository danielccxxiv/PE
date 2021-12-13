
#include "main.hpp"

int main() {
    std::vector<int32_t> prime_list;
    primesieve::generate_primes(1000, 9999, &prime_list);
    int32_t list_len = prime_list.size();
    int32_t n0 = 0;
    int32_t n1 = 0;
    int32_t n2 = 0;
    int32_t hash0;
    int32_t hash1;
    int32_t hash2;
    bool found = false;
    for(int32_t i = 0; i < list_len; i++) {
        n0 = prime_list[i];
        if(n0 == 1487) {
            continue;
        }
        hash0 = unordered_digit_hash<int32_t, int32_t>(n0);
        for(int32_t j = (i + 1); j < list_len; j++) {
            n1 = prime_list[j];
            n2 = 2 * n1 - n0;
            if(n2 > 9999) {
                break;
            }
            if(binary_search(prime_list, n2, 0, list_len) < 0) {
                continue;
            }
            hash1 = unordered_digit_hash<int32_t, int32_t>(n1);
            if(hash0 != hash1) {
                continue;
            }
            hash2 = unordered_digit_hash<int32_t, int32_t>(n2);
            if(hash0 == hash2) {
                found = true;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    std::cout << (100000000L * n0 + 10000L * n1 + 1L * n2) << std::endl;
	return 0;
}
