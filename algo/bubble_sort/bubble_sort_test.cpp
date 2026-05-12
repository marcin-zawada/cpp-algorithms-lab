#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "algo/bubble_sort/bubble_sort.hpp"

using namespace mzawada::lab;
using namespace std;

TEST(BubbleSort, TestSort)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    vector<uint8_t> expected = {1, 2, 3, 3, 4};
    bubble_sort(input.data(), input.size());
    EXPECT_THAT(input, testing::ContainerEq(expected));
}

TEST(BubbleSort, TestSortWithSwap)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    vector<uint8_t> expected = {1, 2, 3, 3, 4};
    bubble_sort_swap(input.data(), input.size());
    EXPECT_THAT(input, testing::ContainerEq(expected));
}

TEST(BubbleSort, TestSortV2)
{
    vector<uint8_t> input = {3, 2, 4, 1, 3};
    vector<uint8_t> expected = {1, 2, 3, 3, 4};
    bubble_sort_v2(input.data(), input.size());
    EXPECT_THAT(input, testing::ContainerEq(expected));
}