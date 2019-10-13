cmake_minimum_required(VERSION 3.14)
project(Addition)

set(CMAKE_CXX_STANDARD 17)

include_directories(../libaddition)
link_directories(../libaddition/build)

add_executable(Addition main.cpp)
target_link_libraries(Addition 1_2_Addition)