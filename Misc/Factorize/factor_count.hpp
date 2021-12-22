
#ifndef FACTOR_COUNT_HPP
#define FACTOR_COUNT_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <cstring>

#include <boost/unordered_map.hpp>

#include "factorize.hpp"

template<class T> struct factor_count_data {
    static boost::unordered_map<T, T> factor_count_map;
    static typename boost::unordered_map<T, T>::iterator factor_count_iter;
};

template<class T> boost::unordered_map<T, T> factor_count_data<T>::factor_count_map;
template<class T> typename boost::unordered_map<T, T>::iterator factor_count_data<T>::factor_count_iter;

template<class T, class P, bool CACHE, bool factor_CACHE = CACHE> T factor_count(T num, prime_factor_list<T>* x = nullptr) {
    factor_count_data<T>::factor_count_iter = factor_count_data<T>::factor_count_map.find(num);
    if(factor_count_data<T>::factor_count_iter != factor_count_data<T>::factor_count_map.end()) {
        return factor_count_data<T>::factor_count_iter->second;
    }
    if(x == nullptr) {
        x = factor<T, P, factor_CACHE>(num);
    } else if(num < 1) {
        throw "factor_count<T>: num less than 1";
    }
	T product = 1;
	for(size_t i = 0; i < x->len; i++) {
		product *= (x->exp[i] + 1);
	}
    if(CACHE) {
        factor_count_data<T>::factor_count_map.emplace(num, product);
    }
	return product;
}

#endif
