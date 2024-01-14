
#include "main.hpp"

/*
Can be solved entirely by hand using the rule:
	(m^2 - n^2, 2mn, m^2 + n^2) generates all primitive pythagorean triples for
	relatively prime m, n

	Multiplying this triple by k generates all possible triples

 =>	k * ((m^2 - n^2) + 2mn + (m^2 + n^2)) = 2 * k * m * (m + n)
 =>	2 * k * m * (m + n) = 1000
 =>	k * m * (m + n) = 500 = 2^2 * 5^3

The only valid solution is k = 25, m = 4, n = 1
The corresponding triple is 200, 375, 425 => 200 * 375 * 425 = 31875000
*/

int main() {
	std::cout << 31875000 << std::endl;
	return 0;
}
