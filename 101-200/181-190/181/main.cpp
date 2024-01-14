
#include "main.hpp"

// This problem can be solved using generating functions: the single color
// version of this problem is equivalent to the partition problem, in which the
// number of ways to partition n is given by the coefficient of x^n in the
// product:
// 	(1 + x + x^2 + ...) * (1 + x^2 + x^4 + ...) * (1 + x^3 + x^6 + ...) * ...
// The product for the two color version is:
//	Product of all: (1 + x^s * y^t + x^2s * y^2t + x^3s * y^3t + ...)
// 	With all pairs of natural numbers (s, t) excluding (0, 0)
// Each pair (s, t) corresponds to a pile of s black and t white objects, and
// each term in the sum corresponds to the number of the specific type of pile
// corresponding to the pair (s, t).

int main() {
	std::cout << get_coef(N, M) << std::endl;
	return 0;
}

uint64_t get_coef(uint64_t n, uint64_t m) {
	// arr is the vector representing the coefficients of the cumulative generating function
	// the coefficient of x^s y^t is in the position s * (m + 1) + t
	std::vector<uint64_t> arr((n + 1) * (m + 1), 0);
	// mult_step is the placeholder array for the current generating function getting multiplied by a new series
	std::vector<uint64_t> mult_step((n + 1) * (m + 1));
	// generating function initialized to the constant 1
	arr[0] = 1;
	for(uint64_t s = 0; s < (n + 1); s++) {
		for(uint64_t t = 0; t < (m + 1); t++) {
			// skipping (s, t) = (0, 0)
			if((s == 0) && (t == 0)) {
				continue;
			}
			// resetting the placeholder array
			std::fill(mult_step.begin(), mult_step.end(), 0);
			// each term in the cumulative generating function needs to be multiplied by the series in this double loop
			for(uint64_t k = 0; k < (n + 1); k++) {
				for(uint64_t l = 0; l < (m + 1); l++) {
					// k_step and l_step is the pair (k, l) shifted by a factor of (cs, ct) for all valid c >= 0
					// k_step = k + cs
					// l_step = l + ct
					uint64_t l_step = l;
					// loop stops when k_step is out of bounds
					for(uint64_t k_step = k; k_step < (n + 1); k_step += s) {
						// loop stops when l_step is out of bounds
						if(l_step > m) {
							break;
						}
						// addition step
						mult_step[k_step * (m + 1) + l_step] += arr[k * (m + 1) + l];
						// l_step is incremented alongside the loop
						l_step += t;
					}
				}
			}
			// the new set of coefficients is transfered back to the vector
			for(uint64_t k = 0; k < arr.size(); k++) {
				arr[k] = mult_step[k];
			}
		}
	}
	// returns the coefficient of x^n y^m
	return arr[arr.size() - 1];
}
