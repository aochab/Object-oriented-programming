#include <QtTest>

#include "speed.h"

class SpeedTest : public QObject
{
    Q_OBJECT


private slots:
    void test_get();
    void test_property();

};


void SpeedTest::test_get()
{
    Speed speed{};

    QSignalSpy spy{&speed,SIGNAL(changed(double))};

    speed.onChange(3);

    QCOMPARE(3, speed.get());

    QCOMPARE(1,spy.count());

    QCOMPARE(3,spy.at(0).value(0));

    speed.onChange(5);

    QCOMPARE(2, speed.get());

    QCOMPARE(2,spy.count());

    QCOMPARE(2,spy.at(1).value(0));

}


void SpeedTest::test_property()
{
    Speed speed{};

    QSignalSpy spy{&speed,SIGNAL(changed(double))};

    speed.setProperty("value",10);

    QCOMPARE(0,spy.count());

    QCOMPARE(0,speed.property("value"));
}

QTEST_APPLESS_MAIN(SpeedTest)

#include "tst_speedtest.moc"
