
#include "main.hpp"

// Can be solved entirely by hand using the rule:
// (m^2 - n^2, 2mn, m^2 + n^2) => 2m (m + n) = 1000
// The only valid solution to this gives m = 20, n = 5
// The corresponding triple is 200, 375, 425
int main(int argc, char** argv) {
	std::cout << 31875000 << std::endl;
	return 0;
}
