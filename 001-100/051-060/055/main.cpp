
#include "main.hpp"

int main() {
    int32_t count = 0;
    int1024_t val;
    int1024_t reverse;
    bool lychrel;
    for(int32_t i = 1; i < 10000; i++) {
        lychrel = true;
        val = i;
        reverse = reverse_digits<int1024_t, int32_t>(val);
        for(int32_t j = 0; j < 50; j++) {
            val += reverse;
            reverse = reverse_digits<int1024_t, int32_t>(val);
            if(val == reverse) {
                lychrel = false;
                break;
            }
        }
        if(lychrel) {
            count++;
        }
    }
    std::cout << count << std::endl;
	return 0;
}
