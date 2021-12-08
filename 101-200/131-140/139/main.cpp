
#include "main.hpp"

int main(int argc, char** argv) {
	int x, y, m, n, total;
	x = 1;
	y = 1;
	total = 0;
	while(true) {
		y += x;
		x += (2 * (y - x));
		m = y;
		n = x - y;
		if((2 * m * (m + n)) > limit) {
			break;
		}
		total += (limit / (2 * m * (m + n)));
	}
	cout << total << endl;
	return 0;
}
