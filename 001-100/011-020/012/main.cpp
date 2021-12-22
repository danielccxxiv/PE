
#include "main.hpp"

int main() {
	int32_t n = 3;
	int32_t a;
    int32_t b;
    int32_t num_facts = 0;
	while(num_facts <= 500) {
		a = n;
		b = n + 1;
		if(a % 2 == 0) {
			a /= 2;
		} else {
			b /= 2;
		}
        num_facts = factor_count<int32_t, true>(a, factor<int32_t, int32_t, true>(a))
            * factor_count<int32_t, true>(b, factor<int32_t, int32_t, true>(b));
		n++;
	}
	std::cout << a * b << std::endl;
	return 0;
}
