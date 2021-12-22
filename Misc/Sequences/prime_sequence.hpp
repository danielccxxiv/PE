
#ifndef PRIME_SEQUENCE_HPP
#define PRIME_SEQUENCE_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include <vector>

// link with -lprimesieve
#include <primesieve.hpp>

template<class T> struct prime {
    static std::vector<T> list;

    static void update(size_t pos) {
        static primesieve::iterator iter;
        while(pos >= list.size()) {
            list.push_back(iter.next_prime());
        }
        return;
    }
};

template<class T> std::vector<T> prime<T>::list;

#endif
