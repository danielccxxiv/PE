
#include "main.hpp"

int main() {
    std::vector<int32_t> prime_list;
    primesieve::generate_primes(limit, &prime_list);
    int32_t list_len = prime_list.size();
    int32_t max_len = 0;
    int32_t new_max_len;
    int32_t result = 0;
    int32_t sum;
    for(int32_t i = 0; i < list_len; i++) {
        new_max_len = 0;
        if((i + max_len) > list_len) {
            break;
        }
        sum = 0;
        for(int32_t j = 0; j < max_len; j++) {
            sum += prime_list[i + j];
        }
        if(sum > limit) {
            break;
        }
        for(int32_t j = max_len; j < (list_len - i); j++) {
            sum += prime_list[i + j];
            if(sum > limit) {
                break;
            }
            if(binary_search(prime_list, sum, 0, list_len) >= 0) {
                new_max_len = j + 1;
                result = sum;
            }
        }
        if(new_max_len > 0) {
            max_len = new_max_len;
        }
    }
    std::cout << result << std::endl;
	return 0;
}
