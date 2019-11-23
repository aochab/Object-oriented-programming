#include "Large.h"
#include "BenchIncludes.h"

static void comparisonTimeLarge(State& state) {

    Large large1{};
    Large large2{};
    large1.randomize();
    large2.randomize();
    for (auto _ : state) {

        large1 < large2;
    }
}

BENCHMARK(comparisonTimeLarge);

static void equalityTimeLarge(State& state) {

    Large large1{};
    Large large2{};
    large1.randomize();
    large2.randomize();
    for (auto _ : state) {

        large1 == large2;
    }
}

BENCHMARK(equalityTimeLarge);

static void hashTimeLarge(State& state)
{
    Large large{};
    large.randomize();
    for(auto _ : state) {

        std::hash<Large>{}(large);
    }
}

BENCHMARK(hashTimeLarge);

