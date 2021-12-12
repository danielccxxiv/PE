
#ifndef FLOOR_SQRT_HPP
#define FLOOR_SQRT_HPP

// Well defined only for non-negative inputs
template<class T> T floor_sqrt(T num) {
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
