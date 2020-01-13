#include <QtTest>

#include "speed.h"

class SpeedTest : public QObject
{
    Q_OBJECT


private slots:
    void test_case1();

};


void SpeedTest::test_case1()
{
    Speed speed{};

    QSignalSpy spy{&speed,SIGNAL(changed(double))};
//onChanged dodac z liczbą i nie dodawac displacement
    speed.setProperty("value",10);

    speed.get();

    QCOMPARE(5, speed.get());

    QCOMPARE(1,spy.count());

    QCOMPARE(5,spy.at(0).value(0));



    QCOMPARE(10, speed.get());

    QCOMPARE(2,spy.count());

    QCOMPARE(10,spy.at(1).value(0));
}

QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"
