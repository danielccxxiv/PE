
#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <cstring>
#include <memory>
#include <stack>
#include <vector>

#include <boost/unordered_set.hpp>

#include "../binary_search.hpp"
#include "../floor_sqrt.hpp"
#include "../Sequences/prime_sequence.hpp"

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

template<class T> struct prime_factor_list_set_node {
    T num;
    std::unique_ptr<prime_factor_list<T>> pf_list_ptr;

    prime_factor_list_set_node(const T num) {
        this->num = num;
        this->pf_list_ptr = nullptr;
    }

    prime_factor_list_set_node(const T num, std::unique_ptr<prime_factor_list<T>>* pf_list_ptr_ref) {
        this->num = num;
        this->pf_list_ptr = std::move(*pf_list_ptr_ref);
    }
};

template<class T> struct prime_factor_list_set_node_hash {
    size_t operator()(const prime_factor_list_set_node<T>& node) const {
        size_t hash_val = 0;
        boost::hash_combine(hash_val, node.num);
        return hash_val;
    }
};

template<class T> struct prime_factor_list_set_node_equals {
    bool operator()(const prime_factor_list_set_node<T>& node0, const prime_factor_list_set_node<T>& node1) const {
        return (node0.num == node1.num);
    }
};

template<class T> struct prime_factor_data {
    static boost::unordered_set<prime_factor_list_set_node<T>, prime_factor_list_set_node_hash<T>, prime_factor_list_set_node_equals<T>> factor_set;
    static typename boost::unordered_set<prime_factor_list_set_node<T>, prime_factor_list_set_node_hash<T>, prime_factor_list_set_node_equals<T>>::iterator factor_iter;
};

template<class T> boost::unordered_set<prime_factor_list_set_node<T>, prime_factor_list_set_node_hash<T>, prime_factor_list_set_node_equals<T>> prime_factor_data<T>::factor_set = {prime_factor_list_set_node<T>(1, &(std::make_unique()))};
template<class T> typename boost::unordered_set<prime_factor_list_set_node<T>, prime_factor_list_set_node_hash<T>, prime_factor_list_set_node_equals<T>>::iterator prime_factor_data<T>::factor_iter;

template<class T, class P, bool CACHE> prime_factor_list<T>* factor(const T num);
template<class T, class P, bool CACHE> prime_factor_list<T>* factor_loop(const T num, size_t prime_list_pos);

// Well defined only for num > 1
template<class T, class P, bool CACHE> prime_factor_list<T>* factor(const T num) {
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_set.find(prime_factor_list_set_node<T>(num));
    if(prime_factor_data<T>::factor_iter != prime_factor_data<T>::factor_set.end()) {
        return (*prime_factor_data<T>::factor_iter).pf_list_ptr.get();
    }
    if(num < 1) {
        throw "factor<T>: input less than 1";
    }
    return factor_loop<T, P, CACHE>(num, 0);
}

template<class T, class P, bool CACHE> prime_factor_list<T>* factor_loop(const T num, size_t prime_list_pos) {
    prime_factor_list<T>* result;
    if(CACHE) {
        std::unique_ptr<prime_factor_list<T>> factor_unique_ptr = std::make_unique<prime_factor_list<T>>();
        result = factor_unique_ptr.get();
        prime_factor_data<T>::factor_set.emplace(prime_factor_list_set_node<T>(num, &factor_unique_ptr));
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
    T val_sqrt = floor_sqrt(num) + 1;
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
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_set.find(prime_factor_list_set_node<T>(num_div));
    if(prime_factor_data<T>::factor_iter == prime_factor_data<T>::factor_set.end()) {
        num_div_list = factor_loop<T, P, CACHE>(num_div, prime_list_pos + 1);
    } else {
        num_div_list = (*prime_factor_data<T>::factor_iter).pf_list_ptr.get();
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
