
#include "main.hpp"

int main() {
	std::cout.precision(10);
	std::cout << solve_linear_system(N) << std::endl;
	return 0;
}

long double solve_linear_system(uint32_t n, uint32_t turns) {
	Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic> M = Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic>::Zero(n * n, n * n);
	Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic> V = Eigen::Matrix<long double, Eigen::Dynamic, Eigen::Dynamic>::Zero(n * n, 1);
	M(1, 0) = 1.0 / 2;
	M(n, 0) = 1.0 / 2;
	M(n - 2, n - 1) = 1.0 / 2;
	M(2 * n - 1, n - 1) = 1.0 / 2;
	M(n * (n - 2), n * (n - 1)) = 1.0 / 2;
	M(n * (n - 1) + 1, n * (n - 1)) = 1.0 / 2;
	M(n * (n - 1) - 1, n * n - 1) = 1.0 / 2;
	M(n * n - 2, n * n - 1) = 1.0 / 2;
	for(uint32_t i = 1; i < (n - 1); i++) {
		M(i - 1, i) = 1.0 / 3;
		M(i + 1, i) = 1.0 / 3;
		M(n + i, i) = 1.0 / 3;
		M(n * (i - 1), n * i) = 1.0 / 3;
		M(n * (i + 1), n * i) = 1.0 / 3;
		M(n * i + 1, n * i) = 1.0 / 3;
		M(n * i - 1, n * (i + 1) - 1) = 1.0 / 3;
		M(n * (i + 2) - 1, n * (i + 1) - 1) = 1.0 / 3;
		M(n * (i + 1) - 2, n * (i + 1) - 1) = 1.0 / 3;
		M(n * (n - 1) + i - 1, n * (n - 1) + i) = 1.0 / 3;
		M(n * (n - 1) + i + 1, n * (n - 1) + i) = 1.0 / 3;
		M(n * (n - 2) + i, n * (n - 1) + i) = 1.0 / 3;
	}
	for(uint32_t i = 1; i < (n - 1); i++) {
		for(uint32_t j = 1; j < (n - 1); j++) {
			M(n * (i - 1) + j, n * i + j) = 1.0 / 4;
			M(n * (i + 1) + j, n * i + j) = 1.0 / 4;
			M(n * i + (j - 1), n * i + j) = 1.0 / 4;
			M(n * i + (j + 1), n * i + j) = 1.0 / 4;
		}
	}
}

template<class F, class I> Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic> pow_matrix(const Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic>& M, const I& n) {
	static_assert(std::numeric_limits<I>::is_integer);
	if(std::numeric_limits<I>::is_signed) {
		if(n < static_cast<I>(0)) {
			throw "pow_matrix<F, I>(Matrix<F> M, I n): negative value of n";
		}
	}
	uint32_t dim = M.rows();
	if(dim != M.cols()) {
		throw "pow_matrix<F, I>(Matrix<F> M, I n): non-square matrix";
	}
	Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic> M_cast = Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic>::Identity(dim, dim);
	Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic> R = Eigen::Matrix<F, Eigen::Dynamic, Eigen::Dynamic>::Identity(dim, dim);

}

















//
