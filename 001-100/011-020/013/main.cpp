
#include "main.hpp"

int main(int argc, char** argv) {
	int256_t* data;
	int256_t sum = 0;
	read_file("data.txt", &data);
	for(int i = 0; i < N; i++) {
		sum += data[i];
	}
    int256_t cutoff = pow<int256_t>(10, 10);
	while(sum >= cutoff) {
        sum /= 10;
    }
	std::cout << sum << std::endl;
	return 0;
}

int read_file(std::string filename, int256_t** param) {
	char* temp;
	int256_t* data = new int256_t[N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	char* raw_data = new char[N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			raw_data[j] = 0;
		}
		stream.getline(raw_data, N);
		data[i] = boost::lexical_cast<int256_t>(raw_data);
	}
	stream.close();
	*param = data;
	return 0;
}
