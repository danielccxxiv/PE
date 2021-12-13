
#include "main.hpp"

int main() {
    int32_t last_prime = prime<int32_t>::iter.next_prime();
    prime<int32_t>::list.push_back(last_prime);
    int32_t n = 1;
    int32_t dbl_sqr;
    bool found = false;
    while(!(found)) {
        n += 2;
        while(last_prime < n) {
            last_prime = prime<int32_t>::iter.next_prime();
            prime<int32_t>::list.push_back(last_prime);
        }
        if(n == last_prime) {
            continue;
        }
        found = true;
        for(int32_t i = 1; i < n; i++) {
            dbl_sqr = 2 * i * i;
            if(dbl_sqr >= n) {
                break;
            }
            if(binary_search(prime<int32_t>::list, n - dbl_sqr, 0, prime<int32_t>::list.size()) >= 0) {
                found = false;
                break;
            }
        }
    }
    std::cout << n << std::endl;
	return 0;
}
