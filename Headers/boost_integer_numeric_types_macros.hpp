
#ifndef BOOST_INTEGER_NUMERIC_TYPES_EXTENDED_HPP
#define BOOST_INTEGER_NUMERIC_TYPES_EXTENDED_HPP

#include <boost/multiprecision/cpp_int.hpp>

#ifndef TYPEDEF_BOOST_INT(bit_count, name)
#define TYPEDEF_BOOST_INT(bit_count, name) typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<bit_count, bit_count, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void>> name;
#endif

#ifndef TYPEDEF_BOOST_UINT(bit_count, name)
#define TYPEDEF_BOOST_UINT(bit_count, name) typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<bit_count, bit_count, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>> name;
#endif

#endif
