
#include "main.hpp"

int main(int argc, char** argv) {
    int max_digit_sum = 0;
    for(int a = 1; a < 100; a++) {
        for(int b = 1; b < 100; b++) {
            max_digit_sum = std::max(max_digit_sum, digit_sum<int1024_t>(pow<int1024_t, int>(a, b)));
        }
    }
    std::cout << max_digit_sum << std::endl;
	return 0;
}
