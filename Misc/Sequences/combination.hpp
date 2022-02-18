
#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <tuple>
#include <vector>

template<class T> struct combination_data {
    static std::vector<std::vector<T>> combination_vector;
};

template<class T> std::vector<std::vector<T>> combination_data<T>::combination_vector = {{static_cast<T>(1)}};

// Uses recursive definition of combination
// Returns 0 for invalid inputs
template<class T> T combination(const unsigned int& n, const unsigned int& k) {
    if(k > n) {
        return 0;
    }
    if((k + k) > n) {
        return combination<T>(n, n - k);
    }
    T val;
    if(combination_data<T>::combination_vector.size() > n) {
        val = combination_data<T>::combination_vector[n][k];
        if(val != 0) {
            return val;
        }
        val = combination<T>(n - 1, k - 1) + combination<T>(n - 1, k);
        combination_data<T>::combination_vector[n][k] = val;
        return val;
    } else {
        if(k != 0) {
            val = combination<T>(n - 1, k - 1) + combination<T>(n - 1, k);
        } else {
            val = combination<T>(n - 1, 0);
        }
        combination_data<T>::combination_vector.emplace_back(std::make_tuple((n / 2) + 1, static_cast<T>(0)));
        combination_data<T>::combination_vector[0] = static_cast<T>(1);
        combination_data<T>::combination_vector[1] = static_cast<T>(n);
        combination_data<T>::combination_vector[k] = val;
        return val;
    }
}

#endif
