
#include "main.hpp"

#include <benchmark/benchmark.h>

#include <random>
#include <ctime>

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

static void BM_int_sqrt(benchmark::State& state) {
    uint64_t num;
    uint64_t arr[256];
    for(int32_t i = 0; i < 256; i++) {
        arr[i] = rand64bits();
    }
    for (auto _ : state) {
        for(int32_t i = 0; i < 256; i++) {
            num = uint64_sqrt(arr[i]);
            benchmark::DoNotOptimize(num);
        }
    }
}

BENCHMARK(BM_int_sqrt);

static void BM_int_sqrt_alt(benchmark::State& state) {
    uint64_t num;
    uint64_t arr[256];
    for(int32_t i = 0; i < 256; i++) {
        arr[i] = rand64bits();
    }
    for (auto _ : state) {
        for(int32_t i = 0; i < 256; i++) {
            num = uint64_sqrt2(arr[i]);
            benchmark::DoNotOptimize(num);
        }
    }
}

BENCHMARK(BM_int_sqrt_alt);

BENCHMARK_MAIN();

// int main() {
//     std::cout << uint64_sqrt(13931850471406165487ULL) << std::endl;
//     return 0;
// }
























//
