cmake_minimum_required(VERSION 3.14)
project(Addition)

include_directories(../libaddition)
link_directories(../libaddition/build)

set(CMAKE_CXX_STANDARD 17)

add_executable(Addition main.cpp)
target_link_libraries(Addition 1_2_Addition)