cmake_minimum_required(VERSION 3.10)

Project(test-ci)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE src_my_lib "my_lib/*")
add_library(my_lib STATIC ${src_my_lib})
include_directories(my_lib)

# add the executable
add_executable(test_ci main.cpp)
target_link_libraries(test_ci PUBLIC my_lib)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_all tests/all.cpp)
target_link_libraries(test_all PUBLIC ${GTEST_BOTH_LIBRARIES} pthread my_lib)

add_test(FullTest test_all)
