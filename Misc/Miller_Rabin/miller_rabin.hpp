
#ifndef MILLER_RABIN_HPP
#define MILLER_RABIN_HPP

#include <array>

#include <boost/multiprecision/cpp_int.hpp>

#include "pow_functions.hpp"

template<class P> struct mr_det_data {
    static array<P, 1> mr_det_arr_0 = {2};
    static array<P, 2> mr_det_arr_1 = {2, 3};
    static array<P, 2> mr_det_arr_2 = {31, 73};
    static array<P, 3> mr_det_arr_3 = {2, 3, 5};
    static array<P, 4> mr_det_arr_4 = {2, 3, 5, 7};
    static array<P, 3> mr_det_arr_5 = {2, 7, 61};
    static array<P, 4> mr_det_arr_6 = {2, 13, 23, 1662803};
    static array<P, 5> mr_det_arr_7 = {2, 3, 5, 7, 11};
    static array<P, 6> mr_det_arr_8 = {2, 3, 5, 7, 11, 13};
    static array<P, 7> mr_det_arr_9 = {2, 3, 5, 7, 11, 13, 17};
    static array<P, 9> mr_det_arr_10 = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    static array<P, 12> mr_det_arr_11 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    static array<P, 13> mr_det_arr_12 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    static int128_t mr_det_limit_0 = boost::lexical_cast<int128_t>("2047");
    static int128_t mr_det_limit_1 = boost::lexical_cast<int128_t>("1373653");
    static int128_t mr_det_limit_2 = boost9080191;
    static int128_t mr_det_limit_3 = 25326001;
    static int128_t mr_det_limit_4 =
};

// data from https://miller-rabin.appspot.com/
// 341531           [9345883071009581737]
// 1050535501       [336781006125, 9639812373923155]
// 350269456337     [4230279247111683200, 14694767155120705706, 16641139526367750375]
// 55245642489451   [2, 141889084524735, 1199124725622454117, 11096072698276303650]
// 7999252175582851 [2, 4130806001517, 149795463772692060, 186635894390467037, 3967304179347715805]
//

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
