
#include "main.hpp"

int main(int argc, char** argv) {
    primesieve::iterator prime_iter;
    int num = prime_iter.next_prime();
    int num_dc;
    int last_digit;
    int max_pandigital_prime = 0;
    int digits = 1;
    int reset_limit = pow<int, int>(10, digits);
    bool valid_num;
    bool* digit_check = new bool[digits];
    while(num < 10000000) {
        if(num >= reset_limit) {
            digits++;
            reset_limit *= 10;
            delete[] digit_check;
            digit_check = new bool[digits];
        }
        valid_num = true;
        for(int i = 0; i < digits; i++) {
            digit_check[i] = false;
        }
        num_dc = num;
        while(num_dc != 0) {
            last_digit = num_dc % 10;
            if((last_digit == 0) || (last_digit > digits) || digit_check[last_digit - 1]) {
                valid_num = false;
                break;
            }
            digit_check[last_digit - 1] = true;
            num_dc /= 10;
        }
        if(valid_num) {
            max_pandigital_prime = num;
        }
        num = prime_iter.next_prime();
    }
    std::cout << max_pandigital_prime << std::endl;
	return 0;
}
