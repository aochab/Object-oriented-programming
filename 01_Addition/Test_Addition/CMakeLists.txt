cmake_minimum_required(VERSION 3.14)
project(Test_Addition)

set(CMAKE_CXX_STANDARD 17)

include_directories(../googletest/googletest/include)
include_directories(../libaddition)
link_directories(../googletest/build/lib)
link_directories(../libaddition/build/)

add_executable(Test_Addition test.cpp)
target_link_libraries(Test_Addition gtest gtest_main pthread 1_2_Addition)