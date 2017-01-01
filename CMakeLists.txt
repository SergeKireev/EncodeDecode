cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 14)

project (EncoderDecoder)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(thirdparty/googletest)
