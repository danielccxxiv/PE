
#ifndef POLLARD_RHO_HPP
#define POLLARD_RHO_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include "gcd.hpp"

// Returns 0 if no factor found
template<class T> T pollard_rho(T num) {
    if(num < 4) {
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
