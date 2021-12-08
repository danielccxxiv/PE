
#include "main.hpp"

int main(int argc, char** argv) {
    boost::unordered_set<int> left_truncatable {2, 3, 5, 7};
    boost::unordered_set<int>::iterator left_truncatable_iter;
    boost::unordered_set<int> right_truncatable {2, 3, 5, 7};
    boost::unordered_set<int>::iterator right_truncatable_iter;
    boost::unordered_set<int> truncatable;
    primesieve::iterator prime_iter;
    prime_iter.skipto(9);
    int num;
    int left_trunc_val;
    int right_trunc_val;
    bool left_trunc_test;
    bool right_trunc_test;
    while(truncatable.size() < 11) {
        num = prime_iter.next_prime();
        left_trunc_test = false;
        right_trunc_test = false;
        left_trunc_val = num % pow<int, int>(10, digit_count(num) - 1);
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
    int sum = 0;
    for(int trunc_num: truncatable) {
        sum += trunc_num;
    }
    std::cout << sum << std::endl;
	return 0;
}
