
#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <vector>

template<class T> struct combination_data {
    static std::vector<T*> combination_vector;
};

template<class T> std::vector<T*> combination_data<T>::combination_vector {new T {1}};

// Uses recursive definition of combination
// Returns 0 for invalid inputs
template<class T> T combination(size_t n, size_t k) {
    if(k > n) {
        return 0;
    }
    if((k + k) > n) {
        return combination<T>(n, n - k);
    }
    T val;
    if(combination_data<T>::combination_vector.size() > n) {
        val = combination_data<T>::combination_vector[n][k];
        if(val > 0) {
            return val;
        }
        if(k > 0) {
            val = combination<T>(n - 1, k - 1) + combination<T>(n - 1, k);
        } else {
            val = 1;
        }
        combination_data<T>::combination_vector[n][k] = val;
        return val;
    }
    if(k > 0) {
        val = combination<T>(n - 1, k - 1) + combination<T>(n - 1, k);
    } else {
        val = combination<T>(n - 1, 0);
    }
    size_t n_len = (n / 2) + 1;
    T* n_list = new T[n_len];
    for(size_t i = 0; i < n_len; i++) {
        n_list[i] = 0;
    }
    n_list[k] = val;
    combination_data<T>::combination_vector.push_back(n_list);
    return val;
}

#endif
