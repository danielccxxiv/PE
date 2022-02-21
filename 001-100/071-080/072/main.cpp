
#include "main.hpp"

int main() {
    int64_t totient_sum = 0;
    for(int32_t i = 2; i < 1000001; i++) {
        totient_sum += totient<int32_t, false>(i, factor<int32_t, int32_t, true>(i));
    }
    std::cout << totient_sum << std::endl;
	return 0;
}
