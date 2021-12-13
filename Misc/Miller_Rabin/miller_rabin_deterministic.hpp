
#ifndef MILLER_RABIN_DETERMINISTIC_HPP
#define MILLER_RABIN_DETERMINISTIC_HPP

#include <numeric>

#include <boost/math/special_functions/log1p.hpp>

#include "miller_rabin_deterministic_hash_table.hpp"
#include "../pow_functions.hpp"

template<class T, class L> bool miller_rabin_det_backend(T num) {
    if(!(num & 1)) {
        return false;
    }
    T d = num >> 1;
    int32_t r = 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    L num_cast = num;
    L max_residue = num_cast - 1;
    double log_val = boost::math::log1p(num);
    int32_t limit = static_cast<int32_t>(2.0 * log_val * log_val) + 1;
    L x;
    bool loop check;
    for(int32_t i = 2; i < limit; i++) {
        if(std::gcd(num, i) != 1) {
            return false;
        }
        loop_check = true;
        x = pow_int_mod<L, T>(i, d, num_cast);
        if((x != 1) && (x != max_residue)) {
            for(int32_t j = 1; j < r; j++) {
                x = (x * x) % num_cast;
                if(x == max_residue) {
                    loop_check = false;
                    break;
                }
            }
            if(loop_check) {
                return false;
            }
        }
    }
    return true;
}

template<class T> bool miller_rabin_det(T num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<T, cpp_int>(num);
}

template<> bool miller_rabin_det<int32_t>(int32_t num) {
    return miller_rabin_det<uint32_t>(num);
}

template<> bool miller_rabin_det<int64_t>(int64_t num) {
    return miller_rabin_det<uint64_t>(num);
}

template<> bool miller_rabin_det<int128_t>(int128_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint128_t, uint256_t>(num);
}

template<> bool miller_rabin_det<uint128_t>(uint128_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint128_t, uint256_t>(num);
}

template<> bool miller_rabin_det<int256_t>(int256_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint256_t, uint512_t>(num);
}

template<> bool miller_rabin_det<uint256_t>(uint256_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint256_t, uint512_t>(num);
}

template<> bool miller_rabin_det<int512_t>(int512_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint512_t, uint256_t>(num);
}

template<> bool miller_rabin_det<uint512_t>(uint512_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(num <= UINT64_MAX) {
        return miller_rabin_det<uint64_t>(num);
    }
    return miller_rabin_det_backend<uint512_t, uint1024_t>(num);
}

template<> bool miller_rabin_det<uint32_t>(uint32_t num) {
    if(!(num & 1)) {
        return false;
    }
    bool loop check = true;
    uint32_t d = num >> 1;
    int32_t r = 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    uint64_t num_cast = num;
    uint64_t max_residue = num_cast - 1;
    uint64_t x = pow_int_mod<uint64_t, uint32_t>(2, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    uint32_t hash_val = (num * mr_det_64_hash_mult) >> 24;
    uint32_t base = mr_det_32_hash_table[hash_val];
    if(std::gcd(num, base) != 1) {
        return false;
    }
    x = pow_int_mod<uint64_t, uint32_t>(base, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        loop_check = true;
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    return true;
}

template<> bool miller_rabin_det<uint64_t>(uint64_t num) {
    if(num <= UINT32_MAX) {
        return miller_rabin_det<uint32_t>(num);
    }
    if(!(num & 1)) {
        return false;
    }
    bool loop_check = true;
    uint64_t d = num >> 1;
    int32_t r = 1;
    while(!(d & 1)) {
        d >>= 1;
        r++;
    }
    uint128_t num_cast = num;
    uint128_t max_residue = num_cast - 1;
    uint128_t x = pow_int_mod<uint128_t, uint64_t>(2, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    uint32_t hash_val = (static_cast<uint32_t>(num) * mr_det_64_hash_mult) >> 18;
    uint64_t base0 = mr_det_64_hash_table0[hash_val];
    if(std::gcd(num, base0) != 1) {
        return false;
    }
    x = pow_int_mod<uint128_t, uint64_t>(base0, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        loop_check = true;
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
                break;
            }
        }
        if(loop_check) {
            return false;
        }
    }
    if(num < mr_det_64_last_check_limit) {
        return true;
    }
    uint64_t base1 = mr_det_64_hash_table1[(base >> 13)];
    if(std::gcd(num, base1) != 1) {
        return false;
    }
    x = pow_int_mod<uint128_t, uint64_t>(base1, d, num_cast);
    if((x != 1) && (x != max_residue)) {
        loop_check = true;
        for(int32_t i = 1; i < r; i++) {
            x = (x * x) % num_cast;
            if(x == max_residue) {
                loop_check = false;
            }
            break;
        }
        if(loop_check) {
            return false;
        }
    }
    return true;
}

#endif
