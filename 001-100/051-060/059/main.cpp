
#include "main.hpp"

int main(int argc, char** argv) {
    std::vector<int> data;
    read_file("cipher.txt", data);
    int* key_arr = new int[3];
    key_arr[0] = (int) 'e';
    key_arr[1] = (int) 'x';
    key_arr[2] = (int) 'p';
    int ascii_sum = 0;
    for(int i = 0; i < data.size(); i++) {
        data[i] ^= key_arr[i % 3];
        ascii_sum += data[i];
    }
    std::cout << ascii_sum << std::endl;
	return 0;
}

int read_file(std::string filename, std::vector<int>& data) {
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
    boost::tokenizer<boost::char_separator<char>>::iterator iter;
    boost::char_separator<char> sep(",");
	getline(stream, raw_data);
	boost::tokenizer<boost::char_separator<char>> tok(raw_data, sep);
    iter = tok.begin();
	while(iter != tok.end()) {
        data.push_back(boost::lexical_cast<int>(*iter));
        iter++;
    }
	stream.close();
	return 0;
}
