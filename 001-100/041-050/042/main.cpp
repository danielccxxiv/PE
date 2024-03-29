
#include "main.hpp"

int main() {
    int32_t count = 0;
    bool* triangle_check = new bool[1000];
    for(int32_t i = 0; i < 1000; i++) {
        triangle_check[i] = false;
    }
    for(int32_t i = 0; i < 1000; i++) {
        if(((i * (i + 1)) / 2) < 1000) {
            triangle_check[(i * (i + 1)) / 2] = true;
        } else {
            break;
        }
    }
    std::vector<std::string> data;
    read_file("words.txt", data);
    int32_t word_sum;
    for(std::string t: data) {
        word_sum = 0;
        for(char c: t) {
            word_sum += ((int32_t) c - 64);
        }
        if(triangle_check[word_sum]) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

void read_file(std::string filename, std::vector<std::string>& data) {
    boost::filesystem::ifstream stream;
    stream.open(filename);
    std::string raw_data;
    getline(stream, raw_data);
    boost::tokenizer<> tok(raw_data);
    for(std::string t: tok) {
        data.push_back(t);
    }
    stream.close();
    return;
}
