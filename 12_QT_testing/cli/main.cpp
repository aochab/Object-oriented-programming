#include <QCoreApplication>

#include "demo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Demo demo{};

    return a.exec();
}
