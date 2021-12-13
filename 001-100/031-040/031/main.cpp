
#include "main.hpp"

int main() {
    int32_t* data = new int[(N + 1) * (len + 1)];
    data[0] = 1;
    for(int32_t i = 1; i < (N + 1); i++) {
        data[i] = 0;
    }
    for(int32_t i = 0; i < len; i++) {
        for(int32_t j = 0; j < (N + 1); j++) {
            data[(i + 1) * (N + 1) + j] = 0;
            for(int32_t k = 0; k < (j + 1); k += piece[i]) {
                data[(i + 1) * (N + 1) + j] += data[i * (N + 1) + j - k];
            }
        }
    }
    std::cout << data[(N + 1) * len + N] << std::endl;
	return 0;
}
