
#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <vector>

template<class T> struct factorial_data {
    static std::vector<T> factorial_vector;
};

template<class T> std::vector<T> factorial_data<T>::factorial_vector {1};

template<class T> T factorial(size_t n) {
    if(factorial_data<T>::factorial_vector.size() > n) {
        return factorial_data<T>::factorial_vector[n];
    }
    T num = n * factorial<T>(n - 1);
    factorial_data<T>::factorial_vector.push_back(num);
    return num;
}

#endif
