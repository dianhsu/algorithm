cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-result -DONLINE_JUDGE -fdiagnostics-color=always")

project(algorithm)

find_package(benchmark REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main benchmark::benchmark)
