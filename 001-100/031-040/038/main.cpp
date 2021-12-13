
#include "main.hpp"

int main() {
    int32_t max_val = 918273645;
    int32_t pandigital_hash = unordered_digit_hash<int32_t, int32_t>(max_val);
    int32_t num;
    for(int32_t i = 9183; i < 10000; i++) {
        num = i * 100002;
        if(unordered_digit_hash<int32_t, int32_t>(num) == pandigital_hash) {
            max_val = num;
        }
    }
    std::cout << max_val << std::endl;
	return 0;
}
