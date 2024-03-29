
#ifndef TOTIENT_HPP
#define TOTIENT_HPP

#include "factorize.hpp"
#include "../pow_int.hpp"

template<class T> struct totient_data {
    static boost::unordered_map<T, T> totient_map;
    static typename boost::unordered_map<T, T>::iterator totient_iter;
};

template<class T> boost::unordered_map<T, T> totient_data<T>::totient_map = {{static_cast<T>(1), static_cast<T>(1)}};
template<class T> typename boost::unordered_map<T, T>::iterator totient_data<T>::totient_iter;

template<class T, bool CACHE> T totient(const T& num, prime_factor_list<T>* x) {
    totient_data<T>::totient_iter = totient_data<T>::totient_map.find(num);
    if(totient_data<T>::totient_iter != totient_data<T>::totient_map.end()) {
        return totient_data<T>::totient_iter->second;
    }
    if(num < 1) {
        throw "totient<T>: num less than 1";
    }
    T product = 1;
    for(size_t i = 0; i < x->len; i++) {
        product *= pow_int<T>(x->primes[i], x->exp[i] - 1);
        product *= (x->primes[i] - 1);
    }
    if(CACHE) {
        totient_data<T>::totient_map.emplace(num, product);
    }
    return product;
}

#endif
