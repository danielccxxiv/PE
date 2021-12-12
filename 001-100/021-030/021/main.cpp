
#include "main.hpp"

int main() {
	uint32_t sum = 0;
    uint32_t div_sum;
	for(uint32_t i = 2; i < 10000; i++) {
        div_sum = factor_sum<uint32_t, true>(factor<uint32_t, uint32_t, true>(i)) - i;
        if((div_sum != i) && (div_sum != 1) && (factor_sum<uint32_t, true>(factor<uint32_t, uint32_t, true>(div_sum)) == (div_sum + i))) {
            sum += i;
        }
	}
	std::cout << sum << std::endl;
	return 0;
}
