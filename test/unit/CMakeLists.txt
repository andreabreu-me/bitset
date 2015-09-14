cmake_minimum_required(VERSION 3.3)

project(bitset_unit_test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#external dependencies
include(ExternalProject)
ExternalProject_Add (
	GTest	
	PREFIX "${PROJECT_SOURCE_DIR}/lib/gtest"
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG "release-1.7.0"
	UPDATE_COMMAND ""
	INSTALL_COMMAND ""
)

#include
ExternalProject_Get_Property(GTest source_dir)
include_directories("${source_dir}/include" "${PROJECT_SOURCE_DIR}/../../include")

#binary
set(SOURCE bitset.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

#libraries
ExternalProject_Get_Property(GTest BINARY_DIR)
add_library(gtest SHARED IMPORTED)
add_library(gtest_main SHARED IMPORTED)
#add_library(bitset SHARED IMPORTED)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${BINARY_DIR}/libgtest.a)
set_property(TARGET gtest_main PROPERTY IMPORTED_LOCATION ${BINARY_DIR}/libgtest_main.a)
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread bitset)
