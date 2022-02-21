
#include "main.hpp"

int main() {
    int32_t N = 0;
    int1024_t max_x = 0;
    int1024_t cur_x = 0;
    for(int32_t i = 1; i < 1001; i++) {
        cur_x = dio_eq_numer(i);
        if(cur_x > max_x) {
            max_x = cur_x;
            N = i;
        }
    }
    std::cout << N << std::endl;
	return 0;
}

int1024_t dio_eq_numer(int32_t n) {
    alg_num base(n, -int_sqrt(n), 1);
    if((base.k * base.k) == n) {
        return 0;
    }
    std::vector<int32_t> cont_frac;
    alg_num next = inverse(base);
    int32_t cont_frac_term = alg_num_floor(next);
    cont_frac.push_back(cont_frac_term);
    next.k -= (next.d * cont_frac_term);
    while(next != base) {
        next = inverse(next);
        cont_frac_term = alg_num_floor(next);
        cont_frac.push_back(cont_frac_term);
        next.k -= (next.d * cont_frac_term);
    }

    std::vector<int1024_t> cont_frac_numer_terms(3);
    std::vector<int1024_t> cont_frac_denom_terms(3);
    cont_frac_numer_terms[0] = -base.k;
    cont_frac_denom_terms[0] = 1;
    if((cont_frac_numer_terms[0] * cont_frac_numer_terms[0] - n * cont_frac_denom_terms[0] * cont_frac_denom_terms[0]) == 1) {
        return cont_frac_numer_terms[0];
    }
    int32_t frac_terms_iter = 1;
    cont_frac_numer_terms[1] = cont_frac[0] * (-base.k) + 1;
    cont_frac_denom_terms[1] = cont_frac[0];
    while((cont_frac_numer_terms[frac_terms_iter % 3] * cont_frac_numer_terms[frac_terms_iter % 3] - n * cont_frac_denom_terms[frac_terms_iter % 3] * cont_frac_denom_terms[frac_terms_iter % 3]) != 1) {
        frac_terms_iter++;
        cont_frac_numer_terms[frac_terms_iter % 3] = cont_frac_numer_terms[(frac_terms_iter - 1) % 3] * cont_frac[(frac_terms_iter - 1) % cont_frac.size()] + cont_frac_numer_terms[(frac_terms_iter - 2) % 3];
        cont_frac_denom_terms[frac_terms_iter % 3] = cont_frac_denom_terms[(frac_terms_iter - 1) % 3] * cont_frac[(frac_terms_iter - 1) % cont_frac.size()] + cont_frac_denom_terms[(frac_terms_iter - 2) % 3];
    }
    return cont_frac_numer_terms[frac_terms_iter % 3];
}

int32_t alg_num_floor(alg_num num) {
    return (int_sqrt(num.n) + num.k) / num.d;
}

alg_num inverse(alg_num num) {
    num.d = (num.n - num.k * num.k) / num.d;
    num.k *= -1;
    return num;
}
