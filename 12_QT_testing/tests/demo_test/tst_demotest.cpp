#include <QtTest>

#include <QSignalSpy>
#include "demo.h"

class DemoTest : public QObject
{
    Q_OBJECT

private slots:
    void test_case1() {

        Demo demo{};

        QSignalSpy spy{&demo,SIGNAL(added())};

        QCOMPARE(10, demo.add(2,8));

        QCOMPARE(1,spy.count());

        //demo.property("value"); mozemy bawic sie tymi property
        //demo.setProperty("value",10);

    }

};

QTEST_APPLESS_MAIN(DemoTest)

#include "tst_demotest.moc"
