
#ifndef DIGIT_COUNT_HPP
#define DIGIT_COUNT_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

// Well defined only for non-negative num and base > 1
// No overflow safety
template<class T, class B> int32_t digit_count(T num, B base = 10) {
	int32_t count = 0;
    T lim = 1;
    while(!(num < lim)) {
    	lim *= base;
    	count++;
    }
	return count;
}

// Well defined only for non-negative num and base > 1
// Overflow safety
template<class T, class B> int32_t digit_count_safe(T num, B base = 10) {
    int32_t count = 0;
    while(num != 0) {
        num /= base;
        count++;
    }
    return count;
}

#endif
