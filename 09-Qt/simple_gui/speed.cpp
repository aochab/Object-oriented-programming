#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{
    this->displacement = 0;
}

void Speed::onDisplacementChange(double v)
{
    qDebug() << "[Speed] Value: " << v;
    emit changed(v);
    this->displacement = v;
}
