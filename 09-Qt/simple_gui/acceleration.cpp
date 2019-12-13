#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{
    this->speed = 0;
}

void Acceleration::onSpeedChange(double v)
{
    qDebug() << "[Acceleration] Value: " << v;
    auto acc = v - this->speed;
    if(acc>0){
        emit changed(acc);
    } else {
        emit changed(0);
    }
    this->speed = v;
}

