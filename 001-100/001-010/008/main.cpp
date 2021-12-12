
#include "main.hpp"

int main() {
	uint32_t* digits;
	read_file("data.txt", &digits);
	uint64_t max_product = 0;
	for(uint32_t i = 0; i < (num_len - prod_len + 1); i++) {
		max_product = std::max(product(digits, i), max_product);
	}
	std::cout << max_product << std::endl;
	return 0;
}

void read_file(std::string filename, uint32_t** param) {
    uint32_t cnt = 0;
    uint32_t* data = new uint32_t[num_len];
    std::string raw_data;
    boost::filesystem::ifstream stream;
    stream.open(filename);
    getline(stream, raw_data);
    uint32_t l_len = raw_data.length();
    while(l_len > 0) {
        for(uint32_t i = 0; i < l_len; i++) {
            data[cnt] = ((uint32_t) raw_data[i]) - 48;
            cnt++;
        }
        getline(stream, raw_data);
        l_len = raw_data.length();
    }
    stream.close();
    *param = data;
    return;
}

uint64_t product(uint32_t* digits, uint32_t start) {
	uint64_t prod = 1;
	for(uint32_t i = start; i < (start + prod_len); i++) {
		prod *= digits[i];
	}
	return prod;
}
