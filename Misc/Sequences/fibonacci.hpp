
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <vector>

template<class T> struct fibonacci_data {
    static std::vector<T> fibonacci_vector;
};

template<class T> std::vector<T> fibonacci_data<T>::fibonacci_vector {0, 1};

// Uses recursive definition
template<class T> T fibonacci(size_t n) {
    if(fibonacci_data<T>::fibonacci_vector.size() > n) {
        return fibonacci_data<T>::fibonacci_vector[n];
    }
    T num = fibonacci<T>(n - 2) + fibonacci<T>(n - 1);
    fibonacci_data<T>::fibonacci_vector.push_back(num);
    return num;
}

#endif
