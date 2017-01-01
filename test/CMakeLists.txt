cmake_minimum_required (VERSION 2.6)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/include)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googlemock/include)

MESSAGE( STATUS "GTEST_SOURCE_DIR:         " ${gtest_SOURCE_DIR} )

add_executable(Encode-test test.cpp)
target_link_libraries(Encode-test encode gtest gtest_main)
enable_testing()
add_test(NAME the_encode_decode_tests COMMAND Encode-test)
