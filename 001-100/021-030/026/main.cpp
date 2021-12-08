
#include "main.hpp"

int main(int argc, char** argv) {
    int max_cyc = 0;
    int temp, max_base, i;
    for(i = 2; i < limit; i++) {
        if((i % 2 == 0) || (i % 5 == 0)) {
            continue;
        }
        temp = mult_group_size<int, true>(i, 10, factor<int, true>(totient<int, true>(factor<int, true>(i))));
        if(temp > max_cyc) {
            max_cyc = temp;
            max_base = i;
        }
    }
    std::cout << max_base << std::endl;
    return 0;
}
