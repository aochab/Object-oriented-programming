#include <iostream>
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                                                                "Fusce at est id purus dapibus pulvinar.";

    TextWrapper wrapper = TextWrapper{17};
    std::cout << wrapper.result(text);

    return 0;
}
