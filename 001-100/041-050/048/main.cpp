
#include "main.hpp"

int main(int argc, char** argv) {
    int128_t mod = pow<int128_t, int>(10, 10);
    int128_t sum = 0;
    for(int i = 1; i < 1001; i++) {
        sum = (sum + pow_mod<int128_t, int>(i, i, mod)) % mod;
    }
    std::cout << sum << std::endl;
	return 0;
}
