
#include "main.hpp"

int main(int argc, char** argv) {
    int count = 0;
    int1024_t val;
    int1024_t reverse;
    bool lychrel;
    for(int i = 1; i < 10000; i++) {
        lychrel = true;
        val = i;
        reverse = reverse_digits<int1024_t>(val);
        for(int j = 0; j < 50; j++) {
            val += reverse;
            reverse = reverse_digits<int1024_t>(val);
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
