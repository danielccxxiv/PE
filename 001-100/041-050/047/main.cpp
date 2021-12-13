
#include "main.hpp"

int main() {
    bool* last_4_condition = new bool[4];
    for(int32_t i = 0; i < 4; i++) {
        last_4_condition[i] = false;
    }
    int32_t n = 2;
    while(!(last_4_condition[0] && (last_4_condition[1] && (last_4_condition[2] && last_4_condition[3])))) {
        last_4_condition[n % 4] = (factor<int32_t, int32_t, true>(n)->len == 4);
        n++;
    }
    std::cout << (n - 4) << std::endl;
	return 0;
}
