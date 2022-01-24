
#ifndef POW_INT_HPP
#define POW_INT_HPP

#include <cstdint>
#include <cstdlib>
#include <limits>
#include <type_traits>

#include <boost/multiprecision/cpp_int.hpp>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;
typedef boost::multiprecision::uint128_t uint128_t;

template<class B, class P> B pow_int(const B& b, const P& p) {
    static_assert(std::numeric_limits<B>::is_integer);
    static_assert(std::numeric_limits<P>::is_integer);
    if(std::numeric_limits<P>::is_signed) {
        if(p < static_cast<P>(0)) {
            throw "pow_int<B, P>(B b, P p): negative value of p";
        }
    }
    B b_cast = b;
    P p_cast = p;
    B r = static_cast<B>(1);
    while(p_cast != static_cast<P>(0)) {
        while((p_cast & static_cast<P>(1)) == static_cast<P>(0)) {
            b_cast *= b_cast;
            p_cast >>= 1;
        }
        r *= b_cast;
        p_cast--;
    }
    return r;
}

template<class B, class P, class C> inline B powm_detail(const B& b, P& p_cast, const B& m) {
    static_assert(std::numeric_limits<B>::is_integer);
    static_assert(std::numeric_limits<P>::is_integer);
    static_assert(std::numeric_limits<C>::is_integer);
    static_assert(!(std::numeric_limits<C>::is_signed));
    C m_cast = static_cast<C>(m);
    C b_cast = static_cast<C>(std::abs(b)) % m_cast;
    C r = static_cast<C>(1);
    while(p != static_cast<P>(0)) {
        while((p & static_cast<P>(1)) == static_cast<P>(0)) {
            b_cast = (b_cast * b_cast) % m_cast;
            p >>= 1;
        }
        r = (r * b_cast) % m_cast;
        p--;
    }
    return r;
}

template<class B, class P> powm(const B& b, const P& p, const B& m) {
    static_assert(std::numeric_limits<B>::is_integer);
    static_assert(std::numeric_limits<P>::is_integer);
    static constexpr int32_t int32_wide_check = (static_cast<int32_t>(1) << 16) + static_cast<int32_t>(1);
    static constexpr uint32_t uint32_wide_check = (static_cast<uint32_t>(1) << 16) + static_cast<uint32_t>(1);
    static constexpr int64_t int64_wide_check = (static_cast<int64_t>(1) << 32) + static_cast<int64_t>(1);
    static constexpr uint32_t uint64_wide_check = (static_cast<uint64_t>(1) << 32) + static_cast<uint64_t>(1);
    static constexpr bool B_is_int32 = std::is_same<B, int32_t>::value;
    static constexpr bool B_is_uint32 = std::is_same<B, uint32_t>::value;
    static constexpr bool B_is_int64 = std::is_same<B, int64_t>::value;
    static constexpr bool B_is_uint64 = std::is_same<B, uint64_t>::value;
    if(!(B_is_int32) && !(B_is_uint32) && !(B_is_int64) && !(B_is_uint64)) {
        return boost::multiprecision::powm(b, p, m);
    }
    if(std::numeric_limits<P>::is_signed) {
        if(p < static_cast<P>(0)) {
            throw "powm<B, P>(B b, P p, B m): negative value of p";
        }
    }
    if(m < static_cast<B>(1)) {
        throw "powm<B, P>(B b, P p, B m): m less than 1";
    }
    P p_cast = p;
    if(B_is_int32) {
        if(m < int32_wide_check) {
            return static_cast<int32_t>(powm_detail<int32_t, P, uint32_t>(b, p_cast, m));
        } else {
            return static_cast<int32_t>(powm_detail<int32_t, P, uint64_t>(b, p_cast, m));
        }
    } else if(B_is_uint32) {
        if(m < uint32_wide_check) {
            return static_cast<uint32_t>(powm_detail<uint32_t, P, uint32_t>(b, p_cast, m));
        } else {
            return static_cast<uint32_t>(powm_detail<uint32_t, P, uint64_t>(b, p_cast, m));
        }
    } else if(B_is_int64) {
        if(m < int64_wide_check) {
            return static_cast<int64_t>(powm_detail<int64_t, P, uint64_t>(b, p_cast, m));
        } else {
            return static_cast<int64_t>(powm_detail<int64_t, P, uint128_t>(b, p_cast, m));
        }
    } else if(B_is_uint64) {
        if(m < uint64_wide_check) {
            return static_cast<uint64_t>(powm_detail<uint64_t, P, uint64_t>(b, p_cast, m));
        } else {
            return static_cast<uint64_t>(powm_detail<uint64_t, P, uint128_t>(b, p_cast, m));
        }
    } else {
        throw "powm<B, P>(B b, P p, B m): unexpected error";
    }
}

#endif
