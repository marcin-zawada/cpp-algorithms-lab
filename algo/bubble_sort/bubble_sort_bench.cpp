#include <vector>
#include <benchmark/benchmark.h>
#include "algo/bubble_sort/bubble_sort.hpp"

using namespace mzawada::lab;
using namespace std;

static void BM_BubbleSort(benchmark::State &state)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    for (auto _ : state) {
        bubble_sort(input.data(), input.size());
    }
}

static void BM_BubbleSort_swap(benchmark::State &state)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    for (auto _ : state) {
        bubble_sort_swap(input.data(), input.size());
    }
}

static void BM_BubbleSort_v2(benchmark::State &state)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    for (auto _ : state) {
        bubble_sort_v2(input.data(), input.size());
    }
}

BENCHMARK(BM_BubbleSort)->Iterations(250'000'000);
BENCHMARK(BM_BubbleSort_swap)->Iterations(250'000'000);
BENCHMARK(BM_BubbleSort_v2)->Iterations(250'000'000);

BENCHMARK_MAIN();