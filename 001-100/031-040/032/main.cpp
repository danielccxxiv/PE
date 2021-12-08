
#include "main.hpp"

int main(int argc, char** argv) {
    boost::unordered_set<int> data;
    int* arr = new int[9];
    loop(arr, 0, data);
    int sum = 0;
    for(int i: data) {
        sum += i;
    }
    std::cout << sum << std::endl;
	return 0;
}

int loop(int* arr, int level, boost::unordered_set<int>& data) {
    if(level == 5) {
        int x = (arr[0] + 10 * arr[1]) * (arr[2] + 10 * arr[3] + 100 * arr[4]);
        int y = x;
        bool test = false;
        if(x < 10000) {
            for(int i = 5; i < 9; i++) {
                arr[i] = y % 10;
                if(arr[i] == 0) {
                    test = true;
                    break;
                }
                for(int j = 0; j < i; j++) {
                    test = (arr[i] == arr[j]);
                    if(test) {
                        break;
                    }
                }
                if(test) {
                    break;
                }
                y /= 10;
            }
            if(!(test)) {
                data.emplace(x);
            }
        }
        x = arr[0] * (arr[1] + 10 * arr[2] + 100 * arr[3] + 1000 * arr[4]);
        y = x;
        test = false;
        if(x < 10000) {
            for(int i = 5; i < 9; i++) {
                arr[i] = y % 10;
                if(arr[i] == 0) {
                    test = true;
                    break;
                }
                for(int j = 0; j < i; j++) {
                    test = (arr[i] == arr[j]);
                    if(test) {
                        break;
                    }
                }
                if(test) {
                    break;
                }
                y /= 10;
            }
            if(!(test)) {
                data.emplace(x);
            }
        }
        return 0;
    }
    for(arr[level] = 1; arr[level] < 10; arr[level]++) {
        bool test = false;
        for(int i = 0; i < level; i++) {
            if(arr[level] == arr[i]) {
                test = true;
                break;
            }
        }
        if(test) {
            continue;
        }
        loop(arr, level + 1, data);
    }
    return 0;
}
