
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include <iostream>

#include "../../../Misc/floor_sqrt.hpp"

// Value is: (sqrt(n) + k) / d
// Proof that remainders will always be in this form is in:
// continued_fractions_mariusjp.pdf (Theorem 2.3)
typedef struct alg_num {
    int32_t n;
    int32_t k;
    int32_t d;

    alg_num(int32_t n, int32_t k, int32_t d) {
        this->n = n;
        this->k = k;
        this->d = d;
    }

    bool operator!=(const alg_num& a_num) {
        return (n != a_num.n) || (k != a_num.k) || (d != a_num.d);
    }
} alg_num;

int32_t cont_frac_period(int32_t n);
int32_t alg_num_floor(alg_num num);
alg_num inverse(alg_num num);

#endif
