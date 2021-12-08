
#ifndef TOTIENT_HPP
#define TOTIENT_HPP

#include <boost/unordered_map.hpp>

#include "factorize.hpp"
#include "../pow_functions.hpp"

template<class T> struct totient_data {
    static boost::unordered_map<T, T> totient_map;
    static typename boost::unordered_map<T, T>::iterator totient_iter;
};

template<class T> boost::unordered_map<T, T> totient_data<T>::totient_map;
template<class T> typename boost::unordered_map<T, T>::iterator totient_data<T>::totient_iter;

template<class T, bool CACHE> T totient(prime_factor_list<T>* x) {
    totient_data<T>::totient_iter = totient_data<T>::totient_map.find(x->num);
    if(totient_data<T>::totient_iter != totient_data<T>::totient_map.end()) {
        return totient_data<T>::totient_iter->second;
    }
    T product = 1;
    for(int i = 0; i < x->len; i++) {
        product *= pow(x->primes[i], x->exp[i] - 1);
        product *= (x->primes[i] - 1);
    }
    if(CACHE) {
        totient_data<T>::totient_map.emplace(x->num, product);
    }
    return product;
}

#endif
