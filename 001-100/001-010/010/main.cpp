
#include "main.hpp"

int main(int argc, char** argv) {
    long sum = 0;
    int val = prime<int>::iter.next_prime();
    while(val < N) {
        sum += val;
        val = prime<int>::iter.next_prime();
    }
    std::cout << sum << std::endl;
	return 0;
}
