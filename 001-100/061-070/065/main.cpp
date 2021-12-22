
#include "main.hpp"

#include <random>

int main() {

    std::cout << (uint32_t) std::rand() << std::endl;
    std::cout << (uint32_t) std::rand() << std::endl;
    std::cout << (uint32_t) std::rand() << std::endl;

    std::cout << std::numeric_limits<BOOST_INT(31)>::digits << std::endl;
	return 0;
}
