
#include "main.hpp"

int main(int argc, char** argv) {
    int pos = 1;
    long pent0;
    long pent1;
    long result;
    bool found = false;
    while(!(found)) {
        pent0 = pentagonal(pos);
        for(int i = 1; i <= pos; i++) {
            pent1 = pentagonal(i);
            if(is_pentagonal(pent0 + pent1)) {
                if(is_pentagonal(2 * pent0 + pent1)) {
                    result = pent1;
                    found = true;
                    break;
                } else if(is_pentagonal(pent0 + 2 * pent1)) {
                    result = pent0;
                    found = true;
                    break;
                }
            }
        }
        pos++;
    }
    std::cout << result << std::endl;
	return 0;
}

long pentagonal(int n) {
    static std::vector<long> data {0, 1};
    if(n < data.size()) {
        return data[n];
    }
    long val = 2 * pentagonal(n - 1) - pentagonal(n - 2) + 3;
    data.push_back(val);
    return val;
}

bool is_pentagonal(long num) {
    long tr_num = 24 * num + 1;
    long test_val = floor_sqrt<long>(tr_num);
    if(((test_val % 6) != 5) || ((test_val * test_val) != tr_num)) {
        return false;
    }
    return true;
}
