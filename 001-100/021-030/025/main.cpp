
#include "main.hpp"

int main() {
    int32_t pos = 1;
    cpp_int lim = pow_int<cpp_int, int>(10, 999);
    while(fibonacci<cpp_int>(pos) < lim) {
        pos++;
    }
    std::cout << pos << std::endl;
    return 0;
}
