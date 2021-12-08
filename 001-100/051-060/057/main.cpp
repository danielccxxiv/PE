
#include "main.hpp"

int main(int argc, char** argv) {
    cpp_int num = 3;
    cpp_int denom = 2;
    cpp_int lim = 10;
    int count = 0;
    for(int i = 0; i < 1000; i++) {
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
