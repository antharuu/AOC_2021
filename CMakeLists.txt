cmake_minimum_required(VERSION 3.24)
project(AOC)

set(CMAKE_CXX_STANDARD 23)

add_executable(AOC main.cpp Days/1/Day_1.cpp Days/1/Day_1.h Input.h Days/2/Day_2.cpp Days/2/Day_2.h Input.h Input.cpp)
