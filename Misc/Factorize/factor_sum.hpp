
#ifndef FACTOR_SUM_HPP
#define FACTOR_SUM_HPP

#include <boost/unordered_map.hpp>

#include "factorize.hpp"
#include "../pow_int.hpp"

template<class T> struct factor_sum_data {
    static boost::unordered_map<T, T> factor_sum_map;
    static typename boost::unordered_map<T, T>::iterator factor_sum_iter;
};

template<class T> boost::unordered_map<T, T> factor_sum_data<T>::factor_sum_map = {{static_cast<T>(1), static_cast<T>(1)}};
template<class T> typename boost::unordered_map<T, T>::iterator factor_sum_data<T>::factor_sum_iter;

template<class T, bool CACHE = true> T factor_sum(const T& num, prime_factor_list<T>* x) {
    factor_sum_data<T>::factor_sum_iter = factor_sum_data<T>::factor_sum_map.find(num);
    if(factor_sum_data<T>::factor_sum_iter != factor_sum_data<T>::factor_sum_map.end()) {
        return factor_sum_data<T>::factor_sum_iter->second;
    }
    if(num < 1) {
        throw "factor_sum<T>: num less than 1";
    }
    T product = 1;
    for(size_t i = 0; i < x->len; i++) {
        product *= ((pow_int<T, int32_t>(x->primes[i], x->exp[i] + 1) - 1) / (x->primes[i] - 1));
    }
    if(CACHE) {
        factor_sum_data<T>::factor_sum_map.emplace(num, product);
    }
    return product;
}

#endif
