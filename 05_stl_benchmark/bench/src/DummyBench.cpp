#include "Dummy.h"
#include "BenchIncludes.h"

static void Dummy_Integrate(State& state) {

    Dummy dummy{}; //tu dajemy daną kolekcje

    for (auto _ : state) {

        auto integral = dummy.integrate(0, state.range(0));  //ii tuu bedziemy cos liczyc i benchamrk to sobie policzy ile zeszlo itd

        DoNotOptimize(integral);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(Dummy_Integrate)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
//to jest zakres w jamim ten benchamrkj sie odpala, czyli zyaczyna od 2 i leci jak potega
//
