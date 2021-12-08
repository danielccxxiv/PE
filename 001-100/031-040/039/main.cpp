
#include "main.hpp"

int main(int argc, char** argv) {
    int* num_solutions = new int[limit];
    for(int i = 0; i < limit; i++) {
        num_solutions[i] = 0;
    }
    int val;
    for(int m = 2; m < limit; m++) {
        if(2 * m * m > limit) {
            break;
        }
        for(int n = 1; n < m; n++) {
            if(gcd(m, n) != 1) {
                continue;
            }
            val = 2 * m * (m + n);
            if(val < limit) {
                for(int i = val; i < limit; i += val) {
                    num_solutions[i]++;
                }
            } else {
                break;
            }
        }
    }
    int max_solutions = 0;
    int result = 0;
    for(int i = 0; i < limit; i++) {
        if(num_solutions[i] > max_solutions) {
            max_solutions = num_solutions[i];
            result = i;
        }
    }
    std::cout << result << std::endl;
	return 0;
}
