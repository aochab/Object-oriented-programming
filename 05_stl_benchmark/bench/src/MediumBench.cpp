#include "Medium.h"
#include "BenchIncludes.h"

static void comparisonTimeMedium(State& state) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    medium2.randomize();
    for (auto _ : state) {

        auto comparison = medium1 < medium2;

        DoNotOptimize(comparison);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(comparisonTimeMedium)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void equalityTimeMedium(State& state) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    medium2.randomize();
    for (auto _ : state) {

        auto equality = medium1 == medium2;

        DoNotOptimize(equality);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(equalityTimeMedium)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void hashTimeMedium(State& state)
{
    Medium medium{};
    medium.randomize();
    for(auto _ : state) {
        auto hash = std::hash<Medium>{}(medium);

        DoNotOptimize(hash);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(hashTimeMedium)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

