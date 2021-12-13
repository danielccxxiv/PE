
#include "main.hpp"

int main() {
    int32_t num_digits = 1;
    int32_t digit_top = 10;
    int32_t n = 0;
    int64_t hash;
    while(true) {
        n++;
        if(n == digit_top) {
            num_digits++;
            digit_top *= 10;
        }
        hash = unordered_digit_hash<int32_t, int32_t, int64_t>(n);
        if((unordered_digit_hash<int32_t, int32_t, int64_t>(2 * n) == hash)
            && ((unordered_digit_hash<int32_t, int32_t, int64_t>(3 * n) == hash)
            && ((unordered_digit_hash<int32_t, int32_t, int64_t>(4 * n) == hash)
            && ((unordered_digit_hash<int32_t, int32_t, int64_t>(5 * n) == hash)
            && ((unordered_digit_hash<int32_t, int32_t, int64_t>(6 * n) == hash)))))) {
            break;
        }
    }
    std::cout << n << std::endl;
	return 0;
}
