
#ifndef BIT_COUNT_HPP
#define BIT_COUNT_HPP

template<class T> int bit_count(T num) {
	int count = 0;
	while(num != 0) {
		num &= (num - 1);
		count++;
	}
	return count;
}

#endif
