
#include "main.hpp"

int main(int argc, char** argv) {
    boost::container::set<std::string> data;
    read_file("names.txt", &data);
    int pos = 0;
    int sum = 0;
    for(std::string t: data) {
        pos++;
        for(char c: t) {
            sum += (((int) c - 64) * pos);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

int read_file(std::string filename, boost::container::set<std::string>* param) {
    boost::filesystem::ifstream stream;
    stream.open(filename);
    std::string raw_data;
    getline(stream, raw_data);
    boost::tokenizer<> tok(raw_data);
    for(std::string t: tok) {
        (*param).insert(t);
    }
    stream.close();
    return 0;
}
