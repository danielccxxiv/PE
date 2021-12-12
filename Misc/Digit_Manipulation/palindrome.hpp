
#ifndef PALINDROME_HPP
#define PALINDROME_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <list>

template<class T> bool is_palindrome(const T* arr, size_t len) {
    if(len == 0) {
        return true;
    }
	for(size_t i = 0; i < (len / 2); i++) {
        if(arr[i] != arr[len - i - 1]) {
            return false;
        }
    }
	return true;
}

// Well defined only for non-negative num and base > 1
template<class T, class B> bool is_palindrome_num(T num, B base = 10) {
    std::list<B> digits;
    while(num != 0) {
        digits.push_back(num % base);
        num /= base;
    }
    while(digits.size() > 1) {
        if(digits.front() != digits.back()) {
            return false;
        }
        digits.pop_front();
        digits.pop_back();
    }
    return true;
}

// Well defined only for non-negative num and base > 1
template<class T, class B> T reverse_digits(T num, B base = 10) {
    T reverse = 0;
    while(num != 0) {
        reverse *= base;
        reverse += (num % base);
        num /= base;
    }
    return reverse;
}

#endif
