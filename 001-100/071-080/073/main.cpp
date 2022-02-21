
#include "main.hpp"

int main() {
    int32_t count = 0;
    for(int32_t i = 4; i < 12001; i++) {
        int32_t lower = (i / 3) + 1;
        int32_t upper = (i / 2) + 1;
        for(int32_t j = lower; j < upper; j++) {
            if(gcd(i, j) == 1) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
	return 0;
}
