cmake_minimum_required(VERSION 3.13)
project(hello-world)
set(CMAKE_CXX_STANDARD 14)

add_executable(hello-world hello-world.cpp)
add_executable(hello-world-calc hello-world.cpp calc.cpp)
add_library(test_library STATIC calc.cpp)

add_executable(print print.cpp)

include_directories(includes/math)
include_directories(includes/general)

find_library(TEST_LIBRARY test_library lib)
#target_link_libraries(hello-world LINK_PUBLIC ${TEST_LIBRARY})

