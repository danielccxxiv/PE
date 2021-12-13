
#include "main.hpp"

int main() {
    boost::unordered_set<int32_t> data;
    int32_t* arr = new int32_t[9];
    loop(arr, 0, data);
    int32_t sum = 0;
    for(int32_t i: data) {
        sum += i;
    }
    std::cout << sum << std::endl;
	return 0;
}

void loop(int32_t* arr, int32_t level, boost::unordered_set<int32_t>& data) {
    if(level == 5) {
        int64_t hash0 = unordered_digit_hash<int32_t, int32_t, int64_t>(
            arr[0]
            + 10 * arr[1]
            + 100 * arr[2]
            + 1000 * arr[3]
            + 10000 * arr[4]
        );
        int32_t x = (arr[0] + 10 * arr[1]) * (arr[2] + 10 * arr[3] + 100 * arr[4]);
        int64_t hash_x = unordered_digit_hash<int32_t, int32_t, int64_t>(x);
        if((hash0 * hash_x) == pandigital_hash) {
            data.emplace(x);
        }
        x = arr[0] * (arr[1] + 10 * arr[2] + 100 * arr[3] + 1000 * arr[4]);
        hash_x = unordered_digit_hash<int32_t, int32_t, int64_t>(x);
        if((hash0 * hash_x) == pandigital_hash) {
            data.emplace(x);
        }
        return;
    }
    for(arr[level] = 1; arr[level] < 10; arr[level]++) {
        bool test = false;
        for(int32_t i = 0; i < level; i++) {
            if(arr[level] == arr[i]) {
                test = true;
                break;
            }
        }
        if(test) {
            continue;
        }
        loop(arr, level + 1, data);
    }
    return;
}
