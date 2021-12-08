
#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

template<class T> int perm_iter_inc(T* arr, int len) {
	int pos = len - 2;
    T temp;
    while((pos > -1) && (arr[pos] >= arr[pos + 1])) {
        pos--;
    }
    if(pos == -1) {
        for(int i = 0; i < (len / 2); i++) {
            temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }
        return 0;
    }
    int pivot = len - 1;
    while(arr[pivot] <= arr[pos]) {
        pivot--;
    }
    temp = arr[pos];
    arr[pos] = arr[pivot];
    arr[pivot] = temp;
    for(int i = pos + 1; i < ((pos + len + 1) / 2); i++) {
        temp = arr[i];
        arr[i] = arr[len + pos - i];
        arr[len + pos - i] = temp;
    }
    return 0;
}

template<class T> int perm_iter_dec(T* arr, int len) {
	int pos = len - 2;
    T temp;
    while((pos > -1) && (arr[pos] <= arr[pos + 1])) {
        pos--;
    }
    if(pos == -1) {
        for(int i = 0; i < (len / 2); i++) {
            temp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = temp;
        }
        return 0;
    }
    int pivot = len - 1;
    while(arr[pivot] >= arr[pos]) {
        pivot--;
    }
    temp = arr[pos];
    arr[pos] = arr[pivot];
    arr[pivot] = temp;
    for(int i = pos + 1; i < ((pos + len + 1) / 2); i++) {
        temp = arr[i];
        arr[i] = arr[len + pos - i];
        arr[len + pos - i] = temp;
    }
    return 0;
}

#endif
