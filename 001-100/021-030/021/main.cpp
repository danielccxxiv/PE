
#include "main.hpp"

int main(int argc, char** argv) {
	int sum = 0;
    int div_sum;
	for(int i = 2; i < 10000; i++) {
        div_sum = factor_sum<int, true>(factor<int, int, true>(i)) - i;
        if((div_sum != i) && (div_sum != 1) && (factor_sum<int, true>(factor<int, int, true>(div_sum)) == (div_sum + i))) {
            sum += i;
        }
	}
	std::cout << sum << std::endl;
	return 0;
}
