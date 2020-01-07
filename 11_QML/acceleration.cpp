#include "acceleration.h"
#include <QDebug>

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{
    this->speed = 0;
}

double Acceleration::getValue()
{
    return acceleration;
}

void Acceleration::onSpeedChange(double v)
{
    qDebug() << "[Acceleration] Value: " << v;
    acceleration = v - this->speed;
    this->speed = v;
    if(acceleration>0){
        emit changed(acceleration);
    } else {
        emit changed(0);
    }
}

