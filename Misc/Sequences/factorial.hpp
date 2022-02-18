
#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include <vector>

template<class T> struct factorial_data {
    static std::vector<T> factorial_vector;
};

template<class T> std::vector<T> factorial_data<T>::factorial_vector = {static_cast<T>(1)};

template<class T> T factorial(const unsigned int& n) {
    if(factorial_data<T>::factorial_vector.size() > n) {
        return factorial_data<T>::factorial_vector[n];
    }
    factorial_data<T>::factorial_vector.resize(n + 1);
    for(unsigned int i = factorial_data<T>::factorial_vector.size(); i < (n + 1); i++) {
        factorial_data<T>::factorial_vector[i] = static_cast<T>(i) * factorial_data<T>::factorial_vector[i - 1];
    }
    return factorial_data<T>::factorial_vector[n];
}

#endif
