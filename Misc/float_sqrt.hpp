
#ifndef FLOAT_SQRT_HPP
#define FLOAT_SQRT_HPP

#include <type_traits>

template<class T, class R = T, class C = T, int32_t N = -1, bool SIGN_CHECK = true, bool ITERATION_LIMIT = false> R float_sqrt(const T& num) {
    static constexpr bool C_eq_float = std::is_same<C, float>::value;
    static constexpr bool C_eq_double = std::is_same<C, double>::value;
    static constexpr bool C_eq_long_double = std::is_same<C, long double>::value;
    static constexpr bool T_eq_C = std::is_same<T, C>::value;
    static_assert(std::is_floating_point<R>::value);
    static_assert(std::is_floating_point<C>::value);
    static_assert(((N == (-1)) && (!(ITERATION_LIMIT))) || ((N >= 0) && ITERATION_LIMIT));
    if(SIGN_CHECK && std::numeric_limits<T>::is_signed) {
        if(num < static_cast<T>(0)) {
            assert(false); /////////////////////////////////////////////
        }
    }
    if(T_eq_float) {
        return static_cast<R>(std::sqrt(static_cast<float>(num)));
    } else if(T_eq_double) {
        return static_cast<R>(std::sqrt(static_cast<double>(num)));
    } else if(T_eq_long_double) {
        return static_cast<R>(std::sqrt(static_cast<long double>(num)));
    } else if(!(ITERATION_LIMIT)) {
        int32_t num_exp;
        T num_sqrt = static_cast<T>(std::frexp(num, num_exp));
    }
}

#endif



































//
