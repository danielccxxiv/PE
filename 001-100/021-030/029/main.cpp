
#include "main.hpp"

int main() {
    boost::unordered_set<pfact, pfact_hash> pfact_set;
    pfact* reference;
    pfact* temp;
    for(int32_t a = 2; a < 101; a++) {
        reference = new pfact(a);
        for(int32_t b = 2; b < 101; b++) {
            temp = new pfact(reference, b);
            pfact_set.emplace(*temp);
        }
        delete reference;
    }
    std::cout << pfact_set.size() << std::endl;
    return 0;
}
