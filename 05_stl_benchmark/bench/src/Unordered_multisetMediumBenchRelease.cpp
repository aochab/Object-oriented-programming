#include "Medium.h"
#include "BenchIncludes.h"
#include <unordered_set>

static void EmptyUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void SizeUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SizeUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void Max_sizeUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Max_sizeUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//========================================================================================

static void ClearUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void InsertUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;
    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        m.randomize();
        state.ResumeTiming();

        auto result = unorderedMultiset.insert(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void EraseUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        auto it = unorderedMultiset.begin();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void EraseRangeUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;


    for (auto _ : state) {

        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        auto it = unorderedMultiset.begin();
        auto itE = unorderedMultiset.end();
        state.ResumeTiming();

        auto result = unorderedMultiset.erase(it,itE);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseRangeUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void SwapUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m1{};
    Medium m2{};
    std::unordered_multiset<Medium> unorderedMultiset1;
    std::unordered_multiset<Medium> unorderedMultiset2;

    for(long i=0; i < N; i++){
        m1.randomize();
        unorderedMultiset1.insert(m1);
        m2.randomize();
        unorderedMultiset1.insert(m2);
    }

    for (auto _ : state) {
        DoNotOptimize(unorderedMultiset1);
        DoNotOptimize(unorderedMultiset2);
        unorderedMultiset1.swap(unorderedMultiset2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void CountUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.count(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(CountUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void FindUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.find(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FindUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void Equal_rangeUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for(long i=0; i < N; i++){
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for (auto _ : state) {

        auto result = unorderedMultiset.equal_range(m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(Equal_rangeUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void RehashUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;


    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.rehash(200);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RehashUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//========================================================================================

static void ReserveUnorderedMultisetMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset;

    for (auto _ : state) {
        state.PauseTiming();
        unorderedMultiset.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            unorderedMultiset.insert(m);
        }
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.reserve(100);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReserveUnorderedMultisetMedium)->RangeMultiplier(2)->Range(1, 128)->Complexity();
