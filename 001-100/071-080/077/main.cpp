
#include "main.hpp"

int main() {
    int32_t num = 0;
    int32_t prime_check = 0;
    prime<int32_t>::update(prime_check);
    bool count_over_5000 = false;
    while(!(count_over_5000)) {
        num++;
        while(!(prime<int32_t>::list[prime_check] > num)) {
            prime_check++;
            prime<int32_t>::update(prime_check);
        }
        count_over_5000 = (partition_count(num, prime_check) > 5000);
    }
    std::cout << num << std::endl;
	return 0;
}

int32_t partition_count(const size_t num, const size_t bound) {
    static std::vector<std::vector<int32_t>> data = {{1}};
    prime<int32_t>::update(bound);
    while((num + 1) > data.size()) {
        data.push_back(std::vector<int32_t>());
    }
    while((bound + 1) > data[num].size()) {
        data[num].push_back(-1);
    }
    if(data[num][bound] != -1) {
        return data[num][bound];
    }
    if(num == 0) {
        data[num][bound] = 1;
        return data[num][bound];
    }
    if(bound == 0) {
        if((num % prime<int32_t>::list[bound]) == 0) {
            data[num][bound] = 1;
        } else {
            data[num][bound] = 0;
        }
        return data[num][bound];
    }
    data[num][bound] = 0;
    for(size_t i = 0; i < (num + 1); i += prime<int32_t>::list[bound]) {
        data[num][bound] += partition_count(num - i, bound - 1);
    }
    return data[num][bound];
}
