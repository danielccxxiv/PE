
#include "main.hpp"

int main() {
	double target = 1.0 / 2;
	int64_t count = 0;
	for(int32_t i = 0; i < reciprocal_list.size(); i++) {
		element_list.push_back(1.0 / (reciprocal_list[i] * reciprocal_list[i]));
		sum_list.push_back(0);
		for(int32_t j = 0; j < sum_list.size(); j++) {
			sum_list[j] += element_list[i];
		}
		bl.push_back(false);
	}
	for(int32_t i = 0; i < element_list.size(); i++) {
		std::cout << element_list[i] << "\t" << sum_list[i] << std::endl;
	}
	loop(target, 0, count);
	std::cout << count << std::endl;
	return 0;
}

void loop(int256_t target, int32_t level, int64_t& count) {
	if(target == 0) {
		for(int32_t i = 0; i < element_list.size(); i++) {
			if(bl[i]) {
				//std::cout << reciprocal_list[i] << "\t";
			}
		}
		//std::cout << std::endl;
		count++;
		return;
	}
	if(level == element_list.size()) {
		return;
	}
	if(target > sum_list[level]) {
		//std::cout << target << "\t" << sum_list[level] << std::endl;
		return;
	}
	if(target >= element_list[level]) {
		bl[level] = true;
		loop(target - element_list[level], level + 1, count);
		bl[level] = false;
	}
	loop(target, level + 1, count);
}






















//
