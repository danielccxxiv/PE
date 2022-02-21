
#include "main.hpp"

int main() {
	int32_t max_val;
	int32_t* data;
	int32_t* sums = new int32_t[N * N];
	read_file("data.txt", &data);
	sums[0] = data[0];
	for(size_t i = 1; i < N; i++) {
		for(size_t j = 1; j < i; j++) {
			sums[N * i + j] = std::max(sums[N * (i - 1) + (j - 1)], sums[N * (i - 1) + j]) + data[N * i + j];
		}
		sums[N * i] = sums[N * (i - 1)] + data[N * i];
		sums[N * i + i] = sums[N * (i - 1) + (i - 1)] + data[N * i + i];
	}
	max_val = 0;
	for(size_t i = 0; i < N; i++) {
		max_val = std::max(max_val, sums[N * (N - 1) + i]);
	}
	std::cout << max_val << std::endl;
	return 0;
}

void read_file(std::string filename, int32_t** param) {
	int32_t* data = new int32_t[N * N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
    boost::tokenizer<>::iterator it;
	for(size_t i = 0; i < N; i++) {
		for(size_t j = 0; j < N; j++) {
			data[N * i + j] = 0;
		}
		getline(stream, raw_data);
		boost::tokenizer<> tok(raw_data);
        it = tok.begin();
		for(size_t j = 0; j < (i + 1); j++) {
			data[N * i + j] = boost::lexical_cast<int32_t>(*it);
			it++;
		}
	}
	stream.close();
	*param = data;
	return;
}
