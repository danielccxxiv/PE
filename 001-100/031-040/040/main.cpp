
#include "main.hpp"

int main(int argc, char** argv) {
    std::cout << digit_at(0) * digit_at(9) * digit_at(99) * digit_at(999) * digit_at(9999) * digit_at(99999) * digit_at(999999) << std::endl;
	return 0;
}

int digit_at(int pos) {
    int digits = 1;
    int block_size = 9;
    while(pos >= block_size) {
        pos -= block_size;
        digits++;
        block_size = digits * (pow<int, int>(10, digits) - pow<int, int>(10, digits - 1));
    }
    int num = pow<int, int>(10, digits - 1) + pos / digits;
    pos = pos % digits;
    for(int i = 0; i < (digits - pos - 1); i++) {
        num /= 10;
    }
    return num % 10;
}
