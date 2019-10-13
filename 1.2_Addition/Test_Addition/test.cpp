#include "gtest/gtest.h"
#include "Addition.h"

TEST(Addition, AddPositiveNumbers_Test)
{
    EXPECT_EQ(5,Addition::add(1,3));
}

TEST(Addition, AddNegativeNumbers_Test)
{
    EXPECT_EQ(-8,Addition::add(-5,-3));
}

TEST(Addition, AddNegativeAndPositiveNumber)
{
    EXPECT_EQ(2,Addition::add(-3,5));
}


