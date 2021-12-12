
#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <stdexcept>

// Well defined only for non-negtive num and base > 1
template<class T, class B> int32_t digit_sum(T num, B base = 10) {
    int32_t sum = 0;
	while(num > 0) {
        sum += (num % base);
		num /= base;
	}
	return sum;
}

#endif
