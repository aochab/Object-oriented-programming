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

#include "Medium.h"

TEST(MediumTest, SizeIsOneKiloByte) {

    EXPECT_EQ(1024u, sizeof(Medium));
}

TEST(MediumTest, CreateObject) {

    Medium medium{};
}

TEST(MediumTest, HasLessThenOperator) {

    Medium a{};
    Medium b{};
    a < b;
}

TEST(MediumTest, HasEqualityOperator) {

    Medium a{};
    Medium b{};
    a == b;
}

TEST(MediumTest, CanBeHashed) {

    Medium medium{};
    std::hash<Medium> hash;
    hash(medium);
}

TEST(MediumTest, Collections) {

    Medium medium{};

    std::vector<Medium> vector{};
    vector.push_back(medium);

    std::array<Medium, 1> array{};
    array[0] = medium;

    std::deque<Medium> deque{};
    deque.push_back(medium);

    std::list<Medium> list{};
    list.push_back(medium);

    std::forward_list<Medium> forward_list{};
    forward_list.push_front(medium);

    std::map<Medium, bool> map{};
    map[medium] = true;

    std::set<Medium> set{};
    set.insert(medium);

    std::unordered_map<Medium, bool> unordered_map{};
    unordered_map[medium] = true;

    std::unordered_set<Medium> unordered_set{};
    unordered_set.insert(medium);
}


TEST(MediumTest, Randomize) {

    Medium medium{};
    medium.randomize();

    auto count = 0u;

    for (int i : medium.data) {
        ASSERT_LE(0, i);
        ASSERT_GE(std::numeric_limits<int>::max(), i);

        if (i != 0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(MediumTest, Clear) {

    Medium medium{};
    medium.randomize();
    medium.clear();

    for (int i : medium.data) {
        ASSERT_EQ(0, i);
    }
}

TEST(MediumTest, LessThenOperator1) {

    Medium medium1{};
    Medium medium2{};

    for(int i=0;i<medium1.SIZE;i++)
    {
        medium1.data[i]=i;
        medium2.data[i]=i+3;
    }
    EXPECT_EQ(true,medium1<medium2);
}

TEST(MediumTest, LessThenOperator2) {

    Medium medium1{};
    Medium medium2{};

    for(int i=0;i<medium1.SIZE;i++)
    {
        medium1.data[i]=i;
        medium2.data[i]=i-3;
    }
    EXPECT_EQ(false,medium1<medium2);
}

TEST(MediumTest, EqualityOperator1) {

    Medium medium1{};
    Medium medium2{};

    for(int i=0;i<medium1.SIZE;i++)
    {
        medium1.data[i]=i;
        medium2.data[i]=i;
    }
    EXPECT_EQ(true,medium1==medium2);
}

TEST(MediumTest, EqualityOperator2) {

    Medium medium1{};
    Medium medium2{};

    for(int i=0;i<medium1.SIZE;i++)
    {
        medium1.data[i]=i;
        medium2.data[i]=i-3;
    }
    EXPECT_EQ(false,medium1==medium2);
}

TEST(MediumTest, HashFunction) {

    Medium medium{};
    long value=0;
    for(int i=0;i<medium.SIZE;i++)
    {
        medium.data[i]=i;
        value += i;
    }
    value %= medium.SIZE;
    auto medium_hash = std::hash<Medium>{}(medium);
    EXPECT_EQ(value,medium_hash);
}

TEST(MediumTest, HashFunction2) {

    Medium medium{};
    long value=0;
    for(int i=0;i<medium.SIZE;i++)
    {
        medium.data[i]=i;
        value += i;
    }
    value %= medium.SIZE+1;
    auto medium_hash = std::hash<Medium>{}(medium);
    EXPECT_NE(value,medium_hash);
}