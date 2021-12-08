
#include "main.hpp"

int main(int argc, char** argv) {
    int* data;
    read_file("poker.txt", &data);
    int count = 0;
    omp::HandEvaluator eval;
    omp::Hand h0;
    omp::Hand h1;
    for(int i = 0; i < N; i++) {
        h0 = omp::Hand::empty();
        h1 = omp::Hand::empty();
        for(int j = 0; j < 5; j++) {
            h0 += omp::Hand(data[10 * i + j]);
            h1 += omp::Hand(data[10 * i + j + 5]);
        }
        if(eval.evaluate(h0) > eval.evaluate(h1)) {
            count++;
        }
    }
    std::cout << count << std::endl;
	return 0;
}

int read_file(std::string filename, int** param) {
	int* data = new int[10 * N];
	boost::filesystem::ifstream stream;
	stream.open(filename);
	std::string raw_data;
    std::string card_data;
    char num;
    char suit;
    int card_val;
    boost::tokenizer<>::iterator tok_iter;
	for(int i = 0; i < N; i++) {
		getline(stream, raw_data);
		boost::tokenizer<> tok(raw_data);
        tok_iter = tok.begin();
		for(int j = 0; j < 10; j++) {
			card_data = *tok_iter;
            num = card_data.at(0);
            suit = card_data.at(1);
            if(num == '2') {
                card_val = 0;
            } else if(num == '3') {
                card_val = 4;
            } else if(num == '4') {
                card_val = 8;
            } else if(num == '5') {
                card_val = 12;
            } else if(num =='6') {
                card_val = 16;
            } else if(num == '7') {
                card_val = 20;
            } else if(num == '8') {
                card_val = 24;
            } else if(num == '9') {
                card_val = 28;
            } else if(num == 'T') {
                card_val = 32;
            } else if(num == 'J') {
                card_val = 36;
            } else if(num == 'Q') {
                card_val = 40;
            } else if(num == 'K') {
                card_val = 44;
            } else if(num == 'A') {
                card_val = 48;
            } else {
                throw "invalid card number";
            }
            if(suit == 'S') {
                card_val += 0;
            } else if(suit == 'H') {
                card_val += 1;
            } else if(suit == 'C') {
                card_val += 2;
            } else if(suit == 'D') {
                card_val += 3;
            } else {
                throw "invalid card suit";
            }
            data[10 * i + j] = card_val;
			tok_iter++;
		}
	}
	stream.close();
	*param = data;
	return 0;
}
