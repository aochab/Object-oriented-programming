#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                                                                "Fusce at est id purus dapibus pulvinar.";

    TextWrapper wrapper = TextWrapper{17};
    std::cout << wrapper.result(text);

    return 0;
}
