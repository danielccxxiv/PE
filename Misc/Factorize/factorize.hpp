
#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

#include <cstdint>
#include <memory>
#include <stack>
#include <vector>

#include <boost/unordered_map.hpp>

#include "../binary_search.hpp"
#include "../int_sqrt.hpp"
#include "../pow_int.hpp"
#include "../Sequences/prime_sequence.hpp"

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

template<class T> struct prime_factor_list {
	T* primes;
	int32_t* exp;
	size_t len;

    prime_factor_list() {
        this->primes = nullptr;
        this->exp = nullptr;
        this->len = 0;
    }

    virtual ~prime_factor_list() {
        if(this->primes != nullptr) {
            delete[] primes;
        }
        if(this->exp != nullptr) {
            delete[] exp;
        }
    }
};

template<class T> struct prime_factor_data {
    static boost::unordered_map<T, prime_factor_list<T>> factor_map;
    static typename boost::unordered_map<T, prime_factor_list<T>>::iterator factor_iter;
};

template<class T> boost::unordered_map<T, prime_factor_list<T>> prime_factor_data<T>::factor_map = {{static_cast<T>(1), prime_factor_list<T>()}};
template<class T> typename boost::unordered_map<T, prime_factor_list<T>>::iterator prime_factor_data<T>::factor_iter;

template<class T, class P, bool CACHE> prime_factor_list<T>* factor(const T& num);
template<class T, class P, bool CACHE> prime_factor_list<T>* factor_loop(const T& num, size_t prime_list_pos);

// Well defined only for num > 1
template<class T, class P, bool CACHE = true> prime_factor_list<T>* factor(const T& num) {
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_map.find(num);
    if(prime_factor_data<T>::factor_iter != prime_factor_data<T>::factor_map.end()) {
        return &(prime_factor_data<T>::factor_iter->second);
    }
    if(num < 1) {
        throw "factor<T>: input less than 1";
    }
    return factor_loop<T, P, CACHE>(num, 0);
}

template<class T, class P, bool CACHE> prime_factor_list<T>* factor_loop(const T& num, size_t prime_list_pos) {
    prime_factor_list<T>* result;
    if(CACHE) {
        result = &(((prime_factor_data<T>::factor_map.emplace(boost::unordered::piecewise_construct, boost::make_tuple(num), boost::make_tuple())).first)->second);
    } else {
        result = new prime_factor_list<T>();
    }
    prime<P>::update(prime_list_pos);
    if((num <= prime<P>::list[prime<P>::list.size() - 1]) && (binary_search<P>(prime<P>::list, num, 0, prime<P>::list.size()) >= 0)) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = num;
        result->exp[0] = 1;
        return result;
    }
    T val_sqrt = int_sqrt<T>(num) + 1;
    bool sm_fact_found = false;
    while(prime<P>::list[prime_list_pos] < val_sqrt) {
        if((num % prime<P>::list[prime_list_pos]) == 0) {
            sm_fact_found = true;
            break;
        }
        prime_list_pos++;
        prime<P>::update(prime_list_pos);
    }
    if(!(sm_fact_found)) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = num;
        result->exp[0] = 1;
        return result;
    }
    T num_div = num / prime<P>::list[prime_list_pos];
    int32_t sm_exp = 1;
    while((num_div % prime<P>::list[prime_list_pos]) == 0) {
        num_div /= prime<P>::list[prime_list_pos];
        sm_exp++;
    }
    if(num_div == 1) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = prime<P>::list[prime_list_pos];
        result->exp[0] = sm_exp;
        return result;
    }
    prime_factor_list<T>* num_div_list;
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_map.find(num_div);
    if(prime_factor_data<T>::factor_iter == prime_factor_data<T>::factor_map.end()) {
        num_div_list = factor_loop<T, P, CACHE>(num_div, prime_list_pos + 1);
    } else {
        num_div_list = &(prime_factor_data<T>::factor_iter->second);
    }
    result->len = num_div_list->len + 1;
    result->primes = new T[result->len];
    result->exp = new int32_t[result->len];
    result->primes[0] = prime<P>::list[prime_list_pos];
    result->exp[0] = sm_exp;
    for(size_t i = 1; i < (result->len); i++) {
        result->primes[i] = num_div_list->primes[i - 1];
        result->exp[i] = num_div_list->exp[i - 1];
    }
    return result;
}

#endif
