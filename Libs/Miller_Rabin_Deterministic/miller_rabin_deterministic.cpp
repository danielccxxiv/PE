
#include "miller_rabin_deterministic.hpp"

#include <cstdint>
#include <cstring>

#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>

typedef std::int32_t int32_t;
typedef std::uint32_t uint32_t;
typedef std::int64_t int64_t;
typedef std::uint64_t uint64_t;

typedef boost::multiprecision::int128_t int128_t;
typedef boost::multiprecision::uint128_t uint128_t;
typedef boost::multiprecision::int256_t int256_t;
typedef boost::multiprecision::uint256_t uint256_t;
typedef boost::multiprecision::int512_t int512_t;
typedef boost::multiprecision::uint512_t uint512_t;
typedef boost::multiprecision::int1024_t int1024_t;
typedef boost::multiprecision::uint1024_t uint1024_t;
typedef boost::multiprecision::cpp_int cpp_int;

static const int32_t int32_0 = static_cast<int32_t>(0);
static const int64_t int64_0 = static_cast<int64_t>(0);
static const int128_t int128_0 = static_cast<int128_t>(0);
static const int256_t int256_0 = static_cast<int256_t>(0);
static const int512_t int512_0 = static_cast<int512_t>(0);
static const int1024_t int1024_0 = static_cast<int1024_t>(0);
static const cpp_int cpp_int_0 = static_cast<cpp_int>(0);

static const int64_t int64_32_bit_limit = static_cast<int64_t>(1) << 32;
static const uint64_t uint64_32_bit_limit = static_cast<uint64_t>(1) << 32;
static const int128_t int128_32_bit_limit = static_cast<int128_t>(1) << 32;
static const uint128_t uint128_32_bit_limit = static_cast<uint128_t>(1) << 32;
static const int256_t int256_32_bit_limit = static_cast<int256_t>(1) << 32;
static const uint256_t uint256_32_bit_limit = static_cast<uint256_t>(1) << 32;
static const int512_t int512_32_bit_limit = static_cast<int512_t>(1) << 32;
static const uint512_t uint512_32_bit_limit = static_cast<uint512_t>(1) << 32;
static const int1024_t int1024_32_bit_limit = static_cast<int1024_t>(1) << 32;
static const uint1024_t uint1024_32_bit_limit = static_cast<uint1024_t>(1) << 32;
static const cpp_int cpp_int_32_bit_limit = static_cast<cpp_int>(1) << 32;

static const int128_t int128_64_bit_limit = static_cast<int128_t>(1) << 64;
static const uint128_t uint128_64_bit_limit = static_cast<uint128_t>(1) << 64;
static const int256_t int256_64_bit_limit = static_cast<int256_t>(1) << 64;
static const uint256_t uint256_64_bit_limit = static_cast<uint256_t>(1) << 64;
static const int512_t int512_64_bit_limit = static_cast<int512_t>(1) << 64;
static const uint512_t uint512_64_bit_limit = static_cast<uint512_t>(1) << 64;
static const int1024_t int1024_64_bit_limit = static_cast<int1024_t>(1) << 64;
static const uint1024_t uint1024_64_bit_limit = static_cast<uint1024_t>(1) << 64;
static const cpp_int cpp_int_64_bit_limit = static_cast<cpp_int>(1) << 64;

static const int256_t int256_128_bit_limit = static_cast<int256_t>(1) << 128;
static const uint256_t uint256_128_bit_limit = static_cast<uint256_t>(1) << 128;
static const int512_t int512_128_bit_limit = static_cast<int512_t>(1) << 128;
static const uint512_t uint512_128_bit_limit = static_cast<uint512_t>(1) << 128;
static const int1024_t int1024_128_bit_limit = static_cast<int1024_t>(1) << 128;
static const uint1024_t uint1024_128_bit_limit = static_cast<uint1024_t>(1) << 128;
static const cpp_int cpp_int_128_bit_limit = static_cast<cpp_int>(1) << 128;

static const int512_t int512_256_bit_limit = static_cast<int512_t>(1) << 256;
static const uint512_t uint512_256_bit_limit = static_cast<uint512_t>(1) << 256;
static const int1024_t int1024_256_bit_limit = static_cast<int1024_t>(1) << 256;
static const uint1024_t uint1024_256_bit_limit = static_cast<uint1024_t>(1) << 256;
static const cpp_int cpp_int_256_bit_limit = static_cast<cpp_int>(1) << 256;

static const int1024_t int1024_512_bit_limit = static_cast<int1024_t>(1) << 512;
static const uint1024_t uint1024_512_bit_limit = static_cast<uint1024_t>(1) << 512;
static const cpp_int cpp_int_512_bit_limit = static_cast<cpp_int>(1) << 512;

static const cpp_int cpp_int_1024_bit_limit = static_cast<cpp_int>(1) << 1024;

bool miller_rabin_det_32_bit(uint32_t num);
bool miller_rabin_det_64_bit(uint64_t num);
bool miller_rabin_det_128_bit(uint128_t num);
bool miller_rabin_det_256_bit(uint256_t num);
bool miller_rabin_det_512_bit(uint512_t num);
bool miller_rabin_det_1024_bit(uint1024_t num);
bool miller_rabin_det_cpp_int(cpp_int num);

template<> bool miller_rabin_det<int32_t>(int32_t num) {
    if(num < int32_0) {
        std::string exception_text =
            "miller_rabin_det<int32_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
}

template<> bool miller_rabin_det<uint32_t>(uint32_t num) {
    return miller_rabin_det_32_bit(num);
}

template<> bool miller_rabin_det<int64_t>(int64_t num) {
    if(num < int64_0) {
        std::string exception_text =
            "miller_rabin_det<int64_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < int64_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
}

template<> bool miller_rabin_det<uint64_t>(uint64_t num) {
    if(num < uint64_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    return miller_rabin_det_64_bit(num);
}

template<> bool miller_rabin_det<int128_t>(int128_t num) {
    if(num < int128_0) {
        std::string exception_text =
            "miller_rabin_det<int128_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < int128_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < int128_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
}

template<> bool miller_rabin_det<uint128_t>(uint128_t num) {
    if(num < uint128_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < uint128_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    return miller_rabin_det_128_bit(num);
}

template<> bool miller_rabin_det<int256_t>(int256_t num) {
    if(num < int256_0) {
        std::string exception_text =
            "miller_rabin_det<int256_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < int256_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < int256_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < int256_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
}

template<> bool miller_rabin_det<uint256_t>(uint256_t num) {
    if(num < uint256_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < uint256_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < uint256_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    return miller_rabin_det_256_bit(num);
}

template<> bool miller_rabin_det<int512_t>(int512_t num) {
    if(num < int512_0) {
        std::string exception_text =
            "miller_rabin_det<int512_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < int512_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < int512_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < int512_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    if(num < int512_256_bit_limit) {
        return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
    }
    return miller_rabin_det_512_bit(static_cast<uint512_t>(num));
}

template<> bool miller_rabin_det<uint512_t>(uint512_t num) {
    if(num < uint512_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < uint512_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < uint512_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    if(num < uint512_256_bit_limit) {
        return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
    }
    return miller_rabin_det_512_bit(num);
}

template<> bool miller_rabin_det<int1024_t>(int1024_t num) {
    if(num < int1024_0) {
        std::string exception_text =
            "miller_rabin_det<int1024_t>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < int1024_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < int1024_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < int1024_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    if(num < int1024_256_bit_limit) {
        return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
    }
    if(num < int1024_512_bit_limit) {
        return miller_rabin_det_512_bit(static_cast<uint512_t>(num));
    }
    return miller_rabin_det_1024_bit(static_cast<uint1024_t>(num));
}

template<> bool miller_rabin_det<uint1024_t>(uint1024_t num) {
    if(num < uint1024_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < uint1024_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < uint1024_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    if(num < uint1024_256_bit_limit) {
        return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
    }
    if(num < uint1024_512_bit_limit) {
        return miller_rabin_det_512_bit(static_cast<uint512_t>(num));
    }
    return miller_rabin_det_1024_bit(num);
}

template<> bool miller_rabin_det<cpp_int>(cpp_int num) {
    if(num < cpp_int_0) {
        std::string exception_text =
            "miller_rabin_det<cpp_int>: negative input (num = " + boost::lexical_cast<std::string>(num) + ")";
        throw exception_text;
    }
    if(num < cpp_int_32_bit_limit) {
        return miller_rabin_det_32_bit(static_cast<uint32_t>(num));
    }
    if(num < cpp_int_64_bit_limit) {
        return miller_rabin_det_64_bit(static_cast<uint64_t>(num));
    }
    if(num < cpp_int_128_bit_limit) {
        return miller_rabin_det_128_bit(static_cast<uint128_t>(num));
    }
    if(num < cpp_int_256_bit_limit) {
        return miller_rabin_det_256_bit(static_cast<uint256_t>(num));
    }
    if(num < cpp_int_512_bit_limit) {
        return miller_rabin_det_512_bit(static_cast<uint512_t>(num));
    }
    if(num < cpp_int_1024_bit_limit) {
        return miller_rabin_det_1024_bit(static_cast<uint1024_t>(num));
    }
    return miller_rabin_det_cpp_int(num);
}

template<class T> bool miller_rabin_det(T num) {
    return miller_rabin_det<cpp_int>(static_cast<cpp_int>(num));
}
