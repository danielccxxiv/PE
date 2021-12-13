
#include "main.hpp"

int main() {
    bool* cn_sm = new bool[N];
    for(size_t i = 0; i < N; i++) {
        cn_sm[i] = true;
    }
    std::vector<int32_t> ab_list;
    for(int32_t i = 2; i < N; i++) {
        if(factor_sum<int32_t, false>(factor<int32_t, int32_t, true>(i)) > (i + i)) {
            ab_list.push_back(i);
        }
    }
    size_t ab_size = ab_list.size();
    int32_t val;
    for(size_t i = 0; i < ab_size; i++) {
        for(size_t j = i; j < ab_size; j++) {
            val = ab_list[i] + ab_list[j];
            if(val < N) {
                cn_sm[val] = false;
            } else {
                break;
            }
        }
    }
    int32_t total_sum = 0;
    for(size_t i = 0; i < N; i++) {
        if(cn_sm[i]) {
            total_sum += i;
        }
    }
    std::cout << total_sum << std::endl;
	return 0;
}
