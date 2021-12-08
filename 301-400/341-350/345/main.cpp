
#include "main.hpp"

int main(int argc, char** argv) {
	uint i, j, lim;
	int num;
	int* data;
	read_file("data.txt", &data);
	uint* pwrs = new uint[N];
	pwrs[0] = 1;
	for(i = 1; i < N; i++) {
		pwrs[i] = pwrs[i - 1] * 2;
	}
	lim = 2 * pwrs[i - 1];
	int* arr = new int[lim];
	for(i = 0; i < lim; i++) {
		arr[i] = 0;
		num = bit_count(i);
		for(j = 0; j < N; j++) {
			if((i ^ pwrs[j]) < i) {
				arr[i] = max(arr[i], arr[i ^ pwrs[j]] + data[N * j + num - 1]);
			}
		}
	}
	cout << arr[lim - 1] << endl;
	return 0;
}

int read_file(char* filename, int** param) {
	int i, j;
	char* temp;
	int* data = new int[N * N];
	ifstream stream;
	stream.open(filename);
	char* raw_data = new char[100];
	for(i = 0; i < N; i++) {
		for(j = 0; j < 100; j++) {
			raw_data[i] = '\0';
		}
		stream.getline(raw_data, 100);
		temp = strtok(raw_data, " \n");
		for(j = 0; j < N; j++) {
			data[N * i + j] = lexical_cast<int>(temp);
			temp = strtok(NULL, " \n");
		}
	}
	stream.close();
	*param = data;
	return 0;
}
