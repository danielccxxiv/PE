
#include "main.hpp"

int main() {
    int32_t totient_min = 1;
    int32_t totient_val = 1;
    double min_ratio = 10000000;
    for(int32_t i = 2; i < 10000000; i++) {
        totient_val = totient<int32_t, false>(i, factor<int32_t, int32_t, true>(i));
        if(unordered_digit_hash<int32_t, int32_t>(totient_val) == unordered_digit_hash<int32_t, int32_t>(i)) {
            double cur_ratio = static_cast<double>(i) / totient<int32_t, false>(i, factor<int32_t, int32_t, true>(i));
            if(cur_ratio < min_ratio) {
                min_ratio = cur_ratio;
                totient_min = i;
            }
        }
    }
    std::cout << totient_min << std::endl;
	return 0;
}
