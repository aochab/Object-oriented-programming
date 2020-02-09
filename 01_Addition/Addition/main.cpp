#include <iostream>
#include "Addition.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    std::cout << Addition::add(1,2) <<std::endl;
    std::cout << Addition::add(-2,2) <<std::endl;
    return 0;
}