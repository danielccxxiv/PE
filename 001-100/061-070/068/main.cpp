
#include "main.hpp"

int main() {
    std::vector<int32_t> ring_init = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    uint64_t max_val = 0;
    for(int32_t target_sum = 14; target_sum < 20; target_sum++) {
        fill_loop(ring_init, target_sum, 0, max_val);
    }
    std::cout << max_val << std::endl;
	return 0;
}

void fill_loop(std::vector<int32_t>& ring, const int32_t target_sum, const size_t level, uint64_t& max_val) {
    if(level == 0) {
        for(size_t i = level; i < 10; i++) {
            int32_t swap_term = ring[i];
            ring[i] = ring[level];
            ring[level] = swap_term;
            fill_loop(ring, target_sum, level + 1, max_val);
            swap_term = ring[i];
            ring[i] = ring[level];
            ring[level] = swap_term;
        }
    } else if(level == 1) {
        for(size_t i = level; i < 10; i++) {
            int32_t swap_term = ring[i];
            ring[i] = ring[level];
            ring[level] = swap_term;
            fill_loop(ring, target_sum, level + 1, max_val);
            swap_term = ring[i];
            ring[i] = ring[level];
            ring[level] = swap_term;
        }
    } else if(((level % 2) == 0) && (level != 10)) {
        for(size_t i = level; i < 10; i++) {
            if(ring[i] > ring[0]) {
                int32_t swap_term = ring[i];
                ring[i] = ring[level];
                ring[level] = swap_term;
                fill_loop(ring, target_sum, level + 1, max_val);
                swap_term = ring[i];
                ring[i] = ring[level];
                ring[level] = swap_term;
            }
        }
    } else if(((level % 2) == 1) && (level != 9)) {
        for(size_t i = level; i < 10; i++) {
            if((ring[level - 3] + ring[level - 2] + ring[i]) == target_sum) {
                int32_t swap_term = ring[i];
                ring[i] = ring[level];
                ring[level] = swap_term;
                fill_loop(ring, target_sum, level + 1, max_val);
                swap_term = ring[i];
                ring[i] = ring[level];
                ring[level] = swap_term;
            }
        }
    } else if(level == 9) {
        if(((ring[6] + ring[7] + ring[9]) == target_sum) && ((ring[8] + ring[9] + ring[1]) == target_sum)) {
            fill_loop(ring, target_sum, level + 1, max_val);
        }
    } else {
        uint64_t cur_val = 0;
        bool ten_check = false;
        for(size_t i = 0; i < 10; i += 2) {
            if(ring[i] == 10) {
                cur_val = cur_val * 100 + 10;
                if(ten_check) {
                    return;
                } else {
                    ten_check = true;
                }
            } else {
                cur_val = cur_val * 10 + ring[i];
            }
            if(ring[(i + 1) % 10] == 10) {
                cur_val = cur_val * 100 + 10;
                if(ten_check) {
                    return;
                } else {
                    ten_check = true;
                }
            } else {
                cur_val = cur_val * 10 + ring[(i + 1) % 10];
            }
            if(ring[(i + 3) % 10] == 10) {
                cur_val = cur_val * 100 + 10;
                if(ten_check) {
                    return;
                } else {
                    ten_check = true;
                }
            } else {
                cur_val = cur_val * 10 + ring[(i + 3) % 10];
            }
        }
        if(cur_val > max_val) {
            max_val = cur_val;
        }
    }
}
