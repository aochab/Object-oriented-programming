#include "Small.h"
#include "BenchIncludes.h"
#include <vector>

static void EmptySetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::set<Small> set;

    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptySetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void SizeSetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::set<Small> set;

    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void Max_sizeSetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::set<Small> set;

    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void ClearSetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::set<Small> set;

    for (auto _ : state) {
        state.PauseTiming();
        for(long i=0; i < N; i++){
            s.randomize();
            set.insert(s);
        }
        state.ResumeTiming();

        DoNotOptimize(set);
        set.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void InsertSetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::set<Small> set;


    for (auto _ : state) {
        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            set.insert(s);
        }
        s.randomize();
        state.ResumeTiming();

        auto result = set.insert(s);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        state.PauseTiming();
        s.randomize();
        set.insert(s);
        auto it = set.begin();
        state.ResumeTiming();

        auto result = set.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseRangeSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};

    for (auto _ : state) {

        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            set.insert(s);
        }
        auto it = set.begin();
        auto itE =set.end();
        state.ResumeTiming();

        auto result = set.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void SwapSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set1;
    std::set<Small> set2;
    Small s1{};
    Small s2{};
    for(long i=0; i < N; i++){
        s1.randomize();
        set1.insert(s1);
        s2.randomize();
        set1.insert(s2);
    }

    for (auto _ : state) {

        DoNotOptimize(set1);
        DoNotOptimize(set2);
        set1.swap(set2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void CountSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.count(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void FindSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.find(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Equal_rangeSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.equal_range(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Lower_boundSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.lower_bound(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Lower_boundSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Upper_boundSetSmall(State& state) {

    auto N = state.range(0);
    std::set<Small> set;
    Small s{};
    for(long i=0; i < N; i++){
        s.randomize();
        set.insert(s);
    }

    for (auto _ : state) {

        auto result = set.upper_bound(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Upper_boundSetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
