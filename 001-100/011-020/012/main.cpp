
#include "main.hpp"

int main() {
	uint32_t n = 3;
	uint32_t a;
    uint32_t b;
    uint32_t num_facts = 0;
	while(num_facts <= 500) {
		a = n;
		b = n + 1;
		if(a % 2 == 0) {
			a /= 2;
		} else {
			b /= 2;
		}
        num_facts = factor_count<uint32_t, true>(factor<uint32_t, uint32_t, true>(a))
            * factor_count<uint32_t, true>(factor<uint32_t, uint32_t, true>(b));
		n++;
	}
	std::cout << a * b << std::endl;
	return 0;
}
