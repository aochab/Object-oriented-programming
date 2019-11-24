
set(BUILD_GMOCK OFF CACHE BOOL "Suppressing gmock's" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Suppressing gtest's install" FORCE)

add_subdirectory(googletest)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "-O2")
add_subdirectory(benchmark)
