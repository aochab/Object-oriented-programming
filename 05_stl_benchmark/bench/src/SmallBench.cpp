#include "Small.h"
#include "BenchIncludes.h"

static void comparisonTimeSmall(State& state) {

    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();
    for (auto _ : state) {

        small1<small2;
    }
}

BENCHMARK(comparisonTimeSmall);

static void equalityTimeSmall(State& state) {

    Small small1{};
    Small small2{};
    small1.randomize();
    small2.randomize();
    for (auto _ : state) {

        small1==small2;
    }
}

BENCHMARK(equalityTimeSmall);

static void hashTimeSmall(State& state)
{
    Small small{};
    small.randomize();
    for(auto _ : state) {

        std::hash<Small>{}(small);
    }
}

BENCHMARK(hashTimeSmall);
