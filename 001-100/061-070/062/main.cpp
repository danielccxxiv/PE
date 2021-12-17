
#include "main.hpp"

int main() {
    boost::unordered_map<int128_t, std::vector<int64_t>> map;
    boost::unordered_map<int128_t, std::vector<int64_t>>::iterator iter;
    int32_t n = 0;
    int64_t digit_check_limit = 1;
    int64_t n_cube;
    int128_t n_cube_hash;
    int64_t min_cube = -1;
    while(true) {
        n++;
        n_cube = n;
        n_cube = n_cube * n_cube * n_cube;
        if(n_cube >= digit_check_limit) {
            if(min_cube != -1) {
                break;
            }
            digit_check_limit *= static_cast<int64_t>(10);
        }
        n_cube_hash = unordered_digit_hash<int64_t, int32_t, int128_t>(n_cube);
        iter = map.find(n_cube_hash);
        if(iter == map.end()) {
            map.emplace(n_cube_hash, std::initializer_list<int64_t>{n_cube});
        } else {
            (iter->second).push_back(n_cube);
            if((iter->second).size() > 4) {
                if(min_cube == -1) {
                    min_cube = (iter->second)[0];
                } else {
                    min_cube = std::min(min_cube, (iter->second)[0]);
                }
            }
        }
    }
    std::cout << min_cube << std::endl;
	return 0;
}
