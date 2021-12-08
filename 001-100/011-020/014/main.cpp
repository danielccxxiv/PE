
#include "main.hpp"

int main(int argc, char** argv) {
    int steps;
    int max = 0;
    int ans = 1;
    for(int i = 0; i < limit; i++) {
        data[i] = -1;
    }
    data[1] = 0;
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

int collatz(int n) {
    if(n < limit) {
        if(data[n] != -1) {
            return data[n];
        }
    }
    int count = 1;
    long next;
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
    int val = collatz(next) + count;
    if(n < limit) {
        data[n] = val;
    }
    return val;
}
