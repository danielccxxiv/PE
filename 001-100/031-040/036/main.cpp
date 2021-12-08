
#include "main.hpp"

int main(int argc, char** argv) {
    int sum = 0;
    uint val;
    for(uint i = 1; i < 1023; i++) {
        val = odd_size_palindrome(i);
        if((val < 1000000) && is_palindrome_num<uint, uint>(val, 10)) {
            sum += val;
        }
        val = even_size_palindrome(i);
        if((val < 1000000) && is_palindrome_num<uint, uint>(val, 10)) {
            sum += val;
        }
    }
    std::cout << sum << std::endl;
	return 0;
}

uint odd_size_palindrome(uint num) {
    uint res = num;
    num >>= 1;
    while(num != 0) {
        res = (res << 1) + (num & 1);
        num >>= 1;
    }
    return res;
}

uint even_size_palindrome(uint num) {
    uint res = num;
    while(num != 0) {
        res = (res << 1) + (num & 1);
        num >>= 1;
    }
    return res;
}
