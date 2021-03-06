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

TEST(TextWrapper, GetOneCharacter){
    auto wrapper = TextWrapper{1};
    std::string text = "a";

    EXPECT_EQ("a\n",wrapper.result(text));
}

TEST(TextWrapper, GetTwoCharactersOneColumn){
    auto wrapper = TextWrapper{1};
    std::string text = "ab";

    EXPECT_EQ("a\nb\n",wrapper.result(text));
}

TEST(TextWrapper, GetThreeCharactersOneColumn){
    auto wrapper = TextWrapper{1};
    std::string text = "abc";

    EXPECT_EQ("a\nb\nc\n",wrapper.result(text));
}

TEST(TextWrapper, GetThreeCharactersTwoCharacterColumn){
    auto wrapper = TextWrapper{2};
    std::string text = "abc";

    EXPECT_EQ("ab\nc\n",wrapper.result(text));
}

TEST(TextWrapper, GetTextWithSpacesTwoCharacterColumn){
    auto wrapper = TextWrapper{2};
    std::string text = "ab   cd";

    EXPECT_EQ("ab\ncd\n",wrapper.result(text));
}


TEST(TextWrapper,GetTextWithSpacesAndSaveThem){
    auto wrapper = TextWrapper{8};
    std::string text = "Lorem ipsum dolor";

    EXPECT_EQ("Lorem ip\nsum dolo\nr\n",wrapper.result(text));
}

TEST(TextWrapper,GetLongTextAndManyColumns){
    auto wrapper = TextWrapper{17};
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                       "Fusce at est id purus dapibus pulvinar.";

    EXPECT_EQ("Lorem ipsum dolor\n"
              "sit amet, consect\n"
              "etur adipiscing e\n"
              "lit. Fusce at est\n"
              "id purus dapibus \n"
              "pulvinar.\n",
              wrapper.result(text));
}

TEST(TextWrapper,GetLongTextAndManyColumns2){
    auto wrapper = TextWrapper{17};
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                       "Fusce at est id purus dapibus    pulvinar.";

    EXPECT_EQ("Lorem ipsum dolor\n"
              "sit amet, consect\n"
              "etur adipiscing e\n"
              "lit. Fusce at est\n"
              "id purus dapibus \n"
              "pulvinar.\n",
              wrapper.result(text));
}

TEST(TextWrapper, DivideWords) {
    auto wrapper = TextWrapper{9,true};
    std::string text = "Lorem ipsum dolor sit amet";

    EXPECT_EQ("Lorem ip-\n"
              "sum dolor\n"
              "sit amet\n",
              wrapper.result(text));
}

TEST(TextWrapper, DivideWords2) {
    auto wrapper = TextWrapper{15,true};
    std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                       "Nunc est nulla, vulputate vel sodales nec, ornare vel nisi.";

    EXPECT_EQ("Lorem ipsum do-\n"
              "lor sit amet,  \n"
              "consectetur ad-\n"
              "ipiscing elit. \n"
              "Nunc est nulla,\n"
              "vulputate vel  \n"
              "sodales nec,   \n"
              "ornare vel nis-\n"
              "i.\n",
              wrapper.result(text));
}