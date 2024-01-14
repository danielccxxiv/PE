
#include "main.hpp"

// There are 16 total values, but since some of them are dependent on each
// other, there are only 9 for loops needed. The rest of the values are updated
// as needed. There is also symmetry in the solutions: for every solution, a
// mirror solution can be found by subtracting each entry from 9. This means the
// search space is cut in half and the first loop on the top left number only
// needs to go to 5. The variables are arranged:
// 		x00 x01 x02 x03
// 		x10 x11 x12 x13
// 		x20 x21 x22 x23
// 		x30 x31 x32 x33
// The order of the loops is:
// 		x00 -> x01 -> x02 -> x03	(this establishes the sum)
// 		x10 -> x20 -> solve for x30
// 		x12 -> solve for x21
// 		x11 -> solve for x13 -> solve for x31
// 		x22 -> solve for x32 -> solve for x23 -> solve for x33
// At each of the solve steps, the value being solved for is checked to see if
// it is in the bounds of the accepted values, and if any additional relevant
// equations in terms of the rows, columns, and diagonals are satisfied. If all
// of these conditions are meant, the counter is incremented. At the end of the
// nested loops, the counter is multiplied by 2 to account for the symmetry in
// the solution space.

int main() {
	uint64_t count = 0;
	uint32_t x13, x21, x23, x30, x31, x32, x33;
	for(uint32_t x00 = 0; x00 < 5; x00++) {
		for(uint32_t x01 = 0; x01 < 10; x01++) {
			for(uint32_t x02 = 0; x02 < 10; x02++) {
				for(uint32_t x03 = 0; x03 < 10; x03++) {
					for(uint32_t x10 = 0; x10 < 10; x10++) {
						for(uint32_t x20 = 0; x20 < 10; x20++) {
							x30 = x01 + x02 + x03 - x10 - x20;
							if(x30 < 0) {
								break;
							} else if(x30 > 9) {
								continue;
							}
							for(uint32_t x12 = 0; x12 < 10; x12++) {
								x21 = x00 + x01 + x02 - x12 - x30;
								if(x21 < 0) {
									break;
								} else if(x21 > 9) {
									continue;
								}
								for(uint32_t x11 = 0; x11 < 10; x11++) {
									x13 = x00 + x20 + x30 - x11 - x12;
									if(x13 < 0) {
										break;
									} else if(x13 > 9) {
										continue;
									}
									x31 = x00 + x02 + x03 - x11 - x21;
									if(x31 < 0) {
										break;
									} else if(x31 > 9) {
										continue;
									}
									for(uint32_t x22 = 0; x22 < 10; x22++) {
										x32 = x00 + x01 + x03 - x12 - x22;
										if(x32 < 0) {
											break;
										} else if(x32 > 9) {
											continue;
										}
										x23 = x00 + x10 + x30 - x21 - x22;
										if(x23 < 0) {
											break;
										} else if(x23 > 9) {
											continue;
										}
										x33 = x01 + x02 + x03 - x11 - x22;
										if(x33 < 0) {
											break;
										} else if(x33 > 9) {
											continue;
										}
										if((x00 + x01 + x02) != (x13 + x23 + x33)) {
											continue;
										}
										if((x00 + x10 + x20) != (x31 + x32 + x33)) {
											continue;
										}
										count++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	count *= 2;
	std::cout << count << std::endl;
}
