
#include "main.hpp"

int main() {
    int32_t totient_max = 1;
    double max_ratio = 1;
    for(int32_t i = 2; i < 1000001; i++) {
        double cur_ratio = static_cast<double>(i) / totient<int32_t, false>(i, factor<int32_t, int32_t, true>(i));
        if(cur_ratio > max_ratio) {
            max_ratio = cur_ratio;
            totient_max = i;
        }
    }
    std::cout << totient_max << std::endl;
	return 0;
}
