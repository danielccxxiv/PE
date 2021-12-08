
#include "main.hpp"

int main(int argc, char** argv) {
    std::vector<int> prime_list;
    primesieve::generate_primes(limit, &prime_list);
    int list_len = prime_list.size();
    int max_len = 0;
    int new_max_len;
    int result = 0;
    int sum;
    for(int i = 0; i < list_len; i++) {
        new_max_len = 0;
        if((i + max_len) > list_len) {
            break;
        }
        sum = 0;
        for(int j = 0; j < max_len; j++) {
            sum += prime_list[i + j];
        }
        if(sum > limit) {
            break;
        }
        for(int j = max_len; j < (list_len - i); j++) {
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
