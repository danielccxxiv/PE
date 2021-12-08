
#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

#include <stdexcept>

// Returns positive digit sum for negative values
template<class T> int digit_sum(T val) {
	int sum = 0;
	if(val < 0) {
		val = -val;
	}
	while(val > 0) {
        sum += ((int) (val % 10));
		val /= 10;
	}
	return sum;
}

// Returns positive digit sum for negative values
// Throws exception for invalid values of base (less than 2)
template<class T> int digit_sum_base(T val, int base) {
    if(base < 2) {
        throw std::invalid_argument("digit_sum_base: Invalid input for base (less than 2)");
    }
	int sum = 0;
	if(val < 0) {
		val = -val;
	}
	while(val > 0) {
        sum += ((int) (val % base));
		val /= base;
	}
	return sum;
}

#endif
