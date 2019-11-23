#include "Medium.h"
#include "BenchIncludes.h"

static void comparisonTimeMedium(State& state) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    medium2.randomize();
    for (auto _ : state) {

        medium1 < medium2;
    }
}

BENCHMARK(comparisonTimeMedium);

static void equalityTimeMedium(State& state) {

    Medium medium1{};
    Medium medium2{};
    medium1.randomize();
    medium2.randomize();
    for (auto _ : state) {

        medium1 == medium2;
    }
}

BENCHMARK(equalityTimeMedium);

static void hashTimeMedium(State& state)
{
    Medium medium{};
    medium.randomize();
    for(auto _ : state) {

        std::hash<Medium>{}(medium);
    }
}

BENCHMARK(hashTimeMedium);

