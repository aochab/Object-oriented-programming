cmake_minimum_required(VERSION 3.14)
project(Addition)

set(CMAKE_CXX_STANDARD 17)

include_directories(../libaddition)
include_directories(../googletest/googletest/include)
link_directories(../libaddition/build)
link_directories(../googletest/build/lib)

set(TEST_SOURCE ../Test_Addition/test.cpp)

add_executable(Addition main.cpp ${TEST_SOURCE})
target_link_libraries(Addition gtest gtest_main pthread)
target_link_libraries(Addition 1_2_Addition)