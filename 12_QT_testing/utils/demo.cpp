#include "demo.h"


Demo::Demo(QObject* parent) : QObject (parent)
{
}

int Demo::add(int a, int b)
{
    emit added();
    return a + b;
}
