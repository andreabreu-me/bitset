cmake_minimum_required(VERSION 2.8)

project(bitset_samples)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#include
include_directories("${PROJECT_SOURCE_DIR}/../../include")

#binary
set(SOURCE main.cpp sample1.cpp sample2.cpp sample3.cpp sample4.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})
