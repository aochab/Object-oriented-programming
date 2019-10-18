#include <iostream>
#include "Dummy.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;
    std::string x = "ab  cd";
    std::cout << x.substr(1,1) << std::endl;

    return 0;
}
