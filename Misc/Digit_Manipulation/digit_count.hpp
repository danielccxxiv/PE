
#ifndef DIGIT_COUNT_HPP
#define DIGIT_COUNT_HPP

#include <stdexcept>

template<class T> int digit_count(T val, bool safety = false) {
	int count = 0;
    if(val < 0) {
		val = -val;
	}
    if(safety) {
        while(val != 0) {
            val /= 10;
            count++;
        }
    } else {
        T lim = 1;
    	while(!(val < lim)) {
    		lim *= 10;
    		count++;
    	}
    }
	return count;
}

// Throws exception for invalid values of base (less than 2)
template<class T0, class T1> int digit_count_base(T0 val, T1 base, bool safety = false) {
    if(base < 2) {
        throw std::invalid_argument("digit_count_base: Invalid input for base (less than 2)");
    }
	int count = 0;
    if(val < 0) {
		val = -val;
	}
    if(safety) {
        while(val != 0) {
            val /= 10;
            count++;
        }
    } else {
        T0 lim = 1;
    	while(!(val < lim)) {
    		lim *= base;
    		count++;
    	}
    }
	return count;
}

#endif
