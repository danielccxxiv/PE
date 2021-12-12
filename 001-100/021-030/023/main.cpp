
#include "main.hpp"

int main() {
    bool* cn_sm = new bool[N];
    for(uint32_t i = 0; i < N; i++) {
        cn_sm[i] = true;
    }
    std::vector<uint32_t> ab_list;
    for(uint32_t i = 2; i < N; i++) {
        if(factor_sum<uint32_t, false>(factor<uint32_t, uint32_t, true>(i)) > (i + i)) {
            ab_list.push_back(i);
        }
    }
    uint32_t ab_size = ab_list.size();
    uint32_t val;
    for(uint32_t i = 0; i < ab_size; i++) {
        for(uint32_t j = i; j < ab_size; j++) {
            val = ab_list[i] + ab_list[j];
            if(val < N) {
                cn_sm[val] = false;
            } else {
                break;
            }
        }
    }
    uint32_t total_sum = 0;
    for(uint32_t i = 0; i < N; i++) {
        if(cn_sm[i]) {
            total_sum += i;
        }
    }
    std::cout << total_sum << std::endl;
	return 0;
}
