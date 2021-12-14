
#ifndef MULT_GROUP_SIZE_HPP
#define MULT_GROUP_SIZE_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <boost/unordered_map.hpp>

#include "factorize.hpp"
#include "totient.hpp"
#include "../gcd.hpp"
#include "../pow_functions.hpp"

template<class T> struct mult_group_size_data {
    static boost::unordered_map<T, boost::unordered_map<T, T>> mult_group_size_map;
    static typename boost::unordered_map<T, boost::unordered_map<T, T>>::iterator mult_group_size_iter0;
    static typename boost::unordered_map<T, T>::iterator mult_group_size_iter1;
};

template<class T> boost::unordered_map<T, boost::unordered_map<T, T>> mult_group_size_data<T>::mult_group_size_map;
template<class T> typename boost::unordered_map<T, boost::unordered_map<T, T>>::iterator mult_group_size_data<T>::mult_group_size_iter0;
template<class T> typename boost::unordered_map<T, T>::iterator mult_group_size_data<T>::mult_group_size_iter1;

template<class T> bool mult_group_size_loop(T num, T residue, prime_factor_list<T>* x, int32_t* arr, size_t level);

template<class T, bool CACHE> T mult_group_size(T num, T base, prime_factor_list<T>* x) {
    base = base % num;
    mult_group_size_data<T>::mult_group_size_iter0 = mult_group_size_data<T>::mult_group_size_map.find(num);
    if(mult_group_size_data<T>::mult_group_size_iter0 != mult_group_size_data<T>::mult_group_size_map.end()) {
        mult_group_size_data<T>::mult_group_size_iter1 = mult_group_size_data<T>::mult_group_size_iter0->second.find(base);
        if(mult_group_size_data<T>::mult_group_size_iter1 != mult_group_size_data<T>::mult_group_size_iter0->second.end()) {
            return mult_group_size_data<T>::mult_group_size_iter1->second;
        }
    } else if(CACHE) {
        mult_group_size_data<T>::mult_group_size_iter0 =
            mult_group_size_data<T>::mult_group_size_map.emplace(num, *(new boost::unordered_map<T, T>())).first;
    }
    int32_t* arr = new int32_t[x->len];
    for(size_t i = 0; i < x->len; i++) {
        arr[i] = 0;
    }
    if(!(mult_group_size_loop<T>(num, base, x, arr, 0))) {
        return 0;
    }
    T product = 1;
    for(size_t i = 0; i < x->len; i++) {
        product *= pow_int<T, int32_t>(x->primes[i], arr[i]);
    }
    if(CACHE) {
        mult_group_size_data<T>::mult_group_size_iter0->second.emplace(base, product);
    }
    delete[] arr;
    return product;
}

template<class T> bool mult_group_size_loop(T num, T residue, prime_factor_list<T>* x, int32_t* arr, size_t level) {
    if(level == x->len) {
        if(residue == 1) {
            return true;
        }
        return false;
    }
    for(arr[level] = 0; arr[level] <= x->exp[level]; arr[level]++) {
        if(mult_group_size_loop<T>(num, residue, x, arr, level + 1)) {
            return true;
        }
        residue = pow_int_mod<T, T>(residue, x->primes[level], num);
    }
    return false;
}

#endif
