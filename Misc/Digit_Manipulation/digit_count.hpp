
#ifndef DIGIT_COUNT_HPP
#define DIGIT_COUNT_HPP

#include "../../Headers/std_integer_numeric_types.hpp"

// Well defined only for non-negative num and base > 1
// Overflow safety
template<class T, class B, class R = int32_t> R digit_count(T num, B base = 10) {
    if(num == 0) {
        return 0;
    }
    num /= base;
	R count = 1;
    T lim = 1;
    while(!(num < lim)) {
    	lim *= base;
    	count++;
    }
	return count;
}

#endif
