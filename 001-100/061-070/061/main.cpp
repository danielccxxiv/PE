
#include "main.hpp"

int main() {
    int32_t** data = new int32_t*[6];
    size_t* data_len = new size_t[6];
    std::queue<int32_t> q;
    int32_t n;
    for(int32_t i = 0; i < 10000; i++) {
        n = (i * (i + 1)) / 2;
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[0] = q.size();
    data[0] = new int32_t[data_len[0]];
    for(size_t i = 0; i < data_len[0]; i++) {
        data[0][i] = q.front();
        q.pop();
    }
    for(int32_t i = 0; i < 10000; i++) {
        n = i * i;
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[1] = q.size();
    data[1] = new int32_t[data_len[1]];
    for(size_t i = 0; i < data_len[1]; i++) {
        data[1][i] = q.front();
        q.pop();
    }
    for(int32_t i = 0; i < 10000; i++) {
        n = (i * (3 * i - 1)) / 2;
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[2] = q.size();
    data[2] = new int32_t[data_len[2]];
    for(size_t i = 0; i < data_len[2]; i++) {
        data[2][i] = q.front();
        q.pop();
    }
    for(int32_t i = 0; i < 10000; i++) {
        n = i * (2 * i - 1);
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[3] = q.size();
    data[3] = new int32_t[data_len[3]];
    for(size_t i = 0; i < data_len[3]; i++) {
        data[3][i] = q.front();
        q.pop();
    }
    for(int32_t i = 0; i < 10000; i++) {
        n = (i * (5 * i - 3)) / 2;
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[4] = q.size();
    data[4] = new int32_t[data_len[4]];
    for(size_t i = 0; i < data_len[4]; i++) {
        data[4][i] = q.front();
        q.pop();
    }
    for(int32_t i = 0; i < 10000; i++) {
        n = i * (3 * i - 2);
        if(n > 9999) {
            break;
        }
        if((n > 999) && ((n % 100) > 9)) {
            q.push(n);
        }
    }
    data_len[5] = q.size();
    data[5] = new int32_t[data_len[5]];
    for(size_t i = 0; i < data_len[5]; i++) {
        data[5][i] = q.front();
        q.pop();
    }
    int32_t arr[] = {0, 0, 0, 0, 0, 0};
    bool used[] = {false, false, false, false, false, false};
    loop(arr, used, 0, data, data_len);
    int32_t sum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5];
    std::cout << sum << std::endl;
	return 0;
}

bool loop(int32_t* arr, bool* used, size_t level, int32_t** data, size_t* data_len) {
    if(level == 6) {
        return ((arr[0] / 100) == (arr[5] % 100));
    }
    if(level == 0) {
        used[0] = true;
        for(size_t i = 0; i < data_len[0]; i++) {
            arr[0] = data[0][i];
            if(loop(arr, used, 1, data, data_len)) {
                return true;
            }
        }
        used[0] = false;
        return false;
    }
    for(size_t i = 1; i < 6; i++) {
        if(used[i]) {
            continue;
        }
        used[i] = true;
        int32_t min_pos = binary_search<int32_t>(data[i], 100 * (arr[level - 1] % 100), 0, data_len[i]);
        if(min_pos < 0) {
            min_pos = (-min_pos - 1);
        }
        int32_t max_pos = binary_search<int32_t>(data[i], 100 * (arr[level - 1] % 100) + 100, 0, data_len[i]);
        if(max_pos < 0) {
            max_pos = (-max_pos - 1);
        }
        for(int32_t j = min_pos; j < max_pos; j++) {
            arr[level] = data[i][j];
            if(loop(arr, used, level + 1, data, data_len)) {
                return true;
            }
        }
        used[i] = false;
    }
    return false;
}
