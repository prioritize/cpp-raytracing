cmake_minimum_required(VERSION 3.19)
project(RayTracing)
enable_testing()
add_subdirectory(GoogleTests)
set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracing main.cpp)
