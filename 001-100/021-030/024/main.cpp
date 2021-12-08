
#include "main.hpp"

int main(int argc, char** argv) {
    int* arr = new int[N];
    int i;
    for(i = 0; i < N; i++) {
        arr[i] = i;
    }
    lex_reorder(arr, N, val);
    std::string result;
    for(i = 0; i < N; i++) {
        result += std::to_string(arr[i]);
    }
    std::cout << result << std::endl;
    return 0;
}

int lex_reorder(int* arr, int len, long val) {
    if(len < 2) {
        return 0;
    }
    int q = val / factorial<int>(len - 1);
    val = val - q * factorial<int>(len - 1);
    int el = arr[q];
    for(int i = q - 1; i > -1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = el;
    lex_reorder(arr + 1, len - 1, val);
    return 0;
}
