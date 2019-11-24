#include "Medium.h"
#include "BenchIncludes.h"
#include <forward_list>
#include <vector>

static void FrontForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        auto result = forwardList.front();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(FrontForwardListMedium)->RangeMultiplier(2)->Range(1, 1<<18)->Complexity();

//============================================================================================

static void EmptyForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        auto result = forwardList.empty();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EmptyForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void MaxSizeForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        auto result = forwardList.max_size();
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(MaxSizeForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ClearForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void InsertAfterForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        auto it = forwardList.begin();
        m.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterCountForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        auto it = forwardList.begin();
        m.randomize();
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,N,m);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterCountForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterRangeForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        auto it = forwardList.begin();

        std::vector<Medium> v(N);
        for(int i=0; i<N; i++) {
            Medium m2{i};
            v.push_back(m2);
        }
        state.ResumeTiming();

        auto result = forwardList.insert_after(it,v.begin(),v.end());
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterRangeForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void EraseAfterForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;
    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        state.PauseTiming();
        m.randomize();
        forwardList.push_front(m);
        auto it = forwardList.begin();
        state.ResumeTiming();

        auto result = forwardList.erase_after(it);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void EraseAfterRangeForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;
    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        state.PauseTiming();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        auto it = forwardList.begin();
        auto itL = std::next(it,N);
        state.ResumeTiming();

        auto result = forwardList.erase_after(it,itL);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterRangeForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void PushFrontForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        m.randomize();
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.push_front(m);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(PushFrontForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ResizeForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ResizeForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void SwapForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m1{};
    Medium m2{};
    std::forward_list<Medium> forwardList1;
    std::forward_list<Medium> forwardList2;
    for(long i=0; i < N; i++){
        m1.randomize();
        forwardList1.push_front(m1);
        m2.randomize();
        forwardList2.push_front(m2);
    }

    DoNotOptimize(forwardList1);
    DoNotOptimize(forwardList2);
    for (auto _ : state) {

        forwardList1.swap(forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//============================================================================================

static void MergeForwardListMedium(State& state) {

    auto N = state.range(0);
    std::forward_list<Medium> forwardList1;
    std::forward_list<Medium> forwardList2;

    for (auto _ : state) {

        state.PauseTiming();
        Medium m1{};
        Medium m2{};
        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            m1.randomize();
            forwardList1.push_front(m1);
            m2.randomize();
            forwardList2.push_front(m2);
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

BENCHMARK(MergeForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void SpliceAfterForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m1{};
    Medium m2{};
    std::forward_list<Medium> forwardList1;
    std::forward_list<Medium> forwardList2;

    for (auto _ : state) {
        state.PauseTiming();

        forwardList1.clear();
        forwardList2.clear();
        for(long i=0; i < N; i++){
            m1.randomize();
            forwardList1.push_front(m1);
            m2.randomize();
            forwardList2.push_front(m2);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList1);
        DoNotOptimize(forwardList2);
        forwardList1.splice_after(forwardList1.begin(),forwardList2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SpliceAfterForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveForwardListMedium(State& state) {

    auto N = state.range(0);
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        Medium m{};
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove(m);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveIfForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;

    for (auto _ : state) {

        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.remove_if([](Medium x){return x.data[0] > 5; });
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveIfForwardListMedium)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ReverseForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;
    for(long i=0; i < N; i++){
        m.randomize();
        forwardList.push_front(m);
    }

    for (auto _ : state) {

        forwardList.reverse();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReverseForwardListMedium)->RangeMultiplier(2)->Range(1<<5, 1<<20)->Complexity();

//============================================================================================

static void UniqueForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.unique();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(UniqueForwardListMedium)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//============================================================================================

static void SortForwardListMedium(State& state) {

    auto N = state.range(0);
    Medium m{};
    std::forward_list<Medium> forwardList;


    for (auto _ : state) {
        state.PauseTiming();
        forwardList.clear();
        for(long i=0; i < N; i++){
            m.randomize();
            forwardList.push_front(m);
        }
        state.ResumeTiming();

        DoNotOptimize(forwardList);
        forwardList.sort();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SortForwardListMedium)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
