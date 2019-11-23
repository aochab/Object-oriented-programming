#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}

TEST(LargeTest, LessThenOperator1) {

    Large large1{};
    Large large2{};

    for(int i=0;i<128u*1024u;i++)
    {
        large1.data[i]=i;
        large2.data[i]=i+3;
    }
    EXPECT_EQ(true,large1<large2);
}

TEST(LargeTest, LessThenOperator2) {

    Large large1{};
    Large large2{};

    for(int i=0;i<128u*1024u;i++)
    {
        large1.data[i]=i;
        large2.data[i]=i-3;
    }
    EXPECT_EQ(false,large1<large2);
}

TEST(LargeTest, EqualityOperator1) {

    Large large1{};
    Large large2{};

    for(int i=0;i<128u*1024u;i++)
    {
        large1.data[i]=i;
        large2.data[i]=i;
    }
    EXPECT_EQ(true,large1==large2);
}

TEST(LargeTest, EqualityOperator2) {

    Large large1{};
    Large large2{};

    for(int i=0;i<128u*1024u;i++)
    {
        large1.data[i]=i;
        large2.data[i]=i-3;
    }
    EXPECT_EQ(false,large1==large2);
}
TEST(LargeTest, HashFunction) {

    Large large{};
    long value=0;
    for(int i=0; i < large.SIZE; i++)
    {
        large.data[i]=i;
        value += large.data[i]*i;
    }
    auto large_hash = std::hash<Large> {}(large);
    EXPECT_EQ(value, large_hash);
}

TEST(LargeTest, HashFunction2) {

    Large large{};
    long value=0;
    for(int i=0; i < large.SIZE; i++)
    {
        large.data[i]=i;
        value += large.data[i]*(i+1);
    }

    auto large_hash = std::hash<Large>{}(large);
    EXPECT_NE(value,large_hash);
}