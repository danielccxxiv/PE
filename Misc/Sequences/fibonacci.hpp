
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <vector>

template<class T> struct fibonacci_data {
    static std::vector<T> fibonacci_vector;
};

template<class T> std::vector<T> fibonacci_data<T>::fibonacci_vector = {static_cast<T>(0), static_cast<T>(1)};

// Uses recursive definition
template<class T> T fibonacci(const int& n) {
    if(n < 0) {
        if((n & 1) != 0) {
            return fibonacci<T>(-n);
        } else {
            return -fibonacci<T>(-n);
        }
    }
    if(fibonacci_data<T>::fibonacci_vector.size() > n) {
        return fibonacci_data<T>::fibonacci_vector[n];
    }
    fibonacci_data<T>::fibonacci_vector.resize(n + 1);
    for(int i = fibonacci_data<T>::fibonacci_vector.size(); i < (n + 1); i++) {
        fibonacci_data<T>::fibonacci_vector[i] = fibonacci_data<T>::fibonacci_vector[i - 2] + fibonacci_data<T>::fibonacci_vector[i - 1];
    }
    return fibonacci_data<T>::fibonacci_vector[n];
}

#endif
