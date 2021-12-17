
#include "main.hpp"

int main() {
    int128_t power;
    int32_t count = 0;
    int32_t exponent;
    for(int32_t i = 1; i < 10; i++) {
        power = i;
        exponent = 1;
        while(digit_count<int128_t, int32_t>(power) == exponent) {
            count++;
            power *= static_cast<int128_t>(i);
            exponent++;
        }
    }
    std::cout << count << std::endl;
	return 0;
}
