
#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

// Well defined only for non-negtive num and base > 1
template<class T, class B, class R = B> R digit_sum(T num, B base = 10) {
    R sum = 0;
	while(num > 0) {
        sum += static_cast<R>(num % base);
		num /= base;
	}
	return sum;
}

#endif
