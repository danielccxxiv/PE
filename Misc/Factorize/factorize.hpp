
#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <stack>
#include <vector>

#include <boost/unordered_map.hpp>

#include "../binary_search.hpp"
#include "../floor_sqrt.hpp"
#include "../Sequences/prime_sequence.hpp"

template<class T> struct prime_factor_list {
	T num;
	T* primes;
	int32_t* exp;
	size_t len;

    virtual ~prime_factor_list() {
        if(this->primes != NULL) {
            delete[] primes;
        }
        if(this->exp != NULL) {
            delete[] exp;
        }
    }
};

template<class T> struct prime_factor_data {
    static boost::unordered_map<T, prime_factor_list<T>> factor_map;
    static typename boost::unordered_map<T, prime_factor_list<T>>::iterator factor_iter;
};

template<class T> boost::unordered_map<T, prime_factor_list<T>> prime_factor_data<T>::factor_map;
template<class T> typename boost::unordered_map<T, prime_factor_list<T>>::iterator prime_factor_data<T>::factor_iter;

template<class T, class P, bool CACHE> prime_factor_list<T>* factor(T num);
template<class T, class P> prime_factor_list<T>* factor_loop_cache(T num, size_t prime_list_pos);
template<class T, class P> prime_factor_list<T>* factor_loop_no_cache(T num);
template<class T, class P, bool CACHE> prime_factor_list<T>* mult_factor(T num1, T num2);

// Well defined only for num > 1
template<class T, class P, bool CACHE> prime_factor_list<T>* factor(T num) {
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_map.find(num);
    if(prime_factor_data<T>::factor_iter != prime_factor_data<T>::factor_map.end()) {
        return &(prime_factor_data<T>::factor_iter->second);
    }
    if(CACHE) {
        return factor_loop_cache<T, P>(num, 0);
    } else {
        return factor_loop_no_cache<T, P>(num);
    }
}

template<class T, class P> prime_factor_list<T>* factor_loop_cache(T num, size_t prime_list_pos) {
    prime_factor_list<T>* result = new prime_factor_list<T>;
    result->num = num;
    while(prime_list_pos >= prime<P>::list.size()) {
        prime<P>::list.push_back(prime<P>::iter.next_prime());
    }
    if((num <= prime<P>::list[prime<P>::list.size()]) && (binary_search<P>(prime<P>::list, num, 0, prime<P>::list.size()) >= 0)) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = num;
        result->exp[0] = 1;
        prime_factor_data<T>::factor_map.emplace(result->num, *result);
        return result;
    }
    T val_sqrt = floor_sqrt(num) + 1;
    bool sm_fact_found = false;
    while(prime<P>::list[prime_list_pos] < val_sqrt) {
        if(num % prime<P>::list[prime_list_pos] == 0) {
            num /= prime<P>::list[prime_list_pos];
            sm_fact_found = true;
            break;
        }
        prime_list_pos++;
        while(prime_list_pos >= prime<P>::list.size()) {
            prime<P>::list.push_back(prime<P>::iter.next_prime());
        }
    }
    if(!(sm_fact_found)) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = num;
        result->exp[0] = 1;
        prime_factor_data<T>::factor_map.emplace(result->num, *result);
        return result;
    }
    int32_t sm_exp = 1;
    while(num % prime<P>::list[prime_list_pos] == 0) {
        num /= prime<P>::list[prime_list_pos];
        sm_exp++;
    }
    if(num == 1) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = prime<P>::list[prime_list_pos];
        result->exp[0] = sm_exp;
        prime_factor_data<T>::factor_map.emplace(result->num, *result);
        return result;
    }
    prime_factor_list<T>* num_div_list;
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_map.find(num);
    if(prime_factor_data<T>::factor_iter == prime_factor_data<T>::factor_map.end()) {
        num_div_list = factor_loop_cache<T, P>(num, prime_list_pos + 1);
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
    prime_factor_data<T>::factor_map.emplace(result->num, *result);
    return result;
}

template<class T, class P> prime_factor_list<T>* factor_loop_no_cache(T num) {
    prime_factor_list<T>* result = new prime_factor_list<T>;
    result->num = num;
    size_t prime_list_pos = 0;
    while(prime_list_pos >= prime<P>::list.size()) {
        prime<P>::list.push_back(prime<P>::iter.next_prime());
    }
    if((num <= prime<P>::list[prime<P>::list.size()]) && (binary_search<P>(prime<P>::list, num, 0, prime<P>::list.size()) >= 0)) {
        result->len = 1;
        result->primes = new T[1];
        result->exp = new int32_t[1];
        result->primes[0] = num;
        result->exp[0] = 1;
        return result;
    }
    std::stack<T> prime_stack;
    std::stack<int32_t> exp_stack;
    T val_sqrt = floor_sqrt(num) + 1;
    int32_t temp_exp;
    while(prime<P>::list[prime_list_pos] < val_sqrt) {
        if(num % prime<P>::list[prime_list_pos] == 0) {
            num /= prime<P>::list[prime_list_pos];
            temp_exp = 1;
            while(num % prime<P>::list[prime_list_pos] == 0) {
                num /= prime<P>::list[prime_list_pos];
                temp_exp++;
            }
            prime_stack.push(prime<P>::list[prime_list_pos]);
            exp_stack.push(temp_exp);
            val_sqrt = floor_sqrt(num) + 1;
        }
        prime_list_pos++;
        while(prime_list_pos >= prime<P>::list.size()) {
            prime<P>::list.push_back(prime<P>::iter.next_prime());
        }
    }
    if(num != 1) {
        prime_stack.push(num);
        exp_stack.push(1);
    }
    result->len = prime_stack.size();
    result->primes = new T[result->len];
    result->exp = new int32_t[result->len];
    for(size_t i = 0; i < (result->len); i++) {
        result->primes[result->len - i - 1] = prime_stack.top();
        result->exp[result->len - i - 1] = exp_stack.top();
        prime_stack.pop();
        exp_stack.pop();
    }
    return result;
}

template<class T, class P, bool CACHE> prime_factor_list<T>* mult_factor(T num1, T num2) {
    prime_factor_data<T>::factor_iter = prime_factor_data<T>::factor_map.find(num1 * num2);
    if(prime_factor_data<T>::factor_iter != prime_factor_data<T>::factor_map.end()) {
        return prime_factor_data<T>::factor_iter->second;
    }
    if((num1 == 1) || (num2 == 1)) {
        return factor<T, P, CACHE>(num1 * num2);
    }
    prime_factor_list<T>* f1 = factor<T, P, CACHE>(num1);
    prime_factor_list<T>* f2 = factor<T, P, CACHE>(num2);
    prime_factor_list<T>* result = new prime_factor_list<T>();
    result->num = num1 * num2;
    size_t s1 = f1->len;
    size_t s2 = f2->len;
    T* p1 = f1->primes;
    T* p2 = f2->primes;
    int32_t* e1 = f1->exp;
    int32_t* e2 = f2->exp;
    result->len = s1 + s2;
    size_t i1 = 0;
    size_t i2 = 0;
    for(size_t i = 0; i < (s1 + s2); i++) {
        if(i1 == s1) {
            i2++;
        } else if(i2 == s2) {
            i1++;
        } else {
            if(f1->primes[i1] > f2->primes[i2]) {
                i2++;
            } else if(f1->primes[i1] < f2->primes[i2]) {
                i1++;
            } else {
                i1++;
                result->len--;
            }
        }
    }
    result->primes = new T[result->len];
    result->exp = new int32_t[result->len];
    i1 = 0;
    i2 = 0;
    for(size_t i = 0; i < (result->len); i++) {
        if(i1 == s1) {
            result->primes[i] = p2[i2];
            result->exp[i] = e2[i2];
            i2++;
        } else if(i2 == s2) {
            result->primes[i] = p1[i1];
            result->exp[i] = e1[i1];
            i1++;
        } else {
            if(p1[i1] > p2[i2]) {
                result->primes[i] = p2[i2];
                result->exp[i] = e2[i2];
                i2++;
            } else if(p1[i1] < p2[i2]) {
                result->primes[i] = p1[i1];
                result->exp[i] = e1[i1];
                i1++;
            } else {
                result->primes[i] = p1[i1];
                result->exp[i] = e1[i1] + e2[i2];
                i1++;
                i2++;
            }
        }
    }
    if(CACHE) {
        prime_factor_data<T>::factor_map.emplace(result->num, *result);
    }
    return result;
}

#endif
