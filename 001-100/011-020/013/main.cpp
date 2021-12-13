
#include "main.hpp"

int main() {
	int256_t* data;
	int256_t sum = 0;
	read_file("data.txt", &data);
	for(size_t i = 0; i < N; i++) {
		sum += data[i];
	}
    int256_t cutoff = pow_int<int256_t, int32_t>(10, 10);
	while(sum >= cutoff) {
        sum /= 10;
    }
	std::cout << sum << std::endl;
	return 0;
}

void read_file(std::string filename, int256_t** param) {
	int256_t* data = new int256_t[N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
	for(size_t i = 0; i < N; i++) {
		getline(stream, raw_data);
		data[i] = boost::lexical_cast<int256_t>(raw_data);
	}
	stream.close();
	*param = data;
	return;
}
