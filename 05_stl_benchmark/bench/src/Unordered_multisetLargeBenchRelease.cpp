#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void EmptyUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void SizeUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void Max_sizeUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void ClearUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1<<5, 1<<15)->Complexity();

//========================================================================================

static void InsertUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;
    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        l.randomize();
        state.ResumeTiming();

        auto result = unorderedMultiset.insert(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void EraseUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        auto it = unorderedMultiset.begin();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void EraseRangeUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        auto it = unorderedMultiset.begin();
        auto itE = unorderedMultiset.end();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void SwapUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l1{};
    Large l2{};
    std::unordered_multiset<Large> unorderedMultiset1;
    std::unordered_multiset<Large> unorderedMultiset2;

    for(long i=0; i < N; i++){
        l1.randomize();
        unorderedMultiset1.insert(l1);
        l2.randomize();
        unorderedMultiset1.insert(l2);
    }

    for (auto _ : state) {
        DoNotOptimize(unorderedMultiset1);
        DoNotOptimize(unorderedMultiset2);
        unorderedMultiset1.swap(unorderedMultiset2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void CountUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.count(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1<<15)->Complexity();

//========================================================================================

static void FindUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.find(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1<<15)->Complexity();

//========================================================================================

static void Equal_rangeUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for(long i=0; i < N; i++){
        l.randomize();
        unorderedMultiset.insert(l);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.equal_range(l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//========================================================================================

static void RehashUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;


    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.rehash(200);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RehashUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void ReserveUnorderedMultisetLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::unordered_multiset<Large> unorderedMultiset;

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            unorderedMultiset.insert(l);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.reserve(100);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReserveUnorderedMultisetLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
