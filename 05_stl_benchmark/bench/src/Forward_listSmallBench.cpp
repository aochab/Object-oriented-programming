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

        forwardList.front();
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

            forwardList.empty();
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

        forwardList.max_size();
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

        forwardList.clear();
    }

    state.SetComplexityN(N);
}

BENCHMARK(ClearForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void InsertAfterForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }
    auto it = forwardList.begin();

    for (auto _ : state) {

        forwardList.insert_after(it,s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterCountForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }
    auto it = forwardList.begin();

    for (auto _ : state) {

        forwardList.insert_after(it,N,s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(InsertAfterCountForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void InsertAfterRangeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;

    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }
    auto it = forwardList.begin();

    for (auto _ : state) {

        state.PauseTiming();
        std::vector<Small> v(N);
        for(int i=0; i<N; i++) {
            Small s2{'a'};
            v.push_back(s2);
        }
        state.ResumeTiming();

        forwardList.insert_after(it,v.begin(),v.end());
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

        forwardList.erase_after(it);
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

        forwardList.erase_after(it,itL);
    }

    state.SetComplexityN(N);
}

BENCHMARK(EraseAfterRangeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void PushFrontForwardListSmall(State& state) {

    auto N = state.range(0);
    std::forward_list<Small> forwardList;

    for (auto _ : state) {
        state.PauseTiming();
        Small s{};
        s.randomize();
        state.ResumeTiming();
        forwardList.push_front(s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(PushFrontForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void ResizeForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }
    for (auto _ : state) {

        forwardList.resize(N);
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
    for (auto _ : state) {

        forwardList1.swap(forwardList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SwapForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


//============================================================================================

static void MergeForwardListSmall(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        state.PauseTiming();
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
        forwardList1.sort();
        forwardList2.sort();
        state.ResumeTiming();

        forwardList1.merge(forwardList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(MergeForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void SpliceAfterForwardListSmall(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {
        state.PauseTiming();
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
        state.ResumeTiming();

        forwardList1.splice_after(forwardList1.cbegin(),forwardList2);
    }

    state.SetComplexityN(N);
}

BENCHMARK(SpliceAfterForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveForwardListSmall(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        state.PauseTiming();
        Small s{};
        std::forward_list<Small> forwardList;
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        forwardList.remove(s);
    }

    state.SetComplexityN(N);
}

BENCHMARK(RemoveForwardListSmall)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

//============================================================================================

static void RemoveIfForwardListSmall(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        state.PauseTiming();
        Small s{};
        std::forward_list<Small> forwardList;
        for(long i=0; i < N; i++){
            s.randomize();
            forwardList.push_front(s);
        }
        state.ResumeTiming();

        forwardList.remove_if([](Small x){return x.data[0] > 'b'; });
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
    }

    state.SetComplexityN(N);
}

BENCHMARK(ReverseForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//============================================================================================

static void UniqueForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {

        forwardList.unique();
    }

    state.SetComplexityN(N);
}

BENCHMARK(UniqueForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();

//============================================================================================

static void SortForwardListSmall(State& state) {

    auto N = state.range(0);
    Small s{};
    std::forward_list<Small> forwardList;
    for(long i=0; i < N; i++){
        s.randomize();
        forwardList.push_front(s);
    }

    for (auto _ : state) {
        forwardList.sort();
    }

    state.SetComplexityN(N);
}

BENCHMARK(SortForwardListSmall)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
