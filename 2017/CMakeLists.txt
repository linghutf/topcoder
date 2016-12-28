cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_definitions("-g")

add_executable(heapsort heapsort.cc)

add_executable(endian endian.c)

add_executable(heapsort_test hs.cc)

add_executable(uint_formula uint_test.cc)

add_executable(kmp kmp.cc)

install(TARGETS heapsort endian heapsort_test uint_formula kmp
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
