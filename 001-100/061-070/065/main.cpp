
#include "main.hpp"

int main() {
    int32_t frac_arr[100];
    int1024_t num_arr[100];
    frac_arr[0] = 2;
    for(int32_t i = 1; i < 100; i++) {
        if((i % 3) == 2) {
            frac_arr[i] = ((i + 1) / 3) * 2;
        } else {
            frac_arr[i] = 1;
        }
    }
    num_arr[0] = frac_arr[0];
    num_arr[1] = frac_arr[0] * frac_arr[1] + 1;
    for(int32_t i = 2; i < 100; i++) {
        num_arr[i] = num_arr[i - 1] * frac_arr[i] + num_arr[i - 2];
    }
    std::cout << digit_sum<int1024_t, int32_t>(num_arr[99]) << std::endl;
    return 0;
}
