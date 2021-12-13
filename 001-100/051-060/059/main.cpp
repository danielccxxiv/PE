
#include "main.hpp"

int main() {
    std::vector<int> data;
    read_file("cipher.txt", data);
    int32_t* key_arr = new int32_t[3];
    key_arr[0] = (int32_t) 'e';
    key_arr[1] = (int32_t) 'x';
    key_arr[2] = (int32_t) 'p';
    int32_t ascii_sum = 0;
    for(size_t i = 0; i < data.size(); i++) {
        data[i] ^= key_arr[i % 3];
        ascii_sum += data[i];
    }
    std::cout << ascii_sum << std::endl;
	return 0;
}

void read_file(std::string filename, std::vector<int32_t>& data) {
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
    boost::tokenizer<boost::char_separator<char>>::iterator iter;
    boost::char_separator<char> sep(",");
	getline(stream, raw_data);
	boost::tokenizer<boost::char_separator<char>> tok(raw_data, sep);
    iter = tok.begin();
	while(iter != tok.end()) {
        data.push_back(boost::lexical_cast<int32_t>(*iter));
        iter++;
    }
	stream.close();
	return;
}
