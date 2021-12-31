
#include "main.hpp"

// #include <benchmark/benchmark.h>

#include <random>
#include <ctime>

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

int main() {
    uint256_t sq;
    for(int64_t i = 0; i < 100; i++) {
        sq = uint256_t((static_cast<uint256_t>(rand64bits()) << 192) + (static_cast<uint256_t>(rand64bits()) << 128)
            + (static_cast<uint256_t>(rand64bits()) << 64) + rand64bits());
        if(int_sqrt<uint256_t, uint256_t, uint512_t>(sq) == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}
























//
