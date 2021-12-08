
#include "main.hpp"

int main(int argc, char** argv) {
    int lim = 6 * pow<int, int>(9, 5) + 1;
    int sum = 0;
    for(int i = 10; i < lim; i++) {
        if(i == digit_power_sum(i, 5)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

int digit_power_sum(int n, int k) {
    int sum = 0;
    while(n > 0) {
        sum += pow<int, int>(n % 10, k);
        n /= 10;
    }
    return sum;
}
