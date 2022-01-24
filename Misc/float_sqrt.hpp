
#ifndef FLOAT_SQRT_HPP
#define FLOAT_SQRT_HPP

#include <algorithm>

#include <boost/multiprecision/cpp_float.hpp>

template<class T> T float_sqrt(const T& num) {
    return boost::multiprecision::sqrt(num);
}

template<> float float_sqrt<float>(const float& num) {
    return std::sqrt(num);
}

template<> double float_sqrt<double>(const double& num) {
    return std::sqrt(num);
}

template<> long double float_sqrt<long double>(const long double& num) {
    return std::sqrt(num);
}

#endif



































//
