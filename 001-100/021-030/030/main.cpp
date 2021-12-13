
#include "main.hpp"

int main() {
    int32_t power5[] = {
        pow_int<int32_t, int32_t>(0, 5),
        pow_int<int32_t, int32_t>(1, 5),
        pow_int<int32_t, int32_t>(2, 5),
        pow_int<int32_t, int32_t>(3, 5),
        pow_int<int32_t, int32_t>(4, 5),
        pow_int<int32_t, int32_t>(5, 5),
        pow_int<int32_t, int32_t>(6, 5),
        pow_int<int32_t, int32_t>(7, 5),
        pow_int<int32_t, int32_t>(8, 5),
        pow_int<int32_t, int32_t>(9, 5)
    };
    int32_t lim = 6 * power5[9] + 1;
    int32_t sum = 0;
    int32_t temp_num;
    int32_t temp_sum;
    for(int32_t i = 10; i < lim; i++) {
        temp_num = i;
        temp_sum = 0;
        while(temp_num != 0) {
            temp_sum += power5[temp_num % 10];
            temp_num /= 10;
        }
        if(i == temp_sum) {
            sum += temp_sum;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
