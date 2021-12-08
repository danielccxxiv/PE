
#include "main.hpp"

int main(int argc, char** argv) {
    std::cout << spiral_sum(1001) << std::endl;
    return 0;
}

long spiral_sum(int n) {
    long x = (n - 1) / 2;
    return ((2 * x * (8 * x * x + 15 * x + 13)) / 3) + 1;
}
