
#include "main.hpp"

int main() {
    int32_t* num_solutions = new int32_t[limit];
    for(int32_t i = 0; i < limit; i++) {
        num_solutions[i] = 0;
    }
    int32_t val;
    for(int32_t m = 2; m < limit; m++) {
        if((2 * m * m) > limit) {
            break;
        }
        for(int32_t n = 1; n < m; n++) {
            if(gcd(m, n) != 1) {
                continue;
            }
            val = 2 * m * (m + n);
            if(val < limit) {
                for(int32_t i = val; i < limit; i += val) {
                    num_solutions[i]++;
                }
            } else {
                break;
            }
        }
    }
    int32_t max_solutions = 0;
    int32_t result = 0;
    for(int32_t i = 0; i < limit; i++) {
        if(num_solutions[i] > max_solutions) {
            max_solutions = num_solutions[i];
            result = i;
        }
    }
    std::cout << result << std::endl;
	return 0;
}
