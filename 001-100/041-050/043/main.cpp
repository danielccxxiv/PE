
#include "main.hpp"

int main(int argc, char** argv) {
    int* d = new int[10];
    for(int i = 0; i < 10; i++) {
        d[i] = i;
    }
    int loop_limit = factorial<int>(10);
    long sum = 0;
    for(int i = 0; i < loop_limit; i++) {
        if(((d[3] % 2) == 0)
            && (((100 * d[2] + 10 * d[3] + d[4]) % 3) == 0)
            && ((d[5] % 5) == 0)
            && (((100 * d[4] + 10 * d[5] + d[6]) % 7) == 0)
            && (((100 * d[5] + 10 * d[6] + d[7]) % 11) == 0)
            && (((100 * d[6] + 10 * d[7] + d[8]) % 13) == 0)
            && (((100 * d[7] + 10 * d[8] + d[9]) % 17) == 0)) {
            sum += (1L * d[9]);
            sum += (10L * d[8]);
            sum += (100L * d[7]);
            sum += (1000L * d[6]);
            sum += (10000L * d[5]);
            sum += (100000L * d[4]);
            sum += (1000000L * d[3]);
            sum += (10000000L * d[2]);
            sum += (100000000L * d[1]);
            sum += (1000000000L * d[0]);
        }
        perm_iter_inc(d, 10);
    }
    std::cout << sum << std::endl;
	return 0;
}
