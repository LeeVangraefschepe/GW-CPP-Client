# Root cmake
cmake_minimum_required(VERSION 3.22)

Project(Benchmarker VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# 3rdParty
add_subdirectory(3rdParty)

# Benchmark project
add_subdirectory(Benchmarker)