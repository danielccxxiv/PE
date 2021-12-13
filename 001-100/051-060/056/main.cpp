
#include "main.hpp"

int main() {
    int32_t max_digit_sum = 0;
    for(int32_t a = 1; a < 100; a++) {
        for(int32_t b = 1; b < 100; b++) {
            max_digit_sum = std::max(max_digit_sum, digit_sum<int1024_t, int32_t>(pow_int<int1024_t, int32_t>(a, b)));
        }
    }
    std::cout << max_digit_sum << std::endl;
	return 0;
}
