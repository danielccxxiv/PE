
#include "main.hpp"

int main(int argc, char** argv) {
    int last_prime = prime<int>::iter.next_prime();
    prime<int>::list.push_back(last_prime);
    int n = 1;
    int dbl_sqr;
    bool found = false;
    while(!(found)) {
        n += 2;
        while(last_prime < n) {
            last_prime = prime<int>::iter.next_prime();
            prime<int>::list.push_back(last_prime);
        }
        if(n == last_prime) {
            continue;
        }
        found = true;
        for(int i = 1; i < n; i++) {
            dbl_sqr = 2 * i * i;
            if(dbl_sqr >= n) {
                break;
            }
            if(binary_search(prime<int>::list, n - dbl_sqr, 0, prime<int>::list.size()) >= 0) {
                found = false;
                break;
            }
        }
    }
    std::cout << n << std::endl;
	return 0;
}
