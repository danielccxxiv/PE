
#include "main.hpp"

// This problem is solved using a set of N = 50 linear equations on the
// variables x_N = E(D_N), x_(N - 1) = E(D_(N - 1)), ... , x_0 = E(D_0)
// representing the expected value of the number of terms from each distance.
// In this case, since there are 100 points in the circle, there are only 51
// possible distances between the dice and the starting distance is 50.
// The exact answer in fractional form for N = 50 is:
// 586615414279592693268781956/155163869452311434997005

int main() {
	std::cout.precision(10);
	std::cout << solve_linear_system(N) << std::endl;
	return 0;
}

// The linear equations come from the probability of reaching a different
// distance from a given distance and adding 1 to represent a turn added to the
// total expected turns. There are 9 total cases since both of the 3 dice can go
// either clockwise, counterclockwise, or stay in place. Adding the cases which
// lead to a specific change in distance gives the probability for each term in
// the matrix. Setting up the equations: the edge cases are for computing x_0,
// x_1, x_(N - 1), and x_N. x_0 = 0 since the goal is to reach D_0. The
// equations for x_0, x_1, x_(N - 1), and x_N are:
// x_0 = 0
// x_1 = 1 + (2 / 9) * x_0 + (19 / 36) * x_1 + (2 / 9) * x_2 + (1 / 36) * x_3
// => (2 / 9) * x_0 + ((19 / 36) - 1) * x_1 + (2 / 9) * x_2 + (1 / 36) * x_3 = -1
// x_(N - 1) = 1 + (1 / 36) * x_(N - 3) + (2 / 9) * x_(N - 2) + (19 / 36) * x_(N - 1) + (2 / 9) * x_N
// => (1 / 36) * x_(N - 3) + (2 / 9) * x_(N - 2) + ((19 / 36) - 1) * x_(N - 1) + (2 / 9) * x_N = -1
// x_N = 1 + (1 / 18) * x_(N - 2) + (4 / 9) * x_(N - 1) + (1 / 2) * x_N
// => (1 / 18) * x_(N - 2) + (4 / 9) * x_(N - 1) + ((1 / 2) - 1) * x_N = -1
// The standard equation for x_i is:
// x_i = 1 + (1 / 36) * x_(i - 2) + (2 / 9) * x_(i - 1) + (1 / 2) * x_i + (2 / 9) * x_(i + 1) + (1 / 36) * x_(i + 2)
// => (1 / 36) * x_(i - 2) + (2 / 9) * x_(i - 1) + ((1 / 2) - 1) * x_i + (2 / 9) * x_(i + 1) + (1 / 36) * x_(i + 2) = -1

long double solve_linear_system(uint32_t n) {
	Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic> M = Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic>::Zero(n + 1, n + 1);
	Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic> V = Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic>::Zero(n + 1, 1);
	M(0, 0) = 1;
	M(1, 0) = 2.0 / 9;
	M(1, 1) = (19.0 / 36) - 1;
	M(1, 2) = 2.0 / 9;
	M(1, 3) = 1.0 / 36;
	for(uint32_t i = 2; i < (n - 1); i++) {
		M(i, i - 2) = 1.0 / 36;
		M(i, i - 1) = 2.0 / 9;
		M(i, i) = (1.0 / 2) - 1;
		M(i, i + 1) = 2.0 / 9;
		M(i, i + 2) = 1.0 / 36;
	}
	M(n - 1, n - 3) = 1.0 / 36;
	M(n - 1, n - 2) = 2.0 / 9;
	M(n - 1, n - 1) = (19.0 / 36) - 1;
	M(n - 1, n) = 2.0 / 9;
	M(n, n - 2) = 1.0 / 18;
	M(n, n - 1) = 4.0 / 9;
	M(n, n) = (1.0 / 2) - 1;
	V(0) = 0;
	for(uint32_t i = 1; i < (n + 1); i++) {
		V(i) = -1;
	}
	return M.fullPivLu().solve(V)(n);
}
