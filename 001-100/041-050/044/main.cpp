
#include "main.hpp"

int main() {
    int32_t pos = 1;
    int64_t pent0;
    int64_t pent1;
    int64_t result;
    bool found = false;
    while(!(found)) {
        pent0 = pentagonal(pos);
        for(int32_t i = 1; i <= pos; i++) {
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

int64_t pentagonal(int32_t n) {
    static std::vector<int64_t> data {0, 1};
    if(n < ((int32_t) data.size())) {
        return data[n];
    }
    int64_t val = 2 * pentagonal(n - 1) - pentagonal(n - 2) + 3;
    data.push_back(val);
    return val;
}

bool is_pentagonal(int64_t num) {
    int64_t tr_num = 24 * num + 1;
    int64_t test_val = int_sqrt<int64_t>(tr_num);
    if(((test_val * test_val) != tr_num) || ((test_val % 6) != 5)) {
        return false;
    }
    return true;
}
