
#ifndef FACTOR_COUNT_HPP
#define FACTOR_COUNT_HPP

#include "factorize.hpp"

template<class T> struct factor_count_data {
    static boost::unordered_map<T, T> factor_count_map;
    static typename boost::unordered_map<T, T>::iterator factor_count_iter;
};

template<class T> boost::unordered_map<T, T> factor_count_data<T>::factor_count_map = {{static_cast<T>(1), static_cast<T>(1)}};
template<class T> typename boost::unordered_map<T, T>::iterator factor_count_data<T>::factor_count_iter;

template<class T, bool CACHE = true> T factor_count(const T& num, prime_factor_list<T>* x) {
    factor_count_data<T>::factor_count_iter = factor_count_data<T>::factor_count_map.find(num);
    if(factor_count_data<T>::factor_count_iter != factor_count_data<T>::factor_count_map.end()) {
        return factor_count_data<T>::factor_count_iter->second;
    }
    if(num < static_cast<T>(1)) {
        throw "factor_count<T>: num less than 1";
    }
	T product = static_cast<T>(1);
	for(unsigned int i = 0; i < x->len; i++) {
		product *= static_cast<T>(x->exp[i] + 1);
	}
    if(CACHE) {
        factor_count_data<T>::factor_count_map.emplace(num, product);
    }
	return product;
}

#endif
