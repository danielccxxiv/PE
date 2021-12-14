
#ifndef UNORDERED_DIGIT_HASH_HPP
#define UNORDERED_DIGIT_HASH_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

#include "../Sequences/prime_sequence.hpp"

template<class T, class B, class R = T, class P = B> R unordered_digit_hash(T num, B base = 10) {
    R result = 1;
    while(static_cast<B>(prime<P>::list.size()) < base) {
        prime<P>::list.push_back(prime<P>::iter.next_prime());
    }
    B digit;
    while(num != 0) {
        digit = num % base;
        result *= prime<P>::list[digit];
        num /= base;
    }
    return result;
}

#endif
