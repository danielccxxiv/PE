
#include "main.hpp"

int main() {
    std::vector<int64_t> partition_count(2, 0);
    partition_count[0] = 1;
    partition_count[1] = 1;
    int32_t num = 1;
    while(partition_count[num] != 0) {
        num++;
        partition_count.push_back(0);
        for(int32_t j = 1; j < num; j++) {
            if((j % 2) == 1) {
                int32_t pent0 = (j * (3 * j - 1)) / 2;
                if(pent0 > num) {
                    break;
                }
                partition_count[num] += partition_count[num - pent0];
                int32_t pent1 = (j * (3 * j + 1)) / 2;
                if(pent1 > num) {
                    break;
                }
                partition_count[num] += partition_count[num - pent1];
            } else {
                int32_t pent0 = (j * (3 * j - 1)) / 2;
                if(pent0 > num) {
                    break;
                }
                partition_count[num] -= partition_count[num - pent0];
                int32_t pent1 = (j * (3 * j + 1)) / 2;
                if(pent1 > num) {
                    break;
                }
                partition_count[num] -= partition_count[num - pent1];
            }
        }
        partition_count[num] %= 1000000;
    }
    std::cout << num << std::endl;
	return 0;
}
