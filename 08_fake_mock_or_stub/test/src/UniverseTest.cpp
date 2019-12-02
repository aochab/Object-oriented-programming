#include "Universe.h"
#include "TestIncludes.h"

class Interface {
public:
    virtual int test() = 0;
};

class Implementation : public Interface {
public:
    int test() override {
        return 10;
    }
};

class MyMock : public Interface {
public:
    MOCK_METHOD0(test, int());
};


class Dummy {
    Interface &interface;
public:
    explicit Dummy(Interface &interface) : interface(interface) {}
    int execute() { return interface.test(); }
};


TEST(Universe, Dummy)
{
    StrictMock<MyMock> myMock{};
    Dummy dummy(myMock);

    EXPECT_CALL(myMock,test()).WillOnce(Return(10));

    EXPECT_EQ(10,dummy.execute());
}

TEST(Universe, Create)
{
    StrictMock<TimeMock> timeMock{};
    StrictMock<ObserverMock> observerMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock,spaceMock,observerMock};


    EXPECT_CALL(timeMock, create(true)).WillOnce(Return());
    EXPECT_CALL(spaceMock, create(11)).WillOnce(Return());
    EXPECT_CALL(spaceMock, dimensions()).WillOnce(Return(11));
    std::string question = "How many dimensions there are?";
    EXPECT_CALL(observerMock, remember(question, "11"));

    universe.create();
}


TEST(Universe, SimulateEarth)
{
    StrictMock<TimeMock> timeMock{};
    StrictMock<ObserverMock> observerMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock,spaceMock,observerMock};

    EXPECT_CALL(timeMock, now).WillOnce(Return(9300000000)).WillOnce(Return(9300000001));
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());

    EXPECT_CALL(observerMock, remember("Is there planet Earth?", "Yes!"));
    universe.simulate(9300000001);
}


TEST(Universe, SimulateLife)
{
    StrictMock<TimeMock> timeMock{};
    StrictMock<ObserverMock> observerMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock,spaceMock,observerMock};

    EXPECT_CALL(timeMock, now).WillOnce(Return(9900000000)).WillOnce(Return(9900000001));
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());

    EXPECT_CALL(observerMock,  remember("Does life exist?", "Yes!"));
    universe.simulate(9900000001);
}
TEST(Universe, SimulatePeople)
{
    StrictMock<TimeMock> timeMock{};
    StrictMock<ObserverMock> observerMock{};
    StrictMock<SpaceMock> spaceMock{};

    Universe universe{timeMock,spaceMock,observerMock};

    EXPECT_CALL(timeMock, now).WillOnce(Return(13800000000)).WillOnce(Return(13800000001));
    EXPECT_CALL(timeMock, flow()).WillOnce(Return());

    EXPECT_CALL(observerMock,  remember("Have People evolved?", "Yes!"));
    universe.simulate(13800000001);
}
