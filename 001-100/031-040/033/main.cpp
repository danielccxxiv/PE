
#include "main.hpp"

int main(int argc, char** argv) {
    int num = 1;
    int denom = 1;
    int frac_smp;
    for(int i = 11; i < 100; i++) {
        if(i % 10 == 0) {
            continue;
        }
        for(int j = i + 1; j < 100; j++) {
            if(j % 10 == 0) {
                continue;
            }
            if((((i / 10) == (j % 10)) && (i * (j / 10) == j * (i % 10)))
                || (((i % 10) == (j / 10)) && (i * (j % 10) == j * (i / 10)))) {
                num *= i;
                denom *= j;
                frac_smp = gcd(num, denom);
                num /= frac_smp;
                denom /= frac_smp;
            }
        }
    }
    std::cout << denom << std::endl;
	return 0;
}
