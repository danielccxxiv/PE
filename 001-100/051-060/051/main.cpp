#include "main.hpp"

int main() {
    int32_t last_prime = prime<int32_t>::iter.next_prime();
    int32_t num_digits = 3;
    bool* wildcard_arr;
    int32_t max_val;
    while(wc_primes.size() == 0) {
        num_digits++;
        wildcard_arr = new bool[num_digits];
        max_val = pow_int<int32_t, int32_t>(10, num_digits);
        while(last_prime < max_val) {
            prime<int32_t>::list.push_back(last_prime);
            last_prime = prime<int32_t>::iter.next_prime();
        }
        for(int32_t i = 3; i < num_digits; i += 3) {
            loop_wildcard(wildcard_arr, num_digits, 0, i, 0, 0);
        }
        delete[] wildcard_arr;
    }
    max_val = pow_int<int32_t, int32_t>(10, num_digits - 1);
    for(int32_t p: wc_primes) {
        if(p >= max_val) {
            std::cout << p << std::endl;
            break;
        }
    }
	return 0;
}

int32_t loop_wildcard(bool* wc_arr, int32_t len, int32_t level, int32_t wildcard_limit, int32_t wildcard_count, int32_t offset) {
    if((len - level) < (wildcard_limit - wildcard_count)) {
        return 0;
    }
    if(level == len) {
        return loop_fill(wc_arr, len, 0, 0, offset);
    }
    wc_arr[level] = true;
    loop_wildcard(wc_arr, len, level + 1, wildcard_limit, wildcard_count, offset);
    if((wildcard_count < wildcard_limit) && (level > 0)) {
        wc_arr[level] = false;
        loop_wildcard(wc_arr, len, level + 1, wildcard_limit, wildcard_count + 1, offset + pow_int<int32_t, int32_t>(10, level));
    }
    return 0;
}

int32_t loop_fill(bool* wc_arr, int32_t len, int32_t level, int32_t base_val, int32_t offset) {
    if(level == len) {
        int32_t count = 0;
        int32_t low;
        int32_t val;
        int32_t lower_limit = pow_int<int32_t, int32_t>(10, len - 1);
        for(int32_t i = 0; i < 10; i++) {
            val = base_val + i * offset;
            if((val >= lower_limit) && (binary_search(prime<int32_t>::list, val, 0, prime<int32_t>::list.size()) >= 0)) {
                if(count == 0) {
                    low = val;
                }
                count++;
            }
        }
        if(count > 7) {
            wc_primes.emplace(low);
        }
    } else if(level == 0) {
        loop_fill(wc_arr, len, 1, 1, offset);
        loop_fill(wc_arr, len, 1, 3, offset);
        loop_fill(wc_arr, len, 1, 7, offset);
        loop_fill(wc_arr, len, 1, 9, offset);
    } else if(wc_arr[level]) {
        for(int32_t i = 0; i < 10; i++) {
            loop_fill(wc_arr, len, level + 1, base_val + i * pow_int<int32_t, int32_t>(10, level), offset);
        }
    } else {
        loop_fill(wc_arr, len, level + 1, base_val, offset);
    }
    return 0;
}
