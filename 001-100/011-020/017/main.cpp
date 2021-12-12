
#include "main.hpp"

int main() {
	std::string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	std::string tens[10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	std::string hundred = "hundred";
	std::string thousand = "thousand";
	std::string word_and = "and";
	uint32_t total = 0;
	for(uint32_t i = 0; i < 10; i++) {
		for(uint32_t j = 0; j < 10; j++) {
			for(uint32_t k = 0; k < 10; k++) {
				if((i + j + k) == 0) {
					continue;
				}
				if(i > 0) {
					total += digits[i - 1].length();
					total += hundred.length();
					if((j + k) > 0) {
						total += word_and.length();
					}
				}
				if(j == 1) {
					total += teens[k].length();
				} else {
					if(j > 1) {
						total += tens[j - 2].length();
					}
					if(k > 0) {
						total += digits[k - 1].length();
					}
				}
			}
		}
	}
	total += digits[0].length();
	total += thousand.length();
	std::cout << total << std::endl;
	return 0;
}
