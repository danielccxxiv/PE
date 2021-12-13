
#include "main.hpp"

int main() {
    int32_t steps;
    int32_t max = 0;
    int32_t ans = 1;
    for(int32_t i = 0; i < limit; i++) {
        data[i] = -1;
    }
    data[1] = 0;
    for(int32_t i = 2; i < limit; i++) {
        steps = collatz(i);
        if(steps >= max) {
            max = steps;
            ans = i;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

int32_t collatz(int32_t n) {
    if(n < limit) {
        if(data[n] != -1) {
            return data[n];
        }
    }
    int32_t count = 1;
    int64_t next;
    if(n % 2 == 0) {
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }
    while(next >= limit) {
        if(next % 2 == 0) {
            next /= 2;
        } else {
            next = 3 * next + 1;
        }
        count++;
    }
    int32_t val = collatz(next) + count;
    if(n < limit) {
        data[n] = val;
    }
    return val;
}
