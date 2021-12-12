
#include "main.hpp"

int main() {
	uint32_t max_val;
	uint32_t* data;
	uint32_t* sums = new uint32_t[N * N];
	read_file("data.txt", &data);
	sums[0] = data[0];
	for(uint32_t i = 1; i < N; i++) {
		for(uint32_t j = 1; j < i; j++) {
			sums[N * i + j] = std::max(sums[N * (i - 1) + (j - 1)], sums[N * (i - 1) + j]) + data[N * i + j];
		}
		sums[N * i] = sums[N * (i - 1)] + data[N * i];
		sums[N * i + i] = sums[N * (i - 1) + (i - 1)] + data[N * i + i];
	}
	max_val = 0;
	for(uint32_t i = 0; i < N; i++) {
		max_val = std::max(max_val, sums[N * (N - 1) + i]);
	}
	std::cout << max_val << std::endl;
	return 0;
}

void read_file(std::string filename, uint32_t** param) {
	uint32_t* data = new uint32_t[N * N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
    boost::tokenizer<>::iterator it;
	for(uint32_t i = 0; i < N; i++) {
		for(uint32_t j = 0; j < N; j++) {
			data[N * i + j] = 0;
		}
		getline(stream, raw_data);
		boost::tokenizer<> tok(raw_data);
        it = tok.begin();
		for(uint32_t j = 0; j < (i + 1); j++) {
			data[N * i + j] = boost::lexical_cast<uint32_t>(*it);
			it++;
		}
	}
	stream.close();
	*param = data;
	return;
}
