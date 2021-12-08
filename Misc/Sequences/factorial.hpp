
#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include <stdexcept>
#include <vector>

template<class T> struct factorial_data {
    static std::vector<T> factorial_vector;
};

template<class T> std::vector<T> factorial_data<T>::factorial_vector {1};

// Throws exception for negative inputs
template<class T> T factorial(int n) {
    if(n < 0) {
        throw std::invalid_argument("factorial: negative input value");
    }
    if(factorial_data<T>::factorial_vector.size() > n) {
        return factorial_data<T>::factorial_vector[n];
    }
    T val = n * factorial<T>(n - 1);
    factorial_data<T>::factorial_vector.push_back(val);
    return val;
}

#endif
