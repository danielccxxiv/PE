
#include "main.hpp"

int main(int argc, char** argv) {
    int* data = new int[(N + 1) * (len + 1)];
    data[0] = 1;
    for(int i = 1; i < (N + 1); i++) {
        data[i] = 0;
    }
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < (N + 1); j++) {
            data[(i + 1) * (N + 1) + j] = 0;
            for(int k = 0; k < (j + 1); k += piece[i]) {
                data[(i + 1) * (N + 1) + j] += data[i * (N + 1) + j - k];
            }
        }
    }
    std::cout << data[(N + 1) * len + N] << std::endl;
	return 0;
}
