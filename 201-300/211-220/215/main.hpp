
#ifndef MAIN_HPP
#define MAIN_HPP

#include <cinttypes>
#include <iostream>

#include <boost/intrusive/set.hpp>
#include <boost/lockfree/stack.hpp>

using namespace std;

using namespace boost::intrusive;
using namespace boost::lockfree;

static const int N = 32;
static const int H = 10;

typedef struct wall: set_base_hook<> {
	int arr[H];
	long num;

	set_member_hook<> member_hook_;

	wall() {
		int i;
		for(i = 0; i < H; i++) {
			arr[i] = 0;
		}
		num = 1;
	}

	wall(int* data, long count) {
		int i;
		for(i = 0; i < H; i++) {
			arr[i] = data[i];
		}
		num = count;
	}

	bool operator==(const wall& o) const {
		int i;
		for(i = 0; i < H; i++) {
			if(this->arr[i] != o.arr[i]) {
				return false;
			}
		}
		return true;
	}
} wall;

typedef struct wall_c {
	bool operator()(const wall& w1, const wall& w2) const {
		int i;
		for(i = 0; i < H; i++) {
			if(w1.arr[i] < w2.arr[i]) {
				return true;
			}
			if(w1.arr[i] > w2.arr[i]) {
				return false;
			}
		}
		return false;
	}
} wall_c;

static stack<pair<wall*, int>, fixed_sized<false> > UUU(0);
static stack<pair<wall*, int>, fixed_sized<false> > FFF(0);

int next_walls();

#endif
