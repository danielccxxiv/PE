
#include "main.hpp"

int main(int argc, char** argv) {
    std::vector<int> prime_list;
    primesieve::generate_primes(1000, 9999, &prime_list);
    int list_len = prime_list.size();
    int n0;
    int n1;
    int n2;
    int hash0;
    int hash1;
    int hash2;
    bool found = false;
    for(int i = 0; i < list_len; i++) {
        n0 = prime_list[i];
        if(n0 == 1487) {
            continue;
        }
        hash0 = unordered_digit_hash(n0);
        for(int j = (i + 1); j < list_len; j++) {
            n1 = prime_list[j];
            n2 = 2 * n1 - n0;
            if(n2 > 9999) {
                break;
            }
            if(binary_search(prime_list, n2, 0, list_len) < 0) {
                continue;
            }
            hash1 = unordered_digit_hash(n1);
            if(hash0 != hash1) {
                continue;
            }
            hash2 = unordered_digit_hash(n2);
            if(hash0 == hash2) {
                found = true;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    std::cout << (100000000L * n0 + 10000L * n1 + 1L * n2) << std::endl;
	return 0;
}

int unordered_digit_hash(int n) {
    int hash = 0;
    while(n != 0) {
        hash += pow<int, int>(5, n % 10);
        n /= 10;
    }
    return hash;
}
