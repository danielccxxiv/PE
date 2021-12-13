
#include "main.hpp"

int main() {
	int32_t current_pal = 0;
    int32_t product = 0;
	for(int32_t i = 999; i > 99; i--) {
		if((i * i) < current_pal) {
			break;
		}
		for(int32_t j = i; j > 99; j--) {
            product = i * j;
			if(product < current_pal) {
				break;
			}
			if(is_palindrome_num<int32_t, int32_t>(product)) {
				current_pal = product;
			}
		}
	}
	std::cout << current_pal << std::endl;
	return 0;
}
