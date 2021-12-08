
#include "main.hpp"

int main(int argc, char** argv) {
    int num_digits = 1;
    int digit_top = 10;
    int n = 0;
    long hash;
    while(true) {
        n++;
        if(n == digit_top) {
            num_digits++;
            digit_top *= 10;
        }
        hash = digit_hash(n, num_digits);
        if((digit_hash(2 * n, num_digits) == hash)
            && ((digit_hash(3 * n, num_digits) == hash)
            && ((digit_hash(4 * n, num_digits) == hash)
            && ((digit_hash(5 * n, num_digits) == hash)
            && ((digit_hash(6 * n, num_digits) == hash)))))) {
            break;
        }
    }
    std::cout << n << std::endl;
	return 0;
}

long digit_hash(int n, int digit_count) {
    long hash = 0;
    while(n != 0) {
        hash += pow<long, int>(digit_count + 2, n % 10);
        n /= 10;
    }
    return hash;
}
