
#include "main.hpp"

int main() {
    int32_t numer = 0;
    double max_val = 0;
    for(int32_t i = 2; i < 1000001; i++) {
        if(i == 7) {
            continue;
        }
        int32_t cur_numer = (3 * i) / 7;
        if(gcd(cur_numer, i) == 1) {
            double cur_val = ((double) cur_numer) / i;
            if(cur_val > max_val) {
                max_val = cur_val;
                numer = cur_numer;
            }
        }
    }
    std::cout << numer << std::endl;
	return 0;
}
