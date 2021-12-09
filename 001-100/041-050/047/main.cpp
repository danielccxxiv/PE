
#include "main.hpp"

int main(int argc, char** argv) {
    bool* last_4_condition = new bool[4];
    for(int i = 0; i < 4; i++) {
        last_4_condition[i] = false;
    }
    int n = 2;
    while(!(last_4_condition[0] && (last_4_condition[1] && (last_4_condition[2] && last_4_condition[3])))) {
        last_4_condition[n % 4] = (factor<int, int, true>(n)->len == 4);
        n++;
    }
    std::cout << (n - 4) << std::endl;
	return 0;
}
