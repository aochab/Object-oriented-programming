#include <iostream>
#include "Dummy.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;
    return 0;
}
