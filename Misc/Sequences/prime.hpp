
#ifndef PRIME_SEQUENCE_HPP
#define PRIME_SEQUENCE_HPP

#include <vector>

// link with -lprimesieve
#include <primesieve.hpp>

template<class T> struct prime {
    static std::vector<T> list;
    static primesieve::iterator iter;
};

template<class T> std::vector<T> prime<T>::list;
template<class T> primesieve::iterator prime<T>::iter;

#endif
