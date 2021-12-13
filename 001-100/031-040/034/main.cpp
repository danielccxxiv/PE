
#include "main.hpp"

int main() {
    int32_t sum = 0;
    int32_t limit = 7 * factorial<int32_t>(9);
    for(int32_t i = 10; i < limit; i++) {
        if(i == digit_fact_sum(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
	return 0;
}

int32_t digit_fact_sum(int32_t n) {
    int32_t sum = 0;
    while(n > 0) {
        sum += factorial<int32_t>(n % 10);
        n /= 10;
    }
    return sum;
}
