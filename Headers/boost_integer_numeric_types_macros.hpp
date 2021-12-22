
#ifndef BOOST_INTEGER_NUMERIC_TYPES_EXTENDED_HPP
#define BOOST_INTEGER_NUMERIC_TYPES_EXTENDED_HPP

#include <boost/multiprecision/cpp_int.hpp>

#ifndef BOOST_INT
#define BOOST_INT(bit_count) boost::multiprecision::number<boost::multiprecision::cpp_int_backend<bit_count, bit_count, boost::multiprecision::signed_magnitude, boost::multiprecision::unchecked, void>>
#endif

#ifndef BOOST_UINT
#define BOOST_UINT(bit_count) boost::multiprecision::number<boost::multiprecision::cpp_int_backend<bit_count, bit_count, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>
#endif

#endif
