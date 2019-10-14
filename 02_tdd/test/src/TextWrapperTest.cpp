#include "TestIncludes.h"
#include "TextWrapper.h"


TEST(TextWrapper, CreateInstance) {

    auto wrapper = TextWrapper{};

}

TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};

    EXPECT_EQ(10, wrapper.columns());
}

TEST(TextWrapper, HasColumnsGetterInConstructor){
    auto wrapper = TextWrapper{2};

    EXPECT_EQ(2,wrapper.columns());
}

TEST(TextWrapper, GetEmptyText){
    auto wrapper = TextWrapper{};
    std::string text = "";

    EXPECT_EQ("",wrapper.result(text));
}