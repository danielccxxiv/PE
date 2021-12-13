
#include "main.hpp"

int main() {
    int32_t pent_pos = 0;
    int32_t hex_pos = 0;
    int64_t pent = 0;
    int64_t hex = 0;
    while(!((pent == hex) && (pent > 40755))) {
        if(pent < hex) {
            pent += (3 * pent_pos + 1);
            pent_pos++;
        } else {
            hex += (4 * hex_pos + 1);
            hex_pos++;
        }
    }
    std::cout << pent << std::endl;
	return 0;
}
