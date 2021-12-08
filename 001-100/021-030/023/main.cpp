
#include "main.hpp"

int main(int argc, char** argv) {
    bool* cn_sm = new bool[N];
    for(int i = 0; i < N; i++) {
        cn_sm[i] = true;
    }
    std::vector<int> ab_list;
    for(int i = 2; i < N; i++) {
        if(factor_sum<int, false>(factor<int, true>(i)) > (2 * i)) {
            ab_list.push_back(i);
        }
    }
    int ab_size = ab_list.size();
    int val;
    for(int i = 0; i < ab_size; i++) {
        for(int j = i; j < ab_size; j++) {
            val = ab_list[i] + ab_list[j];
            if(val < N) {
                cn_sm[val] = false;
            } else {
                break;
            }
        }
    }
    int total_sum = 0;
    for(int i = 0; i < N; i++) {
        if(cn_sm[i]) {
            total_sum += i;
        }
    }
    std::cout << total_sum << std::endl;
	return 0;
}
