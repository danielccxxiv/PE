
#ifndef FACTOR_SUM_HPP
#define FACTOR_SUM_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <boost/unordered_map.hpp>

#include "factorize.hpp"
#include "../pow_functions.hpp"

template<class T> struct factor_sum_data {
    static boost::unordered_map<T, T> factor_sum_map;
    static typename boost::unordered_map<T, T>::iterator factor_sum_iter;
};

template<class T> boost::unordered_map<T, T> factor_sum_data<T>::factor_sum_map;
template<class T> typename boost::unordered_map<T, T>::iterator factor_sum_data<T>::factor_sum_iter;

template<class T, bool CACHE> T factor_sum(prime_factor_list<T>* x) {
    factor_sum_data<T>::factor_sum_iter = factor_sum_data<T>::factor_sum_map.find(x->num);
    if(factor_sum_data<T>::factor_sum_iter != factor_sum_data<T>::factor_sum_map.end()) {
        return factor_sum_data<T>::factor_sum_iter->second;
    }
    T product = 1;
    for(size_t i = 0; i < x->len; i++) {
        product *= ((pow_int<T, int32_t>(x->primes[i], x->exp[i] + 1) - 1) / (x->primes[i] - 1));
    }
    if(CACHE) {
        factor_sum_data<T>::factor_sum_map.emplace(x->num, product);
    }
    return product;
}

#endif
