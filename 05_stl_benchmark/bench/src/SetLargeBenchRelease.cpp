#include "Large.h"
#include "BenchIncludes.h"
#include <vector>

static void EmptySetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::set<Large> set;

    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptySetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void SizeSetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::set<Large> set;

    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void Max_sizeSetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::set<Large> set;

    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void ClearSetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::set<Large> set;

    for (auto _ : state) {
        state.PauseTiming();
        for(long i=0; i < N; i++){
            l.randomize();
            set.insert(l);
        }
        state.ResumeTiming();

        DoNotOptimize(set);
        set.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void InsertSetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::set<Large> set;


    for (auto _ : state) {
        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            set.insert(l);
        }
        l.randomize();
        state.ResumeTiming();

        auto result = set.insert(l);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        state.PauseTiming();
        l.randomize();
        set.insert(l);
        auto it = set.begin();
        state.ResumeTiming();

        auto result = set.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseRangeSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};

    for (auto _ : state) {

        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            set.insert(l);
        }
        auto it = set.begin();
        auto itE =set.end();
        state.ResumeTiming();

        auto result = set.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void SwapSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set1;
    std::set<Large> set2;
    Large l1{};
    Large l2{};
    for(long i=0; i < N; i++){
        l1.randomize();
        set1.insert(l1);
        l2.randomize();
        set1.insert(l2);
    }

    for (auto _ : state) {

        DoNotOptimize(set1);
        DoNotOptimize(set2);
        set1.swap(set2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void CountSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.count(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void FindSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.find(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Equal_rangeSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.equal_range(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Lower_boundSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.lower_bound(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Lower_boundSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Upper_boundSetLarge(State& state) {

    auto N = state.range(0);
    std::set<Large> set;
    Large l{};
    for(long i=0; i < N; i++){
        l.randomize();
        set.insert(l);
    }

    for (auto _ : state) {

        auto result = set.upper_bound(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Upper_boundSetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
