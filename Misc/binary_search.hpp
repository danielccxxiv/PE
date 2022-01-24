
#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>

// search in range [start, start + len), not [start, start + len]
// if negative result, value would be in position -n - 1
template<class T> int binary_search(const T* arr, const T& val, int start, int len) {
    int end = start + len - 1;
	int mid;
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
template<class T> int binary_search(const std::vector<T>& arr, const T& val, int start, int len) {
    int end = start + len - 1;
	int mid;
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
