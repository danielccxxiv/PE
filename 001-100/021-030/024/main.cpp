
#include "main.hpp"

int main() {
    uint32_t* arr = new uint32_t[N];
    for(uint32_t i = 0; i < N; i++) {
        arr[i] = i;
    }
    lex_reorder(arr, N, val);
    std::string result;
    for(uint32_t i = 0; i < N; i++) {
        result += std::to_string(arr[i]);
    }
    std::cout << result << std::endl;
    return 0;
}

void lex_reorder(uint32_t* arr, uint32_t len, uint64_t val) {
    if(len < 2) {
        return 0;
    }
    uint32_t q = val / factorial<uint64_t>(len - 1);
    val = val - q * factorial<uint64_t>(len - 1);
    uint32_t el = arr[q];
    for(uint32_t i = q - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = el;
    lex_reorder(arr + 1, len - 1, val);
    return;
}
