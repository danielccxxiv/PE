
#ifndef DIGIT_LIST_HPP
#define DIGIT_LIST_HPP

#include <queue>
#include <stdexcept>

template<class T> struct digit_list {
	int* list;
	T num;
	int len;
    int base;

	digit_list(T val) {
        this->num = val;
        this->len = 0;
        this->base = 10;
		std::queue<int> col;
        if(val < 0) {
            val = -val;
        }
        while(val != 0) {
            col.push(val % 10);
            val /= 10;
            (this->len)++;
        }
        if(this->len > 0) {
            this->list = new int[this->len];
            for(int i = 0; i < (this->len); i++) {
                this->list[i] = col.front();
                col.pop();
            }
        } else {
            this->list = NULL;
        }
	}

    // Throws exception if base less than 2
    digit_list(T val, int base) {
        if(base < 2) {
            throw std::invalid_argument("digit_list: base less than 2");
        }
        this->num = val;
        this->len = 0;
        this->base = base;
		std::queue<int> col;
        if(val < 0) {
            val = -val;
        }
        while(val != 0) {
            col.push(val % base);
            val /= base;
            (this->len)++;
        }
        if(this->len != 0) {
            this->list = new int[this->len];
            for(int i = 0; i < (this->len); i++) {
                this->list[i] = col.front();
                col.pop();
            }
        } else {
            this->list = NULL;
        }
	}

	virtual ~digit_list() {
        if(this->list != NULL) {
            delete[] list;
        }
	}
};

#endif
