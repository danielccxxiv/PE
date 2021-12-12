
#include "main.hpp"

int main() {
	uint256_t* data;
	uint256_t sum = 0;
	read_file("data.txt", &data);
	for(uint32_t i = 0; i < N; i++) {
		sum += data[i];
	}
    uint256_t cutoff = pow_int<uint256_t, uint32_t>(10, 10);
	while(sum >= cutoff) {
        sum /= 10;
    }
	std::cout << sum << std::endl;
	return 0;
}

void read_file(std::string filename, uint256_t** param) {
	uint256_t* data = new uint256_t[N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	char* raw_data = new char[N];
	for(uint32_t i = 0; i < N; i++) {
		for(uint32_t j = 0; j < N; j++) {
			raw_data[j] = 0;
		}
		stream.getline(raw_data, N);
		data[i] = boost::lexical_cast<uint256_t>(raw_data);
	}
	stream.close();
	*param = data;
	return;
}
