
#ifndef PRIME_SEQUENCE_HPP
#define PRIME_SEQUENCE_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

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
