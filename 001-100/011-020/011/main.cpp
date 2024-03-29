
#include "main.hpp"

int main() {
	int32_t* arr;
    read_file("data.txt", &arr);
	int32_t max_val = 0;
	int32_t current = 0;
	for(size_t i = 0; i < N; i++) {
		for(size_t j = 0; j < (N - 3); j++) {
			current = arr[N * i + j] * arr[N * i + j + 1] * arr[N * i + j + 2] * arr[N * i + j + 3];
			max_val = std::max(max_val, current);
		}
	}
	for(size_t i = 0; i < (N - 3); i++) {
		for(size_t j = 0; j < N; j++) {
			current = arr[N * i + j] * arr[N * (i + 1) + j] * arr[N * (i + 2) + j] * arr[N * (i + 3) + j];
			max_val = std::max(max_val, current);
		}
	}
	for(size_t i = 0; i < (N - 3); i++) {
		for(size_t j = 0; j < (N - 3); j++) {
			current = arr[N * i + j] * arr[N * (i + 1) + j + 1] * arr[N * (i + 2) + j + 2] * arr[N * (i + 3) + j + 3];
			max_val = std::max(max_val, current);
			current = arr[N * i + j + 3] * arr[N * (i + 1) + j + 2] * arr[N * (i + 2) + j + 1] * arr[N * (i + 3) + j];
			max_val = std::max(max_val, current);
		}
	}
	std::cout << max_val << std::endl;
	return 0;
}

void read_file(std::string filename, int32_t** param) {
    int32_t* data = new int32_t[N * N];
    size_t cnt = 0;
    std::string raw_data;
    boost::tokenizer<>::iterator iter;
    boost::filesystem::ifstream stream;
    stream.open(filename);
    getline(stream, raw_data);
    size_t l_len = raw_data.length();
    while(l_len > 0) {
        boost::tokenizer<> tok(raw_data);
        iter = tok.begin();
        for(size_t i = 0; i < N; i++) {
            data[cnt] = boost::lexical_cast<int32_t>(*iter);
            iter++;
            cnt++;
        }
        getline(stream, raw_data);
        l_len = raw_data.length();
    }
    stream.close();
    *param = data;
    return;
}
