#include <QtTest>

#include "acceleration.h"

class AccelerationTest : public QObject
{
    Q_OBJECT

private slots:
    void test_get();
    void test_property();

};


void AccelerationTest::test_get()
{
    Acceleration acceleration{};

    QSignalSpy spy{&acceleration,SIGNAL(changed(double))};

    acceleration.onChange(3);

    QCOMPARE(3, acceleration.get());

    QCOMPARE(1,spy.count());

    QCOMPARE(3,spy.at(0).value(0));

    acceleration.onChange(5);

    QCOMPARE(2, acceleration.get());

    QCOMPARE(2,spy.count());

    QCOMPARE(2,spy.at(1).value(0));

}


void AccelerationTest::test_property()
{
    Acceleration acceleration{};

    QSignalSpy spy{&acceleration,SIGNAL(changed(double))};

    acceleration.setProperty("value",10);

    QCOMPARE(0,spy.count());

    QCOMPARE(0,acceleration.property("value"));
}

QTEST_APPLESS_MAIN(AccelerationTest)

#include "tst_accelerationtest.moc"
