#include "TestIncludes.h"

class TextWrapper {
public:
    int columns() const{
        return 10;
    }
};

TEST(TextWrapper, CreateInstance) {

    auto wrapper = TextWrapper{};

}

TEST(TextWrapper, HasColumnsGetter){
    auto wrapper = TextWrapper{};

    EXPECT_EQ(10, wrapper.columns());
}