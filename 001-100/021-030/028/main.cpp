
#include "main.hpp"

int main(int argc, char** argv) {
    int64_t x = (N - 1) / 2;
    int64_t sum = ((2 * x * (8 * x * x + 15 * x + 13)) / 3) + 1;
    std::cout << sum << std::endl;
    return 0;
}
