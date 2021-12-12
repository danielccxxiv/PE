
#include "main.hpp"

int main() {
    boost::container::set<std::string> data;
    read_file("names.txt", &data);
    uint32_t pos = 0;
    uint32_t sum = 0;
    for(std::string t: data) {
        pos++;
        for(char c: t) {
            sum += (((uint32_t) c - 64) * pos);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

void read_file(std::string filename, boost::container::set<std::string>* param) {
    boost::filesystem::ifstream stream;
    stream.open(filename);
    std::string raw_data;
    getline(stream, raw_data);
    boost::tokenizer<> tok(raw_data);
    for(std::string t: tok) {
        (*param).insert(t);
    }
    stream.close();
    return;
}
