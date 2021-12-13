
#include "main.hpp"

int main() {
	int32_t* digits;
	read_file("data.txt", &digits);
	int64_t max_product = 0;
	for(size_t i = 0; i < (num_len - prod_len + 1); i++) {
		max_product = std::max(product(digits, i), max_product);
	}
	std::cout << max_product << std::endl;
	return 0;
}

void read_file(std::string filename, int32_t** param) {
    size_t cnt = 0;
    int32_t* data = new int32_t[num_len];
    std::string raw_data;
    boost::filesystem::ifstream stream;
    stream.open(filename);
    getline(stream, raw_data);
    size_t l_len = raw_data.length();
    while(l_len > 0) {
        for(size_t i = 0; i < l_len; i++) {
            data[cnt] = ((int32_t) raw_data[i]) - 48;
            cnt++;
        }
        getline(stream, raw_data);
        l_len = raw_data.length();
    }
    stream.close();
    *param = data;
    return;
}

int64_t product(int32_t* digits, size_t start) {
	int64_t prod = 1;
	for(size_t i = start; i < (start + prod_len); i++) {
		prod *= digits[i];
	}
	return prod;
}
