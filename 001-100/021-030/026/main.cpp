
#include "main.hpp"

int main() {
    int32_t max_cyc = 0;
    int32_t temp;
    int32_t max_base;
    for(int32_t i = 2; i < limit; i++) {
        if((i % 2 == 0) || (i % 5 == 0)) {
            continue;
        }
        temp = mult_group_size<int32_t, false>(
            i, 10, factor<int32_t, int32_t, true>(totient<int32_t, true>(factor<int32_t, int32_t, true>(i))));
        if(temp > max_cyc) {
            max_cyc = temp;
            max_base = i;
        }
    }
    std::cout << max_base << std::endl;
    return 0;
}
