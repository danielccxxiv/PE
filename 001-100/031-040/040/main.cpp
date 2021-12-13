
#include "main.hpp"

int main() {
    int32_t num = digit_at(0)
        * digit_at(9)
        * digit_at(99)
        * digit_at(999)
        * digit_at(9999)
        * digit_at(99999)
        * digit_at(999999);
    std::cout << num << std::endl;
	return 0;
}

int32_t digit_at(int32_t pos) {
    int32_t digits = 1;
    int32_t block_size = 9;
    while(pos >= block_size) {
        pos -= block_size;
        digits++;
        block_size = digits * (pow_int<int32_t, int32_t>(10, digits) - pow_int<int32_t, int32_t>(10, digits - 1));
    }
    int32_t num = pow_int<int32_t, int32_t>(10, digits - 1) + pos / digits;
    pos = pos % digits;
    for(int32_t i = 0; i < (digits - pos - 1); i++) {
        num /= 10;
    }
    return num % 10;
}
