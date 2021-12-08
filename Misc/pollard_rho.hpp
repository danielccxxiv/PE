
#ifndef POLLARD_RHO_HPP
#define POLLARD_RHO_HPP

template<class T> T pollard_rho(T num) {
    if(num < 0) {
        num = -num;
    }
    if(num < 2) {
        return 0;
    }
    T x = 2;
    T y = 2;
    T d = 1;
    while(d == 1) {
        x = (x * x + 1) % num;
        y = (y * y + 1) % num;
        y = (y * y + 1) % num;
        if(x == y) {
            return 0;
        }
        if(x > y) {
            d = gcd(x - y, num);
        } else {
            d = gcd(y - x, num);
        }
    }
    return d;
}

#endif
