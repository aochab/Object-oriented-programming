#include "Small.h"
#include "BenchIncludes.h"
#include <forward_list>
#include <vector>

static void FrontForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        auto result = forwardList.front();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FrontForwardListSmall)->RangeMultiplier(2)->Range(1, 1<<18)->Complexity();

//============================================================================================

static void EmptyForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        auto result = forwardList.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void MaxSizeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        auto result = forwardList.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(MaxSizeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ClearForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void InsertAfterForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        auto it = forwardList.begin();
        s.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterCountForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        auto it = forwardList.begin();
        s.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,N,s);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterCountForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterRangeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        auto it = forwardList.begin();

        std::vector<Small> v(N);
        for(int i=0; i<N; i++) {
            Small s2{'a'};
            v.push_back(s2);
        }
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,v.begin(),v.end());
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterRangeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void EraseAfterForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        state.PauseTiming();
        s.randomize();
        forwardList.push_front(s);
        auto it = forwardList.begin();
        state.ResumeTiming();

        auto result = forwardList.erase_after(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void EraseAfterRangeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        auto it = forwardList.begin();
        auto itL = std::next(it,N);
        state.ResumeTiming();

        auto result = forwardList.erase_after(it,itL);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterRangeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void PushFrontForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        s.randomize();
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.push_front(s);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(PushFrontForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ResizeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ResizeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void SwapForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s1{};
    Small s2{};
    std::forward_list<Small> forwardList1;
    std::forward_list<Small> forwardList2;
    for(long i=0; i < N; i++){
        s1.randomize();
        forwardList1.push_front(s1);
        s2.randomize();
        forwardList2.push_front(s2);
    }

    DoNotOptimize(forwardList1);
    DoNotOptimize(forwardList2);
    for (auto _ : state) {

        forwardList1.swap(forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//============================================================================================

static void MergeForwardListSmall(State& state) {

    auto N = state.range(0);
    std::forward_list<Small> forwardList1;
    std::forward_list<Small> forwardList2;

    for (auto _ : state) {

        state.PauseTiming();
        Small s1{};
        Small s2{};
        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            s1.randomize();
            forwardList1.push_front(s1);
            s2.randomize();
            forwardList2.push_front(s2);
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

BENCHMARK(MergeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void SpliceAfterForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s1{};
    Small s2{};
    std::forward_list<Small> forwardList1;
    std::forward_list<Small> forwardList2;

    for (auto _ : state) {
        state.PauseTiming();

        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            s1.randomize();
            forwardList1.push_front(s1);
            s2.randomize();
            forwardList2.push_front(s2);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList1);
        DoNotOptimize(forwardList2);
        forwardList1.splice_after(forwardList1.begin(),forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SpliceAfterForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveForwardListSmall(State& state) {

    auto N = state.range(0);
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        Small s{};
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove(s);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveIfForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove_if([](Small x){return x.data[0] > 'b'; });
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveIfForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ReverseForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        forwardList.reverse();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReverseForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<20)->Complexity();

//============================================================================================

static void UniqueForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.unique();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(UniqueForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//============================================================================================

static void SortForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.sort();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SortForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
