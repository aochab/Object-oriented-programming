#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "displacement.h"
#include "speed.h"
#include "acceleration.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Displacement>("pl.gwizdz", 1, 0, "Displacement");
    qmlRegisterType<Speed>("pl.gwizdz", 1, 0, "Speed");
    qmlRegisterType<Acceleration>("pl.gwizdz", 1, 0, "Acceleration");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    auto displacement = engine.rootObjects().first()->findChild<Displacement*>();
    auto speed = engine.rootObjects().first()->findChild<Speed*>();
    auto acceleration = engine.rootObjects().first()->findChild<Acceleration*>();

    QObject::connect(displacement, SIGNAL(changed(double)), speed, SLOT(onChange(double)));
    QObject::connect(speed, SIGNAL(changed(double)), acceleration, SLOT(onChange(double)));

    return app.exec();
}
