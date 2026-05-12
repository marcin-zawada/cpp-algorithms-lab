cmake_minimum_required(VERSION 3.20)
project(CppAlgorithmsLab VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

add_library(cpp_algorithms_lab STATIC 
    algo/bubble_sort/bubble_sort.cpp
)

target_include_directories(cpp_algorithms_lab PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(algolab main.cpp)
target_link_libraries(algolab PRIVATE 
    cpp_algorithms_lab
    benchmark::benchmark 
)

##
## Bench
##

add_executable(benchmarks algo/bubble_sort/bubble_sort_bench.cpp)

target_link_libraries(benchmarks PRIVATE 
    cpp_algorithms_lab 
    benchmark::benchmark_main
)

##
## Testy
##

enable_testing()

add_executable(cpp_algorithms_tests algo/bubble_sort/bubble_sort_test.cpp)

target_link_libraries(cpp_algorithms_tests PRIVATE 
    cpp_algorithms_lab    
    GTest::gtest 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cpp_algorithms_tests)