#include "TestIncludes.h"
#include "TextWrapper .h"


TEST(TextWrapper, CreateInstance) {

    auto wrapper = TextWrapper{};

}

TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};

    EXPECT_EQ(10, wrapper.columns());
}