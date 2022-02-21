
#include "main.hpp"

int main() {
    std::vector<int32_t> fact_sum(2177282); // 9! * 6 + 1 = 2177281, largest possible factorial sum for any number below 2177282
    std::vector<int32_t> loop_count(2177282);
    std::vector<bool> loop_solved(2177282, false);
    std::vector<int32_t> loop_check;
    int32_t loop_size_60_count = 0;
    for(int32_t i = 1; i < 2177282; i++) {
        fact_sum[i] = factorial_digit_sum(i);
    }
    for(int32_t i = 1; i < 2177282; i++) {
        if(!(loop_solved[i])) {
            int32_t next = i;
            size_t loop_begin_pos = 0;
            bool found = false;
            while(!(found)) {
                loop_check.push_back(next);
                next = fact_sum[next];
                if(loop_solved[next]) {
                    break;
                }
                for(size_t j = 0; j < loop_check.size(); j++) {
                    if(loop_check[j] == next) {
                        found = true;
                        loop_begin_pos = j;
                        break;
                    }
                }
            }
            for(size_t j = 0; j < loop_check.size(); j++) {
                loop_solved[loop_check[j]] = true;
            }
            if(found) {
                for(size_t j = loop_begin_pos; j < loop_check.size(); j++) {
                    loop_count[loop_check[j]] = loop_check.size() - loop_begin_pos;
                }
                for(size_t j = 0; j < loop_begin_pos; j++) {
                    loop_count[loop_check[j]] = loop_check.size() - j;
                }
            } else {
                for(size_t j = 0; j < loop_check.size(); j++) {
                    loop_count[loop_check[j]] = loop_check.size() - j + loop_count[next];
                }
            }
            loop_check.clear();
        }
        if((i < 1000000) && (loop_count[i] == 60)) {
            loop_size_60_count++;
        }
    }
    std::cout << loop_size_60_count << std::endl;
	return 0;
}

int32_t factorial_digit_sum(int32_t num) {
    static int32_t fact_arr[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int32_t fact_sum = 0;
    while(num != 0) {
        fact_sum += fact_arr[num % 10];
        num /= 10;
    }
    return fact_sum;
}
