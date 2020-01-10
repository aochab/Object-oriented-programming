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
    this->speed = v;
    if(acc>0){
        emit changed(acc);
    } else {
        emit changed(0);
    }
}

