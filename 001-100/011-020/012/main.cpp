
#include "main.hpp"

int main(int argc, char** argv) {
	int n = 3;
	int a;
    int b;
    int num_facts = 0;
	while(num_facts <= 500) {
		a = n;
		b = n + 1;
		if(a % 2 == 0) {
			a /= 2;
		} else {
			b /= 2;
		}
        num_facts = factor_count<int, true>(factor<int, int, true>(a)) * factor_count<int, true>(factor<int, int, true>(b));
		n++;
	}
	std::cout << a * b << std::endl;
	return 0;
}
