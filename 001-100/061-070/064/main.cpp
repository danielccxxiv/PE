
#include "main.hpp"

int main() {
    int32_t count = 0;
    for(int32_t i = 1; i < 10001; i++) {
        if(cont_frac_period(i) % 2 == 1) {
            count++;
        }
    }
    std::cout << count << std::endl;
	return 0;
}

int32_t cont_frac_period(int32_t n) {
    alg_num base(n, -int_sqrt(n), 1);
    if((base.k * base.k) == n) {
        return 0;
    }
    int32_t count = 1;
    alg_num next = inverse(base);
    next.k -= (next.d * alg_num_floor(next));
    while(next != base) {
        count++;
        next = inverse(next);
        next.k -= (next.d * alg_num_floor(next));
    }
    return count;
}

int32_t alg_num_floor(alg_num num) {
    return (int_sqrt(num.n) + num.k) / num.d;
}

alg_num inverse(alg_num num) {
    num.d = (num.n - num.k * num.k) / num.d;
    num.k *= -1;
    return num;
}
