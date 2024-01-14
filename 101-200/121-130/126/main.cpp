
#include "main.hpp"

int main() {
	boost::heap::priority_queue<layer*, boost::heap::compare<layer_compare> > h;
	layer* cur;
	h.push(new layer(1, 1, 1, 0));
	layer** next;
	int* next_l = new int(0);
	int i, j, current, count;
	current = 0;
	count = 0;
	while(true) {
		cur = h.top();
		h.pop();
		if(cur->n > current) {
			if(count == 1000) {
				break;
			}
			current = cur->n;
			count = 1;
		} else {
			count++;
		}
		next = next_layers(*cur, next_l);
		for(i = 0; i < *next_l; i++) {
			h.push(next[i]);
		}
		delete cur;
	}
	std::cout << current << std::endl;
	return 0;
}

vector<layer> next_layers(const layer& l, int* len) {
	layer** next;
	int a = l.a;
	int b = l.b;
	int c = l.c;
	int k = l.k;
	if(k > 0) {
		next = new layer*[1];
		*len = 1;
		next[0] = new layer(a, b, c, k + 1);
		return next;
	}
	if(a > (c - 2)) {
		if(a == c) {
			next = new layer*[2];
			*len = 2;
			next[0] = new layer(a, b, c + 1, 0);
			next[1] = new layer(a, b, c, 1);
			return next;
		}
		next = new layer*[3];
		*len = 3;
		next[1] = new layer(a, b, c + 1, 0);
		next[2] = new layer(a, b, c, 1);
		if((b + 1) == c) {
			next[0] = new layer(a, b + 1, c, 0);
			return next;
		}
		next[0] = new layer(a + 1, b, c, 0);
		return next;
	}
	if((b + 1) == c) {
		next = new layer*[3];
		*len = 3;
		next[0] = new layer(a, b + 1, c, 0);
		next[1] = new layer(a, b, c + 1, 0);
		next[2] = new layer(a, b, c, 1);
		return next;
	}
	next = new layer*[2];
	*len = 2;
	next[0] = new layer(a, b, c + 1, 0);
	next[1] = new layer(a, b, c, 1);
	return next;
}
