#include <iostream>
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                       "Nunc est nulla, vulputate vel sodales nec, ornare vel nisi. "
                       "Nullam bibendum, risus id convallis feugiat, neque tellus "
                       "vulputate nibh, in aliquam orci dui convallis leo. Nunc sit "
                       "amet odio ut justo sodales sodales. Morbi id enim ligula. Sed "
                       "luctus porttitor tellus, at blandit eros aliquam eu. Donec "
                       "iaculis orci at orci laoreet consectetur. Maecenas a sapien sit "
                       "amet orci posuere sodales. Ut sed sapien arcu. Suspendisse "
                       "feugiat porta velit, at varius ex placerat quis. Vestibulum "
                       "accumsan dictum nisl, vitae viverra ligula mattis non. Suspendisse"
                       " maximus mi vitae neque rutrum pharetra. Curabitur venenatis sapien"
                       " vel purus mollis sollicitudin.";

    TextWrapper wrapper = TextWrapper{60};
    std::cout << wrapper.result(text);

    return 0;
}
