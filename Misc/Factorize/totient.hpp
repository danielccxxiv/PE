
#ifndef TOTIENT_HPP
#define TOTIENT_HPP

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
    for(size_t i = 0; i < x->len; i++) {
        product *= pow_int<T, int32_t>(x->primes[i], x->exp[i] - 1);
        product *= (x->primes[i] - 1);
    }
    if(CACHE) {
        totient_data<T>::totient_map.emplace(x->num, product);
    }
    return product;
}

#endif
