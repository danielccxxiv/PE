
#include "main.hpp"

int main() {
    boost::unordered_set<int32_t> left_truncatable {2, 3, 5, 7};
    boost::unordered_set<int32_t>::iterator left_truncatable_iter;
    boost::unordered_set<int32_t> right_truncatable {2, 3, 5, 7};
    boost::unordered_set<int32_t>::iterator right_truncatable_iter;
    boost::unordered_set<int32_t> truncatable;
    primesieve::iterator prime_iter;
    prime_iter.skipto(9);
    int32_t num;
    int32_t left_trunc_val;
    int32_t right_trunc_val;
    bool left_trunc_test;
    bool right_trunc_test;
    while(truncatable.size() < 11) {
        num = prime_iter.next_prime();
        left_trunc_test = false;
        right_trunc_test = false;
        left_trunc_val = num % pow_int<int32_t, int32_t>(10, digit_count<int32_t, int32_t>(num) - 1);
        left_truncatable_iter = left_truncatable.find(left_trunc_val);
        if(left_truncatable_iter != left_truncatable.end()) {
            left_truncatable.emplace(num);
            left_trunc_test = true;
        }
        right_trunc_val = num / 10;
        right_truncatable_iter = right_truncatable.find(right_trunc_val);
        if(right_truncatable_iter != right_truncatable.end()) {
            right_truncatable.emplace(num);
            right_trunc_test = true;
        }
        if(left_trunc_test && right_trunc_test) {
            truncatable.emplace(num);
        }
    }
    int32_t sum = 0;
    for(int32_t trunc_num: truncatable) {
        sum += trunc_num;
    }
    std::cout << sum << std::endl;
	return 0;
}
