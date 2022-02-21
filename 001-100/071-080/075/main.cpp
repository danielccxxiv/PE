
#include "main.hpp"

int main() {
    std::vector<int32_t> triangle_count(1500001, 0);
    for(int32_t m = 2; m < 1000; m++) {
        if((2 * m * m) > 1500000) {
            break;
        }
        if((m % 2) == 0) {
            for(int32_t n = 1; n < m; n += 2) {
                if(gcd(m, n) == 1) {
                    int32_t t_sum = 2 * m * (m + n);
                    if(t_sum > 1500000) {
                        break;
                    }
                    for(int32_t k = t_sum; k < 1500001; k += t_sum) {
                        triangle_count[k]++;
                    }
                }
            }
        } else {
            for(int32_t n = 2; n < m; n += 2) {
                if(gcd(m, n) == 1) {
                    int32_t t_sum = 2 * m * (m + n);
                    if(t_sum > 1500000) {
                        break;
                    }
                    for(int32_t k = t_sum; k < 1500001; k += t_sum) {
                        triangle_count[k]++;
                    }
                }
            }
        }
    }
    int32_t count = 0;
    for(size_t i = 0; i < 1500001; i++) {
        if(triangle_count[i] == 1) {
            count++;
        }
    }
    std::cout << count << std::endl;
	return 0;
}
