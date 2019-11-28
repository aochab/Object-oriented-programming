#include "Large.h"
#include "BenchIncludes.h"
#include <forward_list>
#include <vector>

static void FrontForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        auto result = forwardList.front();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FrontForwardListLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void EmptyForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        auto result = forwardList.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyForwardListLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void MaxSizeForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        auto result = forwardList.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(MaxSizeForwardListLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ClearForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearForwardListLarge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void InsertAfterForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        auto it = forwardList.begin();
        l.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

static void InsertAfterCountForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        auto it = forwardList.begin();
        l.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,N,l);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterCountForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

static void InsertAfterRangeForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        auto it = forwardList.begin();

        std::vector<Large> v(N);
        for(int i=0; i<N; i++) {
            Large l2{2.3};
            v.push_back(l2);
        }
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,v.begin(),v.end());
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterRangeForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void EraseAfterForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;
    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        state.PauseTiming();
        l.randomize();
        forwardList.push_front(l);
        auto it = forwardList.begin();
        state.ResumeTiming();

        auto result = forwardList.erase_after(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

static void EraseAfterRangeForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;
    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        auto it = forwardList.begin();
        auto itL = std::next(it,N);
        state.ResumeTiming();

        auto result = forwardList.erase_after(it,itL);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterRangeForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void PushFrontForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        l.randomize();
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.push_front(l);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(PushFrontForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void ResizeForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ResizeForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void SwapForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l1{};
    Large l2{};
    std::forward_list<Large> forwardList1;
    std::forward_list<Large> forwardList2;
    for(long i=0; i < N; i++){
        l1.randomize();
        forwardList1.push_front(l1);
        l2.randomize();
        forwardList2.push_front(l2);
    }

    DoNotOptimize(forwardList1);
    DoNotOptimize(forwardList2);
    for (auto _ : state) {

        forwardList1.swap(forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();


//============================================================================================

static void MergeForwardListLarge(State& state) {

    auto N = state.range(0);
    std::forward_list<Large> forwardList1;
    std::forward_list<Large> forwardList2;

    for (auto _ : state) {

        state.PauseTiming();
        Large l1{};
        Large l2{};
        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            l1.randomize();
            forwardList1.push_front(l1);
            l2.randomize();
            forwardList2.push_front(l2);
        }
        forwardList1.sort();
        forwardList2.sort();
        state.ResumeTiming();

        DoNotOptimize(forwardList1);
        DoNotOptimize(forwardList2);
        forwardList1.merge(forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(MergeForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void SpliceAfterForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l1{};
    Large l2{};
    std::forward_list<Large> forwardList1;
    std::forward_list<Large> forwardList2;

    for (auto _ : state) {
        state.PauseTiming();

        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            l1.randomize();
            forwardList1.push_front(l1);
            l2.randomize();
            forwardList2.push_front(l2);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList1);
        DoNotOptimize(forwardList2);
        forwardList1.splice_after(forwardList1.begin(),forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SpliceAfterForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void RemoveForwardListLarge(State& state) {

    auto N = state.range(0);
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        Large l{};
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove(l);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void RemoveIfForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove_if([](Large x){return x.data[0] > 6.6; });
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveIfForwardListLarge)->RangeMultiplier(2)->Range(1, 128)->Complexity();

//============================================================================================

static void ReverseForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;
    for(long i=0; i < N; i++){
        l.randomize();
        forwardList.push_front(l);
    }

    for (auto _ : state) {

        forwardList.reverse();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReverseForwardListLarge)->RangeMultiplier(2)->Range(1<<5, 128)->Complexity();

//============================================================================================

static void UniqueForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.unique();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(UniqueForwardListLarge)->RangeMultiplier(2)->Range(1<<5, 128)->Complexity();

//============================================================================================

static void SortForwardListLarge(State& state) {

    auto N = state.range(0);
    Large l{};
    std::forward_list<Large> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            l.randomize();
            forwardList.push_front(l);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.sort();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SortForwardListLarge)->RangeMultiplier(2)->Range(1<<5, 128)->Complexity();
