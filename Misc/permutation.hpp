
#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

#include <cstddef>

typedef std::size_t size_t;

template<class T> void perm_iter_inc(T* arr, size_t len) {
	size_t pos = len - 1;
    while((pos > 0) && (arr[pos - 1] >= arr[pos])) {
        pos--;
    }
    T temp;
    if(pos == 0) {
        for(size_t i = 0; i < (len / 2); i++) {
            temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }
        return;
    }
    pos--;
    size_t pivot = len - 1;
    while(arr[pivot] <= arr[pos]) {
        pivot--;
    }
    temp = arr[pos];
    arr[pos] = arr[pivot];
    arr[pivot] = temp;
    for(size_t i = pos + 1; i < ((pos + len + 1) / 2); i++) {
        temp = arr[i];
        arr[i] = arr[len + pos - i];
        arr[len + pos - i] = temp;
    }
    return;
}

template<class T> void perm_iter_dec(T* arr, size_t len) {
	size_t pos = len - 1;
    while((pos > 0) && (arr[pos - 1] <= arr[pos])) {
        pos--;
    }
    T temp;
    if(pos == 0) {
        for(size_t i = 0; i < (len / 2); i++) {
            temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }
        return;
    }
    pos--;
    size_t pivot = len - 1;
    while(arr[pivot] >= arr[pos]) {
        pivot--;
    }
    temp = arr[pos];
    arr[pos] = arr[pivot];
    arr[pivot] = temp;
    for(size_t i = pos + 1; i < ((pos + len + 1) / 2); i++) {
        temp = arr[i];
        arr[i] = arr[len + pos - i];
        arr[len + pos - i] = temp;
    }
    return;
}

#endif
