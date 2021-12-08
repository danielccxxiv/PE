
#include "main.hpp"

int main(int argc, char** argv) {
    int max_val = 918273645;
    bool* digit_list = new bool[10];
    int num;
    for(int i = 9183; i < 10000; i++) {
        for(int j = 0; j < 10; j++) {
            digit_list[j] = false;
        }
        num = i;
        while(num != 0) {
            if(((num % 10) == 0) || digit_list[num % 10]) {
                digit_list[0] = true;
                break;
            }
            digit_list[num % 10] = true;
            num /= 10;
        }
        if(digit_list[0]) {
            continue;
        }
        num = 2 * i;
        while(num != 0) {
            if(((num % 10) == 0) || digit_list[num % 10]) {
                digit_list[0] = true;
                break;
            }
            digit_list[num % 10] = true;
            num /= 10;
        }
        if(digit_list[0]) {
            continue;
        }
        max_val = i * 100002;
    }
    std::cout << max_val << std::endl;
	return 0;
}
