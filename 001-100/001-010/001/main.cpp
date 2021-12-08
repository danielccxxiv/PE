
#include "main.hpp"

int main(int argc, char** argv) {
	int sum3 = (limit - 1) / 3;
	sum3 = 3 * sum3 * (sum3 + 1) / 2;
	int sum5 = (limit - 1) / 5;
	sum5 = 5 * sum5 * (sum5 + 1) / 2;
	int sum15 = (limit - 1) / 15;
	sum15 = 15 * sum15 * (sum15 + 1) / 2;
	int result = sum3 + sum5 - sum15;
	std::cout << result << std::endl;
	return 0;
}
