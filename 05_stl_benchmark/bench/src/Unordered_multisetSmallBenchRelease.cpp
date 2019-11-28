#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void EmptyUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void SizeUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void Max_sizeUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void ClearUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void InsertUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;
    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        s.randomize();
        state.ResumeTiming();

        auto result = unorderedMultiset.insert(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void EraseUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        auto it = unorderedMultiset.begin();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void EraseRangeUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        auto it = unorderedMultiset.begin();
        auto itE = unorderedMultiset.end();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void SwapUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s1{};
    Small s2{};
    std::unordered_multiset<Small> unorderedMultiset1;
    std::unordered_multiset<Small> unorderedMultiset2;

    for(long i=0; i < N; i++){
        s1.randomize();
        unorderedMultiset1.insert(s1);
        s2.randomize();
        unorderedMultiset1.insert(s2);
    }

    for (auto _ : state) {
        DoNotOptimize(unorderedMultiset1);
        DoNotOptimize(unorderedMultiset2);
        unorderedMultiset1.swap(unorderedMultiset2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void CountUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.count(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 1<<15)->Complexity();

//========================================================================================

static void FindUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.find(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 1<<15)->Complexity();

//========================================================================================

static void Equal_rangeUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for(long i=0; i < N; i++){
        s.randomize();
        unorderedMultiset.insert(s);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.equal_range(s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//========================================================================================

static void RehashUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;


    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.rehash(200);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RehashUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void ReserveUnorderedMultisetSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::unordered_multiset<Small> unorderedMultiset;

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            unorderedMultiset.insert(s);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.reserve(100);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReserveUnorderedMultisetSmall)->RangeMultiplier(2)->Range(1, 128)->Complexity();
