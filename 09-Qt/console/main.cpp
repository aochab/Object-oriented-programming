#include <QCoreApplication>

#include "displacement.h"
#include "speed.h"
#include "acceleration.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Displacement d{};
    Speed s{};
    Acceleration a{};

    QObject::connect(&d, SIGNAL(changed(double)),
                     &s, SLOT(onDisplacementChanged(double)));

    QObject::connect(&s, SIGNAL(changed(double)),
                     &a, SLOT(onSpeedChanged(double)));


    d.set(1);
    d.set(2);
    d.set(4);

    return app.exec();
}
