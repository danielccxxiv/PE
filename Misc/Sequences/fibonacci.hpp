
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

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
