
#ifndef DIGIT_LIST_HPP
#define DIGIT_LIST_HPP

#include <cstddef>
#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef std::size_t size_t;

#include <queue>

// Well defined only for non-negative num and base > 1
template<class T, class B> struct digit_list {
    T num;
    B base;
    B* list;
	size_t len;

	digit_list(T num, B base = 10) {
        this->num = num;
        this->base = base;
        this->len = 0;
		std::queue<B> col;
        while(num != 0) {
            col.push(num % base);
            num /= base;
            (this->len)++;
        }
        if(this->len > 0) {
            this->list = new B[this->len];
            for(size_t i = 0; i < (this->len); i++) {
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
