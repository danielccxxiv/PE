
#ifndef FACTOR_COUNT_HPP
#define FACTOR_COUNT_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <boost/unordered_map.hpp>

#include "factorize.hpp"

template<class T> struct factor_count_data {
    static boost::unordered_map<T, T> factor_count_map;
    static typename boost::unordered_map<T, T>::iterator factor_count_iter;
};

template<class T> boost::unordered_map<T, T> factor_count_data<T>::factor_count_map;
template<class T> typename boost::unordered_map<T, T>::iterator factor_count_data<T>::factor_count_iter;

template<class T, bool CACHE> T factor_count(prime_factor_list<T>* x) {
    factor_count_data<T>::factor_count_iter = factor_count_data<T>::factor_count_map.find(x->num);
    if(factor_count_data<T>::factor_count_iter != factor_count_data<T>::factor_count_map.end()) {
        return factor_count_data<T>::factor_count_iter->second;
    }
	T product = 1;
	for(size_t i = 0; i < x->len; i++) {
		product *= (x->exp[i] + 1);
	}
    if(CACHE) {
        factor_count_data<T>::factor_count_map.emplace(x->num, product);
    }
	return product;
}

#endif
