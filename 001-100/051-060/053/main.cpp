
#include "main.hpp"

int main() {
    int32_t count = 0;
    int32_t k;
    for(int32_t n = 0; n < 101; n++) {
        k = 0;
        while((k < ((n / 2) + 1)) && (combination<int128_t>(n, k) <= 1000000)) {
            k++;
        }
        if(!(k == ((n / 2) + 1))) {
            count += (n + 1 - 2 * k);
        }
    }
    std::cout << count << std::endl;
	return 0;
}
