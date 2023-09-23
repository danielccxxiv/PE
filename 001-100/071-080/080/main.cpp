
#include "main.hpp"

int main() {
    int32_t digit_sum = 0;
    int1024_t offset = pow_int<int1024_t, int32_t>(10, 200);
    int1024_t length_check = pow_int<int1024_t, int32_t>(10, 100) - 1;
    for(int32_t i = 2; i < 101; i++) {
        if(pow_int(int_sqrt(i), 2) == i) {
            continue;
        }
        int1024_t sqrt_stream = int_sqrt(i * offset);
        while(sqrt_stream > length_check) {
            sqrt_stream /= 10;
        }
        while(sqrt_stream > 0) {
            digit_sum += static_cast<int32_t>(sqrt_stream % 10);
            sqrt_stream /= 10;
        }
    }
    std::cout << digit_sum << std::endl;
	return 0;
}
