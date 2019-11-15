#include "Large.h"
#include "BenchIncludes.h"

static void comparisonTimeLarge(State& state) {

    Large large1{};
    Large large2{};
    large1.randomize();
    large2.randomize();
    for (auto _ : state) {

        auto comparison = large1 < large2;

        DoNotOptimize(comparison);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(comparisonTimeLarge)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void equalityTimeLarge(State& state) {

    Large large1{};
    Large large2{};
    large1.randomize();
    large2.randomize();
    for (auto _ : state) {

        auto equality = large1 == large2;

        DoNotOptimize(equality);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(equalityTimeLarge)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void hashTimeLarge(State& state)
{
    Large large{};
    large.randomize();
    for(auto _ : state) {
        auto hash = std::hash<Large>{}(large);

        DoNotOptimize(hash);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(hashTimeLarge)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

