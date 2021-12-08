
#include "main.hpp"

int main(int argc, char** argv) {
	int* digits;
	read_file("data.txt", &digits);
    int i;
	long max_product = 0;
	for(i = 0; i < (num_len - prod_len + 1); i++) {
		max_product = std::max(product(digits, i), max_product);
	}
	std::cout << max_product << std::endl;
	return 0;
}

int read_file(std::string filename, int** param) {
    int i;
    int cnt = 0;
    int* data = new int[num_len];
    std::string raw_data;
    boost::filesystem::ifstream stream;
    stream.open(filename);
    getline(stream, raw_data);
    int l_len = raw_data.length();
    while(l_len > 0) {
        for(i = 0; i < l_len; i++) {
            data[cnt] = ((int) raw_data[i]) - 48;
            cnt++;
        }
        getline(stream, raw_data);
        l_len = raw_data.length();
    }
    stream.close();
    *param = data;
    return 0;
}

long product(int* digits, int start) {
	long prod = 1;
	for(int i = start; i < (start + prod_len); i++) {
		prod *= digits[i];
	}
	return prod;
}
