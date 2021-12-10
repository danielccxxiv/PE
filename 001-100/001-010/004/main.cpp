
#include "main.hpp"

int main(int argc, char** argv) {
	uint32_t current_pal = 0;
    uint32_t product = 0;
	for(uint32_t i = 999; i > 99; i--) {
		if((i * i) < current_pal) {
			break;
		}
		for(uint32_t j = i; j > 99; j--) {
            product = i * j;
			if(product < current_pal) {
				break;
			}
			if(palindrome_check(product)) {
				current_pal = product;
			}
		}
	}
	std::cout << current_pal << std::endl;
	return 0;
}

bool palindrome_check(uint32_t n) {
    digit_list<uint32_t> lst = digit_list<uint32_t>(n);
    return is_palindrome(lst.list, lst.len);
}
