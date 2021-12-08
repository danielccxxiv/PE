
#include "main.hpp"

int main(int argc, char** argv) {
	int current_pal = 0;
    int product = 0;
	for(int i = 999; i > 99; i--) {
		if(i * i < current_pal) {
			break;
		}
		for(int j = i; j > 99; j--) {
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

bool palindrome_check(int n) {
    digit_list<int> lst = digit_list<int>(n);
    return is_palindrome(lst.list, lst.len);
}
