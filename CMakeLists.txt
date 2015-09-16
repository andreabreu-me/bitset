cmake_minimum_required(VERSION 3.3) # ExternalProject_Add required

project(bitset)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE include/bitset.h)
add_library(${PROJECT_NAME} ${SOURCE})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(test/unit)
add_test(unit_test ${EXECUTABLE_OUTPUT_PATH}/test/unit/bitset_unit_test)


add_subdirectory(samples)
