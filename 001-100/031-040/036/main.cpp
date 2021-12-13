
#include "main.hpp"

int main() {
    int32_t sum = 0;
    int32_t val;
    for(int32_t i = 1; i < 1023; i++) {
        val = odd_size_palindrome(i);
        if((val < 1000000) && is_palindrome_num<int32_t, int32_t>(val, 10)) {
            sum += val;
        }
        val = even_size_palindrome(i);
        if((val < 1000000) && is_palindrome_num<int32_t, int32_t>(val, 10)) {
            sum += val;
        }
    }
    std::cout << sum << std::endl;
	return 0;
}

int32_t odd_size_palindrome(int32_t num) {
    int32_t res = num;
    num >>= 1;
    while(num != 0) {
        res = (res << 1) + (num & 1);
        num >>= 1;
    }
    return res;
}

int32_t even_size_palindrome(int32_t num) {
    int32_t res = num;
    while(num != 0) {
        res = (res << 1) + (num & 1);
        num >>= 1;
    }
    return res;
}
