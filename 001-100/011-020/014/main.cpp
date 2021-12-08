
#include "main.hpp"

int main(int argc, char** argv) {
    int steps;
    int max = 0;
    int ans = 1;
    for(int i = 0; i < limit; i++) {
        data_arr[i] = -1;
    }
    data_arr[1] = 0;
    for(int i = 2; i < limit; i++) {
        steps = collatz(i);
        if(steps >= max) {
            max = steps;
            ans = i;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

int collatz(long n) {
    if(n < limit) {
        if(data_arr[n] != -1) {
            return data_arr[n];
        }
    } else {
        data_iter = data_map.find(n);
        if(data_iter != data_map.end()) {
            return data_iter->second;
        }
    }
    long next;
    if(n % 2 == 0) {
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }
    int val = collatz(next) + 1;
    if(n < limit) {
        data_arr[n] = val;
    } else {
        data_map.emplace(n, val);
    }
    return val;
}
