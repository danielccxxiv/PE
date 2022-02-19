
#ifndef UNORDERED_DIGIT_HASH_HPP
#define UNORDERED_DIGIT_HASH_HPP

#include "../Sequences/prime_sequence.hpp"

template<class T, class B, class R = T, class P = B> R unordered_digit_hash(T num, B base = 10) {
    prime<P>::update(base);
    R result = 1;
    B digit;
    while(num != 0) {
        digit = num % base;
        num /= base;
        result *= prime<P>::list[digit];
    }
    return result;
}

#endif
