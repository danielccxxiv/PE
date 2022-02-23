
#include "main.hpp"

int main() {
    std::vector<int64_t> partition_count(101, 0);
    partition_count[0] = 1;
    partition_count[1] = 1;
    for(int32_t i = 2; i < 101; i++) {
        for(int32_t j = 1; j < i; j++) {
            if((j % 2) == 1) {
                int32_t pent0 = (j * (3 * j - 1)) / 2;
                if(pent0 > i) {
                    break;
                }
                partition_count[i] += partition_count[i - pent0];
                int32_t pent1 = (j * (3 * j + 1)) / 2;
                if(pent1 > i) {
                    break;
                }
                partition_count[i] += partition_count[i - pent1];
            } else {
                int32_t pent0 = (j * (3 * j - 1)) / 2;
                if(pent0 > i) {
                    break;
                }
                partition_count[i] -= partition_count[i - pent0];
                int32_t pent1 = (j * (3 * j + 1)) / 2;
                if(pent1 > i) {
                    break;
                }
                partition_count[i] -= partition_count[i - pent1];
            }
        }
    }
    std::cout << (partition_count[100] - 1) << std::endl;
	return 0;
}
