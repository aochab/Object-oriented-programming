set(BENCH_HEADERS include/BenchIncludes.h)
set(BENCH_SOURCES src/DummyBench.cpp src/ExampleBench.cpp src/PauseAndResumeBench.cpp src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp src/Forward_listSmallBench.cpp src/SetSmallBench.cpp src/Unordered_multisetSmallBench.cpp)
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

add_executable(05_stl_benchmark_bench ${BENCH_HEADERS} ${BENCH_SOURCES})
target_include_directories(05_stl_benchmark_bench PUBLIC include)
target_link_libraries(05_stl_benchmark_bench 05_stl_benchmark_lib benchmark benchmark_main pthread)
