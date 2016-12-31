cmake_minimum_required (VERSION 2.6)

set(SRC_EXEC
    main.cpp
    encoder.hpp)

set(SRC_LIB
    encoder.hpp)

add_library(encode ${SRC_LIB})
set_target_properties(encode PROPERTIES LINKER_LANGUAGE CXX)
