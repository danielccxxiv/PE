
#include "main.hpp"

int main() {
    int32_t* arr = new int32_t[N];
    for(int32_t i = 0; i < N; i++) {
        arr[i] = i;
    }
    lex_reorder(arr, N, val);
    std::string result;
    for(size_t i = 0; i < N; i++) {
        result += std::to_string(arr[i]);
    }
    std::cout << result << std::endl;
    return 0;
}

void lex_reorder(int32_t* arr, size_t len, int64_t val) {
    if(len < 2) {
        return;
    }
    int32_t q = val / factorial<int64_t>(len - 1);
    val -= (q * factorial<int64_t>(len - 1));
    int32_t el = arr[q];
    for(int32_t i = 0; i < q; i++) {
        arr[q - i] = arr[q - i - 1];
    }
    arr[0] = el;
    lex_reorder(arr + 1, len - 1, val);
    return;
}
