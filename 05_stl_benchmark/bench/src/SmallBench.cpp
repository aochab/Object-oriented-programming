#include "Small.h"
#include "BenchIncludes.h"

static void comparisonTimeSmall(State& state) {

    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();
    for (auto _ : state) {

        auto comparison = small1<small2;

        DoNotOptimize(comparison);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(comparisonTimeSmall)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void equalityTimeSmall(State& state) {

    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();
    for (auto _ : state) {

        auto equality = small1==small2;

        DoNotOptimize(equality);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(equalityTimeSmall)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();

static void hashTimeSmall(State& state)
{
    Small small{};
    small.randomize();
    for(auto _ : state) {
        auto hash = std::hash<Small>{}(small);

        DoNotOptimize(hash);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(hashTimeSmall)->RangeMultiplier(2)->Range(1 << 5, 1 << 18)->Complexity();
