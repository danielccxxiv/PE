
#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <cstdint>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

#include <vector>

// search in range [start, start + len), not [start, start + len]
// if negative result, value would be in position -n - 1
template<class T> int32_t binary_search(const T* arr, const T& val, int32_t start, int32_t len) {
    int32_t end = start + len - 1;
	int32_t mid;
	while(start <= end) {
		mid = start + (end - start) / 2;
		if(arr[mid] < val) {
			start = mid + 1;
		} else if(arr[mid] > val) {
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -start - 1;
}

// search in range [start, start + len), not [start, start + len]
// if negative result, value would be in position -n - 1
template<class T> int binary_search(const std::vector<T>& arr, const T& val, int32_t start, int32_t len) {
    int32_t end = start + len - 1;
	int32_t mid;
	while(start <= end) {
		mid = start + (end - start) / 2;
		if(arr[mid] < val) {
			start = mid + 1;
		} else if(arr[mid] > val) {
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -start - 1;
}

#endif
