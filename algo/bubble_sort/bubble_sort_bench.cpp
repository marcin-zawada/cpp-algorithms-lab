#include <vector>
#include <benchmark/benchmark.h>
#include "algo/bubble_sort/bubble_sort.hpp"

using namespace mzawada::lab;
using namespace std;

constexpr unsigned int iters = 10'000'000;

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

static void BM_BubbleSort_v2_with_skip(benchmark::State &state)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    for (auto _ : state) {
        bubble_sort_v2_with_skip(input.data(), input.size());
    }
}

BENCHMARK(BM_BubbleSort)->Iterations(iters);
BENCHMARK(BM_BubbleSort_swap)->Iterations(iters);
BENCHMARK(BM_BubbleSort_v2)->Iterations(iters);
BENCHMARK(BM_BubbleSort_v2_with_skip)->Iterations(iters);

BENCHMARK_MAIN();