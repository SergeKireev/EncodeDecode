cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Encode-test test.cpp)
target_link_libraries(Encode-test encode gtest gtest_main)
