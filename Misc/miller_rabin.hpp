
#ifndef MILLER_RABIN_HPP
#define MILLER_RABIN_HPP

#include <boost/multiprecision/cpp_int.hpp>

#include "pow_functions.hpp"

static int* mr_default_arr;
static int mr_default_arr_len;
static int mr_arr_1[] = {2, 7, 61};
static int mr_arr_len_1 = 3;
static int mr_arr_2[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
static int mr_arr_len_2 = 13;

template<class T> struct mr_det_data {

};

template<class T> bool miller_rabin(T num) {
	if((num == 1) || (num % 2 == 0)) {
		return false;
	}
	int s = 0;
	T d = num - 1;
	while(d % 2 == 0) {
		d /= 2;
		s++;
	}
	int a, r, len;
	bool x;
	T p2r;
	int* lst;
	if(sizeof(T) <= 4) {
		lst = mr_arr_1;
		len = mr_arr_len_1;
	} else if(sizeof(T) <= 8) {
		lst = mr_arr_2;
		len = mr_arr_len_2;
	} else {
		lst = mr_default_arr;
		len = mr_default_arr_len;
	}
	for(a = 0; a < len; a++) {
		x = true;
		p2r = 1;
		for(r = 0; r < s; r++) {
			if((pow_mod((T) lst[a], d, num) == 1)
				|| (pow_mod((T) lst[a], p2r * d, num) == (num - 1))) {
				x = false;
				break;
			}
			p2r *= 2;
		}
		if(x) {
			return false;
		}
	}
	return true;
}

#endif
