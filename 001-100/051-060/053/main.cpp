
#include "main.hpp"

int main(int argc, char** argv) {
    int count = 0;
    int k;
    for(int n = 0; n < 101; n++) {
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
