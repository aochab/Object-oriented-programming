#include <iostream>
#include "Addition.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << Addition::add(1,2) <<std::endl;
    std::cout << Addition::add(-2,2) <<std::endl;
    return 0;
}