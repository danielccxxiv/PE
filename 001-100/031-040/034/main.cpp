
#include "main.hpp"

int main(int argc, char** argv) {
    int sum = 0;
    int limit = 7 * factorial<int>(9);
    for(int i = 10; i < limit; i++) {
        if(i == digit_fact_sum(i)) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
	return 0;
}

int digit_fact_sum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += factorial<int>(n % 10);
        n /= 10;
    }
    return sum;
}
