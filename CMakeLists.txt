cmake_minimum_required(VERSION 3.20)
project(CppAlgorithmsLab VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(benchmark REQUIRED)

set(EXTERNAL_SOURCES
    # none at this moment
)

add_library(cpp_algorithms_lab STATIC 
    ${EXTERNAL_SOURCES}
    algo/bubble_sort/bubble_sort.cpp
)

target_include_directories(cpp_algorithms_lab PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(cpp_algorithms_lab PUBLIC 
    benchmark::benchmark
)

add_executable(algolab main.cpp)
target_link_libraries(algolab PRIVATE cpp_algorithms_lab)

##
## Tests
##

enable_testing()

set(TEST_SOURCES
    algo/bubble_sort/bubble_sort_test.cpp
)

add_executable(cpp_algorithms_tests ${TEST_SOURCES})

target_link_libraries(cpp_algorithms_tests PRIVATE 
    GTest::gtest 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cpp_algorithms_tests)