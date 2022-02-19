
#include "main.hpp"

int main() {
    int32_t n = 0;
    int32_t prime_count = 0;
    int64_t val;
    while(true) {
        n++;
        val = n * (4 * n - 2) + 1;
        if(mr_det(val)) {
            prime_count++;
        }
        val = 4 * n * n + 1;
        if(mr_det(val)) {
            prime_count++;
        }
        val = n * (4 * n + 2) + 1;
        if(mr_det(val)) {
            prime_count++;
        }
        if((10 * prime_count) < (4 * n + 1)) {
            break;
        }
    }
    std::cout << (2 * n + 1) << std::endl;
	return 0;
}
