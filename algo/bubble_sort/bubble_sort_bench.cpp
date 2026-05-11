#include "algo/bubble_sort/bubble_sort.hpp"
#include <benchmark/benchmark.h>

static void my_first_bubble_sort(benchmark::State &state)
{
    for (auto _ : state) {
        // todo - perform sort
    }
}

BENCHMARK(my_first_bubble_sort)->Iterations(250'000'000);

BENCHMARK_MAIN();