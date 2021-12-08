
#ifndef PALINDROME_HPP
#define PALINDROME_HPP

#include <stdexcept>
#include <vector>

template<class T> bool is_palindrome(const T* arr, const int len) {
    if(len < 1) {
        throw std::invalid_argument("is_palindrome: len less than 1");
    }
	for(int i = 0; i < (len / 2); i++) {
        if(arr[i] != arr[len - i - 1]) {
            return false;
        }
    }
	return true;
}

template<class T> bool is_palindrome_num(T num) {
    if(num < 0) {
        num = -num;
    }
    if(num == 0) {
        return true;
    }
    std::vector<int> digits;
    while(num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    int len = digits.size();
    int lim = digits.size() / 2;
    for(int i = 0; i < lim; i++) {
        if(digits[i] != digits[len - i - 1]) {
            return false;
        }
    }
    return true;
}

template<class T0, class T1> bool is_palindrome_num(T0 num, T1 base) {
    if(base < 2) {
        throw std::invalid_argument("is_palindrome_num: base less than 2");
    }
    if(num < 0) {
        num = -num;
    }
    if(num == 0) {
        return true;
    }
    std::vector<T1> digits;
    while(num != 0) {
        digits.push_back(num % base);
        num /= base;
    }
    int len = digits.size();
    int lim = digits.size() / 2;
    for(int i = 0; i < lim; i++) {
        if(digits[i] != digits[len - i - 1]) {
            return false;
        }
    }
    return true;
}

template<class T> T reverse_digits(T num) {
    if(num < 0) {
        num = -num;
    }
    T reverse = 0;
    while(num != 0) {
        reverse *= 10;
        reverse += (num % 10);
        num /= 10;
    }
    return reverse;
}

template<class T0, class T1> T0 reverse_digits(T0 num, T1 base) {
    if(base < 2) {
        throw std::invalid_argument("reverse_digits: base less than 2");
    }
    if(num < 0) {
        num = -num;
    }
    T0 reverse = 0;
    while(num != 0) {
        reverse *= base;
        reverse += (num % base);
        num /= base;
    }
    return reverse;
}

#endif
