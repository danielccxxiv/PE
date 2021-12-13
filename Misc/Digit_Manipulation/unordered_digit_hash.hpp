
#ifndef UNORDERED_DIGIT_HASH_HPP
#define UNORDERED_DIGIT_HASH_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include "../Sequences/prime_sequence.hpp"

template<class T, class B, class R = T, class P = B> R unordered_digit_hash(T num, B base = 10) {
    R result = 1;
    B digit;
    while(num != 0) {
        digit = num % base;
        while(static_cast<B>(prime<P>::list.size()) <= digit) {
            prime<P>::list.push_back(prime<P>::iter.next_prime());
        }
        result *= prime<P>::list[digit];
        num /= base;
    }
    return result;
}

#endif
