
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>

#include <boost/container_hash/hash.hpp>
#include <boost/unordered_set.hpp>

#include "../../../Misc/Factorize/factorize.hpp"

typedef struct pfact {
    int* arr;
    int len;

    pfact(int n) {
        prime_factor_list<int>* x = factor<int, true>(n);
        this->len = x->primes[x->len - 1] + 1;
        this->arr = new int[this->len];
        for(int i = 0; i < this->len; i++) {
            arr[i] = 0;
        }
        for(int i = 0; i < x->len; i++) {
            this->arr[x->primes[i]] = x->exp[i];
        }
    }

    pfact(pfact* p, int mult) {
        this->len = p->len;
        this->arr = new int[this->len];
        for(int i = 0; i < this->len; i++) {
            this->arr[i] = p->arr[i] * mult;
        }
    }

    ~pfact() {
        if(arr != NULL) {
            delete[] arr;
        }
    }

    bool operator==(const pfact& cmp) const {
        if(this->len != cmp.len) {
            return false;
        }
        for(int i = 0; i < this->len; i++) {
            if(this->arr[i] != cmp.arr[i]) {
                return false;
            }
        }
        return true;
    }
} pfact;

typedef struct pfact_hash {
    std::size_t operator()(const pfact& p) const {
        std::size_t val = 0;
        for(int i = 0; i < p.len; i++) {
            boost::hash_combine(val, p.arr[i]);
        }
        return val;
    }
} pfact_hash;

#endif
