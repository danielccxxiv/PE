
#include "main.hpp"

int main() {
    int64_t mod = pow_int<int64_t, int32_t>(10, 10);
    int64_t sum = 0;
    for(int32_t i = 1; i < 1001; i++) {
        sum = (sum + static_cast<int64_t>(pow_int_mod<int128_t, int32_t>(i, i, mod))) % mod;
    }
    std::cout << sum << std::endl;
	return 0;
}
