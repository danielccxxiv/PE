
#ifndef TOTIENT_HPP
#define TOTIENT_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <cstring>

#include <boost/unordered_map.hpp>

#include "factorize.hpp"
#include "../pow_functions.hpp"

template<class T> struct totient_data {
    static boost::unordered_map<T, T> totient_map;
    static typename boost::unordered_map<T, T>::iterator totient_iter;
};

template<class T> boost::unordered_map<T, T> totient_data<T>::totient_map;
template<class T> typename boost::unordered_map<T, T>::iterator totient_data<T>::totient_iter;

template<class T, class P, bool CACHE, bool factor_CACHE = CACHE> T totient(T num, prime_factor_list<T>* x = nullptr) {
    totient_data<T>::totient_iter = totient_data<T>::totient_map.find(num);
    if(totient_data<T>::totient_iter != totient_data<T>::totient_map.end()) {
        return totient_data<T>::totient_iter->second;
    }
    if(x == nullptr) {
        x = factor<T, P, factor_CACHE>(num);
    } else if(num < 1) {
        throw "totient<T>: num less than 1";
    }
    T product = 1;
    for(size_t i = 0; i < x->len; i++) {
        product *= pow_int<T, int32_t>(x->primes[i], x->exp[i] - 1);
        product *= (x->primes[i] - 1);
    }
    if(CACHE) {
        totient_data<T>::totient_map.emplace(num, product);
    }
    return product;
}

#endif
