
#ifndef ROUND_SQRT_HPP
#define ROUND_SQRT_HPP

#include <stdexcept>

// Throws exception for negative inputs
template<class T> T floor_sqrt(T num) {
	if(num < 0) {
        throw std::invalid_argument("floor_sqrt: negative input");
    }
    if(num == 0) {
        return 0;
    }
    T x = num;
    T y = (x + (num / x)) / 2;
    while(x > y) {
        x = y;
        y = (x + (num / x)) / 2;
    }
    return x;
}

#endif
