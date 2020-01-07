#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{
    this->displacement = 0;
}

double Speed::getSpeed()
{
    return speed;
}

void Speed::onDisplacementChange(double v)
{
    qDebug() << "[Speed] Value: " << v;
    speed = v - this->displacement;
    this->displacement = v;
    if(speed>=0){
        emit changed(speed);
    } else {
        emit changed(-speed);
    }
}
