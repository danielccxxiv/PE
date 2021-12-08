
#include "main.hpp"

int main(int argc, char** argv) {
	int* arr;
    read_file("data.txt", &arr);
	int max_val = 0;
	int current = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < (N - 3); j++) {
			current = arr[N * i + j] * arr[N * i + j + 1] * arr[N * i + j + 2]
                * arr[N * i + j + 3];
			max_val = std::max(max_val, current);
		}
	}
	for(int i = 0; i < (N - 3); i++) {
		for(int j = 0; j < N; j++) {
			current = arr[N * i + j] * arr[N * (i + 1) + j]
                * arr[N * (i + 2) + j] * arr[N * (i + 3) + j];
			max_val = std::max(max_val, current);
		}
	}
	for(int i = 0; i < (N - 3); i++) {
		for(int j = 0; j < (N - 3); j++) {
			current = arr[N * i + j] * arr[N * (i + 1) + j + 1]
                * arr[N * (i + 2) + j + 2] * arr[N * (i + 3) + j + 3];
			max_val = std::max(max_val, current);
			current = arr[N * i + j + 3] * arr[N * (i + 1) + j + 2]
                * arr[N * (i + 2) + j + 1] * arr[N * (i + 3) + j];
			max_val = std::max(max_val, current);
		}
	}
	std::cout << max_val << std::endl;
	return 0;
}

int read_file(std::string filename, int** param) {
    int* data = new int[N * N];
    int cnt = 0;
    std::string raw_data;
    boost::tokenizer<>::iterator iter;
    boost::filesystem::ifstream stream;
    stream.open(filename);
    getline(stream, raw_data);
    int l_len = raw_data.length();
    while(l_len > 0) {
        boost::tokenizer<> tok(raw_data);
        iter = tok.begin();
        for(int i = 0; i < N; i++) {
            data[cnt] = boost::lexical_cast<int>(*iter);
            iter++;
            cnt++;
        }
        getline(stream, raw_data);
        l_len = raw_data.length();
    }
    stream.close();
    *param = data;
    return 0;
}
