
#ifndef PRIME_SEQUENCE_HPP
#define PRIME_SEQUENCE_HPP

// link with -lprimesieve
#include <primesieve.hpp>

template<class T> struct prime {
    static primesieve::iterator iter;
    static std::vector<T> list;

    static void update(const unsigned int& pos) {
        while(pos >= list.size()) {
            list.push_back(iter.next_prime());
        }
        return;
    }
};

template<class T> primesieve::iterator prime<T>::iter;
template<class T> std::vector<T> prime<T>::list;

#endif
