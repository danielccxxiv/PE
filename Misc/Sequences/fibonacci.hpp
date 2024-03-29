
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <vector>

template<class T> struct fibonacci_data {
    static std::vector<T> fibonacci_vector;
};

template<class T> std::vector<T> fibonacci_data<T>::fibonacci_vector = {static_cast<T>(0), static_cast<T>(1)};

// Uses recursive definition
template<class T> T fibonacci(const int32_t& n) {
    if(n < 0) {
        if((n & 1) != 0) {
            return fibonacci<T>(-n);
        } else {
            return -fibonacci<T>(-n);
        }
    }
    if(fibonacci_data<T>::fibonacci_vector.size() > static_cast<size_t>(n)) {
        return fibonacci_data<T>::fibonacci_vector[n];
    }
    size_t current_size = fibonacci_data<T>::fibonacci_vector.size();
    fibonacci_data<T>::fibonacci_vector.resize(n + 1);
    for(int32_t i = current_size; i < (n + 1); i++) {
        fibonacci_data<T>::fibonacci_vector[i] = fibonacci_data<T>::fibonacci_vector[i - 2] + fibonacci_data<T>::fibonacci_vector[i - 1];
    }
    return fibonacci_data<T>::fibonacci_vector[n];
}

#endif
