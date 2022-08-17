cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-result -DONLINE_JUDGE -fdiagnostics-color=always")

project(algorithm)

find_package(benchmark REQUIRED)

add_executable(test test.cpp)
add_executable(main main.cpp)
target_link_libraries(test benchmark::benchmark)
