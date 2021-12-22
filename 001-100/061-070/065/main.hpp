
#ifndef MAIN_HPP
#define MAIN_HPP

#include "../../../Headers/std_integer_numeric_types.hpp"
#include "../../../Headers/boost_integer_numeric_types.hpp"
#include "../../../Headers/boost_integer_numeric_types_macros.hpp"
#include <iostream>

#include <limits>
#include <type_traits>

#include <boost/integer.hpp>

template<class T> bool fixed_precision_test(int junk) {
    return std::numeric_limits<T>::is_bounded;
}


// TYPEDEF_BOOST_UINT(2048, uint2048_t);

#endif
