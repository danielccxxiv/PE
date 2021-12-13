
#include "main.hpp"

int main() {
    cpp_int num = 3;
    cpp_int denom = 2;
    cpp_int lim = 10;
    int32_t count = 0;
    for(int32_t i = 0; i < 1000; i++) {
        while(lim <= denom) {
            lim *= 10;
        }
        if(num >= lim) {
            count++;
        }
        denom += num;
        num = 2 * denom - num;
    }
    std::cout << count << std::endl;
	return 0;
}
