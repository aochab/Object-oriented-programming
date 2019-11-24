#include "Medium.h"
#include "BenchIncludes.h"
#include <vector>

static void EmptySetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::set<Medium> set;

    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptySetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void SizeSetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::set<Medium> set;

    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void Max_sizeSetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::set<Medium> set;

    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void ClearSetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::set<Medium> set;

    for (auto _ : state) {
        state.PauseTiming();
        for(long i=0; i < N; i++){
            m.randomize();
            set.insert(m);
        }
        state.ResumeTiming();

        DoNotOptimize(set);
        set.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void InsertSetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::set<Medium> set;


    for (auto _ : state) {
        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            set.insert(m);
        }
        m.randomize();
        state.ResumeTiming();

        auto result = set.insert(m);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        state.PauseTiming();
        m.randomize();
        set.insert(m);
        auto it = set.begin();
        state.ResumeTiming();

        auto result = set.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void EraseRangeSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};

    for (auto _ : state) {

        state.PauseTiming();
        set.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            set.insert(m);
        }
        auto it = set.begin();
        auto itE =set.end();
        state.ResumeTiming();

        auto result = set.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//===========================================================================

static void SwapSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set1;
    std::set<Medium> set2;
    Medium m1{};
    Medium m2{};
    for(long i=0; i < N; i++){
        m1.randomize();
        set1.insert(m1);
        m2.randomize();
        set1.insert(m2);
    }

    for (auto _ : state) {

        DoNotOptimize(set1);
        DoNotOptimize(set2);
        set1.swap(set2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void CountSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.count(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void FindSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.find(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Equal_rangeSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.equal_range(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Lower_boundSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.lower_bound(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Lower_boundSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//===========================================================================

static void Upper_boundSetMedium(State& state) {

    auto N = state.range(0);
    std::set<Medium> set;
    Medium m{};
    for(long i=0; i < N; i++){
        m.randomize();
        set.insert(m);
    }

    for (auto _ : state) {

        auto result = set.upper_bound(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Upper_boundSetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
