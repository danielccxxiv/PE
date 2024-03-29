
#include "main.hpp"

int main() {
	int32_t sum = 0;
    int32_t div_sum;
	for(int32_t i = 2; i < 10000; i++) {
        div_sum = factor_sum<int32_t, true>(i, factor<int32_t, int32_t, true>(i)) - i;
        if((div_sum != i) && (div_sum != 1) && (factor_sum<int32_t, true>(div_sum, factor<int32_t, int32_t, true>(div_sum)) == (div_sum + i))) {
            sum += i;
        }
	}
	std::cout << sum << std::endl;
	return 0;
}
