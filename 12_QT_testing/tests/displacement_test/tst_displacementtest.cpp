#include <QtTest>

#include <QSignalSpy>
#include "displacement.h"

class DisplacementTest : public QObject
{
    Q_OBJECT


private slots:
    void test_setget();
    void test_property();

};

void DisplacementTest::test_setget()
{
    Displacement displacement{};

    QSignalSpy spy{&displacement,SIGNAL(changed(double))};

    displacement.set(5);

    QCOMPARE(5, displacement.get());

    QCOMPARE(1,spy.count());

    QCOMPARE(5,spy.at(0).value(0));

    displacement.set(8);

    QCOMPARE(8, displacement.get());

    QCOMPARE(2,spy.count());

    QCOMPARE(8,spy.at(1).value(0));

}


void DisplacementTest::test_property()
{
    Displacement displacement{};

    QSignalSpy spy{&displacement,SIGNAL(changed(double))};

    displacement.setProperty("value",10);

    QCOMPARE(1,spy.count());

    QCOMPARE(10,displacement.property("value"));
}

QTEST_APPLESS_MAIN(DisplacementTest)

#include "tst_displacementtest.moc"
