set(TEST_HEADERS include/TestIncludes.h)
set(TEST_SOURCES src/DummyTest.cpp)

add_executable(07_abstract_factory_pattern_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(07_abstract_factory_pattern_test PUBLIC include)
target_link_libraries(07_abstract_factory_pattern_test 07_abstract_factory_pattern_lib gtest gtest_main pthread)
