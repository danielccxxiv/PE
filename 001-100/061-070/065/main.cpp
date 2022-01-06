
#include "main.hpp"

#include <benchmark/benchmark.h>

#include <random>
#include <ctime>
#include <cmath>
#include <iomanip>

#include <boost/lexical_cast.hpp>

unsigned rand256() {
    static unsigned const limit = RAND_MAX - RAND_MAX % 256;
    unsigned result = rand();
    while (result >= limit) {
        result = rand();
    }
    return result % 256;
}

unsigned long long rand64bits() {
    unsigned long long results = 0ULL;
    for ( int count = 8; count > 0; -- count ) {
        results = 256U * results + rand256();
    }
    return results;
}

// static void sqrt_1(benchmark::State& state) {
//     std::uint8_t j = 0;
//     uint128_t arr[256];
//     uint128_t num;
//     for(int32_t i = 0; i < 256; i++) {
//         arr[i] =
//             (static_cast<uint128_t>(rand64bits()) << 448) + (static_cast<uint128_t>(rand64bits()) << 384) +
//             (static_cast<uint128_t>(rand64bits()) << 320) + (static_cast<uint128_t>(rand64bits()) << 256) +
//             (static_cast<uint128_t>(rand64bits()) << 192) + (static_cast<uint128_t>(rand64bits()) << 128) +
//             (static_cast<uint128_t>(rand64bits()) << 64) + rand64bits();
//     }
//     for(auto _: state) {
//         num = int_sqrt<uint128_t>(arr[j++]);
//         benchmark::DoNotOptimize(num);
//     }
// }
//
// BENCHMARK(sqrt_1);
//
// static void sqrt_2(benchmark::State& state) {
//     std::uint8_t j = 0;
//     uint128_t arr[256];
//     uint128_t num;
//     for(int32_t i = 0; i < 256; i++) {
//         arr[i] =
//             (static_cast<uint128_t>(rand64bits()) << 448) + (static_cast<uint128_t>(rand64bits()) << 384) +
//             (static_cast<uint128_t>(rand64bits()) << 320) + (static_cast<uint128_t>(rand64bits()) << 256) +
//             (static_cast<uint128_t>(rand64bits()) << 192) + (static_cast<uint128_t>(rand64bits()) << 128) +
//             (static_cast<uint128_t>(rand64bits()) << 64) + rand64bits();
//     }
//     for(auto _: state) {
//         num = int_sqrt<uint128_t, uint128_t, uint256_t, true, true, false>(arr[j++]);
//         benchmark::DoNotOptimize(num);
//     }
// }
//
// BENCHMARK(sqrt_2);
//
// BENCHMARK_MAIN();

// static void BM_int_sqrt(benchmark::State& state) {
//     std::uint8_t y = 0;
//     uint64_t num;
//     uint64_t arr[256];
//     for(int32_t i = 0; i < 256; i++) {
//         arr[i] = rand64bits();
//     }
//     for (auto _ : state) {
//         num = uint64_sqrt(arr[y++]);
//         benchmark::DoNotOptimize(num);
//         // for(int32_t i = 0; i < 256; i++) {
//         //     num = uint64_sqrt(arr[i]);
//         //     benchmark::DoNotOptimize(num);
//         // }
//     }
// }
//
// BENCHMARK(BM_int_sqrt);
//
// BENCHMARK_MAIN();

// int main() {
//     // uint64_t f = (static_cast<uint64_t>(1) << 53);
//     // std::cout << f << std::endl << isqrt_64_clz(f) << std::endl;
//
//     // static constexpr uint64_t limit = static_cast<uint64_t>(1) << 27;
//     for(uint64_t i = ((static_cast<uint64_t>(1) << 52) - 5000); i < (static_cast<uint64_t>(1) << 52); i++) {
//         if(std::sqrt(static_cast<double>(i)) == std::sqrt(static_cast<double>(i + 1))) {
//             std::cout << i << std::endl;
//         }
//     }
//
//     // std::cout << std::setprecision(100) << std::sqrt(static_cast<long double>(std::numeric_limits<uint64_t>::max())) << std::endl;
//     // std::cout << std::setprecision(100) << std::sqrt(static_cast<long double>(std::numeric_limits<uint64_t>::max() - 1)) << std::endl;
//     // for(uint64_t i = 1; i < limit; i++) {
//     //     if(static_cast<uint64_t>(std::sqrt(static_cast<double>((i * i) - 1))) >= i) {
//     //         std::cout << i << "\t" << i * i << std::endl;
//     //         std::cout << std::setprecision(100) << std::sqrt(static_cast<double>((i * i) - 3)) << std::endl;
//     //         std::cout << static_cast<double>((i * i) - 1) << std::endl;
//     //         break;
//     //     }
//     // }
//
//
//
//     // uint32_t sq;
//     // uint32_t t;
//     // for(uint32_t i = 0; i <= std::numeric_limits<uint32_t>::max(); i++) {
//     //     sq = (uint32_t) std::sqrt((double) i);
//     //     t = sq * sq;
//     //     if((t > i) || ((i - t) > (sq << 1))) {
//     //         std::cout << i << "\t" << sq << std::endl;
//     //     }
//     //     if(!(i << 8)) {
//     //         std::cout << i << std::endl;
//     //     }
//     // }
// }

// int main() {
//     uint64_t sq;
//     for(int32_t i = 0; i < 100; i++) {
//         sq = uint64_sqrt(rand64bits());
//         if(sq == 0) {
//             std::cout << std::endl;
//         }
//     }
//     // uint256_t sq;
//     // for(int64_t i = 0; i < 100; i++) {
//     //     sq = uint256_t((static_cast<uint256_t>(rand64bits()) << 192) + (static_cast<uint256_t>(rand64bits()) << 128)
//     //         + (static_cast<uint256_t>(rand64bits()) << 64) + rand64bits());
//     //     if(int_sqrt<uint256_t, uint256_t, uint512_t>(sq) == 0) {
//     //         std::cout << std::endl;
//     //     }
//     // }
//     return 0;
// }

int main() {
    int32_t u;
    double x;
    std::cout << std::setprecision(100);
    for(uint64_t i = 1; i < 20; i++) {
        // std::cout << (std::numeric_limits<uint64_t>::max() - (i - 1)) << std::endl;
        x = std::sqrt((((std::numeric_limits<uint64_t>::max() >> 1) - (i - 1)) >> 12) << 12);
        std::cout << std::frexp(x * x, &u) << std::endl;
        // std::cout << std::frexp(((std::numeric_limits<uint64_t>::max() - (i - 1)) >> 13) << 13, &u) << std::endl;
        // std::cout << std::frexp(((static_cast<uint64_t>(1) << 53) - i), &u) << std::endl;
        // std::cout << std::sqrt(((static_cast<uint64_t>(1) << 51) - i)) << std::endl;
    }

    // std::cout << std::sqrt(((static_cast<uint64_t>(1) << 52) - 2) << 11) << std::endl;
    // std::cout << std::sqrt(((static_cast<uint64_t>(1) << 52) - 3) << 11) << std::endl;
    // std::cout << std::sqrt(((static_cast<uint64_t>(1) << 52) - 4) << 11) << std::endl;
    return 0;
}






















//
